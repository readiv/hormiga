#include <iostream>
#include <conio.h>
#include <cmath>

#define n_max 25
#define init_x 1000
#define init_y 1000

using namespace std;

int  sum_of_digits(int digits)    // Возвращает сумму чисел в числе
{
    int result = 0;
    digits = abs(digits); //  Отрицательные числа
    while (digits!=0)
    {
        result += digits % 10;
		digits =  digits / 10;
    }
    return result;
}

int border_search(int x,int dx)
{
    while (sum_of_digits(x)<=n_max)
        x += dx;
    return x;
}

void fill_line(int **potato_field, int x_n, int y_n)
{
    int i, j;
    int flag = 1;
    while (flag != 0)
    {
        flag = 0;
        for (j = 1; j<y_n - 1; j++)    // По краям у нас стена
            for (i = 1; i<x_n - 1; i++)
                if (potato_field[i][j] == 0) //клетка доступна
                    if (potato_field[i+1][j]==2 || potato_field[i-1][j]==2 || // До соседней муравей добрался?
							potato_field[i][j+1]==2 || potato_field[i][j-1]==2)
                    {
                        potato_field[i][j] = 2 ;
                        flag++; //
                    }
    }

}

int main ()
{
    // Идем влево в поисках координаты x, в которой сумма цифр будет больше 25
    // Так как при любом значении y сумма цифр x и y будет заведомо больше 25,
    // то для муравья это значении x будет непреодолимой стеной.
    int i, j;

    int x_left =  border_search(init_x, -1);
    int x_right =  border_search(init_x, 1);
    int x_n = x_right -  x_left + 1;  // Число элементов по оси x

    int y_down =  border_search(init_y, -1);
    int y_top =  border_search(init_y, 1);
    int y_n = y_top -  y_down + 1;  // Число элементов по оси y

//    cout << "\n\r x: " << x_left << " " << x_right << " x_n:" << x_n
//		 << "\n\r y: " << y_down   << " " << y_top << " y_n:" << y_n
//		 <<"\n\r";

// Выделение памяти под массив и начальная инициализация нулями и единицами
	int **potato_field;
	potato_field = (int**)malloc(x_n * sizeof(int*));
    for (i = 0; i<x_n; i++)
    {
        potato_field[i] = (int*)malloc(y_n * sizeof(int));
        for (j = 0; j<y_n; j++)
            potato_field[i][j] = (int) ((sum_of_digits(x_left + i) + sum_of_digits(y_down + j)) > n_max);
    }

//	for (j = 0; j<20 && j<y_n-1; j++)
//	{   cout << j + y_down << "\t";
//		for (i = 0; i<80 && i<x_n-1; i++) {
//			cout << potato_field[i][j];
//		}
//		cout << "\n\r";
//	}
//	cout << "\n\r\n\r\n\r";

    potato_field[init_x-x_left][init_y-y_down]=2;

    fill_line(potato_field, x_n, y_n);
    // Считаем двойки. Их число и будет ответом на задачу
    int n2 = 0;
    for (j = 1; j<y_n - 1; j++)    // По краям у нас стена
        for (i = 1; i<x_n - 1; i++)
            if (potato_field[i][j] == 2) //О-о-о! Муравей тут побывал.
                n2++;
    cout << "The ant will be able to visit " << n2 << " cells";

    for (i = 0; i < x_n; i++)  // Освобождение памяти
        free(potato_field[i]);
    free(potato_field);

    _getch();
    return 0;
}
