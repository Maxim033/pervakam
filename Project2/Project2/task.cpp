#include <iostream>
#include <cmath>
#define EPS 1e-9
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    float sum = 0.0f, part_sum = 0.0f;
    for (int n = 0;; n++) {
        part_sum = (n % 2 ? -1.0f : 1.0f) / (n+1);
        //part_sum = pow(-1, n) / (n+1);
        if (abs(part_sum) < EPS) {
            break;
        }
        sum += part_sum;
    }

    float exp = log(2);
    cout << "сумма:" << sum << endl;
    cout << "exp:" << exp << endl;
    system("pause");
    return 0;
}
второй таск номер6