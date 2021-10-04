#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
//1
void task1(unsigned int n) {
	for (unsigned int i = 0; i <= n; i++) {
		for (unsigned int g = 0; g <= i; g++) {
			cout << g;
		}
		cout << endl;
	}
}
//2
void task2(unsigned int n) {
	cout << "Биноминальная последовательность:\n";
	double res = 1.;
	cout << res << " ";
	for (unsigned int r = 1; r <= n; r++) {
		res *= (n - (r - 1.)) / r;
		cout << res << " ";
	}
	cout << endl;
}
//3
void task3() {
	int a, sum = 0, n = 0;
	cout << "Введите последовательность чисел с числовой прямой. Конец ввода обозначить символом f.\n";
	double average;
	std::string buffer = "";
	while (buffer != "f") {
		cin >> buffer;
		if (buffer == "f") break;
		try {
			a = std::stoi(buffer);
			sum += a;
			n++;
		}
		catch (std::invalid_argument e) {
			cout << buffer << "Не является числом. Он не будет учитываться в сумме\n";
		}
	}
	average = (double)sum / n;
	cout << "Среднее значение координат: " << average << endl;
}
//4
int main(int argc, char* argv) {
	system("chcp 65001 > nul");
	char option;
	unsigned int n;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Числовой треугольник\n"
			<< "2. Нахождение биноминальных коэффициентов\n"
			<< "3. Вычисление среднего арифметического введенных точек на прямой, заданных своими координатами\n"
			<< "4. Выход\n"
			<< "Ваш выбор: ";
		cin >> option;
		switch (option)
		{
		case '1':
			cout << "Введите n [0, 15]: ";
			cin >> n;
			if (n > 15) {
				cout << "n не удовлетворяет условию\n";
				break;
			}
			task1(n);
			break;
		case '2':
			cout << "Введите n [0, 100]: ";
			cin >> n;
			if (n > 100) {
				cout << "n не удовлетворяет условию\n";
				break;
			}
			task2(n);
			break;
		case '3':
			task3();
			break;
		default:
			return 0;
		}
		system("pause");
		system("cls");
	}
} 