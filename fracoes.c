#include "fracoes.h"

Fracao divisao(Fracao fracao1, Fracao fracao2) {
  Fracao resultado;

  // Método dos meios e extremos

  resultado.numerador = fracao1.numerador * fracao2.denominador;
  resultado.denominador = fracao1.denominador * fracao2.numerador;

  simplificacao(&resultado);

  return resultado;
}

Fracao multiplicacao(Fracao fracao1, Fracao fracao2) {
  Fracao resultado;

  resultado.numerador = fracao1.numerador * fracao2.numerador;
  resultado.denominador = fracao1.denominador * fracao2.denominador;

  simplificacao(&resultado);

  return resultado;
}

Fracao subtracao(Fracao *fracao1, Fracao *fracao2) {
  Fracao resultado;
  int MMC;

  MMC = mmc(fracao1->denominador, fracao2->denominador);

  fracao1->numerador = fracao1->numerador * (MMC / fracao1->denominador);
  fracao1->denominador = MMC;

  fracao2->numerador = fracao2->numerador * (MMC / fracao2->denominador);
  fracao2->denominador = MMC;

  resultado.numerador = fracao1->numerador - fracao2->numerador;
  resultado.denominador = MMC;

  simplificacao(&resultado);

  return resultado;
}

Fracao stof(char *f) {
  Fracao frac;

  frac.numerador = atoi(strtok(f, "/"));
  frac.denominador = atoi(strtok(NULL, "/"));

  return frac;
}

void leitura(Fracao *fracao) {
  int operacaoInvalida = 0;

  do {
    scanf("%d/%d", &fracao->numerador, &fracao->denominador);

    if (fracao->denominador == 0) {
      printf("\n");
      printf("Ops! A fração que digitou contém divisão por zero!\n");
      printf("Por favor, tente novamente:\n");
      operacaoInvalida = 1;
    }

  } while (operacaoInvalida == 1);

  simplificacao(fracao);
}

Fracao adicao(Fracao *fracao1, Fracao *fracao2) {
  Fracao resultado;
  int MMC;

  MMC = mmc(fracao1->denominador, fracao2->denominador);

  fracao1->numerador = fracao1->numerador * (MMC / fracao1->denominador);
  fracao1->denominador = MMC;

  fracao2->numerador = fracao2->numerador * (MMC / fracao2->denominador);
  fracao2->denominador = MMC;

  resultado.numerador = fracao1->numerador + fracao2->numerador;
  resultado.denominador = MMC;

  simplificacao(&resultado);

  return resultado;
}

void simplificacao(Fracao *fracao) {
  int i, j, fator;
  int *fatoresNum, *fatoresDen;

  if (fracao->numerador % fracao->denominador == 0) {
    fracao->numerador = fracao->numerador / fracao->denominador;
    fracao->denominador = 1;
  } else {
    if (fracao->denominador % fracao->numerador == 0) {
      fracao->denominador = fracao->denominador / fracao->numerador;
      fracao->numerador = 1;
    } else {
      fatoresNum = fatoriacao(fracao->numerador);
      fatoresDen = fatoriacao(fracao->denominador);

      for (i = 1; i <= fatoresNum[0]; i++)
        for (j = 1; j <= fatoresDen[0]; j++) {
          if (fatoresNum[i] == fatoresDen[j] && fatoresNum[i] != 0) {
            fracao->numerador = fracao->numerador / fatoresNum[i];
            fracao->denominador = fracao->denominador / fatoresNum[i];

            fatoresNum[i] = 0;
            fatoresDen[j] = 0;
          }
        }
    }
  }
}

int mmc(int num1, int num2) {
  int i, j, k, nFatores, mmc, achou;
  int *fatores1, *fatores2, *fatoresMMC;

  fatores1 = fatoriacao(num1);
  fatores2 = fatoriacao(num2);

  nFatores = 0;
  achou = 0;

  fatoresMMC = malloc(sizeof(int) * nFatores);

  for (i = 1; i <= fatores1[0]; i++) {
    for (j = 1; j <= fatores2[0]; j++) {
      if (fatores1[i] != 0 && fatores1[i] == fatores2[j]) {
        nFatores++;
        fatoresMMC = realloc(fatoresMMC, (sizeof(int) * nFatores));

        fatoresMMC[(nFatores - 1)] = fatores1[i];

        fatores1[i] = 0;
        fatores2[j] = 0;

        for (k = (j + 1); k <= fatores2[0]; k++) {
          fatores2[(k - 1)] = fatores2[k];
          fatores2[k] = 0;
        }

        achou = 1;
        j = fatores2[0];
      }
    }

    if (!achou) {
      nFatores++;
      fatoresMMC = realloc(fatoresMMC, (sizeof(int) * nFatores));

      fatoresMMC[(nFatores - 1)] = fatores1[i];

      fatores1[i] = 0;
    }

    achou = 0;
  }

  for (j = 1; j <= fatores2[0]; j++)
    if (fatores2[j] != 0) {
      nFatores++;
      fatoresMMC = realloc(fatoresMMC, (sizeof(int) * nFatores));

      fatoresMMC[(nFatores - 1)] = fatores2[j];
    }

  mmc = 1;

  for (i = 0; i < nFatores; i++)
    mmc = mmc * fatoresMMC[i];

  return mmc;
}

void escreve(Fracao fracao) {
  int modNumerador, modDenominador;

  modNumerador = sqrt(fracao.numerador * fracao.numerador);
  modDenominador = sqrt(fracao.denominador * fracao.denominador);

  if (fracao.numerador * fracao.denominador >= 0)
    printf("%d", modNumerador);

  else
    printf("-%d", modNumerador);

  if (fracao.denominador != 1)
    printf("/%d\n", modDenominador);
}

int *fatoriacao(int num) {
  int i, j, k, primo, *fatores, nFatores = 0;

  i = 2;
  fatores = malloc(sizeof(int));

  while (sqrt(num * num) != 1) {
    primo = 1;

    for (j = 2; j < i; j++)
      if (i % j == 0)
        primo = 0;

    if (primo)
      while (num % i == 0) {
        num = num / i;
        nFatores++;
        fatores = realloc(fatores, sizeof(int) * (nFatores + 1));
        fatores[nFatores] = i;
      }

    i++;
  }
  fatores[0] = nFatores;

  return fatores;
}
