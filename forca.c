#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void imagem(int qtd);
char* escolhePalavra(char** palavras);
void oJogo(char* palavra,char* preenchePalavra);

int main(){
    FILE *arq = fopen("palavras.txt","r");
    if(arq == NULL){
        printf("erro na leitura do arquivo");
    }

    int i=0;
    char** palavras = (char**)malloc(sizeof(char*) * 118);
    char pal[100];

    fgets(pal,100,arq);

    while(fgets(pal,55,arq)){
        palavras[i] = strdup(pal);
        i++;
        
    }

    for(int j=0;j<i;j++){
        palavras[j][strlen(palavras[j])-1]='\0';
    }

    printf("***  JOGO DA FORCA  ***\n");
    printf("*********************\n\n");
    printf("REGRAS:\n N DIGITE LETRAS COM ACENTOS OU CEDILHA\n");
    printf("digite enter para iniciar\n");
    while(getchar() != '\n'){}
 
    char* palavraAleatoria = escolhePalavra(palavras);
    char* preenchePalavra = (char*)malloc(sizeof(char)*strlen(palavraAleatoria));

    int j;
    for(j=0;j<strlen(palavraAleatoria);j++){
        preenchePalavra[j] = '_';
    }
    preenchePalavra[j] = '\0';
    
    oJogo(palavraAleatoria,preenchePalavra);

    for(j=0;j<i;j++){
        free(palavras[j]);
    }
    free(palavras);
    free(preenchePalavra);
    fclose(arq);
    return 0;
}

void oJogo(char* palavra,char* preenchePalavra){
    int chances = 5,venceu=0;
    int qtdLetras = strlen(palavra),ver = 0;
    char letra;
    char letrasUtilizadas[26];
    int qtdLetrasUtilizadas = 0;

    while(chances >0 && venceu == 0){
        printf("VOCE TEM %d CHANCES\n",chances);
        printf("DIGITE UMA LETRA:\n");
        scanf("%c",&letra);
        letra = tolower(letra);
        getchar();

        for(int i=0;i<strlen(palavra);i++){
            if(letra == palavra[i]){
                preenchePalavra[i] = letra;
                qtdLetras--;
                ver=1;
            }
        }
        if(ver == 0){
            imagem(chances);
            chances--;
            printf("ESSA LETRA NAO ESTA NA PALAVRA!!!\n");
            printf("LETRAS JA UTILIZADAS:\n");
            letrasUtilizadas[qtdLetrasUtilizadas]= letra;
            qtdLetrasUtilizadas++;
            for(int i=0;i<qtdLetrasUtilizadas;i++){
                printf("%c ",letrasUtilizadas[i]);
            }
            printf("\n");
        }
        else{
            ver = 0;
            for(int i=0;i<strlen(palavra);i++){
                printf("%c",preenchePalavra[i]);
            }
        }
        printf("\n");
        
        if(qtdLetras == 0){
            printf("VOCE VENCEU!!!!");
            exit(0);
        }
        if(chances == 0){
            printf("VOCE PERDEU! :/\n");
            printf("A palavra era %s\n",palavra);
        }

    }
}

char* escolhePalavra(char** palavras){
    srand(time(NULL));
    int num = rand() % 116;
    printf("A dica eh: ");

    if(num < 26){
        printf("profissoes");
    }
    else if(num <60){
        printf("animais");
    }
    else if(num <97){
        printf("objetos");
    }
    else if(num<116){
        printf("frutas");
    }
    printf("\n");
    return palavras[num];
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