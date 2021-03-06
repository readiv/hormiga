# Тестовое задание на Си++ 

## Условия задачи
На бесконечной координатной сетке находится муравей. Муравей может
перемещаться на 1 клетку вверх (x,y+1), вниз (x,y-1), влево (x-1,y),
вправо (x+1,y), по одной клетке за шаг.

Клетки, в которых сумма цифр в координате X плюс сумма цифр в
координате Y больше чем 25 недоступны
муравью. Например, клетка с координатами (59, 79) недоступна, т.к.
5+9+7+9=30, что больше 25.

Сколько клеток может посетить муравей если его начальная позиция
(1000,1000), (включая начальную клетку).

## Описание решения
Сделал в Embarcadero C++Builder 10.4

Алгоритм следующий. 

Идем влево в поисках координаты x, в которой сумма цифр будет больше 25. Так как при любом значении y сумма цифр x и y будет заведомо больше 25, то для муравья это значении x будет непреодолимой стеной.
То же самое повторяем для движения вправо, вверх и вниз. Таким образом мы определили диапазон, за который муравей никогда не выползет. 

Создаем динамический двумерный массив и заполняем его нулями и еденицами. 0 - ячейка доступна муравью. 1 - ячейка недоступна(сумма цифр координат больше 25). 2 - муравей смог сюда добраться.
Фактически в этот момент задача првращаеться в стандартную задачу заливки с 4 соседями. 

Для заливки применим следующий алгоритм. Без рекурсий и стэков. 

Записываем в начальную точку значение 2.
сбрасываем флаг завершения
Пока флаг завершения сброшен
	взводим флаг завершения
	Делаем полный проход по всей матрице. Если значение в текущей точке 0, а в соседней 2, то меняем 0 на 2 и сбрасываем флаг

Считаем число ячеек с двойками. Это и будет ответ на задачу.