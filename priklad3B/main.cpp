#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

void citaj(string nazov) {
	vector<string> cisla;
	string str;
	ifstream input(nazov + ".txt", ifstream::in);
	char c = input.get();
	int pocitadlo = 0;
	int s = -1;
	while (c != EOF && pocitadlo != s) {
		if (c == ',') {
			cisla.push_back(str);
			if (pocitadlo == 0) s = stoi(str);
			str = "";
			pocitadlo++;
			c = input.get();
		}
		else {
			str = str + c;
			c = input.get();
		}
	}
	input.close();
	int v = cisla.size();
	vector<int> numbers;
	//s = INT_MAX;
	srand(time(NULL));
	s = rand() % stoi(cisla.at(0));
	for (unsigned int i = 0; i < cisla.size(); i++) {
		numbers.push_back(std::stoi(cisla.at(i)));
		/*if (numbers.at(i) < s) {
			s = numbers.at(i);
			pocitadlo = i;
		}*/
	}
	cout << "Cislo na indexe " << s << " je " << numbers.at(s) << endl;
	for (unsigned int i = 0; i < numbers.size(); i++) {
		if (numbers.at(i) > numbers.at(s)) {
			cout << "Cislo vacsie ako na indexe " << s << " je " << numbers.at(i) << endl;
		}
	}
	/*cout << "Index Najvacsieho cisla v poli " << pocitadlo << endl;
	cout << "Prvy prvok " << numbers.at(0) << endl;

	int temp = numbers.at(0);
	numbers.at(0) = numbers.at(pocitadlo);
	numbers.at(pocitadlo) = temp;*/

}

int main() {
	string nazov;
	cout << "Zadajte nazov suboru" << endl;
	cin >> nazov;
	citaj(nazov);

	return 0;
}