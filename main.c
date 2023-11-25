#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "tad.h"





char menu()
{
    system("cls");
    printf("## MENU ## \n");
    printf("[1] - insere\n");
    printf("[2] - Pre-ord\n");
    printf("[3] - In-ord\n");
    printf("[4] - Pos-Ord\n");
    printf("[5] - Liberar arvore\n");
    printf("[6] - Excluir elemento\n");
    printf("[7] - Altura e nivel\n");
    printf("[A] - Carregar arvore ja definida\n"); 
    printf("[ESC] - Sair\n");
    printf("opcao: ");
    return getche();
}

int main()
{
    Tree *raiz, *e, *p;
    char op,lado;
    int info,altura,infoB,level;
    init(&raiz);

    do{
        op = menu();
        system("cls");
        switch (op)
        {
            
            case '1':   
                printf("## INSERINDO NA ARVORE ##\n");
                printf("valor a ser insirido: ");
                scanf("%d",&info);
                insereABB(&raiz,info);
                printf("\naperte uma tecla para continuar\n");
                getch();
                break;
            case '2':
                printf("## PREORD ##\n");
                if(raiz!=NULL)
                {
                    preOrd(raiz);
                    printf("\n## PREORD I ##\n");
                    preOrdI(raiz);
                    printf("\n\n");
                    printTree(raiz, 0);
                }
                else
                {
                    printf("arvore vazia\n");
                }
                printf("\naperte uma tecla para continuar\n");
                getch();
                break;
            case '3':
                printf("## INORD ##\n");
                if(raiz!=NULL)
                {
                    inOrd(raiz);
                    printf("\n## POSORD I ##\n");
                    posOrdI(raiz);
                    printf("\n\n");
                    printTree(raiz, 0);
                }
                else
                {
                    printf("arvore vazia\n");
                }
                printf("\naperte uma tecla para continuar\n");
                getch();
                break;
            case '4':
                printf("## POSORD ##\n");
                if(raiz!=NULL)
                {
                    posOrd(raiz);
                    printf("\n## POSORD I ##\n");
                    posOrdI(raiz);
                    printf("\n\n");
                    printTree(raiz, 0);
                }
                else
                {
                    printf("arvore vazia\n");
                }
               
                printf("\naperte uma tecla para continuar\n");
                getch();
                break;
            case '5':
                printf("## deletando arvore ##\n");
                if(raiz!=NULL)
                {
                    deletTree(&raiz);
                    posOrd(raiz);
                }
                else
                    printf("arvore vazia\n");
                printf("\naperte uma tecla para continuar\n");
                getch();
                break;
            case '6':
                printf("## excluindo elemento da arvore ##\n");
                if(raiz!=NULL)
                {
                    printTree(raiz, 0);
                    printf("\nDigite o elemento para a exclusao: ");
                    scanf("%d",&info);
                    printf("\nDigite o lado: ");
                    fflush(stdin);
                    scanf("%c",&lado);

                    BuscaNoI(raiz,&e,&p,info);
                    if(e!=NULL)
                    {
                        exclusaoABBI(&raiz,e,p,lado);
                        printf("\nexcluido com sucesso\n");
                        printTree(raiz, 0);
                    }
                    else
                        printf("\nelemento nao esta na arvore\n");
                }
                else
                {
                    printf("\narvore vazia\n");
                }
                printf("\naperte uma tecla para continuar\n");
                getch();
                break;
            case '7':
                altura = calculatealturaIterative(raiz);
                printf("Altura da arvore: %d\n", altura);

                printTree(raiz, 0);
                printf("\ndigite o elemento para buscar: ");
                scanf("%d",&infoB);
                level = CalculaNivel(raiz, infoB, 0);
                if (level != -1) 
                {
                    printf("\nNivel do no %d: %d\n", infoB, level);
                } 
                else 
                {
                    printf("\nNo %d nao encontrado na arvore\n", infoB);
                }
                getch();
            break;
            case 'A' :
            case 'a' :
                insereABB(&raiz, 10);
                insereABB(&raiz, 5);
                insereABB(&raiz, 15);
                insereABB(&raiz, 3);
                insereABB(&raiz, 7);
                insereABB(&raiz, 12);
                insereABB(&raiz, 18);   
                getch();
                break;
        }
        
    }while(op != 27);
     printTree(raiz, 0);
    return 0;
}
