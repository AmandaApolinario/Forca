import random

def imagem(qtd):
    if(qtd == 5):
        print("\n___________");
        print("|          |");
        print("|           ");
        print("|           ");
        print("|           ");
        print("|           ");
        print("--           ");
    elif(qtd == 4):
        print("\n___________");
        print("|          |");
        print("|          0");
        print("|           ");
        print("|           ");
        print("|           ");
        print("--           ");
    elif(qtd == 3):
        print("\n___________");
        print("|          |");
        print("|          0");
        print("|          | ");
        print("|           ");
        print("|           ");
        print("--           ");
    elif(qtd == 2):
        print("\n___________");
        print("|         |");
        print("|         0");
        print("|         | ");
        print("|        /\\ ");
        print("|           ");
        print("--           ");
    elif(qtd == 1):
        print("\n___________");
        print("|         |");
        print("|        \\O/");
        print("|         | ");
        print("|        /\\ ");
        print("|           ");
        print("--           ");
    else:
        print("\n___________");
        print("|         |");
        print("|        \\X/");
        print("|         | ");
        print("|        /\\ ");
        print("|           ");
        print("--           ");


palavras = []
qtdLinhas = 0

arq = open('palavras.txt','r')
palavras = arq.readlines()

for i in palavras:
    qtdLinhas+=1


print("***  JOGO DA FORCA  ***");
print("*********************");
print("REGRAS:\nN DIGITE LETRAS COM ACENTOS OU CEDILHA\n\n");

indice = random.randint(2,qtdLinhas)
palavraAleatoria = palavras[indice]
palavraAleatoria = palavraAleatoria[:-1] #remove o \n

print("A dica eh: ")
if(indice <27):
    print("profissoes")
elif(indice < 61):
    print("animais")
elif(indice <98):
    print("objetos")
else:
    print("frutas")

preenchePalavra = []
j=0

for i in palavraAleatoria:
    preenchePalavra.append('_')

for i in preenchePalavra:
    print(i + " ",end = "")
print("\n")

chances = 5
qtdLetras = len(palavraAleatoria)
ver = 0
letrasUtilizadas = []
venceu = 0

while(chances > 0 and venceu == 0):
    print("VOCE TEM " + str(chances) + " CHANCES")
    print("DIGITE UMA LETRA")
    letra = input()
    letra.lower()
    j =0

    for i in palavraAleatoria:
        if letra == i:
            preenchePalavra[j] = letra
            qtdLetras-=1
            ver = 1
        j+=1

    if ver == 0:
        imagem(chances)
        chances -=1
        print("ESSA LETRA NAO ESTA NA PALAVRA!!!");
        print("LETRAS JA UTILIZADAS:");
        letrasUtilizadas.append(letra)
        
        for i in letrasUtilizadas:
            print(i,end = " ")
        print("\n")
    else:
        ver = 0
        for i in preenchePalavra:
            print(i,end = " ")
        print("\n")
    if(qtdLetras == 0):
        print("VOCE VENCEU!!!")
        break
    if(chances == 0):
        print("VOCE PERDEU!")
        print("A palavra era " + palavraAleatoria)
        break
    
arq.close()