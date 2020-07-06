#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
    //Объявить сущность и описать её свойства (характеристики вроде роста, цвета, названия и прочего). +
	//Объявить массивы сущностей. Заполнить атрибуты числовыми и текстовыми значениями (диапазон значений определить самостоятельно).+
	// g. одежда +
	// a. автомобиль +

	//Для каждого из массивов реализовать поиск по ключу (атрибуту структуры). -
    //(В результате должны быть две отдельные функции). +
    //Для каждого из массивов реализовать сортировку по одному ключу.  +
    //(В результате должны быть две отдельные функции). +

int key;

struct Clother
{
	string name;
	string size;
	int age;
	string material;
	string color;
};

struct Car 
{
	string name;
	int speed;
	int wheels;
	int age;
	string color;
};

void randName(string &str){
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    str = "     ";


    for(int i=0; i < str.length(); i++){
        int r = rand() % (sizeof(alphabet)-1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;
}

void showClother(const Clother c){
    cout << c.name<< "\t"
         << c.size << "\t"
         << c.age << "\t"
		 << c.material << "\t"
		 << c.color << endl;
}

void showCar(const Car c){
    cout << c.name<< "\t"
         << c.speed << "\t"
         << c.wheels << "\t"
		 << c.age << "\t"
		 << c.color << endl;
}

void write2File(const Clother f[],const Car c[], const int l)
{
    ofstream file;
    file.open("Week8.txt");
		file << "Clothers_Size___Age_____Material____Color_______________________________________" << endl;
		for(int i = 0; i < l; i++){
        file << f[i].name<< "\t"
			 << f[i].size << "\t"
			 << f[i].age << "\t"
			 << f[i].material << "\t"
			 << f[i].color << endl;
		}
		file << "Cars_Speed_Wheels_Age_Color________________________________________" << endl;
		for(int i = 0; i < l; i++){
        file << c[i].name<< "\t"
			 << c[i].speed << "\t"
			 << c[i].wheels << "\t"
			 << c[i].age << "\t"
			 << c[i].color << endl;
		}
		file.close();
}

int findClothersSize(const Clother f[], const int l, string key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(f[i].size == key){
            showClother(f[i]);
            count++;
        }
    }
    return count;
}

int findClothersKey(const Clother f[], const int l, string key){
    int count = 0;
    for(int i=0; i<l; i++){
		if(f[i].material == key){
            showClother(f[i]);
            count++;
        }
    }
    return count;
}

int findCarsAge(const Car c[], const int l, int key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(c[i].age >= key){
            showCar(c[i]);
            count++;
        }
    }
    return count;
}

int findCarsKey(const Car c[], const int l, int key){
    int count = 0;
    for(int i=0; i<l; i++){
        if(c[i].age == key){
            showCar(c[i]);
            count++;
        }
    }
    return count;
}

void bubbleSortClothers(Clother f[], int len) {
    Clother tmp;
    for(int i = 0; i<len; i++){
        for(int j = len-1; j >= i+1; j--){
            if(f[j].age < f[j-1].age){
                tmp = f[j];
                f[j] = f[j-1];
                f[j-1] = tmp;
            }
        }
    }
}

void bubbleSortCars(Car cars[], int len) {
    Car tmp;
    for(int i = 0; i<len; i++){
        for(int j = len-1; j >= i+1; j--){
            if(cars[j].speed < cars[j-1].speed){
                tmp = cars[j];
                cars[j] = cars[j-1];
                cars[j-1] = tmp;
            }
        }
    }
}

std::string mascolor[10] = {"    White","    Green", "    Yellow", "    Dark", "    Violet", "    Blue", "    Purple", "    Orange", "    Pink"};
std::string masmaterial[9] = {"Coton","Paper", "Wool", "Steel", "Gold ", "Silver", "Wood", "Glass"};
std::string massize[10] = {"XS","S", "M", "L", "XL", "XXL", "XXXL", "XXXXL", "XXXXXL"};

int main()
{
	const int len = 20;
    Clother clothers[len];
	Car cars[len];
	//Одежда
	//Определение и заполнение массива одежды
	std::cout << "Clothers_Size___Age_____Material____Color_______________________________________" << endl;
    for(int i=0; i<len; i++){
        clothers[i].age = rand() % 25;
		clothers[i].material = masmaterial[rand() % 8];
		clothers[i].size = massize[rand() % 9];
		clothers[i].color = mascolor[rand() % 9];
        randName(clothers[i].name);
        showClother(clothers[i]);
    }
	//Поиск одежды по элементу
	string size = massize[rand() % 9];
    std::cout << endl << "Find all Clothers which size is " << size << endl;
    int findClothers = findClothersSize(clothers, len, size);
    std::cout << "Total " << findClothers << " elements" << endl;
	//Поиск одежды по ключу 
	cout <<"Write find Clother material ";
	string material; cin >> material;
    std::cout << endl << "Find all Clothers which material is " << material << endl;
    findClothers = findClothersKey(clothers, len, material);
    std::cout << "Total " << findClothers << " elements" << endl;
	//Сортировка одежды по возрасту
	std::cout << endl << "Sorted by age" << endl;
	bubbleSortClothers(clothers, len);
	for(int i=0; i<len; i++)
			showClother(clothers[i]);
	//Машинки
	//Определение и заполнение массива машинок
	std::cout << endl;
	std::cout << "Cars____Speed___Wheels__Age_____Color________________________________________" << endl;
    for(int i=0; i<len; i++){
        cars[i].speed = rand() % 1000;
		cars[i].wheels = 2*rand() % 50;
		cars[i].age = rand() % 100;
		cars[i].color = mascolor[rand() % 9];
        randName(cars[i].name);
        showCar(cars[i]);
    }
	//Поиск машинок по элементу
	int age = rand() % 100;
    std::cout << endl << "Find all Car which age even " << age << endl;
    int findCars = findCarsAge(cars, len, age);
    std::cout << "Total " << findCars << " elements" << endl;
	//Поиск машинок по ключу
	cout <<"Write find сars age ";
	key; cin >> key;
    std::cout << endl << "Find all Car which age " << key << endl;
    findCars = findCarsKey(cars, len, key);
    std::cout << "Total " << findCars << " elements" << endl;
	//Сортировка машинок
	std::cout << endl << "Sorted by speed " << endl;
	bubbleSortCars(cars, len);
	for(int i=0; i<len; i++)
			showCar(cars[i]);
    
	write2File(clothers,cars, len);
	


	std::getchar();
	std::getchar();
    return 0;
}



