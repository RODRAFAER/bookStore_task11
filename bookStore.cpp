#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::get;
using std::string;
using std::getline;
using std::ios_base;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string source;

	cout << "Укажите расположение файла: ";
	cin >> source;

	ifstream openFile(source);

	string record;
	vector <string> name;
	vector <string> author;
	vector <string> publish;
	vector <string> year;
	vector <string> price;

	string head[5] = {"Название", "Автор", "Издательство", "Год", "Цена (руб.)"};
	int count = 0;

	string nameOut;
	//Заносим все слова в массивы
	if (!openFile.is_open()) {
		cout << "Не удалось открыть файл." << endl;
		system("pause");
		return 0;
	}
	else {
		string proverka;
		getline(openFile, proverka);
		if (proverka.empty()) {
			cout << "В файле нет значений.";
			system("pause");
			return 0;
		}
		else {
			while (openFile >> record) {
				if (count == 0) {
					name.push_back(record);
				}
				else if (count == 1) {
					author.push_back(record);
				}
				else if (count == 2) {
					publish.push_back(record);
				}
				else if (count == 3) {
					year.push_back(record);
				}
				else if (count == 4) {
					price.push_back(record);
				}
				count++;
				if (count == 5) {
					count = 0;
				}

			}
		}
	}
	record.clear();
	openFile.close();

	//Вычисление размеров самых длинных слов в файле
	int maxName;
	int maxAuthor;
	int maxPublish;
	int maxYear;
	int maxPrice;
	if (name.size() == 1) {
		maxName = name[0].length();
	}
	else {
		for (int i = 1; i < name.size(); i++) {
			if (name[i - 1].length() > name[i].length()) {
				maxName = name[i - 1].length();
			}
			else {
				maxName = name[i].length();
			}
		}
	}
	
	if (author.size() == 1) {
		maxAuthor = author[0].length();
	}
	else {
		for (int i = 1; i < author.size(); i++) {
			if (author[i - 1].length() >= author[i].length()) {
				maxAuthor = author[i - 1].length();
			}
			else {
				maxAuthor = author[i].length();
			}
		}
	}

	if (publish.size() == 1) {
		maxPublish = publish[0].length();
	}
	else {
		for (int i = 1; i < publish.size(); i++) {
			if (publish[i - 1].length() > publish[i].length()) {
				maxPublish = publish[i - 1].length();
			}
			else {
				maxPublish = publish[i].length();
			}
		}
	}

	if (year.size() == 1) {
		maxYear = year[0].length();
	}
	else {
		for (int i = 1; i < year.size(); i++) {
			if (year[i - 1].length() > year[i].length()) {
				maxYear = year[i - 1].length();
			}
			else {
				maxYear = year[i].length();
			}
		}
	}

	if (price.size() == 1) {
		maxPrice = price[0].length();
	}
	else {
		for (int i = 1; i < price.size(); i++) {
			if (price[i - 1].length() > price[i].length()) {
				maxPrice = price[i - 1].length();
			}
			else {
				maxPrice = price[i].length();
			}
		}
	}



	//Вывод верхней строки на экран
	if (maxName > head[0].length()) {
		string spaceName(maxName - head[0].length()+1, ' ');
		cout << head[0] << spaceName;
		spaceName.clear();
	}
	else {
		cout << head[0] << " ";
	}


	if (maxAuthor > head[1].length()) {
		string spaceAuthor((maxAuthor - head[1].length())+1, ' ');
		cout << head[1] << spaceAuthor;
	}
	else {
		cout << head[1] << " ";
	}

	if (maxPublish > head[2].length()) {
		string spacePublish(maxPublish - head[2].length()+1, ' ');
		cout << head[2] << spacePublish;
		spacePublish.clear();
	}
	else {
		cout << head[2] << " ";
	}
	
	if (maxYear > head[3].length()) {
		string spaceYear(maxYear - head[3].length()+1, ' ');
		cout << head[3] << spaceYear;
		spaceYear.clear();
	}
	else {
		cout << head[3] << " ";
	}

	if (maxPrice > head[4].length()) {
		string spacePrice(maxPrice - head[4].length()+1, ' ');
		cout << head[4] << spacePrice;
		spacePrice.clear();
	}
	else {
		cout << head[4] << " ";
	}
	cout << endl;

	int allNames = name.size();

	for (int i = 0; i < allNames;i++) {
		if (head[0].length() <= maxName) {
			string spaceName(maxName - name[i].length() + 1, ' ');
			cout << name[i] << spaceName;
		}
		else {
			string spaceName(head[0].length() - name[i].length() + 1, ' ');
			cout << name[i] << spaceName;
		}


		if (head[1].length() <= maxAuthor) {
			string spaceAuthor(maxAuthor - author[i].length() + 1, ' ');
			cout << author[i] << spaceAuthor;
		}
		else {
			string spaceAuthor(head[1].length() - author[i].length() + 1, ' ');
			cout << author[i] << spaceAuthor;
		}

		if (head[2].length() <= maxPublish) {
			string spacePublish(maxPublish - publish[i].length() + 1, ' ');
			cout << publish[i] << spacePublish;
		}
		else {
			string spacePublish(head[2].length() - publish[i].length() + 1, ' ');
			cout << publish[i] << spacePublish;
		}


		if (head[3].length() <= maxYear) {
			string spaceYear(maxYear - year[i].length() + 1, ' ');
			cout << year[i] << spaceYear;
		}
		else {
			string spaceYear(head[3].length() - year[i].length() + 1, ' ');
			cout << price[i] << spaceYear;
		}


		if (head[4].length() <= maxPrice) {
			string spacePrice(maxPrice - price[i].length() + 1, ' ');
			cout << price[i] << spacePrice;
		}
		else {
			string spacePrice(head[4].length() - price[i].length() + 1, ' ');
			cout << price[i] << spacePrice;
		}

		cout << endl;
	}

	system("pause");
	return 0;
}