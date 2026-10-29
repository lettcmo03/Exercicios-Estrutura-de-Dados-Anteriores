#include <stdio.h>

#define CAPACIDADE 5

int main() {
    int fila[CAPACIDADE];
    int inicio = 0;
    int fim = 0;
    int quantidade = 0;
    int opcao;
    int numero;
    int i;
    int posicao;

    do {
        printf("\n--- MENU DA FILA ---\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

        if (opcao == 1) {
            if (quantidade == CAPACIDADE) {
                printf("A fila esta cheia!\n");
            } else {
                printf("Digite o numero: ");
                if (scanf("%d", &numero) != 1) {
                    printf("Entrada invalida.\n");
                    return 1;
                }
                fila[fim] = numero;
                fim = (fim + 1) % CAPACIDADE;
                quantidade++;
                printf("Numero enfileirado!\n");
            }
        } else if (opcao == 2) {
            if (quantidade == 0) {
                printf("A fila esta vazia!\n");
            } else {
                printf("Numero removido: %d\n", fila[inicio]);
                inicio = (inicio + 1) % CAPACIDADE;
                quantidade--;
            }
        } else if (opcao == 3) {
            if (quantidade == 0) {
                printf("A fila esta vazia!\n");
            } else {
                printf("Fila: ");
                for (i = 0; i < quantidade; i++) {
                    posicao = (inicio + i) % CAPACIDADE;
                    printf("%d ", fila[posicao]);
                }
                printf("\n");
            }
        } else if (opcao != 4) {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    printf("Programa encerrado.\n");
    return 0;
}
