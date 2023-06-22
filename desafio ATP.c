#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Mcoluna 6 //MAXIMO DE COLUNA
#define Mlinha 6  //MAXIMO DE LINHA

char map[Mlinha][Mcoluna]; //map = mapa - uma analogia que criei para me ajudar a relacionar a matriz a posições
int a[9], b[9]; // vetores a e b sao utilizados para guardarem as posições dos obstaculos em todo o codigo

// PROTOTIPO
void obstaculos(int repetidor); // função responsavel pelos obstaculos que o usuario colocara
void criancaomatriz(); // esse metodo so serve para criar a matriz inicial que sera visivel na tela
void geradormatriz(); // esse metodo serve para mostrar na tela a matriz com todas as alterações durante o codigo
void imprimirCaminho(int pai[Mlinha][Mcoluna], int final1, int final2);

// IMPLEMENTAR

void obstaculos(int repetidor) {
    int c; // o c é apenas um contador para o "for" presente nesse metodo
    printf("Digite as coordenadas dos obstaculos:\n");
    for (c = 0; c < repetidor; c++) {
        printf("Obstaculo %i: ", c+1);
        scanf("%i %i", &a[c], &b[c]);

        if (map[a[c]][b[c]] == '-') {
            map[a[c]][b[c]] = 'X';
        } else {
            printf("Essa posicao ja esta ocupada. Digite outra.\n");
            c--;
        }
    }
}

void criancaomatriz() {
    int linha, coluna;
    for (linha = 0; linha < Mlinha; linha++) {
        for (coluna = 0; coluna < Mcoluna; coluna++) {
            map[linha][coluna] = '-';
        }
    }
}

void geradormatriz() {
    int i, j;
    for (i = 0; i < Mlinha; i++) {
        for (j = 0; j < Mcoluna; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void imprimirCaminho(int pai[Mlinha][Mcoluna], int final1, int final2) {
    int i,j,novoI,novoJ;
    printf("\nCaminho do inicio ao final:\n");
    i = final1;
    j = final2;

    while (pai[i][j] != -1) {
        map[i][j] = '+';
        novoI = pai[i][j] / 10;
        novoJ = pai[i][j] % 10;
        i = novoI;
        j = novoJ;
    }

    geradormatriz();
}

int main() {
    int i = 0, j = 0, opcao, repetidor = 0, posicao = 0, comeco1, comeco2, final1, final2,visitado[Mlinha][Mcoluna],pai[Mlinha][Mcoluna];
    int fila[Mlinha * Mcoluna],inicio = 0,fim = 0;


    srand(time(NULL));
    criancaomatriz();

    printf("BEM VINDO AO LABIRINTO\n\n");
    printf("O Mapa do labirinto eh uma matriz 6x6\n\n");
    geradormatriz();
    printf("Por favor, defina o local de partida: \n");
    scanf("%i %i", &comeco1, &comeco2);
    map[comeco1][comeco2] = '*';
    i = comeco1;
    j = comeco2;
    printf("Por favor, defina o final do labirinto: \n");
    scanf("%i %i", &final1, &final2);
    map[final1][final2] = '*';
    printf("\n\nPor favor, defina o numero de obstaculos que deseja ter no labirinto:\n");
    printf("(5) (7) (9)\n");
    printf("Lembre-se, eh possivel que o labirinto nao tenha solucao :)\n");
    scanf("%i", &opcao);

    switch (opcao) { // esse switch sera utilizado para a escolha da quantidade de obstaculos
        case 5:
            repetidor = 5;
            obstaculos(repetidor);
            geradormatriz();
            break;
        case 7:
            repetidor = 7;
            obstaculos(repetidor);
            geradormatriz();
            break;
        case 9:
            repetidor = 9;
            obstaculos(repetidor);
            geradormatriz();
            break;
    }

    for (i = 0; i < Mlinha; i++) {
        for (j = 0; j < Mcoluna; j++) {
            visitado[i][j] = 0;
            pai[i][j] = -1;
        }
    }

    visitado[comeco1][comeco2] = 1;
    pai[comeco1][comeco2] = -1;

    fila[fim++] = comeco1 * 10 + comeco2;
    /*
    A partir daqui sera utilizado um conceito chamado BFS - Breadth-First Search(ou busca em largura), achei esse
    tipo de algoritmo fazendo pesquisas para achar uma forma de achar, percorrer e imprimir o percurso do ponto
    inicial ao ponto final. Basicamente O algoritmo explora todos os vertices vizinhos em largura antes de
    prosseguir para os vertices mais distantes.O BFS é utilizado para encontrar o caminho do ponto de partida
    ao ponto de chegada no labirinto e depois o caminho é impresso.
    */
    /*
    A variavel "pai" é uma variavel/termo muito comum na aplicação do BFS. Basicamente ele representa o vértice
    anterior na sequência de vértices que levam até um determinado vértice.Ou seja,é utilizada para armazenar a
    informação do pai de cada vértice durante o BFS
    */


    while (inicio != fim) {
        int atual = fila[inicio++];
        int linha = atual / 10;
        int coluna = atual % 10;

        if (linha == final1 && coluna == final2) {
            imprimirCaminho(pai, final1, final2);
            return 0;
        }

        if (linha > 0 && map[linha - 1][coluna] != 'X' && visitado[linha - 1][coluna] == 0) {
            visitado[linha - 1][coluna] = 1;
            pai[linha - 1][coluna] = linha * 10 + coluna;
            fila[fim++] = (linha - 1) * 10 + coluna;
        }

        if (linha < Mlinha - 1 && map[linha + 1][coluna] != 'X' && visitado[linha + 1][coluna] == 0) {
            visitado[linha + 1][coluna] = 1;
            pai[linha + 1][coluna] = linha * 10 + coluna;
            fila[fim++] = (linha + 1) * 10 + coluna;
        }

        if (coluna > 0 && map[linha][coluna - 1] != 'X' && visitado[linha][coluna - 1] == 0) {
            visitado[linha][coluna - 1] = 1;
            pai[linha][coluna - 1] = linha * 10 + coluna;
            fila[fim++] = linha * 10 + coluna - 1;
        }

        if (coluna < Mcoluna - 1 && map[linha][coluna + 1] != 'X' && visitado[linha][coluna + 1] == 0) {
            visitado[linha][coluna + 1] = 1;
            pai[linha][coluna + 1] = linha * 10 + coluna;
            fila[fim++] = linha * 10 + coluna + 1;
        }
    }

    printf("Nao ha caminho do inicio ao final do labirinto.\n");

    return 0;
}
