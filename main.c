//
//  main.c
//  Sistema Passagem Aerea
//
//  Created by Bernardo de Magalhaes Machado Nogueira Baptista on 12/11/16.
//  Copyright (c) 2016 Bernardo de Magalhaes Machado Nogueira Baptista. All rights reserved.
//

#include <stdio.h>
#include "spa.h"

int main(int argc, char * argv[]) {
    // insert code here...
    
    _Bool encerra=0;
    int identidade[10],opcao=0,numerovoo=0,resultado=0,opcaoimpressao=0;
    struct voo voos[50];
    
    InicializarDados(voos);
    while (encerra==0) {
        printf("Bem vindo ao sistema de passagem aerea.Digite o numero da opcao que voce deseja e aperte enter\nOpcao 1: Criar nova instancia\nOpcao 2: Incluir reserva\nOpcao 3: Excluir reserva\nOpcao 4: Imprimir Reserva\n");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                InicializarDados(voos);
                break;
                
            case 2:
                printf("Digite o numero do voo que se deseja fazer a reserva\n");
                scanf("%d",&numerovoo);
                printf("Agora digite cada caracter da identidade seguido de enter\n");
                for (int i=0; i<10; i++) {
                    scanf("%d",&identidade[i]);
                }
                resultado=IncluirReserva(voos, identidade, numerovoo);
                if (resultado==2) {
                    printf("A sua reserva foi realizada com sucesso!\n");
                }
                else if (resultado==1){
                    printf("Este voo ja esta com capacidade maxima. Por favor tente outro voo\n");
                }
                else printf("Este voo nao existe. Por favor tente outro voo\n");
                break;
            
            case 3:
                printf("Digite o numero do voo que se deseja excluir a reserva\n");
                scanf("%d",&numerovoo);
                printf("Agora digite cada caracter da identidade seguido de enter\n");
                for (int i=0; i<10; i++) {
                    scanf("%d",&identidade[i]);
                }
                resultado=ExcluirReserva(voos, identidade, numerovoo);
                if (resultado==2) {
                    printf("A sua reserva foi excluida com sucesso!\n");
                }
                else if (resultado==1){
                    printf("Nao existe uma reserva com a identidade desejada neste voo. Por favor tente outra identidade\n");
                }
                else printf("Este voo nao existe. Por favor tente outro voo\n");
                break;
                
            case 4:
                printf("Digite qual opcao de impressao:\nOpcao 1: Nivel de preenchimento de um voo especifico\nOpcao 2: Impressao dos voos e seu preenchimento\nOpcao 3: Impressao completa\n");
                scanf("%d",&opcaoimpressao);
                if (opcaoimpressao==1) {
                    printf("Digite agora o numero do voo\n");
                    scanf("%d",&numerovoo);
                    ImprimeReserva(voos, 1, numerovoo);
                }
                else if (opcaoimpressao==2) {
                    ImprimeReserva(voos, 2, numerovoo);
                }
                else if (opcaoimpressao==3) {
                    ImprimeReserva(voos, 3, numerovoo);
                }
                else printf("Essa opcao nao existe");
                break;
                
            default:
                encerra=1;
                break;
        }
    }
    
    struct voo teste[50];
    int id[10];
    id[0]=77;
    id[1]=71;
    for (int i=2; i<10; i++) {
        id[i]=i;
    }
    InicializarDados(teste);
    printf("%d\n",IncluirReserva(teste, id , 1001));
    printf("%d\n",IncluirReserva(teste, id , 1002));
    ImprimeReserva(teste, 1, 1001);
    ImprimeReserva(teste, 3, 1002);
    printf("%d\n",ExcluirReserva(teste, id , 1001));
    printf("%d\n",ExcluirReserva(teste, id , 1001));
    ImprimeReserva(teste, 2, 1001);
    
    return 0;
}
