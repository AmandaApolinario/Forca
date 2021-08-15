#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


void palavraaleatoria(char palavra[],char dica[]);
void imagem(int qtd);
void IniciaJogo(char *palavra,char *dica);

int main(){
    char *palavra,*dica;

    IniciaJogo(palavra,dica);
    //printf("%s %s",palavra,dica);

    free(palavra);
    free(dica);
    return 0;
}

void IniciaJogo(char *palavra,char *dica){
    int cod;
    char temp[50],temp2[50];

    printf("***  JOGO DA FORCA  ***\n");
    printf("*********************\n\n");
    printf("REGRAS:\n N DIGITE LETRAS COM ACENTOS OU CEDILHA\n");
    printf("digite 1 para escrever a palavra ou 2 para jogar com uma palavra aleatoria:\n");
    scanf("%d",&cod);

    if(cod == 1){
        printf("digite a palavra:\n");
        scanf("%s",temp);
        palavra = strdup(temp);

        printf("digite uma dica:\n");
        scanf("%s",temp2);
        dica = strdup(temp2);
    }
}



void palavraaleatoria(char *palavra,char *dica){
    srand(time(NULL));
    int num = rand() % 50;
    
    if(num >= 0 && num <= 10){
        strcpy(dica,"ANIMAL");
        switch (num){
            case 0: strcpy(palavra,"BORBOLETA");
            break;
            case 1: strcpy(palavra,"MACACO");
            break;
            case 2: strcpy(palavra,"ELEFANTE");
            break;
            case 3: strcpy(palavra,"CACHORRO");
            break;
            case 4: strcpy(palavra,"TARTARUGA");
            break;
            case 5: strcpy(palavra,"COBRA");
            break;
            case 6: strcpy(palavra,"COELHO");
            break;
            case 7: strcpy(palavra,"OVELHA");
            break;
            case 8: strcpy(palavra,"CORUJA");
            break;
            case 9: strcpy(palavra,"PAPAGAIO");
            break;
            case 10: strcpy(palavra,"MORCEGO");
            break;
        }
    }
    else if(num >= 11 && num <= 20){
        strcpy(dica,"ELETRODOMESTICOS");
        switch(num){
            case 11: strcpy(palavra,"GELADEIRA");
            break;
            case 12: strcpy(palavra,"FOGAO");
            break;
            case 13: strcpy(palavra,"FREEZER");
            break;
            case 14: strcpy(palavra,"BATEDEIRA");
            break;
            case 15: strcpy(palavra,"LIQUIDIFICADOR");
            break;
            case 16: strcpy(palavra,"TELEVISÃO");
            break;
            case 17: strcpy(palavra,"SECADORA");
            break;
            case 18: strcpy(palavra,"COMPUTADOR");
            break;
            case 19: strcpy(palavra,"VENTILADOR");
            break;
            case 20: strcpy(palavra,"TELEFONE");
            break;
        }
    }
    else if(num >= 21 && num <= 30){
        strcpy(dica,"COMIDA");
        switch (num){
            case 21: strcpy(palavra,"LASANHA");
            break;
            case 22: strcpy(palavra,"ESCONDIDINHO");
            break;
            case 23: strcpy(palavra,"MACARRAO");
            break;
            case 24: strcpy(palavra,"CHURRASCO");
            break;
            case 25: strcpy(palavra,"FEIJOADA");
            break;
            case 26: strcpy(palavra,"MILKSHAKE");
            break;
            case 27: strcpy(palavra,"CHEESECAKE");
            break;
            case 28: strcpy(palavra,"TORTA");
            break;
            case 29: strcpy(palavra,"QUEIJO");
            break;
            case 30: strcpy(palavra,"SUSHI");
            break;
        }
    }

    else if(num >= 31 && num <= 40 ){
        strcpy(dica,"LUGAR (PAIS)");
        switch (num){
            case 31: strcpy(palavra,"BRASIL");
            break;
            case 32: strcpy(palavra,"ESPANHA");
            break;
            case 33: strcpy(palavra,"CHILE");
            break;
            case 34: strcpy(palavra,"SUECIA");
            break;
            case 35: strcpy(palavra,"INGLATERRA");
            break;
            case 36: strcpy(palavra,"RUSSIA");
            break;
            case 37: strcpy(palavra,"MEXICO");
            break;
            case 38: strcpy(palavra,"CANADA");
            break;
            case 39: strcpy(palavra,"AUSTRALIA");
            break;
            case 40: strcpy(palavra,"DINAMARCA");
            break;
        }
    }

    else if(num >= 41 && num <= 50){
        strcpy(dica,"ROUPAS");
        switch (num){
            case 41: strcpy(palavra,"VESTIDO");
            break;
            case 42: strcpy(palavra,"CASACO");
            break;
            case 43: strcpy(palavra,"CAMISA");
            break;
            case 44: strcpy(palavra,"SHORT");
            break;
            case 45: strcpy(palavra,"BERMUDA");
            break;
            case 46: strcpy(palavra,"GRAVATA");
            break;
            case 47: strcpy(palavra,"TERNO");
            break;
            case 48: strcpy(palavra,"PIJAMA");
            break;
            case 49: strcpy(palavra,"BIQUINI");
            break;
            case 50: strcpy(palavra,"JEANS");
            break;
        }
    }
}

void imagem(int qtd){
    if(qtd == 5){
        printf("\n___________\n");
        printf("|          |\n");
        printf("|           \n");
        printf("|           \n");
        printf("|           \n");
        printf("|           \n");
        printf("--           \n");
    }
    else if(qtd == 4){
        printf("\n___________\n");
        printf("|          |\n");
        printf("|          0\n");
        printf("|           \n");
        printf("|           \n");
        printf("|           \n");
        printf("--           \n");
    }
    else if(qtd == 3){
        printf("\n___________\n");
        printf("|          |\n");
        printf("|          0\n");
        printf("|          | \n");
        printf("|           \n");
        printf("|           \n");
        printf("--           \n");
    }
    else if(qtd == 2){
        printf("\n___________\n");
        printf("|         |\n");
        printf("|         0\n");
        printf("|         | \n");
        printf("|        /\\ \n");
        printf("|           \n");
        printf("--           \n");
    }
    else if(qtd == 1){
        printf("\n___________\n");
        printf("|         |\n");
        printf("|        \\O/\n");
        printf("|         | \n");
        printf("|        /\\ \n");
        printf("|           \n");
        printf("--           \n");
    }
    else{
        printf("\n___________\n");
        printf("|         |\n");
        printf("|        \\X/\n");
        printf("|         | \n");
        printf("|        /\\ \n");
        printf("|           \n");
        printf("--           \n");
    }
}