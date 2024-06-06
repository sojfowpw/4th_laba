#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void randdig(int* arrdig, int size, int beg, int end_) { // заполнение массива случайными числами
	random_device rd;
	mt19937_64 random_(rd()); // подключение mt19937_64
	for (int i = 0; i < size; i++) {
		arrdig[i] = random_() % (end_ - beg + 1) + beg;
		cout << arrdig[i] << " ";
	}
	cout << endl;
}

vector<int> vect_arr(int* arrdig, int size) { // заполнение вектора элементами массива
	vector<int> digits;
	for (int i = 0; i < size; i++) {
		digits.push_back(arrdig[i]);
	}
	return digits;
}

void newarrfor3(int* arrdig_2, int* arrdig_3, int* newarr, int size) { // заполнение нового массива 
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			newarr[i] = arrdig_2[i] + arrdig_3[i]; // если i - чётное, то сумма
			cout << newarr[i] << " ";
		}
		else {
			newarr[i] = arrdig_2[i] - arrdig_3[i]; // иначе - разность
			cout << newarr[i] << " ";
		}
	}
}

void leapYear(int beg, int end_) { // високосные года
	for (int i = beg; i <= end_; i++) {
		if (i % 400 == 0) { // если год кратен 4, то он високосный
			cout << i << " ";
		}
		else if (i % 100 != 0 && i % 4 == 0) {
			cout << i << " ";
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "№1-2" << endl << "Введите размер массива: ";
	int size = 0; // размер массивов
	cin >> size;
	int* arrdig_1 = new int[size]; // 1 массив
	cout << "Исходный массив: ";
	randdig(arrdig_1, size, 100, 200); // заполнение случайными значеними от 100 до 200
	vector<int> sortedarr = vect_arr(arrdig_1, size);
	delete[] arrdig_1; // освобождение памяти
	cout << "Отсортированный массив: ";
	sort(sortedarr.begin(), sortedarr.end()); // сортировка по возрастанию
	for (int i : sortedarr) { // вывод отсортированного вектора
		cout << i << " ";
	}
	cout << endl << "2 по величине элемент: " << sortedarr[size - 2] << endl; // вывод 2 по величине элемента
	int sum = 0;
	for (int i = 1; i < size - 2; i++) { // сумма элементов между минимальным и 2 по величине
		sum += sortedarr[i];
	}
	cout << "Сумма элементов между минимальным и 2 по величине: " << sum << endl << endl;

	cout << "№3" << endl;
	int* arrdig_2 = new int[size]; // 1 массив
	cout << "Первый массив: ";
	randdig(arrdig_2, size, -50, 50); // заполнение случайными значеними от -50 до 50
	int* arrdig_3 = new int[size]; // 2 массив
	cout << "Второй массив: ";
	randdig(arrdig_3, size, -50, 50); // заполнение случайными значеними от -50 до 50
	int* newarr = new int[size]; // новый массив
	cout << "Новый массив: ";
	newarrfor3(arrdig_2, arrdig_3, newarr, size); // заполнение нового массива
	delete[] arrdig_2; // освобождение памяти
	delete[] arrdig_3;
	delete[] newarr;
	cout << endl << endl;

	cout << "№4" << endl << "Исходный массив: ";
	int* arrdigfor4 = new int[size]; // исходный массив
	randdig(arrdigfor4, size, 100, 200); // заполнение случайными значеними от 100 до 200
	sortedarr = vect_arr(arrdigfor4, size); //заполнение вектора элементами массива
	delete[] arrdigfor4; // освобождение памяти
	map<int, int> countdig; // map для связи: число - количество
	for (int i : sortedarr) {
		countdig[i]++; // подсчёт количества
	}
	for (auto& pair : countdig) {
		cout << "Число: " << pair.first << " количество повторений: " << pair.second << endl;
	}
	cout << endl << endl;

	cout << "№5" << endl << "Ввод диапазона лет: ";
	int first_year = 0, last_year = 0; // переменные для диапазона 
	cin >> first_year;
	cin >> last_year;
	leapYear(first_year, last_year); // вывод високосных годов
	return 0;
}
