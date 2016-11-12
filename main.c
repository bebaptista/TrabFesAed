//
//  main.c
//  Sistema Passagem Aerea
//
//  Created by Bernardo de Magalhaes Machado Nogueira Baptista on 12/11/16.
//  Copyright (c) 2016 Bernardo de Magalhaes Machado Nogueira Baptista. All rights reserved.
//

#include <stdio.h>
#include "spa.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    struct voo teste[50];
    char id[10];
    for (int i=0; i<10; i++) {
        id[i]=64+i;
    }
    InicializarDados(teste);
    printf("%d\n",IncluirReserva(teste, id , 1001));
    ImprimeReserva(teste, 1, 1001);
    printf("%d\n",ExcluirReserva(teste, id , 1001));
    printf("%d\n",ExcluirReserva(teste, id , 1001));
    ImprimeReserva(teste, 2, 1001);
    
    return 0;
}
