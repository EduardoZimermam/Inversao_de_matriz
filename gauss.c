#include <stdio.h>

int main() {

	int dim = 3, i, j, y;
	float m[dim][dim], r;
	double u[dim][dim];
	double l[dim][dim];

//Zera as martizes para garantir que não haverá lixo de memória.
	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			m[i][j] = 0;
			u[i][j] = 0;
			l[i][j] = 0;
		}
	}

//Faz a leitura da matriz de exemplo.
		for(i = 0; i < dim; i++){
			for(j = 0; j < dim; j++){
				scanf("%f", &m[i][j]);
			}
		}

//Seta um espelho da matriz m em u para que todas as operações sejam efetuadas em u.
	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			u[i][j] = m[i][j];
		}
	}


//Aplicação do método de Gauss através do espelho da matriz m sobre a matriz u.
	for(y = 0; y < dim; y++){
		for(i = y + 1; i < dim; i++){
			r = u[i][y] / u[y][y];
			l[i][y] = r;
			for(j = y; j < dim; j++){
				u[i][j] = (r * ((-1) * u[y][j])) + u[i][j];
			}
		}
	}

//Normalização da matriz l para que sua diagonal principal receba o valor 1.
	for(i = 0; i < dim; i++){
		l[i][i] = 1;
	}


//Demonstração das matrizes através do printf.
 	printf("\nMATRIZ U:\n");
	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			printf("%.17g ", u[i][j]);
		}
		printf("\n");
	}

	printf("\nMATRIZ L:\n");
	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			printf("%.17g ", l[i][j]);
		}
		printf("\n");
	}



	return 0;
}
