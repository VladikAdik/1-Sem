#include <iostream>
using namespace std;

int main() {
	//////////////// Задание 1://////////////////
	setlocale(0, "");
	cout << "////////////Задание 1:////////////" << "\n";
	
	cout << "int: " << sizeof(int) << "\n";
	cout << "short int: " << sizeof(short) << "\n";
	cout << "long int: " << sizeof(long int) << "\n";
	cout << "float: " << sizeof(float) << "\n";
	cout << "double: " << sizeof(double) << "\n";
	cout << "long double: " << sizeof(long double) << "\n";
	cout << "char: " << sizeof(char) << "\n";
	cout << "bool: " << sizeof(bool) << "\n";
	
	//////////////// Задание 2://////////////////
	
	cout << "\n" <<  "////////////Задание 2:////////////" << "\n";
	cout << "Введите значение: ";
	
	int num;
	cin >> num;

	int a = 32; // Эта переменная отвечает за разряды
	int mask = 1 << a - 1;
	
	for (int i = 0; i < a; i++) {
		if (i == 1 || i % 8 == 0)
			cout << " ";
		cout << (num & mask ? '1' : '0');
		num <<= 1;
	}

	//////////////// Задание 3://////////////////

	cout << "\n" << "\n" << "////////////Задание 3:////////////" << "\n";
	cout << "Введите значение: ";

	union {
		int num2;
		float float_num;
	};

	cin >> float_num;

	int a1 = 32; // Эта переменная отвечает за разряды
	int mask1 = 1 << a1 - 1;

	for (int i = 0; i < a1; i++) {
		if (i == 1 || i % 8 == 0)
			cout << " ";
		cout << (num2 & mask1 ? '1' : '0');
		num2 <<= 1;
	}
	cout << "\n" << "  |<--------Мантисса------->|<Экспонента>|";

	//////////////// Задание 4://////////////////

	cout << "\n" << "\n" << "////////////Задание 4:////////////" << "\n";
	cout << "Введите значение: ";

	union {
		double dub_num;
		int num3[2];
	};

	cin >> dub_num;

	int a2 = 32; // Эта переменная отвечает за разряды
	int mask2 = 1 << a2 - 1;

	for (int i = 0; i < a2; i++) {
		if (i == 1 || i % 8 == 0 || i == 12)
			cout << " ";
		cout << (num3[1] & mask2 ? '1' : '0');
		num3[1] <<= 1;
	} // Работает с первыми 4 битами

	for (int i = 0; i < a2; i++) {
		if (i % 8 == 0)
			cout << " ";
		cout << (num3[0] & mask2 ? '1' : '0');
		num3[0] <<= 1;
	} // Работает со вторыми 4 битами
	
	cout << "\n" << "  |<Экспонента>|<------------------------Мантисса------------------------->|";
}