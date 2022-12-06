#include <iostream>

using namespace std;

const int SIZE = 10;
void add(int arr[]) {
	srand(time(0));	
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 20;		
	}
}
void print(int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

/*
	Написать функцию, определяющую минимум
	и максимум (значение и номер) элементов передаваемого
	ей массива.
*/
void f1(int arr[], int s) {
	int max = arr[0], imax;
	int min = arr[0], imin;

	for (int i = 1; i < s; i++) {
		if (min > arr[i]) {
			min = arr[i];
			imin = i;
		}
		if (max < arr[i]) {
			max = arr[i];
			imax = i;
		}
	}
	cout << "Maximum -> " << max << " his index -> " << imax
		<< endl << "Minimum -> " << min << " his index -> " << imin << endl;
}
/*
	Написать функцию, меняющую порядок следования элементов передаваемого
	ей массива на противоположный.
*/
void f2(int arr[]) {
	int temp;
	for (int i = 0, j = SIZE-1; i < j; i++, j--) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
/*
	Написать функцию, возвращающую количество простых чисел
	в передаваемом ей массиве.
*/
int f3(int arr[]) {
	int count = 0;
	int j;
	for (int i = 0; i < SIZE; i++) {
		for (j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) break;
		}
		if (j == arr[i] || arr[i] == 1) count++;
	}
	return count;
}
/*
	Дан массив чисел размерностью 10 элементов.Написать функцию,
	которая сортирует массив по возрастанию или по убыванию,
	в зависимости от третьего параметра функции. Если он равен true, сортировка
	идет по убыванию, если false, то по возрастанию.
	Первые 2 параметра функции — это массив и его размер, третий
	параметр по умолчанию равен false.
*/
void f4(int arr[], int s, bool flag = false) {
	if (!flag) {
		// сортировка пузырьком по возрастанию
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	else {
		// сортировка пузырьком по убыванию
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s - 1; j++) {
				if (arr[j] < arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}

/*
Написать функцию, которая сортирует первую
половину массива по убыванию, а вторую — по возрастанию,
используя сортировку простыми вставками.
*/

void f5(int arr[]) {
	// сортировка вставками
	int x, j;
	for (int i = 0; i < SIZE; i++) {
		x = arr[i];
		if (i < SIZE / 2) {
			// цикл для поиска места элемента в готовой последовательности
			for (j = i - 1; j >= 0 && arr[j] < x; j--) {
				// сдвиг элемента направо
				arr[j + 1] = arr[j];
			}
		}
		else {
			for (j = i - 1; j >= SIZE/2 && arr[j] > x; j--) {
				// сдвиг элемента направо
				arr[j + 1] = arr[j];
			}
		}
		arr[j + 1] = x;
	}
}
int main()
{
	int arr[SIZE];
	add(arr);
	print(arr);

	//f1(arr, SIZE);
	//f2(arr);
	//print(arr);
	//cout << f3(arr);
	//f4(arr, SIZE, true);
	//f5(arr);
	print(arr);



	/*
	В функцию передаётся массив случайных
	чисел в диапазоне от -20 до +20. Необходимо найти позиции крайних
	отрицательных элементов (самого левого отрицательного элемента и 
	самого правого отрицательного элемента) и отсортировать элементы, находящиеся
	между ними.
	*/
  
}
