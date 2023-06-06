#include <stdio.h>
#include <locale.h>

main(){
setlocale(LC_ALL, "Portuguese");
float num1, num2;
int opcao=0;

while(opcao!=3){
        system("CLS");
printf("\n***********************SISTEMA DE MENUS**********************\n");
printf("\n Op誽o 01 - SOMAR\n");
printf("\n Op誽o 02 - SUBTRAIRo\n");
printf("\n Op誽o 03 - SAIR DO SISTEMA\n");

printf("\nDigite o nero da op誽o: ");
scanf("%i", &opcao);
    switch(opcao){
    case 1:
            printf("\nAcessando o Menu 01 - SOMAR\n");
            printf("\n\n Digite o primeiro nero: ");
            scanf("%f", &num1);
            printf("\n\n Digite o segundo nero: ");
            scanf("%f", &num2);
            printf("\n\n A soma entre %.2f + %.2f = %.2f\n\n", num1, num2, num1+num2);
            printf("\n<<<<<PRESSIONE QUALQUER TECLA PARA CONTINUAR>>>>>\n");
            printf("\n***********************************************************\n");
            getch();
            break;

    case 2:
            printf("\nAcessando o Menu 02 - SUBTRAIR\n");
            printf("\n\n Digite o primeiro nero: ");
            scanf("%f", &num1);
            printf("\n\n Digite o segundo nero: ");
            scanf("%f", &num2);
            printf("\n\n A subtra誽o entre %.2f - %.2f = %.2f\n\n", num1, num2, num1-num2);
            printf("\n<<<<<PRESSIONE QUALQUER TECLA PARA CONTINUAR>>>>>\n");
            printf("\n***********************************************************\n");
            getch();
            break;

   case 3:
            printf("\nSAIR DO SISTEMA\n");
            printf("\n<<<<<PRESSIONE QUALQUER TECLA PARA CONTINUAR>>>>>\n");
            printf("\n***********************************************************\n");
            getch();
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
