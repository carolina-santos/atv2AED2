//Carolina Gabriele Souza dos Santos - 102159

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100


void imprimeVetor(int vet[]){
    int i=0;
    for(i=0; i<TAM; i++)
        printf("%d ",vet[i]);
    printf("\n");
}

void shellsort(int vet[]){
    int i , j , num,salto = 1;
  
    do {
        salto=3*salto+1;
    }while(salto<TAM); 
    do {
        salto/=3;
        for(i=salto; i<TAM; i++) {
            num=vet[i];
            j=i-salto;
            while(j>=0&&num<vet[j]) {
                vet[j+salto]=vet[j];
                j-=salto;
            }
            vet[j+salto]=num;
        }
    }while(salto>1);
    imprimeVetor(vet);
}

void quicksort(int vet[], int direita, int esquerda){
    int i, j, x, y;
     
    i=esquerda;
    j=direita;
    x=vet[(esquerda+direita)/2];
     
    while(i<=j){
        while(vet[i]<x && i<direita)
            i++;  
        while(vet[j]>x && j>esquerda)
            j--;
        if(i<=j){
            y=vet[i];
            vet[i]=vet[j];
            vet[j]=y;
            i++;
            j--;
        }
    }  
    if(j > esquerda) 
        quicksort(vet, esquerda, j); 
    if(i < direita) 
        quicksort(vet, i, direita);
   
    imprimeVetor(vet);
}

void heapSort(int vet[]){
   int i=TAM/2,pai,filho, aux,n=TAM;

   while(n!=0){
      if (i > 0){
          i--;
          aux=vet[i];
      }else{
          n--;
          if(n==0) 
            return;
          aux=vet[n];
          vet[n]=vet[0];
      }
      pai=i;
      filho=i*2+1;
      while(filho<n){
          if((filho+1<n)&&(vet[filho+1]>vet[filho]))
              filho++;
          if (vet[filho]>aux){
             vet[pai]=vet[filho];
             pai=filho;
             filho=pai*2+1;
          }else
             break;
      }
      vet[pai] = aux;
   }
    imprimeVetor(vet);
}

int main (){
   
    int vet [TAM];
    int i;
    srand((unsigned)time(NULL));
    clock_t tempo;

    for (i=0; i<TAM; i++){
        //vet[i] = (rand()%TAM);
        vet[i] = i;
    }

    //shellsort(vet);
    //quicksort(vet, TAM-1,0);
    heapSort(vet);
    
    printf("\n Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);    
    return 0;
}


