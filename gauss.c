#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **generateSquareRandomMatrix(int n)
{
	double **mat;

  srand(time(NULL));
  
  mat = (double**) malloc (n * sizeof(double**));

  for(int i = 0; i < n; i++){
		mat[i] = (double*) malloc (n * sizeof(double*));
  }		

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			mat[i][j] = rand();
		}
	}

	return(mat);
}

void trocarLinha(double **m, int i, int j, int dim){
	int maior = i;
	double aux;

	for(i; i < dim; i++){
		if(m[maior][j] < m[i][j])
			maior = i;
	}

	i = j;

	if(maior != i){
		for(j; j < dim; j++){
			aux = m[maior][j];
			m[maior][j] = m[i][j];
			m[i][j] = aux;
		}
	}

}

int main(int argc, char const *argv[]) {

	int dim = atoi(argv[1]), i, j, y;
	double **m, r;
	double **u, **l;


	m = generateSquareRandomMatrix(dim);
	u = (double**) malloc (dim * sizeof(double**));
	l = (double**) malloc (dim * sizeof(double**));

	for(i = 0; i < dim; i++){
		u[i] = (double*) malloc (dim * sizeof(double*));
		l[i] = (double*) malloc (dim * sizeof(double*));
	}

//Zera as martizes para garantir que não haverá lixo de memória.
	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			u[i][j] = 0;
			l[i][j] = 0;
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
		trocarLinha(u, y, y, dim);
		for(i = y + 1; i < dim; i++){
			r = u[i][y] / u[y][y];
			l[i][y] = r;
			for(j = y; j < dim; j++){
				u[i][j] = (r * u[y][j]) - u[i][j];
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
