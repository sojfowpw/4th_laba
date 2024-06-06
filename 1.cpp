#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>

using namespace std;

double func(double x) { // функция из условия
	return x * log(x + 1) - 1;
}

double derivativeFunc(double x) { // производная функции
    return log(x + 1) + x / (x + 1);
}

void halfDivision(double a, double b, double eps, double& x, vector<tuple<double, double, double, double>>& result) { // метод половинного деления
    int N = 0; // число итераций
    while ((b - a) >= eps) { // цикл будет выполняться, пока разница между границами интервала больше заданной точности eps
        double c = (a + b) / 2;
        result.push_back({ N, a, b, b - a });
        if (func(c) == 0) { // если функция принимает значение 0 в середине интервала, корень найден
            break;
        }
        else if (func(a) * func(c) < 0) { // если произведение значений функции в границах интервала имеет разные знаки, корень находится в левой половине
            b = c; // сдвиг правой границы интервала к середине
        }
        else {
            a = c; // сдвиг левой границы интервала к середине
        }
        N++;
        x = c;
    }
}

void Newton(double x0, double eps, double& x, vector<tuple<double, double, double, double>>& result) { // метод Ньютона
    int N = 0; // число итераций
    while (abs(func(x0)) >= eps) { // цикл будет выполняться, пока абсолютное значение функции в текущем приближении больше заданной точности eps
        double x1 = x0 - func(x0) / derivativeFunc(x0);
        double c = abs(x1 - x0); // вычисление абсолютной разницы между текущим и следующим приближением
        if (c < 0.0001) {
            c = 0.0001; // если разница слишком близка к нулю, устанавливаем минимальную разницу
        }
        result.push_back({ N, x0, x1, c });
        if (c <= eps) {
            break;
        }
        x0 = x1;
        N++;
        x = x0;
    }
}

double f(double x) { // функция для метода простых итераций
    if (x < 0.0) {
        return exp(1.0 / x) - 1;
    }
    else {
        return 1.0 / log(x + 1);
    }
}

void simpleIterations(double x0, double eps, double& x, vector<tuple<double, double, double, double>>& result) { // метод простых итераций
    int N = 0; // число итераций
    while (abs(f(x0)) >= eps) { // цикл будет выполняться, пока абсолютное значение функции в текущем приближении больше заданной точности eps
        double x1 = f(x0);
        if (abs(x1 - x0) < eps) {
            break;
        }
        result.push_back({ N, x0, x1, abs(x1 - x0) });
        x0 = x1;
        N++;
        x = x0;
    }
}

void resultTables(double a, double b, double eps, double x0) {
    double x = 0;
    vector<tuple<double, double, double, double>> reshd; // вектор для метода половинного деления
    vector<tuple<double, double, double, double>> resn; // вектор для метода Ньютона
    vector<tuple<double, double, double, double>> ressi; // вектор для метода простых итераций
    cout << "Метод половинного деления:\n\n";
    cout << "|" << setw(2) << "N" << setw(2) << "|" << setw(8) << "a" << setw(8) << "|" << setw(8) << "b" << setw(8) << "|" << setw(10) << "b - a" << setw(7) << "|\n";
    halfDivision(a, b, eps, x, reshd);
    for (tuple<double, double, double, double> i : reshd) { // табличный вывод метода половинного деления
        cout << "|" << setw(2) << get<0>(i) << setw(2) << "|" << setw(15) << get<1>(i) << "|" << setw(15) << get<2>(i) << "|" << setw(15) << get<3>(i) << "|\n";
    }
    cout << "\nх = " << x;
    cout << "\n\nМетод Ньютона:\n\n";
    cout << "|" << setw(2) << "N" << setw(2) << "|" << setw(8) << "x0" << setw(8) << "|" << setw(8) << "x1" << setw(8) << "|" << setw(10) << "x1 - x0" << setw(7) << "|\n";
    Newton(x0, eps, x, resn);
    for (tuple<double, double, double, double> i : resn) { // табличный вывод метода Ньютона
        cout << "|" << setw(2) << get<0>(i) << setw(2) << "|" << setw(15) << get<1>(i) << "|" << setw(15) << get<2>(i) << "|" << setw(15) << get<3>(i) << "|\n";
    }
    cout << "\nх = " << x;
    cout << "\n\nМетод простых итераций:\n\n";
    cout << "|" << setw(2) << "N" << setw(2) << "|" << setw(8) << "x0" << setw(8) << "|" << setw(8) << "x1" << setw(8) << "|" << setw(10) << "x1 - x0" << setw(7) << "|\n";
    simpleIterations(x0, eps, x, ressi);
    for (tuple<double, double, double, double> i : ressi) { // табличный вывод метода простых итераций
        cout << "|" << setw(2) << get<0>(i) << setw(2) << "|" << setw(15) << get<1>(i) << "|" << setw(15) << get<2>(i) << "|" << setw(15) << get<3>(i) << "|\n";
    }
    cout << "\nх = " << x;
}

int main() {
	setlocale(LC_ALL, "Russian");
	double a = -1, b = 1, eps = 0.0001; // a, b - промежуток, eps - точность
    double x0 = -0.5; // начальное приближение
    cout << "1 корень\n\n";
    resultTables(a, b, eps, x0); // 1 корень
    a = 0;
    b = 2;
    x0 = 0.5;
    cout << "\n\n2 корень\n\n";
    resultTables(a, b, eps, x0); // 2 корень
	return 0;
}
