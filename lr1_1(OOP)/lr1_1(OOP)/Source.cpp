#include<iostream>
#include<fstream>
#include<cstring>

#define M 20

using namespace std;

struct Trains {
	int number;
	char station[M];
	char time[M];
	char time1[M];
};

void writeFile(int N, Trains *list) {
	ofstream fileIn("TRAINS.DAT");
	for (int i = 0; i < N; i++) {
		cout << "Train " << i + 1 << ":\n" << "Number: ";
		cin >> list[i].number;
		cout << "Station: ";
		cin >> list[i].station;
		cout << "Departure time: ";
		cin >> list[i].time;
		cout << "Travel time: ";
		cin >> list[i].time1;

		fileIn.write((char *)&list[i], sizeof(list[i]));
	}
	fileIn.close();
}

void readFile(int N, Trains *list) {
	ifstream fileOut("TRAINS.DAT");
	for (int i = 0; i < N; i++) {
		fileOut.read((char *)&list[i], sizeof(list[i]));
	}
	for (int i = 0; i < N; i++) {
		if ((list[i].time[0] == '0') || (list[i].time[0] == '1') && ((list[i].time[1] < '8') && (list[i].time[1] >= '0'))) {
			cout << "\nTrain " << i + 1 << ": ";
			cout << "Number: " << list[i].number << "\n";
			cout << "Station: " << list[i].station << "\n";
			cout << "Departure time: " << list[i].time << "\n";
			cout << "Travel time: " << list[i].time1 << "\n";
		}
		
	}
	fileOut.close();
}

int main() {
	int N;
	cout << "Enter the number of trains: " << endl;
	cin >> N;
	Trains *trainList = new Trains[N];
	Trains *trainListOut = new Trains[N];
	cout << "Enter information about trains\n";
	writeFile(N, trainList);
	
	readFile(N, trainListOut);
	cout << "\n";
	system("pause");
	delete[] trainList;
	return 0;
}

