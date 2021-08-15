#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int ojogo(char letra, char palavra[], char lista[],int tamlista);
void palavraaleatoria(char palavra[],char dica[]);
void imagem(int qtd);

int main(){
    int cod;
    char palavra[50],letra;
    char a;
    char dica[50];

    printf("***  JOGO DA FORCA  ***\n");
    printf("\n");
    printf("*********************\n\n");
    printf("REGRAS:\n N DIGITE LETRAS COM ACENTOS OU CEDILHA\n");
    printf("digite 1 para escrever a palavra ou 2 para jogar com uma palavra aleatoria:\n");
    scanf("%d",&cod);
    if(cod == 1){
        printf("digite a palavra\n");
        scanf("%s",palavra);
        scanf("%c",&a);
        printf("digite uma palavra como dica\n");
        scanf("%s",dica);
        scanf("%c",&a);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("*** JOGO DA FORCA ***\n");
        printf("*********************\n\n");
    }
    else if(cod == 2){
        palavraaleatoria(palavra,dica);

    }
    else{
        printf("digite um numero válido\n");
    }

    printf("a dica é: %s\n",dica);
    printf("a palavra tem %ld letras",strlen(palavra));

    int tamlista = 0,fazparar = 1;
    char lista[40];
    int chances = 5;

    while(fazparar != 0){
        printf("\ndigite a letra:\n");
        scanf("%c%c",&a,&letra);
        letra = toupper(letra);
        printf("\n");
        lista[tamlista] = letra;
        tamlista++;
        fazparar = ojogo(letra,palavra,lista,tamlista);
        
    }
    char continuar;
    if(fazparar == 0){
        printf("\nVOCE GANHOU!!!");
        exit(0);
    }

    return 0;
}

int ojogo(char letra, char palavra[], char lista[],int tamlista){
    int tam,i,j,teste=0,testeletra = 0;
    static int x =0;
    static int chances = 5;
    tam   = strlen(palavra);
    int fazparar;
    fazparar = tam;

    for(i=0;i<tam;i++){

        if(letra == palavra[i]){
            testeletra = 1;
        }
        
        for(j=0;j<tamlista;j++){
            if(palavra[i] == lista[j]){
                teste=1;
            }
        }
        if(teste == 1){
            printf("%c ",palavra[i]);
            teste = 0;
            fazparar--;
        }
        else{
            printf("_ ");
        }
    }

    if(testeletra == 1){
        printf("\nA LETRA \'%c\' ESTA NA PALAVRA",letra);
    }
    else{
        printf("\nA LETRA \'%c\' NAO ESTA NA PALAVRA",letra);
        printf("\nAs letras ja utilizadas foram:");
        int i;
        for(i=0;i<tamlista;i++){
            printf("%c ",lista[i]);
        }
        printf("\n");
        chances--;
    }
    imagem(chances);
    printf("\nVOCE TEM %d CHANCES AINDA",chances);
    if(chances == 0){
        printf("\nVOCE PERDEU :\( ");
        printf("\nA PALAVRA ERA %s",palavra);
        printf("\nTENTE NOVAMENTE");
        exit(0);
    }

    return fazparar;
}

void palavraaleatoria(char palavra[],char dica[]){
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