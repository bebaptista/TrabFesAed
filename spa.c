//
//  spa.c
//  Sistema Passagem Aerea
//
//  Created by Bernardo de Magalhaes Machado Nogueira Baptista on 12/11/16.
//  Copyright (c) 2016 Bernardo de Magalhaes Machado Nogueira Baptista. All rights reserved.
//

#include "spa.h"

void InicializarDados(struct voo aereo[50]) {
    for (int i=0; i<50; i++) {
        if (i<10) {
            aereo[i].numerovoo = 1001+i;
            aereo[i].lotacao = 0;
            for (int j=0; j<10; j++) {
                aereo[i].poltrona[j].ocupado=0;
                aereo[i].poltrona[j].passageiro = 0;
            }
        }
        else if (i<20) {
            aereo[i].numerovoo = 1991+i;
            aereo[i].lotacao = 0;
            for (int j=0; j<10; j++) {
                aereo[i].poltrona[j].ocupado=0;
                aereo[i].poltrona[j].passageiro = 0;
            }
        }
        else if (i<30) {
            aereo[i].numerovoo = 2981+i;
            aereo[i].lotacao = 0;
            for (int j=0; j<10; j++) {
                aereo[i].poltrona[j].ocupado=0;
                aereo[i].poltrona[j].passageiro = 0;
            }
        }
        else if (i<40) {
            aereo[i].numerovoo = 3971+i;
            aereo[i].lotacao = 0;
            for (int j=0; j<10; j++) {
                aereo[i].poltrona[j].ocupado=0;
                aereo[i].poltrona[j].passageiro = 0;
            }
        }
        else {
            aereo[i].numerovoo = 4961+i;
            aereo[i].lotacao = 0;
            for (int j=0; j<10; j++) {
                aereo[i].poltrona[j].ocupado=0;
                aereo[i].poltrona[j].passageiro = 0;
            }
        }
        //printf("%d\n",aereo[i].numerovoo);
    }
}

int IncluirReserva(struct voo aereo[50], long int identidade, int numerovoo) {
    for (int i=0; i<50; i++) {
        if (numerovoo==aereo[i].numerovoo) {
            if (aereo[i].lotacao==10) {
                return 1;
            }
            else {
                for (int j=0; j<10; j++) {
                    if (aereo[i].poltrona[j].ocupado==0) {
                        aereo[i].lotacao++;
                        aereo[i].poltrona[j].ocupado=1;
                        aereo[i].poltrona[j].passageiro = identidade;
                        return 2;
                    }
                }
            }
        }
    }
    return 0;
}

int ExcluirReserva(struct voo aereo[50], long int identidade, int numerovoo) {
    for (int i=0; i<50; i++) {
        if (numerovoo==aereo[i].numerovoo) {
            for (int j=0; j<10; j++) {
                if(ComparaIdentidade(identidade, aereo[i].poltrona[j].passageiro)==1) {
                    aereo[i].poltrona[j].passageiro = 0;
                    aereo[i].poltrona[j].ocupado=0;
                    aereo[i].lotacao--;
                    return 2;
                }
            }
            return 1;
        }
    }
    return 0;
}

void ImprimeReserva(struct voo aereo[50],int modo, int numerovoo){
    _Bool flag=0;
    switch (modo) {
        case 1:
            printf("Numero do voo: %d\n",numerovoo);
            for (int i=0; i<50; i++) {
                if (numerovoo==aereo[i].numerovoo) {
                    flag=1;
                    printf("Numero de reservas no voo: %d\n",aereo[i].lotacao);
                    for (int j=0; j<10; j++) {
                        if (aereo[i].poltrona[j].ocupado==1) {
                            printf("%li\n",aereo[i].poltrona[j].passageiro);
                        }
                    }
                }
            }
            if (flag==0) {
                printf("Numero de voo inexistente\n");
            }
            break;
            
        case 2:
            for (int i=0; i<50; i++) {
                printf("Numero do voo: %d Reservas: %d\n",aereo[i].numerovoo,aereo[i].lotacao);
            }
            break;
        
        case 3:
            for (int i=0; i<50; i++) {
                printf("Numero do voo: %d\n",aereo[i].numerovoo);
                printf("Numero de reservas no voo: %d\n",aereo[i].lotacao);
                for (int j=0; j<10; j++) {
                    if (aereo[i].poltrona[j].ocupado==1) {
                        printf("%li\n",aereo[i].poltrona[j].passageiro);
                    }
                }
            }
            break;
    }
}

_Bool ComparaIdentidade(long int identidade1, long int identidade2) {
    if (identidade1==identidade2) {
        return 1;
    }
    else return 0;
}