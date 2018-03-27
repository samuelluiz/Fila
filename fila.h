#ifndef FILA_H
#define FILA_H

#define MAX_ELEMENTOS 10

typedef int tElemento;
typedef struct tFila{
    tElemento itens[MAX_ELEMENTOS];
    int frenteA, fundoA, frenteB, fundoB;
};

extern void CriaFila(tFila *f);

extern void AcrescentaDireita(tFila *f, tElemento item);
extern tElemento RetiraDireita(tFila *f);

extern void AcrescentaEsquerda(tFila *f, tElemento item);
extern tElemento RetiraEsquerda(tFila *f);

#endif // FILA_H
