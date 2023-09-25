#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

struct ExecInfo
{
    int compare;
    int exchange;
    double execTime;
};

typedef struct ExecInfo execInfo;

//InsertionSort
execInfo insertion_sort(int vetor[], int n) {
  int comparations = 0;
  int exchanges = 0;
  double time_spent = 0.0;
  clock_t begin = clock();
  for (int step = 1; step < n; step++) {
    int key = vetor[step];
    int j = step - 1;

    while (key < vetor[j] && j >= 0) {
        comparations++;
        exchanges++;
      vetor[j + 1] = vetor[j];
      --j;
    }
    vetor[j + 1] = key; 
    exchanges++;
  }
  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    execInfo info;
    info.compare = comparations;
    info.exchange = exchanges;
    info.execTime = time_spent;
    return info;
}

void run_func(int vector[], int n, char* mode){
    FILE *arq;
    arq = fopen("InsertionSort.txt", "a");
    int result;
    execInfo info;

    if (arq == NULL) 
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    info = insertion_sort(vector, n);
    result = fprintf(arq, mode);  					  
    result = fprintf(arq,", %d \n", n);  					  
    result = fprintf(arq,"Comparações: %d\n",info.compare);  
    if (result == EOF)		    
	  printf("Erro na Gravacao\n");					  
    result = fprintf(arq,"Trocas: %d\n",info.exchange);
    if (result == EOF)		    
	  printf("Erro na Gravacao\n");  					  
    result = fprintf(arq,"Tempo: %f\n\n",info.execTime);  					  
    if (result == EOF)		    
	  printf("Erro na Gravacao\n");

    fclose(arq);
}

int main(){
    //gerando dados
    int vec1_cres[100];
    int vec1_desc[100];
    int vec1_rand[100];

    int vec2_cres[1000];
    int vec2_desc[1000];
    int vec2_rand[1000];

    int vec3_cres[10000];
    int vec3_desc[10000];
    int vec3_rand[10000];

    int vec4_cres[100000];
    int vec4_desc[100000];
    int vec4_rand[100000];

    for(int i=0; i<100; i++){
        vec1_cres[i] = i;
        vec1_desc[i] = 99-i;
        vec1_rand[i] = rand()%100;
    }

    run_func(vec1_cres, 100, "Crescente");
    run_func(vec1_desc, 100, "Descresecente");
    run_func(vec1_rand, 100, "Aleatório");

    for(int i=0; i<1000; i++){
        vec2_cres[i] = i;
        vec2_desc[i] = 999-i;
        vec2_rand[i] = rand()%1000;
    }

    run_func(vec2_cres, 1000, "Crescente");
    run_func(vec2_desc, 1000, "Descresecente");
    run_func(vec2_rand, 1000, "Aleatório");

    for(int i=0; i<10000; i++){
        vec3_cres[i] = i;
        vec3_desc[i] = 9999-i;
        vec3_rand[i] = rand()%10000;
    }

    run_func(vec3_cres, 10000, "Crescente");
    run_func(vec3_desc, 10000, "Descresecente");
    run_func(vec3_rand, 10000, "Aleatório");

    for(int i=0; i<100000; i++){
        vec4_cres[i] = i;
        vec4_desc[i] = 99999-i;
        vec4_rand[i] = rand()%100000;
    }

    run_func(vec4_cres, 100000, "Crescente");
    run_func(vec4_desc, 100000, "Descresecente");
    run_func(vec4_rand, 100000, "Aleatório");
    
    printf("Ok");

}