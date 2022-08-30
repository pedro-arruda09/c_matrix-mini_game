#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  // Dados da escola:
  int tam_escola = 5;
  char cenario_escola[tam_escola][tam_escola];

  // Dados do estacionamento:
  int l_estac = 3;
  int c_estac = 10;
  char cenario_estac[l_estac][c_estac];

  // Dados da rua:
  int l_rua = 8;
  int c_rua = 10;
  char cenario_rua[l_rua][l_estac];

  // Inicializando o cenário da escola.
  for (int l = 0; l < tam_escola; l++) {
    for (int c = 0; c < tam_escola; c++) {
      cenario_escola[l][c] = '_';
    }
  }

  // Inicializando Walter.
  int walt_l = 1;
  int walt_c = 0;

  cenario_escola[walt_l][walt_c] = 'W';

  // Inicializando produtos.
  cenario_escola[0][3] = '1';
  cenario_escola[0][4] = '1';
  cenario_escola[1][3] = '1';
  cenario_escola[1][4] = '2';
  cenario_escola[2][3] = '2';
  cenario_escola[2][4] = '2';
  cenario_escola[3][3] = '3';
  cenario_escola[3][4] = '4';
  cenario_escola[4][3] = '3';
  cenario_escola[4][4] = '4';

  int produtos = 0;
  int preso = 0;

  do {
    // Imprimindo cenário
    printf("\nESCOLA\n\n");
    for (int l = 0; l < tam_escola; l++) {
      for (int c = 0; c < tam_escola; c++) {
        printf("%c ", cenario_escola[l][c]);
      }
      printf("\n");
    }

    printf("\nProdutos: %i", produtos);

    char movimento;
    printf(" > ");
    scanf("%c", &movimento);
    getchar();

    // Movendo o personagem pelo cenário.
    switch (movimento) {
    case 'w':

      if (walt_l - 1 >= 0 && cenario_escola[walt_l - 1][walt_c]) {

        if (cenario_escola[walt_l - 1][walt_c] == '1' ||
            cenario_escola[walt_l - 1][walt_c] == '2' ||
            cenario_escola[walt_l - 1][walt_c] == '3' ||
            cenario_escola[walt_l - 1][walt_c] == '4') {
          produtos++;
        }

        cenario_escola[walt_l][walt_c] = '_';

        walt_l--;
        cenario_escola[walt_l][walt_c] = 'W';
      }

      break;

    case 'a':

      if (walt_c - 1 >= 0 && cenario_escola[walt_l][walt_c - 1]) {

        if (cenario_escola[walt_l][walt_c - 1] == '1' ||
            cenario_escola[walt_l][walt_c - 1] == '2' ||
            cenario_escola[walt_l][walt_c - 1] == '3' ||
            cenario_escola[walt_l][walt_c - 1] == '4') {
          produtos++;
        }

        cenario_escola[walt_l][walt_c] = '_';

        walt_c--;
        cenario_escola[walt_l][walt_c] = 'W';
      }

      break;

    case 'd':

      if (walt_c + 1 < tam_escola) {

        if (cenario_escola[walt_l][walt_c + 1] == '1' ||
            cenario_escola[walt_l][walt_c + 1] == '2' ||
            cenario_escola[walt_l][walt_c + 1] == '3' ||
            cenario_escola[walt_l][walt_c + 1] == '4') {
          produtos++;
        }

        cenario_escola[walt_l][walt_c] = '_';

        walt_c++;
        cenario_escola[walt_l][walt_c] = 'W';
      }
      break;

    case 's':
      if (walt_l + 1 < tam_escola) {

        if (cenario_escola[walt_l + 1][walt_c] == '1' ||
            cenario_escola[walt_l + 1][walt_c] == '2' ||
            cenario_escola[walt_l + 1][walt_c] == '3' ||
            cenario_escola[walt_l + 1][walt_c] == '4') {
          produtos++;
        }

        cenario_escola[walt_l][walt_c] = '_';

        walt_l++;
        cenario_escola[walt_l][walt_c] = 'W';
      }
      break;
    }

    // Inicializando o estacionamento.
    if (walt_l == 0 && walt_c == 0) {
      for (int l = 0; l < l_estac; l++) {
        for (int c = 0; c < c_estac; c++) {
          cenario_estac[l][c] = '_';
        }
      }

      // Inicializando Walter no estacionamento.
      int walt_l = 0;
      int walt_c = 0;

      cenario_estac[walt_l][walt_c] = 'W';

      // Inicializando os carros.
      cenario_estac[0][3] = '1';
      cenario_estac[0][4] = '2';
      cenario_estac[0][5] = '3';
      cenario_estac[0][6] = '4';
      cenario_estac[0][7] = '5';
      cenario_estac[0][8] = '6';
      cenario_estac[0][9] = '7';

      do {
        printf("\nESTACIONAMENTO\n\n");
        // Imprimindo cenário do estacionamento.
        for (int l = 0; l < l_estac; l++) {
          for (int c = 0; c < c_estac; c++) {
            printf("%c ", cenario_estac[l][c]);
          }
          printf("\n");
        }

        printf("\nProdutos: %i", produtos);

        char movimento;
        printf(" > ");
        scanf("%c", &movimento);
        getchar();

        switch (movimento) {
        case 'w':

          if (walt_l - 1 >= 0 && cenario_estac[walt_l - 1][walt_c]) {

            cenario_estac[walt_l][walt_c] = '_';

            walt_l--;
            cenario_estac[walt_l][walt_c] = 'W';
          }

          break;

        case 'a':

          if (walt_c - 1 >= 0 && cenario_estac[walt_l][walt_c - 1]) {

            cenario_estac[walt_l][walt_c] = '_';

            walt_c--;
            cenario_estac[walt_l][walt_c] = 'W';
          }

          break;

        case 'd':

          if (walt_c + 1 < c_estac) {

            cenario_estac[walt_l][walt_c] = '_';

            walt_c++;
            cenario_estac[walt_l][walt_c] = 'W';
          }
          break;

        case 's':
          if (walt_l + 1 < l_estac) {

            cenario_estac[walt_l][walt_c] = '_';

            walt_l++;
            cenario_estac[walt_l][walt_c] = 'W';
          }
          break;
        }

        if (walt_l == 0 && walt_c == 7) {
          printf("Você pegou o carro, se dirija à saída!\n");
        }

        if (walt_l == 2 && walt_c == 9) {

          // Inicializando a rua.
          for (int l = 0; l < l_rua; l++) {
            for (int c = 0; c < c_rua; c++) {
              cenario_rua[l][c] = '_';
            }
          }

          // Inicializando Walter na rua.
          int walt_l = 0;
          int walt_c = 0;

          cenario_rua[walt_l][walt_c] = 'W';

          do {
            printf("\nRUA\n\n");
            // Imprimindo cenário da rua.
            for (int l = 0; l < l_rua; l++) {
              for (int c = 0; c < c_rua; c++) {
                printf("%c ", cenario_rua[l][c]);
              }
              printf("\n");
            }

            char movimento;
            printf(" > ");
            scanf("%c", &movimento);
            getchar();
            switch (movimento) {
            case 'w':

              if (walt_l - 1 >= 0 && cenario_rua[walt_l - 1][walt_c]) {

                cenario_rua[walt_l][walt_c] = '_';

                walt_l--;
                cenario_rua[walt_l][walt_c] = 'W';
              }

              break;

            case 'a':

              if (walt_c - 1 >= 0 && cenario_rua[walt_l][walt_c - 1]) {

                cenario_rua[walt_l][walt_c] = '_';

                walt_c--;
                cenario_rua[walt_l][walt_c] = 'W';
              }

              break;

            case 'd':

              if (walt_c + 1 < c_rua) {

                cenario_rua[walt_l][walt_c] = '_';

                walt_c++;
                cenario_rua[walt_l][walt_c] = 'W';
              }
              break;

            case 's':
              if (walt_l + 1 < l_rua) {

                cenario_rua[walt_l][walt_c] = '_';

                walt_l++;
                cenario_rua[walt_l][walt_c] = 'W';
              }
              break;
            }

            system("clear");
          } while (preso == 0);
        }
        system("clear");
      } while (preso == 0);
    }

    system("clear");
  } while (preso == 0);

  printf("Você foi preso!");

  return 0;
}
