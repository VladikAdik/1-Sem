#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void Bubblesort(int A[]) {
	for (int n = 100; n > 0; --n) {
		for (int i = 0; i < n - 1; ++i) {
			if (A[i] > A[i + 1])
				swap(A[i], A[i + 1]);
		}
	}
}

void Shakersort(int A[]) {
	for (int n = 100; n > 0; --n) {
		for (int i = 0; i < n - 1; ++i) {
			if (A[i] > A[i + 1])
				swap(A[i], A[i + 1]);
		}
		for (int i = n - 2; i > 0; --i) {
			if (A[i] < A[i - 1])
				swap(A[i], A[i - 1]);
		}
	}
}

void Combsort(int A[]) {
	int gap = 100;

	while (gap != 1) {
		gap = int(gap / 1.3);
		if (gap < 1)
			gap = 1;
		for (int i = 0; i < 100 - gap; i++) {
			if (A[i] > A[i + gap])
				swap(A[i], A[i + gap]);
		}
	}
}

void Insertsort(int A[]) {
	int key, j;

	for (int i = 0; i < 100; ++i) {
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j -= 1;
		}
		A[j + 1] = key;
	}
}

void Viewmassive(int A[]) {
	for (int i = 0; i < 100; i++)
		cout << A[i] << " ";
	cout << "\n";
}//Эта функция просто показывает массив

int main() {
	setlocale(0, "");
	
	int input = 0;
	int A[100], Ac[100];//Два массива создаётся для удобства и стабильной работы меню
	
	srand(time(0));
	
	cout << "Начальный массив:\n";
	
	for (int i = 0; i < 100; ++i)
		A[i] = -99 + rand() % 199;//1 массив

	for (int i = 0; i < 100; ++i)
		Ac[i] = A[i];//2 массив
	
	Viewmassive(A);
	cout << "\n";

	Menu: {
		for (int i = 0; i < 100; ++i)
			A[i] = Ac[i];//Массив Ac[] выступает как маска, с которой впоследствии копируется массив A[]. Вот уже над ним творятся всякие надругательства

		cout << "1. Сгенерировать новый массив\n";
		cout << "2. Отсортировать массив\n";
		cout << "3. Найти максимальный и минимальный элементы массива\n";
		cout << "4. Найти среднее значение максимального и минимального значения\n";
		cout << "5. Найти количество элементов меньших числа X\n";
		cout << "6. Найти количество элементов больших числа X\n";
		cout << "7. Поиск числа в массиве\n";
		cout << "8. Поменять местами элементы массива\n";
		cout << "9. Закончить страдания программы\n";
		cout << "Введите номер операции, которую хотите выполнить: ";
		cin >> input;
		cout << "\n";
	}//Как понятно из названия - это меню вызова заданий
	
	switch (input) {
		case 1: {
			cout << "Новый массив:\n";
			srand(time(0));
			for (int i = 0; i < 100; ++i)
			Ac[i] = -99 + rand() % 199;
			Viewmassive(A);
			cout << "\n";
			goto Menu;
		}
		
		case 2: {// Я дурачёк, и поэтому сделал возможность отсортировать массив разными способами
			cout << "Какой сортировкой вы хотите воспользоваться?:\n";
			cout << "1) Bubblesort\n";
			cout << "2) Shakersort\n";
			cout << "3) Combsort\n";
			cout << "4) Insertsort\n";
			cout << "Введите номер операции, которую хотите выполнить: ";
			cin >> input;
			cout << "\n";
			if (input == 1) {
				auto start = chrono::steady_clock::now();
				Bubblesort(A);
				auto end = chrono::steady_clock::now();
				duration<double> sec = end - start;
				Viewmassive(A);
				cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << " микросекунд\n\n";
				goto Menu;//Эта штука может показаться страшной, но на деле тут только сортировка и вывод массива. Страх появляется только из-за подсчитывания времени.
			}
			else if (input == 2) {
				auto start = chrono::steady_clock::now();
				Shakersort(A);
				auto end = chrono::steady_clock::now();
				duration<double> sec = end - start;
				Viewmassive(A);
				cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << " микросекунд\n\n";
				goto Menu;
			}
			else if (input == 3) {
				auto start = chrono::steady_clock::now();
				Combsort(A);
				auto end = chrono::steady_clock::now();
				duration<double> sec = end - start;
				Viewmassive(A);
				cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << " микросекунд\n\n";
				goto Menu;
			}
			else if (input == 4) {
				auto start = chrono::steady_clock::now();
				Insertsort(A);
				auto end = chrono::steady_clock::now();
				duration<double> sec = end - start;
				Viewmassive(A);
				cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << " микросекунд\n\n";
				goto Menu;
			}
			else {
				cout << "Братан, тут ошибочка вышла. Пропробуй ещё раз.\n\n";
				goto Menu;
			}
		}

		case 3: {
			Insertsort(A);
			int min = 100, max = -100;
			auto start = chrono::steady_clock::now();
			for (int i = 0; i < 100; i++) {
				if (A[i] > max)
					max = A[i];
				if (A[i] < min)
					min = A[i];
			}
			auto end = chrono::steady_clock::now();

			cout << "Максимальный элемент: " << max << "\nМинимальный элемент: " << min << "\n";
			cout << "Отсортированный: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n";

			min = 100;
			max = -100;
			start = chrono::steady_clock::now();
			for (int i = 0; i < 100; i++) {
				if (Ac[i] > max)
					max = A[i];
				if (Ac[i] < min)
					min = Ac[i];
			}
			end = chrono::steady_clock::now();

			cout << "Неотсортированный: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n\n";
			goto Menu;
		}

		case 4: {
			Insertsort(A);
			int max = A[99], min = A[0];
			double mid = round((max + min) / 2);
			cout << "Среднее значение: " << mid << "\n";
			
			auto start = chrono::steady_clock::now();
			int count = 0;
			for (int i = 0; i < 100; i++) {
				if (Ac[i] == mid)
					count += 1;
			}
			auto end = chrono::steady_clock::now();

			cout << "Найдено " << count << " похожих чисел. Они находятся на позициях: ";
			
			for (int i = 0; i < 100; i++) {
				if (Ac[i] == mid)
					cout << i + 1 << " ";
			}
			cout << "\nВремя поиска: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n\n";
			
			goto Menu;
		}// тут можно было объеденить эти циклы, но мне так было проще
		
		case 5: {
			int x, count = 0;
			cout << "Введите число X: ";
			cin >> x;
			
			Insertsort(A);
			for (int i = 0; i < 100; i++) {
				if (A[i] < x)
					count += 1;
			}
			cout << "Кол-во элементов меньших " << x << " = " << count << "\n\n";
			goto Menu;
		}

		case 6: {
			int x, count = 0;
			cout << "Введите число X: ";
			cin >> x;

			Insertsort(A);
			for (int i = 0; i < 100; i++) {
				if (A[i] > x)
					count += 1;
			}
			cout << "Кол-во элементов больших " << x << " = " << count << "\n\n";
			goto Menu;
		}

		case 7: {
			Insertsort(A);
			int left = -99, right = 99;
			int mid, key;

			cout << "Введите искомое число: ";
			cin >> key;
			auto start = chrono::steady_clock::now();
			while (left < right) {
				mid = (left + right) / 2;

				if (A[mid] > key)
					right = mid;
				else
					left = mid + 1;
			}
			right -= 1;
			auto end = chrono::steady_clock::now();

			if (A[right] == key)
				cout << "\nТакое число в массиве есть\n";
			else
				cout << "\nТакого числа в массиве нет\n";// Это бинарный поиск
			
			cout << "Время поиска: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n";

			start = chrono::steady_clock::now();
			bool k = false;
			for (int i = 0; i < 100; i++) {
				if (A[i] == key) {
					k = true;
				}
			}// Это поиск перебором

			end = chrono::steady_clock::now();
			cout << "Время поиска перебором: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n\n";

			goto Menu;
		}
		
		case 8: {
			int x1, x2;
			cout << "Введите 2 элемента, которые вы хотите поменять местами: ";
			cin >> x1 >> x2;
			cout << "\n";
			
			auto start = chrono::steady_clock::now();
			swap(Ac[x1 - 1], Ac[x2 - 1]);
			auto end = chrono::steady_clock::now();

			Viewmassive(Ac);

			cout << "Скорость обмена: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " наносекунд\n\n";
			
			goto Menu;
		}//здесь вообще 2 строчки рабочего кода

		default: {
			cout << "Братан, тут ошибочка вышла. Пропробуй дрогое число.\n\n";
			goto Menu;
		}

		case 9: {
			exit;
		}//Этот кейс идёт ниже дефолта, т. к. при выходе программа идёт дальше вниз. Если было бы иначе, получилась бы петля.
	}

}