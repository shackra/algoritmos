#include <math.h>
#include <stdio.h>

/*
  Tenemos dos bolas de cristal, no importa cuantas veces se dejen
  caer, no se rompen, sin embargo, pueden romperse a determinada
  altura. Hay que usar ambas bolas de cristal para determinar esa
  altura de manera eficiente.

  expectativa: O(sqrt(n))
  ver: https://frontendmasters.com/courses/algorithms/two-crystal-balls-problem/
 */

int find_optimal_height(const bool pisos[], size_t len) {
  const int jmpBy = (int)floor(sqrt((double)len));

  // NOLINTNEXTLINE
  int i = jmpBy;
  for (; i < len; i += jmpBy) {
    if (pisos[i]) {
      break;
    }
  }

  // retrocedemos por la cantidad que saltamos
  i -= jmpBy;

  // tratamos de romper la segunda bola de cristal
  for (int j = 0; j <= jmpBy && i < len; j++, i++) {
    if (pisos[i]) {
      return i;
    }
  }

  return -1;
}

int main() {
  bool pisos[] = {false, false, false, false, false,
                  false, true,  true,  true,  true};
  size_t len = sizeof(pisos) / sizeof(pisos[0]);

  int best = find_optimal_height(pisos, len);
  printf("la mejor altura en la que ambas bolas de cristal se rompe es %d\n",
         best);
}
