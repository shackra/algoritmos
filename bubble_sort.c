#include <stddef.h>
#include <stdio.h>

/*
  En un arreglo de tamaño N, por cada pasada `i` de 0 hasta N hay que
  realizar una pasada adicional `j` desde 0 hasta N-1-i. El ultimo
  elemento del arreglo se ignora en cada pasada `j` porque siempre es
  el ultimo elemento más grande de la pasada anterior.

  Big O: O(n^2)
  ver: https://frontendmasters.com/courses/algorithms/bubble-sort/
 */

void print_array(int arreglo[], size_t len) {
  if (len == 0) {
    printf("arreglo vacío!\n");
  }

  for (int i = 0; i < len; i++) {
    printf("%d ", arreglo[i]);
  }

  printf("\n");
}

int main() {
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  int elementos[] = {25, 21, 19, 10, 7, 3, 2, 1};
  size_t largo = sizeof(elementos) / sizeof(elementos[0]);

  printf("antes:\n");
  print_array(elementos, largo);

  for (int i = 0; i < largo; i++) {
    for (int j = 0; j < largo - i - 1; j++) {
      if (elementos[j] > elementos[j + 1]) {
        // realiza el intercambio de posiciones
        int tmp = elementos[j];
        elementos[j] = elementos[j + 1];
        elementos[j + 1] = tmp;
      }
    }
  }

  printf("ahora:\n");
  print_array(elementos, largo);
}
