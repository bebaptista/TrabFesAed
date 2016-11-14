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
