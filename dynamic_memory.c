#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define oops(s) {perror((s)); exit(EXIT_FAILURE);}
#define MALLOC(s, t) s = malloc(t); if(s == NULL) {oops("error: malloc() ");}
#define INCREMENT 10

int main() {
	double x, y, z, **xyz, **tmp;
	int i, scannedItems, current_size = 0, n = INCREMENT;
	char buffer[50];

	MALLOC(xyz, sizeof(double *) * INCREMENT);
	for (i = 0; i < INCREMENT; i++) {
		MALLOC(xyz[i], sizeof(double) * 3);
	}

	FILE *data = fopen("files/data", "r");
	if (data == NULL) {
		perror("Couldn't open file: ");
		exit(EXIT_FAILURE);
	}

	tmp = xyz;
	while (fgets(buffer, sizeof buffer, data) != NULL) {
		scannedItems = sscanf(buffer, "%lf %lf %lf", &x, &y, &z);

		if (scannedItems != 3) {
			fprintf(stderr, "Invalid line: %s", buffer);
			continue;
		}

		x = round(x * 100) / 100;
		y = round(y * 100) / 100;
		z = round(z * 100) / 100;

		(*tmp)[0] = x;
		(*tmp)[1] = y;
		(*tmp)[2] = z;

		current_size++;

		if (current_size >= n) {
			tmp = realloc(xyz, sizeof(double *) * (n + INCREMENT));
			if (tmp == NULL) {
				oops("realloc() error! ");
			}
			for (i = n; i < n + INCREMENT; i++) {
				MALLOC(tmp[i], sizeof(double) * 3);
			}

			xyz = tmp;
			tmp += (n-1);
			
			n += INCREMENT;
		}

		tmp++;
	}

	fclose(data);

	for (i = 0; i < n; i++) {
		if (n < current_size) {
			printf("%.2lf %.2lf %.2lf\n", xyz[i][0], xyz[i][1], xyz[i][2]);
		}
		free(xyz[i]);
	}

	free(xyz);

	return EXIT_SUCCESS;
}
