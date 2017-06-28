//
//  main.c
//  ED_LISTA_EST_05
//
//  Created by Dev on 04/05/17.
//  Copyright © 2017 Wooba. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "ListaSequencial.h"

int main(int argc, const char * argv[]) {
    Lista *li;
    li = cria_lista();
    struct aluno *al = (struct aluno*) malloc(sizeof(struct aluno));
    al->matricula = 1;
    int inseriu = insere_lista_inicio(li, *al);
    printf("%d\n", inseriu);
    int achou_posicao = consulta_lista_pos(li, 0, al);
    printf("%d\n", achou_posicao);
    int achou_matricula = consulta_lista_mat(li, 1, al);
    printf("%d\n", achou_matricula);
    libera_lista(li);
    return 0;
}
