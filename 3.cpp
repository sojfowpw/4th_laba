#include <iostream>
#include <vector>
#include <random>

using namespace std;

double chiSquare(const vector<int>& arr, int amountIntervals) {
    double expectedFrequency = static_cast<double>(arr.size()) / amountIntervals;
    vector<int> frequency(amountIntervals, 0);
    for (int i : arr) {
        int interval = (i - 1) / (100 / amountIntervals);
        if (interval < amountIntervals) {
            frequency[interval]++;
        }
    }
    double Xi = 0;
    for (int i : frequency) {
        Xi += pow(i - expectedFrequency, 2) / expectedFrequency;
    }

    return Xi;
}

bool hypothesis(double Xi, int degreeOfFreedom) {
    double criticalValues[] = { 0, 3.84, 5.99, 7.81, 9.49, 11.1, 12.6, 14.1, 15.5, 16.9, 18.3, 19.7, 21.0, 22.4, 23.7, 25.0, 26.3, 27.6, 28.9, 30.1, 31.4, 32.7, 33.9, 35.2, 36.4, 37.7, 38.9, 40.1, 41.3, 42.6, 43.8 };
    int index = degreeOfFreedom;
    if (index > 30) {
        index = 30;
    }
    double criticalValue = criticalValues[index];
    return Xi < criticalValue;
}

int main() {
	setlocale(LC_ALL, "Russian");
	random_device rd;
	mt19937_64 random_(rd());
	vector<int> arr_50;
	vector<int> arr_100;
	vector<int> arr_1000;
	int sum50 = 0, sum100 = 0, sum1000 = 0;
	for (int i = 0; i < 50; i++) {
		arr_50.push_back(random_() % 100 + 1);
		sum50 += arr_50[i];
	}
	for (int i = 0; i < 100; i++) {
		arr_100.push_back(random_() % 100 + 1);
		sum100 += arr_100[i];
	}
	for (int i = 0; i < 1000; i++) {
		arr_1000.push_back(random_() % 100 + 1);
		sum1000 += arr_1000[i];
	}
	double teormx = 50.5;
	double mx50 = static_cast<double>(sum50) / 50;
	double mx100 = static_cast<double>(sum100) / 100;
	double mx1000 = static_cast<double>(sum1000) / 1000;
	cout << "Теоретическое математическое ожидание: " << teormx << endl;
	cout << "Реальное математическое ожидание для 1 массива: " << mx50 << endl;
	cout << "Реальное математическое ожидание для 2 массива: " << mx100 << endl;
	cout << "Реальное математическое ожидание для 3 массива: " << mx1000 << endl;
	double Xi50 = chiSquare(arr_50, 10);
	double Xi100 = chiSquare(arr_100, 20);
	double Xi1000 = chiSquare(arr_1000, 30);
	cout << "Хi для 1 массива: " << Xi50;
	cout << (hypothesis(Xi50, 9) ? " - гипотеза верна" : " - гипотеза неверна") << endl;
	cout << "Хi для 2 массива: " << Xi100;
	cout << (hypothesis(Xi100, 19) ? " - гипотеза верна" : " - гипотеза неверна") << endl;
	cout << "Хi для 3 массива: " << Xi1000;
	cout << (hypothesis(Xi1000, 29) ? " - гипотеза верна" : " - гипотеза неверна") << endl;
    return 0;
}
