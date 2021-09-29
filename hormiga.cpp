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
int main ()
{
	cout << sum_of_digits(123456789);
	_getch();
    return 0;
}
