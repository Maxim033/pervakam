#include <stdio.h>
#include <string.h>
#include <locale.h>

void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    char str[100]; // Выделяем достаточно места для строки, например, 100 символов
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin); // Безопасное чтение строки с пробелами
    str[strcspn(str, "\n")] = 0; // Удаляем символ новой строки, если он есть
    reverse_string(str);
    printf("Перевернутая строка: %s\n", str);
    return 0;
}