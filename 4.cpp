#include <iostream>
#include <random>
#include <vector>

using namespace std;
random_device rd;
mt19937_64 random_(rd());

bool alg_1(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) { // упор на победу
	if (round_number == 0) {
		return false;
	}
	else if (round_number > 100) {
		return false;
	}
	else if (enemy_choices[round_number - 1] == false && self_choices[round_number - 1] == true) {
		return false;
	}
	else {
		return random_() % 2;
	}
}

bool alg_2(int round_number, const vector<bool>& self_choices, const vector<bool>& enemy_choices) { // упор на сотрудничество
	if (round_number == 0) {
		return true;
	}
	else if (enemy_choices[round_number - 1] == false && self_choices[round_number - 1] == true) {
		return false;
	}
	else {
		return true;
	}
}

bool algRandom() { // рандом
	return random_() % 2;
}

void gameAlg_1AndRandom(int number) { // упор на победу + рандом
	int scoreA = 0, scoreB = 0;
	vector<bool> choicesA;
	vector<bool> choicesB;
	for (int i = 0; i < number; i++) {
		bool choiceA = alg_1(i, choicesA, choicesB);
		bool choiceB = algRandom();
		choicesA.push_back(choiceA);
		choicesB.push_back(choiceB);
		if (choiceA && choiceB) {
			scoreA += 24;
			scoreB += 24;
		}
		else if (choiceA == true && choiceB == false) {
			scoreB += 20;
		}
		else if (choiceA == false && choiceB == true) {
			scoreA += 20;
		}
		else {
			scoreA += 4;
			scoreB += 4;
		}
	}
	cout << "Результат 1 алгоритма: " << scoreA << endl << "Результат рандомного алгоритма: " << scoreB << endl << endl;
}

void gameAlg_1AndAlg_2(int number) { // упор на победу + упор на сотрудничество
	int scoreA = 0, scoreB = 0;
	vector<bool> choicesA;
	vector<bool> choicesB;
	for (int i = 0; i < number; i++) {
		bool choiceA = alg_1(i, choicesA, choicesB);
		bool choiceB = alg_2(i, choicesB, choicesA);
		choicesA.push_back(choiceA);
		choicesB.push_back(choiceB);
		if (choiceA && choiceB) {
			scoreA += 24;
			scoreB += 24;
		}
		else if (choiceA == true && choiceB == false) {
			scoreB += 20;
		}
		else if (choiceA == false && choiceB == true) {
			scoreA += 20;
		}
		else {
			scoreA += 4;
			scoreB += 4;
		}
	}
	cout << "Результат 1 алгоритма: " << scoreA << endl << "Результат 2 алгоритма: " << scoreB << endl << endl;
}

void gameAlg_2AndRandom(int number) { // упор на сотрудничество + рандом
	int scoreA = 0, scoreB = 0;
	vector<bool> choicesA;
	vector<bool> choicesB;
	for (int i = 0; i < number; i++) {
		bool choiceA = alg_2(i, choicesA, choicesB);
		bool choiceB = algRandom();
		choicesA.push_back(choiceA);
		choicesB.push_back(choiceB);
		if (choiceA && choiceB) {
			scoreA += 24;
			scoreB += 24;
		}
		else if (choiceA == true && choiceB == false) {
			scoreB += 20;
		}
		else if (choiceA == false && choiceB == true) {
			scoreA += 20;
		}
		else {
			scoreA += 4;
			scoreB += 4;
		}
	}
	cout << "Результат 2 алгоритма: " << scoreA << endl << "Результат рандомного алгоритма: " << scoreB << endl << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int number = random_() % (101) + 100;
	cout << "Количество раундов: " << number << endl;
	gameAlg_1AndRandom(number);
	gameAlg_1AndAlg_2(number);
	gameAlg_2AndRandom(number);
	return 0;
}
