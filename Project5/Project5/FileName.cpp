// C(n) = (2n)!/ ((n + 1)!*n!)
#include <stdio.h>
#include <stdbool.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long catalan_direct(int n);
long long catalan_indirect(int n);//catalan_indirect вызывает catalan_direct, обеспечивая косвенную рекурсию

long long catalan_direct(int n) {
    if (n <= 1) {
        return 1;
    }
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += catalan_direct(i) * catalan_indirect(n - i - 1);
    }
    return result;
}

long long catalan_indirect(int n) {
    return catalan_direct(n);
}

int main() {
    int n = 6;
    printf("Число Каталана C(%d) = %lld\n", n, catalan_direct(n));
    return 0;
}