#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

int countB = 0;

void insertionSort(int * massiv, int len) 
{//���������� ���������
    float key = 0;
    int j = 0;
    for(int i = 1; i<len; i++)// ������ �� �������
	{
        key = massiv[i];  // ��������
        j = i - 1;//������� �������
        while(j >= 0 && massiv[j] > key)// ������������ �������� �� ������ �����
		{
            massiv[j+1] = massiv[j]; //������ ����������� �������� �� �������
            j = j-1; //����� ���������� �� ���� ������� �����
            massiv[j+1] = key; 
			countB++;
        }
    }
}

void bubbleSort(int * massiv, int len) //���������� ����������
{
    float tmp = 0;
    for(int i = 0; i<len; i++) // ��� �� �������
	{
        
        for(int j = len-1; j >= i+1; j--)// ������ �������� � ���������� ����� �������
		{
            if(massiv[j] < massiv[j-1])// ���������� �������� ��������
                // ������ ������������
                tmp = massiv[j]; //������ ���������
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
        // ���� ����� ����������� �������� ����� ��������� �� i-�� �� �����
        j = i;


        for(int k = i; k < len; k++){
            if(massiv[j] > massiv[k]){
                j = k;
            }
        }
        // ������ ������� ���������� ������� � �������
        tmp = massiv[i];
        massiv[i] = massiv[j];
        massiv[j] = tmp;
		countB++;
    }
}


int main()
{
	//��������� ���������, ������� ����� ������� ���������� �������� ������������ ���������. +
	//����������� ����������� ���������� ������������ �� ���������� ��������� � ������� +-
	//(����������� �� ����� 5-�� �������� �����, ��������, ��� 100, 1000, 5000, 10000, 100000). +
	//� ���������� ������������ ������ ��������� ������������� ������� ��� ���������� �������: +
	// b: ���������� ���������;
	// c: ���������� ���������;
	//������ ���������� ���������� �������� �� ����� 3 ��� (��� ������ ��������� ��������� ���). +
	//� ���� ������� ��������� ���� ����������� � ����� � ���������� ����������� (��� ���� � ��� ����). +-

	//���������� ���������. 5 �������� �����. ��������� ���������� 3 ���� ��� ������ ���������.

	std::fstream f; // ������� ������ ������ ifstream
	f.open("Nedela7_Storage.txt",std::ios::out); // ��������� ����

	for(int dlina = 10; dlina < 101; dlina = dlina*10)
	{
		for(int n = 0;n<3;n++)
		{
			
			int *massiv = new int[dlina]; //�������� ������������ ������ 

			cout << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: insertionSort" << endl;  cout << endl;
			f << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: insertionSort" << endl;  cout << endl;
			for (int i = 0; i < dlina; i++)  {massiv[i] = rand() % dlina; }// ��������� ���������� �������
			insertionSort(massiv,dlina); //��������� ������ ����� ������� ���������� ���������
			cout << "Colichestvo perestanovok " << countB << endl;f << "Colichestvo perestanovok " << countB << endl; countB = 0;
			cout << "Elementi massiva: "; f << "Elementi massiva: ";
			for (int i = 0; i < dlina; i++) {cout << massiv[i] << ";" ; f << massiv[i] << ";" ;} cout << endl; f << endl; //������������� ��������� ���������� �������
			
			cout << endl; f << endl; 

			cout << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: bubbleSort" << endl; cout << endl;
			f << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: bubbleSort" << endl; cout << endl;
			for (int i = 0; i < dlina; i++)  {massiv[i] = rand() % dlina; }
			bubbleSort(massiv,dlina);//��������� ������ ����� ������� ���������� ����������
			cout << "Colichestvo perestanovok " << countB << endl;f << "Colichestvo perestanovok " << countB << endl; countB = 0;
			cout << "Elementi massiva: "; f << "Elementi massiva: ";
			for (int i = 0; i < dlina; i++) {cout << massiv[i] << ";" ; f << massiv[i] << ";" ;} cout << endl; f << endl; //������������� ��������� ���������� �������

			cout << endl; f << endl; 

			cout << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: selectionSort" << endl; cout << endl;
			f << "Nomer Sortirovki " << n+1 << " ___ " << "Tip sortirovki: selectionSort" << endl; cout << endl;
			for (int i = 0; i < dlina; i++)  {massiv[i] = rand() % dlina; }
			selectionSort(massiv,dlina);//��������� ������ ����� ������� ���������� �������
			cout << "Colichestvo perestanovok " << countB << endl;f << "Colichestvo perestanovok " << countB << endl; countB = 0;
			cout << "Elementi massiva: "; f << "Elementi massiva: ";
			for (int i = 0; i < dlina; i++) {cout << massiv[i] << ";" ; f << massiv[i] << ";" ;} cout << endl; f << endl; //������������� ��������� ���������� �������

			cout << endl; f << endl; 

			delete [] massiv; // ������� ������
			cout << endl; f << endl; 
		}
	}
	std::getchar();
	std::getchar();
    return 0;
}



