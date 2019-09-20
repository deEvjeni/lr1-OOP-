#include<iostream>
#include<fstream>
#include<cstring>

#define M 20
#define K 64

using namespace std;

void writeFile(int N) {
	ofstream fileIN("shops.txt");
	int num, kat;
	char name[M], loc[M];
	for (int i = 1; i <= N; i++) {
		cout << "\nShop " << i << ":\n" << "Number: ";
		cin >> num;
		fileIN << "Number: " << num << endl;
		cout << "Name: ";
		cin >> name;
		fileIN << "Name: " << name << endl;
		cout << "Location: ";
		cin >> loc;
		fileIN << "Location: " << loc << endl;
		cout << "Kategory: ";
		cin >> kat;
		fileIN << "Kategory: " << kat << endl;
	}
	fileIN.close();
}


void readFile(int N) {
	ifstream fileOUT("shops.txt");
	char one[K], two[K], three[K], four[K];
	char str[M] = "1";
	for (int i = 1; i <= N; i++) {
		fileOUT.getline(one, sizeof(one));
		fileOUT.getline(two, sizeof(two));
		fileOUT.getline(three, sizeof(three));
		fileOUT.getline(four, sizeof(four));
		if (strpbrk(four, str)) {
			cout << "\nShop " << i << ": " << endl;
			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
			cout << four << endl;
		}

	}
	fileOUT.close();
}

int main() {
	int N;
	cout << "\nEnter the number of shops: " << endl;
	cin >> N;
	cout << "\nKategory:\n" << "01 - Products\n" << "02 - Food\n" << "03 - Universal\n";
	cout << "\nEnter information about shops:\n";
	writeFile(N);
	cout << "\n";
	readFile(N);
	cout << "\n";
	system("pause");
	return 0;
}

