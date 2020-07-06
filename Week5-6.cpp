#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
	std::fstream file; // создаем объект класса ifstream
	file.open("Week5-6.txt",std::ios::out); // открываем файл
	//file<<""<<std::endl;

	int arr[10]; //Массив
	int Exercise2i = 0; //Сумма меньше 4
	int Exercise2c = 0; //Сумма больше 3
	int Exercise6max = 0; int Exercise6indexmax = 0; //Максимальное чило в массиве
	int Exercise6min = 10; int Exercise6indexmin = 0; //Минимальное чило в массиве
	int Exercise5max = 0; int Exercise5indexmax = 0; //Номер максимального числа
	int Exercise5min = 10; int Exercise5indexmin = 0;//Номер минимального числа
	int Zadannoechislo = 0; int Kollichestvo = 0; std::cin >> Zadannoechislo; // Ввод заданного числа для задания 10
	int Exercise14 = 0; //Задание 14
	for(int i=0; i<10; i++)
	{
       arr[i] = rand() % 10; //Задание 1. Заполнить массив случайными чисами в диапазоне от 0 до 10.
	   //Вычислить сумму элементов массива,
	   if (arr[i] < 4) { Exercise2i +=arr[i]; }; //меньших 4.
	   if (arr[i] > 3) { Exercise2c +=arr[i]; }; //больших 3.
	   //Задание 6. Найти номер минимального/максимального по модулю элемента
	   if (abs(arr[i]) > Exercise6max) { Exercise6max = arr[i]; Exercise6indexmax=i; };
	   if (abs(arr[i]) < Exercise6min) { Exercise6min = arr[i]; Exercise6indexmin=i; };
	   //Задание 5. Найти наибольший/наименьший элемент массива и его номер по порядку
	   if (arr[i] > Exercise5max) { Exercise5max = arr[i]; Exercise5indexmax=i; }; //Наибольший элемент массива и его номер
	   if (arr[i] < Exercise5min) { Exercise5min = arr[i]; Exercise5indexmin=i; }; //Наименьший элемент массива и его номер
	   //Задание 10. Посчитать количество (и вывести на экран) элементов массива, больших заданного числа
	   if (arr[i] > Zadannoechislo) { Kollichestvo++; }; 
	   //Задание 12. Увеличить все нечётные элементы массива на 3, а чётные в 2 раза
	   if (arr[i] % 2 == 0) {arr[i]=arr[i]*2;} else {arr[i]+=3;}
	   //Задание 14. Найти наибольший элемент массива среди элементов с чётными индексами.
	   if (i % 2 == 0) {if (arr[i] > Exercise14) { Exercise14 = arr[i];} }

	}
	std::cout << Kollichestvo << std::endl;
	file<<"Exercise2i "<<Exercise2i<<std::endl;
	file<<"Exercise2c "<<Exercise2c<<std::endl;
	file<<"Zadanie6 "<<"Max_index "<<Exercise6indexmax<<" Min_index "<<Exercise6indexmin<<::endl;
	file<<"Zadanie5 "<<"Max "<<Exercise5max<<" index "<<Exercise5indexmax<<" Min "<<Exercise5min<<" index "<<Exercise5indexmin<<::endl;
	file<<"Zadanie10 "<<Kollichestvo<<std::endl;
	file<<"Zadanie14 "<<Exercise14<<std::endl;

	std::getchar();
	std::getchar();
	return 0;
}

