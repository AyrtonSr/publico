#include <iostream>
#include <string.h>
#include <stdio.h>

#define LIMITVET 50
#define LIMITALUNO 10
#define LIMITDISCIPLINA 10
#define LIMITTURMA 10

using namespace std;

typedef struct Nota
{
    int nota1;
    int nota2;
    int nota3;
    int nota4;
} nota;

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Disciplina
{
    int codigo;  // Primary Key
    char nome[LIMITVET];
    int ch;// Carga horaria
} Disciplina;

typedef struct Aluno
{
    int matricula; // Primary Key
    char nome[LIMITVET];
    Data dataNascimento;
} Aluno;

typedef struct Turma
{
    Disciplina disCodigo;        // Primary Key
    Aluno alunoMatricula;
    int ano;
    Nota notas;
    int media;
    char situacao;
    int faltas;
} Turma;

// ################################# INICIO DAS FUN합ES ALUNO ###########################################

void menuAluno(Aluno *listaAlunos, int *qntAlunos);
void cadastrarAluno(Aluno *listaAlunos, int *qntAlunos);
void exibirAluno (Aluno listaAlunos);
void exibirListaAluno(Aluno *listaAlunos, int qntAlunos);
void excluirAluno(Aluno *listaAlunos, int *qntAlunos);
void atualizarAluno(Aluno *listaAlunos, int *qntAlunos);
int buscarPosicaoAluno(Aluno *listaAlunos, int qntAlunos, int matricula);

void exibirAluno(Aluno listaAluno){
    cout << "\n------------------------------------------------------------------------------------------\n";
    cout << "Matricula: " << listaAluno.matricula << endl;
    cout << "Nome: " << listaAluno.nome << endl;
    cout << "Data de nascimento: ";
    cout << listaAluno.dataNascimento.dia << "/"<< listaAluno.dataNascimento.mes<<"/"<<listaAluno.dataNascimento.ano;
    cout << "\n------------------------------------------------------------------------------------------\n";

}

int buscarPosicaoAluno(Aluno *listaAlunos, int qntAlunos, int matricula){
    for (int i = 0; i < qntAlunos; i++) {
        if (listaAlunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

void atualizarAluno(Aluno *listaAlunos, int *qntAlunos){
    int matricula;

    system("cls");
    fflush(stdin);

    cout << "Digite a matricula do cliente que deseja atualizar: ";
    cin >> matricula;

    int posicao = buscarPosicaoAluno(listaAlunos, *qntAlunos, matricula);
    if (posicao != -1) {
            cout << "Informe o nome do ALuno: \n";
            cin.ignore();
            cin.getline(listaAlunos[posicao].nome, 50);
            cout << "Nome cadastrado\n";
            cout << "Digite o dia do nascimento: ";
            cin >> listaAlunos[posicao].dataNascimento.dia;
            cout << "\nDigite o mes do nascimento: ";
            cin >> listaAlunos[posicao].dataNascimento.mes;
            cout << "\nDigite o ano do nascimento: ";
            cin >> listaAlunos[posicao].dataNascimento.ano;
            cout << "Data cadastrada\n";
    } else {
        cout << "\nAluno nao encontrado!\n\n";
    }

}

void excluirAluno(Aluno *listaAlunos, int *qntAlunos){
    int matricula;

    system("cls");
    fflush(stdin);

    cout << "Digite a matricula do cliente que deseja excluir: ";
    cin >> matricula;

    int posicao = buscarPosicaoAluno(listaAlunos, *qntAlunos, matricula);
    if (posicao != -1) {
        for (int i = posicao; i < *qntAlunos - 1; i++) {
            listaAlunos[i] = listaAlunos[i + 1];
        }
        (*qntAlunos)--;
        system("cls");
    } else {
        cout << "\nAluno nao encontrado!\n\n";
    }
}

void exibirListaAluno(Aluno *listaAlunos, int qntAlunos){
    for (int i = 1; i < qntAlunos; i++){
        exibirAluno(listaAlunos[i]);
    }
}

void cadastrarAluno(Aluno *listaAluno, int *qntAlunos){

    int sair=0;

    system("cls");
    while (sair != 1){
    if (*qntAlunos<LIMITALUNO){
            cout << "Informe o nome do ALuno: \n";
            cin.ignore();
            cin.getline(listaAluno[*qntAlunos].nome, 50);
            cout << "Nome cadastrado\n";
            cout << "Digite o dia do nascimento: ";
            cin >> listaAluno[*qntAlunos].dataNascimento.dia;
            cout << "\nDigite o mes do nascimento: ";
            cin >> listaAluno[*qntAlunos].dataNascimento.mes;
            cout << "\nDigite o ano do nascimento: ";
            cin >> listaAluno[*qntAlunos].dataNascimento.ano;
            cout << "Data cadastrada\n";
            cout << "Gerando Matricula\n";
            listaAluno[*qntAlunos].matricula = *qntAlunos + 100;
            cout << "...\n";
            cout << "Matricula gerada\n";
            cout << "Obrigado\n";
            (*qntAlunos)++;
            sair = 1;


    } else {
        cout << "\nNumero maximo de Alunos Cadastrados\n";
        sair = 1;
    }

}

}

void menuAluno(Aluno *listaAlunos, int *qntAlunos){

    int opcaomenu;
    int posicao = 0;
    system("cls");
    while (opcaomenu != 4) {
        fflush(stdin);
        cout << "Bem vindo ao Menu Aluno \n";
        cout << "Selecione alguma das opcoes a seguir: \n";
        cout << "1 - Cadastrar Aluno \n";
        cout << "2 - Editar Aluno \n";
        cout << "3 - Excluir Atendimento \n";
        cout << "4 - Voltar ao Menu principal \n";
        cin >> opcaomenu;

        switch (opcaomenu) {
            case 1:
                cadastrarAluno(listaAlunos, qntAlunos);
                break;
            case 2:
                atualizarAluno(listaAlunos, qntAlunos);
                break;
            case 3:
                excluirAluno(listaAlunos, qntAlunos);
                break;
            case 4:
                system("cls");
                cout << "\n\nAte a proxima!\n\n";
                break;
            default:
                system("cls");
                cout << "Opcao Invalida\n\n";
                break;
        }
}
}

// ################################# FIM DAS FUN합ES ALUNO ###########################################

// ################################# INICIO DAS FUN합ES DISCIPLINA ###########################################
void menuDisciplina(Disciplina *listaDisciplina, int *qntDisciplina);
void cadastrarDisciplina(Disciplina *listaDisciplina, int *qntDisciplina);
void atualizarDisciplina(Disciplina *listaDisciplina, int *qntDisciplina);
int buscarPosicaoDisciplina(Disciplina *listaDisciplina, int qntDisciplina, int codigo);
void exibirListaDisciplina(Disciplina *listaDisciplina, int qntDisciplina);
void exibirDisciplina(Disciplina listaDisciplina);
void excluirDisciplina(Disciplina *listaDisciplina, int *qntDisciplina);

void exibirDisciplina(Disciplina listaDisciplina){
    cout << "\n------------------------------------------------------------------------------------------\n";
    cout << "Codigo: " << listaDisciplina.codigo << endl;
    cout << "Nome: " << listaDisciplina.nome << endl;
    cout << "Carga Horaria: " << listaDisciplina.ch<< "H" <<endl;
    cout << "\n------------------------------------------------------------------------------------------\n";

}

void exibirListaDisciplina(Disciplina *listaDisciplina, int qntDisciplina){
    for (int i = 1; i < qntDisciplina; i++){
        exibirDisciplina(listaDisciplina[i]);
    }
}

int buscarPosicaoDisciplina(Disciplina *listaDisciplina, int qntDisciplina, int codigo){
    for (int i = 0; i < qntDisciplina; i++) {
        if (listaDisciplina[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void excluirDisciplina(Disciplina *listaDisciplina, int *qntDisciplina){
    int codigo;

    fflush(stdin);
    cout << "Lista de Disciplinas: \n";
    exibirListaDisciplina(listaDisciplina, *qntDisciplina);

    cout << "Digite o codigo da Disciplina que deseja excluir: ";
    cin >> codigo;

    int posicao = buscarPosicaoDisciplina(listaDisciplina, *qntDisciplina, codigo);
    if (posicao != -1) {
        for (int i = posicao; i < *qntDisciplina - 1; i++) {
            listaDisciplina[i] = listaDisciplina[i + 1];
        }
        (*qntDisciplina)--;
        system("cls");
    } else {
        cout << "\nDisciplina nao encontrado!\n\n";
    }

}

void atualizarDisciplina(Disciplina *listaDisciplina, int *qntDisciplina){
    int codigo;

    fflush(stdin);
    cout << "Lista de Disciplinas: \n";
    exibirListaDisciplina(listaDisciplina, *qntDisciplina);

    cout << "Digite o codigo da Disciplina que deseja atualizar: ";
    cin >> codigo;

    int posicao = buscarPosicaoDisciplina(listaDisciplina, *qntDisciplina, codigo);
    if (posicao != -1) {
            cout << "Informe o nome da Disciplina: \n";
            cin.ignore();
            cin.getline(listaDisciplina[posicao].nome, 50);
            cout << "Nome cadastrado\n";
            cout << "Digite a Carga horaria 'valor numerico': ";
            cin >> listaDisciplina[posicao].ch;
            cout << "Carga Horaria cadastrada\n";
    } else {
        cout << "\nDisciplina nao encontrada!\n\n";
    }

}

void cadastrarDisciplina(Disciplina *listaDisciplina, int *qntDisciplina){
    int sair=0;

    system("cls");
    while (sair != 1){
    if (*qntDisciplina<LIMITDISCIPLINA){
            cout << "Informe o nome da Disciplina: \n";
            cin.ignore();
            cin.getline(listaDisciplina[*qntDisciplina].nome, 50);
            cout << "Nome cadastrado\n";
            cout << "Digite a Carga horaria 'valor numerico': ";
            cin >> listaDisciplina[*qntDisciplina].ch;
            cout << "Carga Horaria cadastrada\n";
            cout << "Gerando Matricula\n";
            listaDisciplina[*qntDisciplina].codigo = *qntDisciplina + 10;
            cout << "...\n";
            cout << "Codigo gerada\n";
            cout << "Obrigado\n";
            (*qntDisciplina)++;
            sair = 1;
    } else {
        cout << "\nNumero maximo de Disciplinas Cadastradas\n";
        sair = 1;
    }

}

}

void menuDisciplina(Disciplina *listaDisciplina, int *qntDisciplina){
    int opcaomenu;
        int posicao = 0;
        system("cls");
        while (opcaomenu != 4) {
            fflush(stdin);
            cout << "Bem vindo ao Menu Disciplina \n";
            cout << "Selecione alguma das opcoes a seguir: \n";
            cout << "1 - Cadastrar Disciplina \n";
            cout << "2 - Editar Disciplina \n";
            cout << "3 - Excluir Disciplina \n";
            cout << "4 - Voltar ao Menu principal \n";
            cin >> opcaomenu;

            switch (opcaomenu) {
                case 1:
                    system("cls");
                    cadastrarDisciplina(listaDisciplina, qntDisciplina);
                    break;
                case 2:
                    system("cls");
                    atualizarDisciplina(listaDisciplina, qntDisciplina);
                    break;
                case 3:
                    system("cls");
                    excluirDisciplina(listaDisciplina, qntDisciplina);
                    break;
                case 4:
                    system("cls");
                    cout << "\n\nAte a proxima!\n\n";
                    break;
                default:
                    system("cls");
                    cout << "Opcao Invalida\n\n";
                    break;
            }
    }

}
// ################################# FIM DAS FUN합ES DISCIPLINA ###########################################

// ################################# INICIO DAS FUN합ES TURMA ###########################################
void menuTurma(Turma *listaTurma, int *qntTurma, Disciplina *listaDisciplina, int qntDisciplina, Aluno *listaAlunos, int qntAlunos);
void cadastrarTurma(Turma *listaTurma, int *qntTurma);
void atualizarTurma(Turma *listaTurma, int *qntTurma);
void excluirTurma(Turma *listaTurma, int *qntTurma);
void exibirListaTurma(Turma *listaTurma, int qntTurma);
void exibirTurma(Turma listaTurma);
int buscarPosicaoTurma(Turma *listaTurma, int qntTurma, int codigo, int matricula);

int buscarPosicaoTurma(Turma *listaTurma, int qntTurma, int codigo, int matricula){
    for (int i = 0; i < qntTurma; i++) {
        if (listaTurma[i].disCodigo.codigo == codigo && listaTurma[i].alunoMatricula.matricula == matricula) {
            return i;
        }
    }
    return -1;
}

void exibirTurma(Turma listaTurma){
    cout << "\n------------------------------------------------------------------------------------------\n";
    cout << "Codigo da Disciplina: " << listaTurma.disCodigo.codigo << endl;
    cout << "Matricula do Aluno: " << listaTurma.alunoMatricula.matricula << endl;
    cout << "Ano: " << listaTurma.ano<< endl;
    cout << "Nota 1: " << listaTurma.notas.nota1<< endl;
    cout << "Nota 2: " << listaTurma.notas.nota2<< endl;
    cout << "Nota 3: " << listaTurma.notas.nota3<< endl;
    cout << "Nota 4: " << listaTurma.notas.nota4<< endl;
    cout << "Media: " << listaTurma.media<< endl;
    cout << "Faltas: " << listaTurma.faltas<< endl;
    cout << "Situacao [A=Aprovado],[R=Reprovado]: " << listaTurma.situacao<< endl;
    cout << "\n------------------------------------------------------------------------------------------\n";

}

void exibirListaTurma(Turma *listaTurma, int qntTurma){
    for (int i = 1; i < qntTurma; i++){
        exibirTurma(listaTurma[i]);
    }

}

void atualizarTurma(Turma *listaTurma, int *qntTurma){
    int codigo;
    int matricula;
    fflush(stdin);
    cout << "Lista de Turmas: \n";
    exibirListaTurma(listaTurma, *qntTurma);

    cout << "Digite o codigo da Disciplina da Turma que deseja atualizar: ";
    cin >> codigo;
    cout << "\nDigite a matricula do Aluno da Turma que deseja atualizar: ";
    cin >> matricula;

    int posicao = buscarPosicaoTurma(listaTurma, *qntTurma, codigo, matricula);
    if (posicao != -1) {
            cout << "Informe o ano da Turma: ";
            cin >> listaTurma[posicao].ano;
            cout << "Informe a nota 1: ";
            cin >> listaTurma[posicao].notas.nota1;
            cout << "\nInforme a nota 2: ";
            cin >> listaTurma[posicao].notas.nota2;
            cout << "\nInforme a nota 3: ";
            cin >> listaTurma[posicao].notas.nota3;
            cout << "\nInforme a nota 4: ";
            cin >> listaTurma[posicao].notas.nota4;

            listaTurma[posicao].media = (listaTurma[posicao].notas.nota1+listaTurma[posicao].notas.nota2+listaTurma[posicao].notas.nota3+listaTurma[posicao].notas.nota4)/4;
            if (listaTurma[posicao].media >=6){
                listaTurma[posicao].situacao = 'A';
            }else{
                listaTurma[posicao].situacao = 'R';
            }
            cout << "\nInforme o numero de faltas: ";
            cin >> listaTurma[posicao].faltas;
    } else {
        cout << "\nTurma nao encontrada!\n\n";
    }

}

void excluirTurma(Turma *listaTurma, int *qntTurma){
    int codigo;
    int matricula;
    fflush(stdin);
    cout << "Lista de Turmas: \n";
    exibirListaTurma(listaTurma, *qntTurma);

    cout << "Digite o codigo da Disciplina da Turma que deseja atualizar: ";
    cin >> codigo;
    cout << "\nDigite a matricula do Aluno da Turma que deseja atualizar: ";
    cin >> matricula;

    int posicao = buscarPosicaoTurma(listaTurma, *qntTurma, codigo, matricula);
    if (posicao != -1) {
        for (int i = posicao; i < *qntTurma - 1; i++) {
            listaTurma[i] = listaTurma[i + 1];
        }
        (*qntTurma)--;
        system("cls");
    } else {
        cout << "\nTurma nao encontrada!\n\n";
    }

}

void cadastrarTurma(Turma *listaTurma, int *qntTurma, Disciplina *listaDisciplina, int qntDisciplina, Aluno *listaAlunos, int qntAlunos){
    int sair=0;
    int codigo;
    int matricula;
    system("cls");
    while (sair != 1){
    if (*qntTurma<LIMITTURMA){
            cout << "Lista de Disciplinas: \n";
            exibirListaDisciplina(listaDisciplina, qntDisciplina);

            cout << "Digite o codigo da Disciplina que deseja aplicar na turma: ";
            cin >> codigo;
            int posicao = buscarPosicaoDisciplina(listaDisciplina,qntDisciplina,codigo);
            if (posicao != -1) {
                listaTurma[*qntTurma].disCodigo.codigo = codigo;
                system("cls");
                cout << "Codigo Aplicado\n";
            } else {
                cout << "\nDisciplina nao encontrado!\n\n";
                break;
            }
            cout << "Lista de Alunos: \n";
            exibirListaAluno(listaAlunos, qntAlunos);
            cout << "Digite a matricula do Aluno que deseja aplicar na turma: ";
            cin >> matricula;
            posicao = buscarPosicaoAluno(listaAlunos,qntAlunos,matricula);
            if (posicao != -1) {
                listaTurma[*qntTurma].alunoMatricula.matricula= matricula;
                cout << "Matricula Aplicada\n";
            } else {
                cout << "\nAluno nao encontrado!\n\n";
                break;
            }
            cout << "Informe o ano da Turma: ";
            cin >> listaTurma[*qntTurma].ano;
            cout << "Informe a nota 1: ";
            cin >> listaTurma[*qntTurma].notas.nota1;
            cout << "\nInforme a nota 2: ";
            cin >> listaTurma[*qntTurma].notas.nota2;
            cout << "\nInforme a nota 3: ";
            cin >> listaTurma[*qntTurma].notas.nota3;
            cout << "\nInforme a nota 4: ";
            cin >> listaTurma[*qntTurma].notas.nota4;

            listaTurma[*qntTurma].media = (listaTurma[*qntTurma].notas.nota1+listaTurma[*qntTurma].notas.nota2+listaTurma[*qntTurma].notas.nota3+listaTurma[*qntTurma].notas.nota4)/4;
            if (listaTurma[*qntTurma].media >=6){
                listaTurma[*qntTurma].situacao = 'A';
            }else{
                listaTurma[*qntTurma].situacao = 'R';
            }
            cout << "\nInforme o numero de faltas: ";
            cin >> listaTurma[*qntTurma].faltas;
            (*qntTurma)++;
            sair = 1;
    } else {
        cout << "\nNumero maximo de Turmas cadastradas\n";
        sair = 1;
    }
}
}

void menuTurma(Turma *listaTurma, int *qntTurma, Disciplina *listaDisciplina, int qntDisciplina, Aluno *listaAlunos, int qntAlunos){
    int opcaomenu;
        int posicao = 0;
        system("cls");
        while (opcaomenu != 4) {
            fflush(stdin);
            cout << "Bem vindo ao Menu Turma \n";
            cout << "Selecione alguma das opcoes a seguir: \n";
            cout << "1 - Cadastrar Turma \n";
            cout << "2 - Editar Turma \n";
            cout << "3 - Excluir Turma \n";
            cout << "4 - Voltar ao Menu principal \n";
            cin >> opcaomenu;

            switch (opcaomenu) {
                case 1:
                    cadastrarTurma(listaTurma, qntTurma, listaDisciplina,qntDisciplina, listaAlunos, qntAlunos);
                    break;
                case 2:
                    atualizarTurma(listaTurma, qntTurma);
                    break;
                case 3:
                    excluirTurma(listaTurma, qntTurma);
                    break;
                case 4:
                    system("cls");
                    cout << "\n\nAte a proxima!\n\n";
                    break;
                default:
                    system("cls");
                    cout << "Opcao Invalida\n\n";
                    break;
            }
    }

}
// ################################# FIM DAS FUN합ES Turma ###########################################


int main (){

int opcao, qntAlunos = 1, qntDisciplina = 1, qntTurma = 1;
Aluno listaAlunos[LIMITVET];
Disciplina listaDisciplina[LIMITVET];
Turma listaTurma [LIMITVET];

    while (opcao != 5)
    {
        fflush(stdin);
        cout << "1 - Menu de Disciplina" << endl;
        cout << "2 - Menu de Aluno" << endl;
        cout << "3 - Menu de Turma" << endl;
        cout << "4 - Relatorio" << endl;
        cout << "5 - Sair" << endl;

        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            menuDisciplina(listaDisciplina, &qntDisciplina);
            break;
        case 2:
            menuAluno(listaAlunos, &qntAlunos);
            break;
        case 3:
            menuTurma(listaTurma, &qntTurma,listaDisciplina, qntDisciplina,listaAlunos, qntAlunos);
            break;
        case 4:
            system("cls");
            exibirListaAluno(listaAlunos, qntAlunos);
            break;
        case 5:
            cout << "\n\nAte a proxima!\n\n";
            break;
        default:
            system("cls");
            cout << "Opcao invalida, tente novamente!\n\n";
        }
    }


}
