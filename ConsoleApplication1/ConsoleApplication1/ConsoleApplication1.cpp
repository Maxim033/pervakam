#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 2 // Максимальное количество строк в таблицах

// Функция для обмена значений двух элементов
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция для сортировки результирующей таблицы по ключам
void sort_result(int result[N * 2][2]) {
    for (int i = 0; i < N * 2 - 1; i++) {
        for (int j = 0; j < N * 2 - i - 1; j++) {
            if (result[j][0] > result[j + 1][0]) {
                // Обмен значений всех полей
                swap(&result[j][0], &result[j + 1][0]);
                swap(&result[j][1], &result[j + 1][1]);
            }
        }
    }
}

// Функция для соединения двух таблиц
void join_tables(int table1[N][2], int table2[N][2], int result[N * 2][2]) {
    int count1 = 0; // Счетчик для количества строк в table1
    int count2 = 0; // Счетчик для количества строк в table2

    // Подсчитываем количество строк в каждой таблице
    for (int i = 0; i < N; i++) {
        if (table1[i][0] != 0) count1++;
        if (table2[i][0] != 0) count2++;
    }

    // Соединяем таблицы
    int idx = 0;
    for (int i = 0; i < count1; i++) {
        int key = table1[i][0];
        int value1 = table1[i][1];

        // Записываем результат в новую таблицу
        result[idx][0] = key;
        result[idx][1] = value1;
        idx++;
    }

    // Добавляем оставшиеся строки из второй таблицы
    for (int i = 0; i < count2; i++) {
        int key = table2[i][0];
        int value2 = table2[i][1];

        // Проверяем, есть ли ключ в первой таблице
        int found = 0;
        for (int j = 0; j < count1; j++) {
            if (result[j][0] == key) {
                found = 1;
                break;
            }
        }

        // Если ключ не найден, добавляем его в результат
        if (!found) {
            result[idx][0] = key;
            result[idx][1] = value2;
            idx++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int table1[N][2] = { 0 }; // Инициализируем таблицы нулями
    int table2[N][2] = { 0 };
    int result[N * 2][2] = { 0 }; // Увеличиваем размер результата

    // Ввод данных для первой таблицы
    printf("Введите данные для первой таблицы (ключ и значение через пробел):\n");
    for (int i = 0; i < N; i++) {
        if (scanf("%d %d", &table1[i][0], &table1[i][1]) != 2) {
            printf("Некорректный ввод для первой таблицы.\n");
            return 1;
        }
    }

    // Ввод данных для второй таблицы
    printf("Введите данные для второй таблицы (ключ и значение через пробел):\n");
    for (int i = 0; i < N; i++) {
        if (scanf("%d %d", &table2[i][0], &table2[i][1]) != 2) {
            printf("Некорректный ввод для второй таблицы.\n");
            return 1;
        }
    }

    join_tables(table1, table2, result);

    // Сортируем результирующую таблицу по ключам
    sort_result(result);

    // Выводим результат
    printf("Key\tResult\n");
    for (int i = 0; i < N * 2; i++) {
        if (result[i][0] != 0) {
            printf("%d\t%d\n", result[i][0], result[i][1]);
        }
    }

    return 0;
}