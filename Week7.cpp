#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

int countB = 0;

void insertionSort(int * massiv, int len) 
{//Сортировка вставками
    float key = 0;
    int j = 0;
    for(int i = 1; i<len; i++)// проход по массиву
	{
        key = massiv[i];  // ключевой
        j = i - 1;//текущий элемент
        while(j >= 0 && massiv[j] > key)// перестановка элемента на нужное место
		{
            massiv[j+1] = massiv[j]; //Замена предыдущего элемента на текущий
            j = j-1; //Сдвиг сортировки на один элемент назад
            massiv[j+1] = key; 
			countB++;
        }
    }
}

void bubbleSort(int * massiv, int len) //Сортировка пузырьками
{
    float tmp = 0;
    for(int i = 0; i<len; i++) // идём по массиву
	{
        
        for(int j = len-1; j >= i+1; j--)// делаем проверки в оставшейся части массива
		{
            if(massiv[j] < massiv[j-1])// сравниваем соседние элементы
			{  
                // делаем перестановку
                tmp = massiv[j]; //Замена элементов
                massiv[j] = massiv[j-1];
                massiv[j-1] = tmp;
				countB++;
            }
        }
    }
}

void selectionSort(int * massiv, int len) {
    int j = 0;
    float tmp = 0;


    for(int i=0; i<len; i++){
        // ищем номер наименьшего элемента среди элементов от i-го до конца
        j = i;


        for(int k = i; k < len; k++){
            if(massiv[j] > massiv[k]){
                j = k;
            }
        }
        // меняем местами наибольший элемент и текущий
        tmp = massiv[i];
        massiv[i] = massiv[j];
        massiv[j] = tmp;
		countB++;
    }
}


int main()
{
	//Составить программу, которая будет считать количество действий перестановки элементов. +
	//Исследовать зависимость количества перестановок от количества элементов в массиве +-
	//(рассмотреть не менее 5-ти значений длины, например, для 100, 1000, 5000, 10000, 100000). +
	//В результате исследования должна получится сравнительная таблица для нескольких методов: +
	// b: Сортировка вставками;
	// c: Сортировка пузырьком;
	//Каждую сортировку необходимо провести не менее 3 раз (при разных стартовых значениях ГСЧ). +
	//В этом задании интересны ваши рассуждения и мысли о полученных результатах (код ведь и так есть). +-

	//Сортировка вставками. 5 значений длины. Совершить сортировка 3 раза при разных значениях.

	std::fstream f; // создаем объект класса ifstream
	f.open("Nedela7_Storage.txt",std::ios::out); // открываем файл

	for(int dlina = 10; dlina < 101; dlina = dlina*10)
	{
		for(int n = 0;n<3;n++)
		{
			
			int *massiv = new int[dlina]; //Обьявлем динамический массив 

			cout << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: insertionSort" << endl;  cout << endl;
			f << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: insertionSort" << endl;  cout << endl;
			for (int i = 0; i < dlina; i++)  {massiv[i] = rand() % dlina; }// заполняем случайными числами
			insertionSort(massiv,dlina); //Прогоняем массив через функцию сортировки вставками
			cout << "Colichestvo perestanovok " << countB << endl;f << "Colichestvo perestanovok " << countB << endl; countB = 0;
			cout << "Elementi massiva: "; f << "Elementi massiva: ";
			for (int i = 0; i < dlina; i++) {cout << massiv[i] << ";" ; f << massiv[i] << ";" ;} cout << endl; f << endl; //Документируем результат сортировки массива
			
			cout << endl; f << endl; 

			cout << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: bubbleSort" << endl; cout << endl;
			f << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: bubbleSort" << endl; cout << endl;
			for (int i = 0; i < dlina; i++)  {massiv[i] = rand() % dlina; }
			bubbleSort(massiv,dlina);//Прогоняем массив через функцию сортировки пузыпьками
			cout << "Colichestvo perestanovok " << countB << endl;f << "Colichestvo perestanovok " << countB << endl; countB = 0;
			cout << "Elementi massiva: "; f << "Elementi massiva: ";
			for (int i = 0; i < dlina; i++) {cout << massiv[i] << ";" ; f << massiv[i] << ";" ;} cout << endl; f << endl; //Документируем результат сортировки массива

			cout << endl; f << endl; 

			cout << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: selectionSort" << endl; cout << endl;
			f << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: selectionSort" << endl; cout << endl;
			for (int i = 0; i < dlina; i++)  {massiv[i] = rand() % dlina; }
			selectionSort(massiv,dlina);//Прогоняем массив через функцию сортировки выбором
			cout << "Colichestvo perestanovok " << countB << endl;f << "Colichestvo perestanovok " << countB << endl; countB = 0;
			cout << "Elementi massiva: "; f << "Elementi massiva: ";
			for (int i = 0; i < dlina; i++) {cout << massiv[i] << ";" ; f << massiv[i] << ";" ;} cout << endl; f << endl; //Документируем результат сортировки массива

			cout << endl; f << endl; 

			delete [] massiv; // очистка памяти
			cout << endl; f << endl; 
		}
	}
	std::getchar();
	std::getchar();
    return 0;
}



