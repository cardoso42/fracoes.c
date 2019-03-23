#ifndef FRACOES_H_INCLUDED
#define FRACOES_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_matriz
{
    int numerador;
    int denominador;
} Fracao;

void leitura (Fracao *fracao);
Fracao adicao (Fracao *fracao1, Fracao *fracao2);
int* fatoriacao (int num);
int mmc (int num1, int num2);
void simplificacao (Fracao *fracao);
void escreve (Fracao fracao);
Fracao stof (char *f);
Fracao subtracao (Fracao *fracao1, Fracao *fracao2);
Fracao multiplicacao (Fracao fracao1, Fracao fracao2);
Fracao divisao (Fracao fracao1, Fracao fracao2);

#endif // FRACOES_H_INCLUDED
