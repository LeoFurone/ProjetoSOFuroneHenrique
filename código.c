#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

 	
	int		M, N, T, l, c, ret;
	float 		**matriz, V;

			void* SearchFunction (void *arg);
			float** CreateMatriz (int M, int N);


int main()
{
	
	char 	nome_arquivo[15];
	int 	i, j, aux;
	
		printf("Dimensao: ");		scanf("%d %d", &M, &N);
		printf("NUM_Threads: ");	scanf("%d", &T);
		printf("Valor: ");		scanf("%f", &V);
		getchar(); 
		printf("Nome_Arquivo: ");	scanf("%s",nome_arquivo);

		
			FILE* file = fopen(nome_arquivo, "r");
				if(file == NULL){
					printf("Arquivo nao encontrado\n"); 
					return 0;
					}
					
			matriz = CreateMatriz(M, N);
			pthread_t thread_id[T]; 
				
			for(l = 0; l < M; l++){
				for(c = 0; c < N; c++){
					fscanf(file, "%f", &matriz[l][c]); 
					}
			}
		
		aux = M / T;	l = 0;		c = 0;	ret = 0;
		
		
				for(j = 0 ;j < aux; j++){
					for(i = 0; i < T; i++){
						pthread_create(&thread_id[i], NULL, SearchFunction, NULL);
						pthread_join(thread_id[i], NULL);
					}
				  //	for(i=0; i<T; i++){ pthread_join(thread_id[i], NULL); }		
				}
				
				if(T < M){
					aux = M - aux * T;
					for(i = 0; i < aux; i++){ 
						pthread_create(&thread_id[i], NULL, SearchFunction, NULL);
						pthread_join(thread_id[i], NULL);
					}
				  //	for(i=0; i<aux; i++){ pthread_join(thread_id[i], NULL); }
				}

				if(ret == 0){ printf("Valor nao encontrado\n"); }
						g
return 0;
}

void* SearchFunction (void *arg) 
{	
	while(c < M){
		if(matriz[l][c] == V){ printf("%d - %d\n", l, c); ret =g 1; }
		c++;
	}
	
	c = 0;	l++;
}

float** CreateMatriz(int M, int N) 
{ 
 
  int i, j; 
  
  	float **m = (float**)malloc(M * sizeof(float*)); 
 
  		for (i = 0; i < M; i++){ 
       		m[i] = (float*) malloc(N * sizeof(float)); 
       		for (j = 0; j < N; j++) { m[i][j] = 0.0; }
  		}
  
return m;
}
