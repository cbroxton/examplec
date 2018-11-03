#include <errno.h>
#include <stdio.h>
#include <string.h>

#define ERR_MSG(fn) {(void)fflush(stderr); \
					 (void)fprintf(stderr, __FILE__ ":%d:" #fn ": %s\n", \
							 	   __LINE__, strerror(errno)); }
#define METAPRINTF(fn, args, exp) ({int ret = fn args; if(ret exp) ERR_MSG(fn); ret;})

#define PRINTF(args)	METAPRINTF(printf, args, < 0)
#define FPRINTF(args)	METAPRINTF(fprintf, args, < 0)
#define SCANF(args)		METAPRINTF(scanf, args, < 0)
#define FSCANF(args)	METAPRINTF(fscanf, args, < 0)
#define FFLUSH(args)	METAPRINTF(fflush, args, < 0)

int main() {
	int x;

	PRINTF(("This is so cool!\n"));
	FPRINTF((stderr, "This is on stderr!\n"));
	PRINTF(("Enter a number: "));
	int ret = SCANF(("%d", &x));
	if (ret > 0) {
		PRINTF(("%d\n", x));
	} else {
		printf("Invalid number!\n");
	}

	return 0;
}
