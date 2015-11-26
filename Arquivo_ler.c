#include <stdio.h>
#include <stdlib.h>
#define MAX 50000

void ler_arquivo(int *vetor1,FILE *fp){
    fread(vetor1,sizeof(int),MAX,fp);
    return;
}

void Imprimindo_Valores_Array(int *Ptr) {

 int i = 0;   // indice para percorrer o array

 for (; i < MAX; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));
}


int main(){

  FILE *fp;
  int vetor1[MAX];

  fp = fopen("arquivo_50000.bin","rb");
  ler_arquivo(vetor1,fp);

  Imprimindo_Valores_Array(vetor1);

  return 0;


}
