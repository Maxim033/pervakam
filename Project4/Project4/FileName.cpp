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
    char str[100]; // �������� ���������� ����� ��� ������, ��������, 100 ��������
    printf("������� ������: ");
    fgets(str, sizeof(str), stdin); // ���������� ������ ������ � ���������
    str[strcspn(str, "\n")] = 0; // ������� ������ ����� ������, ���� �� ����
    reverse_string(str);
    printf("������������ ������: %s\n", str);
    return 0;
}