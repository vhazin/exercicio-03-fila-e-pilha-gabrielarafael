#include <stdio.h>
#include <string.h>
int achar_prox(int pessoas[],int inicio,int tamanho){

    if(inicio==tamanho)
        return 0;
    else{
    if(pessoas[inicio]!=0){
        return pessoas[inicio];}
    else{
        return achar_prox(pessoas,inicio+1,tamanho);
    }
    }
}
int local_prox(int pessoas[],int inicio,int flag,int tamanho){
   if(inicio==tamanho-1){
        return tamanho-1;
        }
   else{
       if(pessoas[inicio]!=0 && flag != inicio){
           return inicio;
       }
       else{
           return local_prox(pessoas,inicio+1,flag,tamanho);
       }
   }
}

int main()
{
    int numero_fila;
    scanf(" %d",&numero_fila);
    int pessoas_fila[numero_fila];
    int iterador;
    int iterador2;
    char string[numero_fila][500];
    int pessoas_retiradas;



    for(iterador=0;iterador<numero_fila;iterador++){
        scanf("%s",string[iterador]);
    }
    for(iterador=0;iterador<numero_fila;iterador++){
        pessoas_fila[iterador] = atoi(string[iterador]);
    }

    scanf("%d",&pessoas_retiradas);
    char stringR[pessoas_retiradas][500];
    for(iterador=0;iterador<pessoas_retiradas;iterador++){
        scanf("%s",stringR[iterador]);
    }

    for(iterador = 0 ; iterador < numero_fila ;iterador++){
        for(iterador2 = 0 ; iterador2<pessoas_retiradas;iterador2++){
            if(pessoas_fila[iterador] == atoi(stringR[iterador2])){
                pessoas_fila[iterador] = 0;
            }
        }
    }

    for(iterador = 0; iterador<numero_fila;iterador++){
        if(pessoas_fila[iterador]==0 && iterador!= numero_fila-1){
            pessoas_fila[iterador]=achar_prox(pessoas_fila,iterador,sizeof(pessoas_fila)/sizeof(pessoas_fila[0]));
            pessoas_fila[local_prox(pessoas_fila,iterador,iterador,sizeof(pessoas_fila)/sizeof(pessoas_fila[0]))]=0;

        }
    }
    printf("\n");
    for(iterador = 0;iterador< numero_fila-pessoas_retiradas;iterador++){
        printf("%d ",pessoas_fila[iterador]);
    }




}
