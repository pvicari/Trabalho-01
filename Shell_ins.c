#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


    // numero maximo de numeros aleatorios
#define MAX 100000
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/


void Bubble(int *vet){

	int i, j;
	for(i = 1; i < MAX; i++)
  		for(j = 0; j < (MAX-i); j++)
    		 if ( *(vet+j+1) < *(vet+j) )
        		Troca(vet, j, j+1);
	return;
}

void Troca(int *vet, int a, int b){

	int aux;

	aux = vet[a];
	vet[a] = vet[b];
	vet[b] = aux;
}




void ler_arquivo(int *vetor1,FILE *fp){
    fread(vetor1,sizeof(int),MAX,fp);
    return;
}

void Imprimindo(int *Ptr) {

 int i = 0;   // indice para percorrer o array

 for (; i < MAX; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));
}



int Leitura_Dimensao_Array(void) {
int dim, continua;
  do
   {
     continua = 0;
     printf("Insira o numero de componentes do array (>= 1 && <= 500000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX) ) continua = 1;
   }
  while ( continua );

return(dim);
} // Leitura_Dimensao_Array

/*--------------------------------------------------------*/
void Associa_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
time_t t;

  srand((unsigned) time(&t));
  for ( ; i < Dim; i++) *(Ptr+i) = rand()%1000;

return;
} // Associando_Valores_Array

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array

 for (; i < Dim; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));
} // Associando_Valores_Array

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*void Troca(int *Ind1, int *Ind2) {
int aux;
  aux =  *Ind1;
  *Ind1 =  *Ind2;
  *Ind2 = aux;
} // Troca
*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void Ordenacao_Insercao(int *Elem, int Dim) { //ordem crescente
 int i, j, x;

 for (i = 1; i < Dim; i++) {       // controla o numero de varreduras que deve ser (Dim-1)
   x = *(Elem+i);
   j = i-1;
   while ( (j >= 0) &&  (*(Elem+j) > x) ) {   // procura a posição correta para inserir o elemento x
     *(Elem+j+1) = *(Elem+j);  // deslocando o elemento e abrindo espaço para a futura inserção
     j--;
   }     // while
   *(Elem+j+1) = x;
  }  //for
  return;
} // Ordenacao_Insercao
/*--------------------------------------------------------*/

void ShellSort (int *Str, int Dim) {
int i, j, x, salto;

for (salto=Dim/2; salto>0; salto /=2){
   for (i = salto; i < Dim; i++) {
     x = *(Str+i);
     for (j=i; j >= salto && x < *(Str+j-salto); j=j-salto)
        *(Str+j) = *(Str+j-salto);
     *(Str+j) = x;
   }	//for i
}	// for k
return;
}	//ShellSort
/*--------------------------------------------------------*/




int main(voi){
int vetor1[MAX];   // array vetor1 para armazenar os elementos


   struct timeval inicio, final;
    int tmili;
    int i;

    FILE *fp;

   fp = fopen("arquivo_100000.bin","rb");
   if(!fp){
   printf("error\n");
   exit(1);
   }
   ler_arquivo(vetor1,fp);
   //Imprimindo(vetor1);







    gettimeofday(&inicio, NULL);
    for(i=0;i<1000;i++)
    //ShellSort(vetor1,MAX);
    Bubble(vetor1);
    gettimeofday(&final, NULL);
    tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);

    printf("tempo decorrido: %d\n", tmili);

    fclose(fp);
  //Imprimindo_Valores_Array(&vetor1[0],n1);
  //puts("\n\n\n");

  //Imprimindo_Valores_Array(vetor1,n1);

  //printf("\n\n Acabou ");
  //puts("\n\n\n");
  //system("Pause");
  return(0);
}

