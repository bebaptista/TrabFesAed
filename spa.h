//
//  spa.h
//  Sistema Passagem Aerea
//
//  Created by Bernardo de Magalhaes Machado Nogueira Baptista on 12/11/16.
//  Copyright (c) 2016 Bernardo de Magalhaes Machado Nogueira Baptista. All rights reserved.
//

#ifndef __Sistema_Passagem_Aerea__spa__
#define __Sistema_Passagem_Aerea__spa__

#include <stdio.h>

struct assento {
    _Bool ocupado;
    int passageiro[10];
};

struct voo {
    int lotacao;
    struct assento poltrona[10];
    int numerovoo;
};

void InicializarDados(struct voo aereo[50]);

int IncluirReserva(struct voo aereo[50], int identidade[10], int numerovoo);

int ExcluirReserva(struct voo aereo[50], int identidade[10], int numerovoo);

void ImprimeReserva(struct voo aereo[50],int modo, int numerovoo);

_Bool ComparaIdentidade(int identidade1[10], int identidade2[10]);

#endif /* defined(__Sistema_Passagem_Aerea__spa__) */
