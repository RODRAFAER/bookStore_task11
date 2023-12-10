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

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream openFile("bookStore.txt");

	string record;
	vector <string> name;
	vector <string> author;
	vector <string> publish;
	vector <string> year;
	vector <string> price;

	string head[5] = {"Название", "Автор", "Издательство", "Год", "Цена"};
	int count = 0;


	//Заносим все слова в массивы
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

	record.clear();
	openFile.close();

	//Вычисление размеров самых длинных слов в файле
	int maxName;
	int maxAuthor;
	int maxPublish;
	int maxYear;
	int maxPrice;

	for (int i = 1; i < name.size(); i++) {
		if (name[i-1].length() > name[i].length()) {
			maxName = name[i-1].length();
		}
		else {
			maxName = name[i].length();
		}
	}

	for (int i = 1; i < author.size(); i++) {
		if (author[i - 1].length() > author[i].length()) {
			maxAuthor = author[i].length();
		}
		else {
			maxAuthor = author[i].length();
		}
	}

	for (int i = 1; i < publish.size(); i++) {
		if (publish[i - 1].length() > publish[i].length()) {
			maxPublish = publish[i - 1].length();
		}
		else {
			maxPublish = publish[i].length();
		}
	}

	for (int i = 1; i < year.size(); i++) {
		if (year[i - 1].length() > year[i].length()) {
			maxYear = year[i - 1].length();
		}
		else {
			maxYear = year[i].length();
		}
	}

	for (int i = 1; i < price.size(); i++) {
		if (price[i - 1].length() > price[i].length()) {
			maxPrice = price[i - 1].length();
		}
		else {
			maxPrice = price[i].length();
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
		string spaceAuthor(maxAuthor - head[1].length()+1, ' ');
		cout << head[1] << spaceAuthor;
		spaceAuthor.clear();
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

	int allNames = 0;
	allNames += name.size();
	int count1 = 0;

	for (int i = 0; i < allNames;i++) {
		if (name[i].length() < head[0].length()) {
			string spaceName(head[0].length() - name[i].length() + 1, ' ');
			cout << name[i] << spaceName;
		}
		else {
			cout << name[i] << " ";
		}

		if (author[i].length() < head[1].length()) {
			string spaceAuthor(head[1].length() - author[i].length() + 1, ' ');
			cout << author[i] << spaceAuthor;
		}
		else if (author[i].length() > head[1].length() && author[i].length() != maxAuthor) {
			string spaceAuthor(author[i].length() - head[1].length()+1, ' ');
			cout << author[i] << spaceAuthor;
		}
		else if (author[i].length() > head[1].length() && author[i].length() == maxAuthor) {
			cout << author[i] << " ";
		}

		if (publish[i].length() < head[2].length()) {
			string spacePublish(head[2].length() - publish[i].length() + 1, ' ');
			cout << publish[i] << spacePublish;
		}
		else {
			cout << publish[i] << " ";
		}

		if (year[i].length() < head[3].length()) {
			string spaceYear(head[3].length() - year[i].length() + 1, ' ');
			cout << year[i] << spaceYear;
		}
		else {
			cout << year[i] << " ";
		}

		if (price[i].length() < head[4].length()) {
			string spacePrice(head[4].length() - price[i].length() + 1, ' ');
			cout << price[i] << spacePrice;
		}
		else {
			cout << price[i] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}