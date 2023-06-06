#include <stdio.h>
#include <locale.h>

float num1,num2;

void somar ();
void somar (){
printf("\n Acessando o Menu 01 - SOMAR\n");
            printf("\n\n Digite o primeiro numero: ");
            scanf("%f", &num1);
            printf("\n\n Digite o segundo numero: ");
            scanf("%f", &num2);
            printf("\n\n A soma entre %.2f + %.2f = %.2f\n\n", num1, num2, num1+num2);
            printf("\n<<<<<PRESSIONE QUALQUER TECLA PARA CONTINUAR>>>>>\n");
            printf("\n***********************************************************\n");
            getch();
}

void subtrair();
void subtrair(){
printf("\nAcessando o Menu 02 - SUBTRAIR\n");
            printf("\n\n Digite o primeiro numero: ");
            scanf("%f", &num1);
            printf("\n\n Digite o segundo numero: ");
            scanf("%f", &num2);
            printf("\n\n A subtracao entre %.2f - %.2f = %.2f\n\n", num1, num2, num1-num2);
            printf("\n<<<<<PRESSIONE QUALQUER TECLA PARA CONTINUAR>>>>>\n");
            printf("\n***********************************************************\n");
            getch();
}

void sair();
void sair(){
printf("\nSAIR DO SISTEMA\n");
            printf("\n<<<<<PRESSIONE QUALQUER TECLA PARA CONTINUAR>>>>>\n");
            printf("\n***********************************************************\n");
            getch();

}



int main (){
    float num1, num2;
    int opcao;
    while(opcao!=3){
        system("CLS");
        printf("\n***********************SISTEMA DE MENUS**********************\n");
        printf("\n Opcao 01 - SOMAR\n");
        printf("\n Opcao 02 - SUBTRAIRo\n");
        printf("\n Opcao 03 - SAIR DO SISTEMA\n");

        printf("\nDigite o numero da opcao: ");
        scanf("%i", &opcao);

        switch(opcao){
            case 1:
                somar ();
                break;

            case 2:
                subtrair();
                break;

            case 3:
                sair ();

            break;
    default:
            printf("\nMenu INESISTENTE\n");
            printf("\n<<<<<PRESSIONE QUALQUER TECLA PARA CONTINUAR>>>>>\n");
            printf("\n***********************************************************\n");
            getch();
    }
}
    return 0;

}
