#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFile(char* fileName);
void writeInFile(char* fileName);
void findByHeightAndWeight(char *fileName, int height, int weight);
void writeToStart(char* fileName);

int main() {
    char fileName[] = "D:\\file.txt";

    int n;
    cout << "Inputn N: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        writeInFile(fileName);
    }

    readFile(fileName);
   
    int height, weight;
    cout << "Input height: ";
    cin >> height;
    cout << "Input weight: ";
    cin >> weight;

    findByHeightAndWeight(fileName, height, weight);

    readFile(fileName);
    
    writeToStart(fileName);

    readFile(fileName);
}

void writeInFile(char* fileName) {
    cout << "Write new record:\n";

    char name1[50];
    char name2[50];
    char name3[50];
    char year[50];
    char height[50];
    char weight[50];

    cout << "Input name1: ";
    cin >> name1;
    cout << "Input name2: ";
    cin >> name2;
    cout << "Input name3: ";
    cin >> name3;
    cout << "Input birthday: ";
    cin >> year;
    cout << "Input height: ";
    cin >> height;
    cout << "Input weight: ";
    cin >> weight;

    ofstream out(fileName, ios::app);
    if (out.is_open()) {
        out <<  name1 << " " << name2 << " " << name3 << " " << endl;
        out <<  year << endl;
        out <<  height << endl;
        out <<  weight << endl;
    }
    out.close();
}

void readFile(char *fileName) {
    string line;

    ifstream in(fileName);

    cout << "FILE " << fileName;
    cout << "\n--------------------------\n";

    if (in.is_open()){
        while (getline(in, line)){
            cout << line << std::endl;
        }
    }

    cout << "--------------------------\n";

    in.close();
}

void findByHeightAndWeight(char *fileName, int height, int weight) {
    string line;
    ifstream in(fileName);

    int count = 0;
    int currentRecord = 1;
    int recordByHeight = 0;
    int recordByWeight = 0;

    if (in.is_open()) {
        while (getline(in, line)) {
            if (count == 2) {
                if (stoi(line) == height) {
                    recordByHeight = currentRecord;
                }
                count++;
            } else if (count == 3) {
                if (stoi(line) == weight) {
                    recordByWeight = currentRecord;
                }
                currentRecord++;
                count = 0;
            } else {
                count++;
            }
        }
    }

    if (recordByHeight != recordByWeight) {
        in.close();
        return;
    }

    int recordToDelete = recordByHeight;

    in.close();
    in.open(fileName);

    ofstream out("D:\\temp.txt", ios_base::trunc);

    currentRecord = 1;
    count = 0;
    if (in.is_open()) {
        while (getline(in, line)) {
            if (currentRecord != recordToDelete) {
                out << line << endl;
            }
            
            if (count == 3) {
                currentRecord++;
                count = 0;
            } else {
                count++;
            }
        }
    }

    out.close();
    in.close();

    out.open(fileName, ios_base::trunc);
    in.open("D:\\temp.txt", ios_base::in);

    if (in.is_open()) {
        while (getline(in, line)) {
            out << line << endl;
        }
    }

    out.close();
    in.close();
}

void writeToStart(char *fileName) {
    ofstream out;
    ifstream in(fileName);
    string line;

    out.open("D:\\temp.txt", ios_base::trunc);

    if (in.is_open()) {
        while (getline(in, line)) {
            out << line << endl;
        }
    }

    in.close();
    out.close();

    in.open("D:\\temp.txt");
    out.open(fileName, ios_base::trunc);
    out.close();

    int n;
    cout << "Inputn N: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        writeInFile(fileName);
    }

    out.open(fileName, ios_base::app);

    if (in.is_open()) {
        while (getline(in, line)) {
            out << line << endl;
        }
    }
}
