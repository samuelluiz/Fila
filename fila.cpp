#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

static int FilaCheia(tFila *f)
{
   int i, deslocamentoA, deslocamentoB;

   if (f->fundoA != ((f->fundoB)-1))
      return 0; /* Há espaço no final do array */
   if (f->frenteA == -1 && f->fundoA == ((f->fundoB)-1))
      return 1; /* Não há mais espaço no array */

      if(f->frenteA != -1){
          deslocamentoA = 0;
            for(i=f->frenteA;i == -1; i--){
                deslocamentoA+=1;
            }
            for (i = f->frenteA + 1; i <= f->fundoA; ++i)
      f->itens[i - deslocamentoA] = f->itens[i];
      /* A frente e o fundo da fila também */
      /* precisam ser deslocados           */
   f->frenteA -= deslocamentoA;
   f->fundoA -= deslocamentoA;
      /* A fila foi deslocada e agora     */
      /* podem-se acrescentar novos itens */
   return 0;
      }

   if(f->frenteB != MAX_ELEMENTOS){
          deslocamentoB = 0;
            for(i= f->frenteB;i = MAX_ELEMENTOS ; i++){
                deslocamentoB+=1;
            }
            for (i = f->frenteB + 1; i <= f->fundoB; ++i)
      f->itens[i - deslocamentoB] = f->itens[i];
      /* A frente e o fundo da fila também */
      /* precisam ser deslocados           */
   f->frenteB += deslocamentoB;
   f->fundoB += deslocamentoB;
      /* A fila foi deslocada e agora     */
      /* podem-se acrescentar novos itens */
   return 0;
      }
}

void CriaFila(tFila *f){
    f->frenteA = f->fundoA = -1;
    f->frenteB = f->fundoB = MAX_ELEMENTOS;
}

void AcrescentaDireita(tFila *f, tElemento item){
    if (FilaCheia(f)){
        puts("fila cheia");
        exit(1);
    }
    f->itens[++f->fundoA] = item;
}

void AcrescentaEsquerda(tFila *f, tElemento item){
    if (FilaCheia(f)){
        puts("fila cheia");
        exit(1);
    }
    f->itens[--f->fundoB] = item;
}

tElemento RetiraDireita(tFila *f){
    if (f->frenteA == f->fundoA){
        puts("fila vazia");
        exit(1);
    }

    return f->itens[++f->frenteA];
}

tElemento RetiraEsquerda(tFila *f){
    if (f->frenteB == f->fundoB){
        puts("fila vazia");
        exit(1);
    }

    return f->itens[--f->frenteB];
}
