#include <stdio.h>

/*
  En un arreglo de tamaño N ordenado de manera ascendente hay
  verificar si existe un valor más rápido que O(n).

  Big O: O(log n)
  ver: https://frontendmasters.com/courses/algorithms/binary-search-algorithm/
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

bool search(int target, const int arreglo[], size_t len) {
  int low = 0;
  int high = (int)len;

  while (low < high) {
    int midp = low + ((high - low) / 2);
    int value = arreglo[midp];

    if (value == target) {
      return true;
    }

    if (value > target) {
      high = midp;
    } else {
      low = midp + 1;
    }
  };

  return false;
}

int main() {
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers)
  int lista[] = {1, 2, 4, 5, 6, 7, 8, 9, 11, 13, 15, 28, 48};
  size_t largo = sizeof(lista) / sizeof(lista[0]);

  const int busca13 = 13;
  const int busca99 = 99;
  const int busca48 = 48;

  printf("búsqueda binaria. Ejercitando el código.\n");
  printf("arreglo:\n");
  print_array(lista, largo);

  bool existe13 = search(busca13, lista, largo);
  printf("existe %d en el arreglo? %d\n", busca13, (int)existe13);

  bool existe99 = search(busca99, lista, largo);
  printf("existe %d en el arreglo? %d\n", busca99, (int)existe99);

  bool existe48 = search(busca48, lista, largo);
  printf("existe %d en el arreglo? %d\n", busca48, (int)existe48);
}
