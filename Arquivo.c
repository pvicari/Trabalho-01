#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#define MAX 500

void Associa_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
//time_t t;
int j = MAX;

  //srand((unsigned) time(&t));
  for ( ; j > 0; j--) *(Ptr+i++) = j;//rand()%MAX;

return;
} // Associando_Valores_Arra


int main(){

  int i;
  FILE *fp;
  int vetor1[MAX];
  Associa_Valores_Array(vetor1,MAX);
  fp = fopen("arquivo_500_Decresc.bin","wb");
  for(i=0;i<MAX;i++){
  fwrite(&vetor1[i],sizeof(int),1,fp);
  }

  return 0;


}
