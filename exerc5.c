#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 10

// Fun��o para exibir o vetor
void alimentavetor(int arr[], int n) {
    printf("--------------------------------------\n");
    printf("|               N�MEROS              |\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("\n|Posi��o: %d | N�mero %d|", i, arr[i]);
    printf("\n\n");
}

// Fun��o de busca linear
int buscaLinear(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Fun��o de busca bin�ria
int buscaBinaria(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return buscaBinaria(arr, l, mid - 1, x);
        return buscaBinaria(arr, mid + 1, r, x);
    }
    return -1;
}

// Fun��o de busca tern�ria
int buscaTernaria(int l, int r, int key, int ar[]) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (ar[mid1] == key)
            return mid1;
        if (ar[mid2] == key)
            return mid2;
        if (key < ar[mid1])
            return buscaTernaria(l, mid1 - 1, key, ar);
        else if (key > ar[mid2])
            return buscaTernaria(mid2 + 1, r, key, ar);
        else
            return buscaTernaria(mid1 + 1, mid2 - 1, key, ar);
    }
    return -1;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    int opcao;
    printf("+----------------------+\n");
    printf("|    OP��ES DE BUSCA   |\n");
    printf("+----------------------+\n");
    printf("|  [1] Busca Linear    |\n");
    printf("|  [2] Busca Bin�ria   |\n");
    printf("|  [3] Busca Tern�ria  |\n");
    printf("|  [4] Terminar        |\n");
    printf("+----------------------+\n");
    printf("Escolha sua op��o: ");
    scanf("%d", &opcao);
    printf("Informe a chave a ser localizada no Array: ");
    scanf("%d", &x);
    switch (opcao) {
        case 1:
            alimentavetor(arr, n);
            printf("Resultado da busca linear: %d\n", buscaLinear(arr, n, x));
            break;
        case 2:
            alimentavetor(arr, n);
            printf("Resultado da busca bin�ria: %d\n", buscaBinaria(arr, 0, n - 1, x));
            break;
        case 3:
            alimentavetor(arr, n);
            printf("Resultado da busca tern�ria: %d\n", buscaTernaria(0, n - 1, x, arr));
            break;
        case 4:
            printf("Programa terminado.\n");
            break;
        default:
            printf("Op��o inv�lida.\n");
            break;
    }
    return 0;
}

