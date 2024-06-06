#include <iostream>
#include <vector>

using namespace std;

void prnt(vector<int>& fib) { // функция вывода
    for (int i = 2; i < fib.size(); i++) {
        cout << fib[i] << " ";
    }
    cout << endl;
}

vector<int> sum(int j, int k, int k0, int k1, int m) { // метод со сложением
    vector<int> fib;
    fib.push_back(k0);
    fib.push_back(k1);
    for (int i = 2; i <= 10; i++) {
        fib.push_back((fib[i - j] + fib[i - k]) % m);
    }
    return fib;
}

vector<int> sub(int j, int k, int k0, int k1, int m) { // метод с вычитанием
    vector<int> fib;
    fib.push_back(k0);
    fib.push_back(k1);
    for (int i = 2; i <= 10; i++) {
        fib.push_back((fib[i - j] - fib[i - k]) % m);
    }
    return fib;
}

vector<int> mult(int j, int k, int k0, int k1, int m) { // метод с умножением
    vector<int> fib;
    fib.push_back(k0);
    fib.push_back(k1);
    for (int i = 2; i <= 10; i++) {
        fib.push_back((fib[i - j] * fib[i - k]) % m);
    }
    return fib;
}

vector<int> funXOR(int j, int k, int k0, int k1, int m) { // метод с исключающим или
    vector<int> fib;
    fib.push_back(k0);
    fib.push_back(k1);
    for (int i = 2; i <= 10; i++) {
        fib.push_back((fib[i - j] ^ fib[i - k]) % m);
    }
    return fib;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int j = 2, k = 1, k0 = 1, k1 = 4, m = 16; // j, k - шаг; k0, k1 - первые 2 значения; m - модуль
    vector<int> fib = sum(j, k, k0, k1, m); // вектор для чисел 
    cout << "Метод сложения: ";
    prnt(fib);
    fib = sub(j, k, k0, k1, m);
    cout << "Метод вычитания: ";
    prnt(fib);
    fib = mult(j, k, k0, k1, m);
    cout << "Метод умножения: ";
    prnt(fib);
    fib = funXOR(j, k, k0, k1, m);
    cout << "Метод с исключающим или: ";
    prnt(fib);
    return 0;
}
