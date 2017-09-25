#include <stdio.h>

int main() {

	float r = 0;
	int dim = 3, i, j, y;
	float m[dim][dim];
	double u[dim][dim];

	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			scanf("%f", &m[i][j]);
		}
	}

	for(j = 0; j < dim; j++){
		u[0][j] = m[0][j];
	}

	for(i = 1; i < dim; i++){
		r = m[i][0] / m[i - 1][0];
		for(j = 0; j < dim; j++){
			u[i][j] = (r * ((-1) * m[i - 1][j])) + m[i][j];
		}
	}

	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			printf("%.2lf ", u[i][j]);
		}
		printf("\n");
	}

	return 0;
}