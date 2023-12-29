#include <stdio.h>
#include <stdlib.h>
#include <locale>

#define SIZE 99

int main() {
    setlocale(LC_ALL, "Ukr");
    // Введення користувачем розмірності матриці
    int M, N;
    printf("Введiть кiлькiсть рядкiв матрицi: ");
    scanf_s("%d", &M);
    printf("Введiть кiлькiсть стовпцiв матрицi: ");
    scanf_s("%d", &N);

    if (M <= 0 || N <= 0) {
        printf("Некоректнi розмiри матрицi. Введiть додатнi цiлi числа для кiлькостi рядкiв та стовпцiв.\n");
        return 1;
    }

    if (M * N > SIZE) {
        printf("Розмiри матрицi перевищують SIZE. Змiнiть розмiри або збiльште SIZE.\n");
        return 1;
    }

    // Оголошення та заповнення матриці "змійкою"
    int a[SIZE][SIZE];
    int c = 1;

    for (int i = 0; i < M; i++) {
        // Перевірка парності рядка для визначення напряму заповнення
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++) {
                a[i][j] = c++;
            }
        }
        else {
            for (int j = N - 1; j >= 0; j--) {
                a[i][j] = c++;
            }
        }
    }

    // Вивід матриці у консоль
    printf("Матриця, заповнена \"змiйкою\":\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("[%0.2d] ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}