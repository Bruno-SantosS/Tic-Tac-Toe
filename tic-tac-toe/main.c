#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

void limpa(char loc[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            loc[i][j] = ' ';
        }
    }
}

void tabela (char loc[3][3]){
    printf("\t    1   2   3   \n");
    printf("\n1\t    %c | %c | %c", loc[0][0], loc[0][1], loc[0][2]);
    printf("\n\t   ---|---|---");
    printf("\n2\t    %c | %c | %c", loc[1][0], loc[1][1], loc[1][2]);
    printf("\n\t   ---|---|---");
    printf("\n3\t    %c | %c | %c", loc[2][0], loc[2][1], loc[2][2]);
}

int vitoria(char loc[3][3]){
    if(loc[0][0] == 'X' && loc[0][1] == 'X' && loc[0][2] == 'X'){
        return 1;
    }
    if(loc[1][0] == 'X' && loc[1][1] == 'X' && loc[1][2] == 'X'){
        return 1;
    }
    if(loc[2][0] == 'X' && loc[2][1] == 'X' && loc[2][2] == 'X'){
        return 1;
    }
    if(loc[0][0] == 'X' && loc[1][1] == 'X' && loc[2][2] == 'X'){
        return 1;
    }
    if(loc[2][0] == 'X' && loc[1][1] == 'X' && loc[0][2] == 'X'){
        return 1;
    }
    if(loc[0][0] == 'X' && loc[1][0] == 'X' && loc[2][0] == 'X'){
        return 1;
    }
    if(loc[0][1] == 'X' && loc[1][1] == 'X' && loc[2][1] == 'X'){
        return 1;
    }
    if(loc[0][2] == 'X' && loc[1][2] == 'X' && loc[2][2] == 'X'){
        return 1;
    }
}

int derrota(char loc[3][3]){
    if(loc[0][0] == 'O' && loc[0][1] == 'O' && loc[0][2] == 'O'){
        return 0;
    }
    if(loc[1][0] == 'O' && loc[1][1] == 'O' && loc[1][2] == 'O'){
        return 0;
    }
    if(loc[2][0] == 'O' && loc[2][1] == 'O' && loc[2][2] == 'O'){
        return 0;
    }
    if(loc[0][0] == 'O' && loc[1][1] == 'O' && loc[2][2] == 'O'){
        return 0;
    }
    if(loc[2][0] == 'O' && loc[1][1] == 'O' && loc[0][2] == 'O'){
        return 0;
    }
    if(loc[0][0] == 'O' && loc[1][0] == 'O' && loc[2][0] == 'O'){
        return 0;
    }
    if(loc[0][1] == 'O' && loc[1][1] == 'O' && loc[2][1] == 'O'){
        return 0;
    }
    if(loc[0][2] == 'O' && loc[1][2] == 'O' && loc[2][2] == 'O'){
        return 0;
    }
}

int vazio(char loc[3][3]){
    int z = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(loc[i][j] != 'X' && loc[i][j] != 'O'){
                z++;
            }
        }
    }
    if(z > 0){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    char loc[3][3];
    const char jogador = 'X';
    const char maquina = 'O';
    int evazio;
    int linha;
    int coluna;
    int linhamaq;
    int colunamaq;
    int tsbool = 1;
    int vit = 0;
    int der = 0;
    int fechar;

    limpa(loc);
    evazio = vazio(loc);

    while(evazio == 1 | vit == 1 | der == 0){
        tabela(loc);
        printf("\n\nLinha: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        if (linha > 3 | linha < 1 | coluna > 3 | coluna < 1){
            system("cls");
            if (linha > 3 | linha < 1){
                printf("Não existe essa linha! (As linhas vão de 1 à 3)\n");
            }
                if (coluna > 3 | coluna < 1){
                    printf("Não existe essa Coluna! (As linhas vão de 1 à 3)\n\n");
                    continue;
                }
                else{
                    printf("\n");
                    continue;
                }
        }
        linha -= 1;
        coluna -= 1;
        if (loc[linha][coluna] == 'O' | loc[linha][coluna] == 'X'){
            system("cls");
            printf("\nEsse lugar está ocupado!\n\n");
            continue;
        }
        else{
            loc[linha][coluna] = jogador;
        }
        vit = vitoria(loc);
        der = derrota(loc);
        if (vit == 1 | der == 0){
            break;
        }
        system("cls");
        tabela(loc);
        printf("\n\nO bot está pensando...");
        while(tsbool == 1){
            evazio = vazio(loc);
            if (evazio == 0){
                break;
            }
            else{
                srand(time(0));
                linhamaq = (rand() % 3);
                colunamaq = (rand() % 3);
                if (loc[linhamaq][colunamaq] == 'X' | loc[linhamaq][colunamaq] == 'O'){
                    tsbool = 1;
                }
                else{
                    loc[linhamaq][colunamaq] = maquina;
                    tsbool == 0;
                    break;
                }
            }
        }
        vit = vitoria(loc);
        der = derrota(loc);
        if (vit == 1 | der == 0){
            break;
        }
        system("cls");
    }

    system("cls");

    if (vit == 1){
        printf("\n\t<--------------->");
        printf("\n\t     Vitória!\n");
        printf("\t<--------------->\n\n");
    }
    else if(der == 0){
        printf("\n\t<--------------->");
        printf("\n\t     Derrota!\n");
        printf("\t<--------------->\n\n");
    }
    else{
        printf("\n\t<--------------->");
        printf("\n\t     Empate!\n");
        printf("\t<--------------->\n\n0");
    }

    tabela(loc);
    printf("\n");

    printf("\n\n\nPrecione qualquer tecla para fechar...\n");
    scanf("%c", &fechar);
    getchar();

    return 0;
}
