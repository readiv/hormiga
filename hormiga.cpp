#include <iostream>
#include <conio.h>
#include <cmath>

#define n_max 25
#define init_x 1000
#define init_y 1000

using namespace std;

int  sum_of_digits(int digits) {  // Возвращает сумму чисел в числе
	int result = 0;
	digits = abs(digits); //  Отрицательные числа
	while (digits!=0) {
		result += digits % 10;
		digits =  digits / 10;
	}
	return result;
}

int border_search(int x,int dx) {
	while (sum_of_digits(x)<=n_max)
		x += dx;
	return x;
}

int main ()
{    // Идем влево в поисках координаты x, в которой сумма цифр будет больше 25
	 // Так как при любом значении y сумма цифр x и y будет заведомо больше 25,
	 // то для муравья это значении x будет непреодолимой стеной.
	int i, j;

	int x_left =  border_search(init_x, -1);
	int x_right =  border_search(init_x, 1);
	int x_n = x_right -  x_left + 1;  // Число элементов по оси x

	int y_down =  border_search(init_y, -1);
	int y_top =  border_search(init_y, 1);
	int y_n = y_top -  y_down + 1;  // Число элементов по оси y

	int **potato_field;
// Выделение памяти под массив и начальная инициализация нулями и единицами
	potato_field = (int**)malloc(x_n * sizeof(int*));
	for (i = 0; i<x_n; i++)
	{
		potato_field[i] = (int*)malloc(y_n * sizeof(int));
		std::memset(potato_field[i], 0, y_n * sizeof(int));
		for (j = 0; j<y_n; j++) {
			if ((sum_of_digits(x_left + i) + sum_of_digits(y_down + j)) > 25)
				potato_field[i][j] = 1;
		}
	}

	for (i = 0; i<120; i++)
	{   cout << i + x_left << "\t";
		for (j = 0; j<110; j++) {
			cout << potato_field[i][j];
		}
		cout << "\n\r";
	}

	for (i = 0; i < x_n; i++)  // Освобождение памяти
	  free(potato_field[i]);
	free(potato_field);

	cout << "\n\r x: " << x_left << " " << x_right << " x_n:" << x_n
		 << "\n\r y: " << y_down   << " " << y_top << " y_n:" << y_n
		 <<"\n\r";
	_getch();
    return 0;
}
