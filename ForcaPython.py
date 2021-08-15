import random

def forca(nome_jogador):
    def imprime_boneco(erros):

        if erros ==6:
            print("       +---+")
            print("       |   |")
            print("           |")
            print("           |")
            print("           |")
            print("           |")
            print("   =========")
            
        if erros ==5:
            print("       +---+")
            print("       |   |")
            print("       o   |")
            print("           |")
            print("           |")
            print("           |")
            print("   =========")
            
        if erros ==4:
            print("       +---+")
            print("       |   |")
            print("       o   |")
            print("        |  |")
            print("           |")
            print("           |")
            print("   =========")
            
        if erros ==3:
            print("       +---+")
            print("       |   |")
            print("       o   |")
            print("       |\  |")
            print("           |")
            print("           |")
            print("   =========")
            
        if erros ==2:
            print("       +---+")
            print("       |   |")
            print("       o   |")
            print("       /|\ |")
            print("           |")
            print("           |")
            print("   =========")
            
            
        if erros ==1:
            print("       +---+")
            print("       |   |")
            print("       o   |")
            print("       /|\ |")
            print("        \  |")
            print("           |")
            print("   =========")

        if erros ==0:
            print("       +---+")
            print("       |   |")
            print("       o   |")
            print("       /|\ |")
            print("       / \ |")
            print("           |")
            print("   =========")

    linha = '-' * 90
    print(linha)

    inicio = '''
                                        >> BEM VINDO AO JOGO DA FORCA <<
                        - - - - - Você é bom em desafios? Em advinhar as coisas?? - - - - -
                                * Convide um amigo e faça parte dessa bricadeira *
                                -Você começa com 6 pontos e cada erro perde um ponto-
            '''
    print(inicio)
    print(linha)
    print("Preparada para jogar {}?".format(nome_jogador))

    forca = ["banana", "morango", "melancia", "pera", "abacaxi", "limao", "laranja", "uva","abacate", "acerola","amora",
        "caju","cacau","cereja","coco","damasco","figo","framboesa","graviola","goiaba","jaca ","jabuticaba","manga","pitanga",
        "seriguela","porco","cachorro","camelo","cavalo","vaca","mosquito","coelho", "borboleta", "gato","cobra", "mesa", "armario",
        "computador", "celular","geladeira","cadeira","panela","lapis", "caderno", "mochila","laranja","azul","verde","branco",
        "preto", "amarelo","lilas","dourado","vermelho","cinza"]

    indice = random.randint(0,54)
    palavra_secreta = forca[indice]
    erros = 6
    verificador = 0

    qtd_letras = len(palavra_secreta)

    letras_certas = []
    letras_descobertas = []
    letras_adivinhadas = []

    for i in range(0,len(palavra_secreta)):
        letras_descobertas.append("_")

    print(palavra_secreta)
    print("A palavra possui {} letras {}".format(qtd_letras,nome_jogador))
    print(*letras_descobertas)

    if(indice>-1 and indice <=24):
        print( "A dica é: FRUTA")

    elif(indice>24 and indice <=34):
        print( "A dica é: ANIMAL")

    elif(indice>34 and indice <=44):
        print( "A dica é: OBJETO")

    elif(indice>44 and indice <=54):
        print( "A dica é: COR")

    acerto = False

    while acerto == False:
        letra = input("Digite uma letra: ")

        if not letra in letras_adivinhadas:
            if not letra in letras_certas:
                for i in range(0,len(palavra_secreta)):
                        
                    if letra == palavra_secreta[i]:
                        letras_certas.append(letra)
                        letras_descobertas[i] = letra
                        qtd_letras-=1
                        verificador=1
        else:
            print("Letra ja adivinhada")
            verificador = 1


        if verificador != 1:
            if not letra in letras_adivinhadas:
                erros-=1
        imprime_boneco(erros)
        
        verificador = 0
        letras_adivinhadas.append(letra)

        print (*letras_descobertas)
        print("Voce tem {} chance(s)".format(erros))
        if erros == 0:
            print("Você perdeu {} :(".format(nome_jogador))
            acerto = True

        
        if(qtd_letras==0):
            print("Você ganhou {}!!!".format(nome_jogador))
            acerto = True

    pontuacao = erros
    return pontuacao

forca('amanda')