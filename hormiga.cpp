#include <iostream>
#include <conio.h>
#include <cmath>

#define n_max 25
#define init_x 1000
#define init_y 1000

using namespace std;

int  sum_of_digits(int digits) {  // ���������� ����� ����� � �����
	int result = 0;
	digits = abs(digits); //  ������������� �����
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
{    // ���� ����� � ������� ���������� x, � ������� ����� ���� ����� ������ 25
	 // ��� ��� ��� ����� �������� y ����� ���� x � y ����� �������� ������ 25,
	 // �� ��� ������� ��� �������� x ����� ������������� ������.
	int x_left =  border_search(init_x, -1);
	int x_right =  border_search(init_x, 1);
	int x_n = x_right -  x_left + 1;  // ����� ��������� �� ��� x

	int y_down =  border_search(init_y, -1);
	int y_top =  border_search(init_y, 1);
	int y_n = y_top -  y_down + 1;  // ����� ��������� �� ��� y

	int **potato_field;


	cout << "\n\r x: " << x_left << " " << x_right << " x_n:" << x_n
		 << "\n\r y: " << y_down   << " " << y_top << " y_n:" << y_n
		 <<"\n\r";
	_getch();
    return 0;
}
