#include<stdio.h>
#include<iostream>
#include<windows.h>

using namespace std;

// criação da fila
typedef struct FILA
{
  int nPacote;
  FILA *proxpacote;
} FILA;

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void enqueue(FILA **inicio, FILA **fim, int pacote){ // metodo responsavel por acrescentar um novo item na fila

    FILA *novoPacote = new FILA(); // Atribui uma nova região de memória à um ponteiro

    if ((*inicio)==NULL){ // verificação se ja existe uma fila
        (*inicio)=novoPacote;
        (*fim)=novoPacote;
        novoPacote->nPacote = pacote;
        novoPacote->proxpacote = NULL;
    }else{
        (*fim)->proxpacote = novoPacote;
        (*fim) = (*fim)->proxpacote;
        novoPacote->nPacote = pacote;
        novoPacote->proxpacote=NULL;
    }
}

FILA *dequeue(FILA *&inicio){ // metodo responsavel por tirar o item do incio da fila e retornalo para ser exibido

    FILA *aux; // aux é responsavel por armazenar o item que sera exibido apos esse metodo
    aux=inicio;
    inicio= inicio->proxpacote;
    return aux;
}

void telaDeCarregamento(int qtd, int atual, int carregamento){
    system("COLOR 0e");

    int bar1 = 177, bar2 = 219;
    gotoxy(24,4);cout<<"Carregando..."<<"["<< atual<<"/"<<qtd<<"]";
    for(int i=20;i<=45;i++){
    gotoxy(i,5);printf("%c", bar1);
    }
    for(int i=20;i<=45;i++){
    gotoxy(i,5);printf("%c", bar2);
    Sleep(carregamento);
    }
}


int main (){

    FILA *inicio = NULL;
    FILA *fim = NULL;
    int tamanho = 0, pacotes = 50, qtdpacotes = 0, c=1, c2=0, carregamento = 40;

    gotoxy(2,2);printf("%c", 254);
    gotoxy(4,2);cout << "INFORME O TAMANHO DO ARQUIVO(EM KB): ";
    cin >> tamanho;

    if (tamanho>1000){
        pacotes = 500;
        carregamento = 150;
    }

    // Verificação de quantos pacotes serão necessarios
    if (tamanho%pacotes == 0){
        qtdpacotes = tamanho/pacotes;
    } else{
        qtdpacotes = (tamanho/pacotes)+1;
    }

    gotoxy(2,3);printf("%c", 254);
    gotoxy(4,3);cout << "Quantidade de pacotes necessarios: "<<qtdpacotes<<endl;
    gotoxy(2,4);printf("%c", 254);
    gotoxy(4,4);cout << "Tamanho dos pacotes = "<<pacotes<<" KB"<<endl;
    system("pause");

    //Vai acrescentar de acordo com a quantidade de pacotes necessarios
    while(c<=qtdpacotes){
        enqueue(&inicio, &fim, c);
        c++;
    }
    int y=7;
    system("cls");

    //Vai retirar o inicial e exibir como carregado e apaga ele em seguida
    while(inicio!=NULL){
        FILA *aux; // aux do tipo FILA que ira receber o intem que esta no inicio da fila
        aux=dequeue(inicio);

        telaDeCarregamento(qtdpacotes,c2, carregamento);
        c2++;
        gotoxy(5,y);cout<< "Pacote "<<aux->nPacote<< " Carregado";
        y++;
        delete(aux);//Deleta o aux para liberar memoria
    }
    for(int i= 20; i<=45;i++){
    gotoxy(i,4); printf("%c", 32);
    }
    gotoxy(25,4);cout<<"Completo..."<<"["<< c2<<"/"<<qtdpacotes<<"]";
    gotoxy(1,y); printf("%c", 32);

return 0;
}

