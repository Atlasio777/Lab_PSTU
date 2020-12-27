#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string name;
    string pasport;
};

struct Bucket {
    int hash;
    vector<Node> buckets;
};

void printHashTable(vector<Bucket>& hashTable);
void insert(vector<Bucket>& hashTable, string name, string pasport);
void remove(vector<Bucket>& hashTable, string key);
void find(vector<Bucket>& hashTable, string key);
void loadFromFile(char* databaseName, vector<Bucket>& hashTable);
void save(char* fileName, vector<Bucket>& hashTable);
void countConflict(vector<Bucket>& hashTable);

int main() {
    vector<Bucket> hashTable;
    int size = 20;
    char fileName[] = "D:\\lab11.txt";

    for (int i = 0; i < 20; i++) {
        Bucket* bucket = new Bucket();
        bucket->hash = i;
        hashTable.push_back(*bucket);
    }

    int help;

    loadFromFile(fileName, hashTable);
    printHashTable(hashTable);

    cout << "\nInput N from insert: ";
    cin >> help;

    for (int i = 0; i < help; i++) {
        string name, pasport;
        cout << "\nCreate new Record\nInput name: ";
        cin >> name;
        cout << "Input pasport: ";
        cin >> pasport;
        insert(hashTable, name, pasport);
    }

    printHashTable(hashTable);

    cout << "\nInput N from delete: ";
    cin >> help;

    for (int i = 0; i < help; i++) {
        string key;
        cout << "\nDelete Record\nInput key: ";
        cin >> key;
        remove(hashTable, key);
    }

    printHashTable(hashTable);

    cout << "\nInput N from search: ";
    cin >> help;


    for (int i = 0; i < help; i++) {
        string key;
        cout << "\n\Search Record\nInput key: ";
        cin >> key;
        find(hashTable, key);
    }

    countConflict(hashTable);

    save(fileName, hashTable);
}

void insert(vector<Bucket> &hashTable, string name, string pasport) {
    Node* node = new Node();
    node->name = name;
    node->pasport = pasport;

    int hash = (node->name.length()) % (hashTable.size());

    int isContains = 0;

    for (int i = 0; i < hashTable.at(hash).buckets.size(); i++) {
        if (hashTable.at(hash).buckets.at(i).name == name) {
            isContains = 1;
            break;
        }
    }
    if (!isContains) {
        hashTable.at(hash).buckets.push_back(*node);
    }
}

void remove(vector<Bucket> &hashTable, string key) {
    int hash = key.length() % 20;
    for (int i = 0; i < hashTable.at(hash).buckets.size(); i++) {
        if (key == hashTable.at(hash).buckets.at(i).name) {
            hashTable.at(hash).buckets.erase(hashTable.at(hash).buckets.begin() + i);
        }
    }
}

void find(vector<Bucket>& hashTable, string key) {
    int hash = key.length() % 20;
    for (int i = 0; i < hashTable.at(hash).buckets.size(); i++) {
        if (key == hashTable.at(hash).buckets.at(i).name) {
            cout << " { " << hashTable.at(hash).buckets.at(i).name << " : " << hashTable.at(hash).buckets.at(i).pasport << " }";
        }
    }
}

void printHashTable(vector<Bucket>& hashTable) {
    cout << "\n------------------------------------Hastable------------------------------------";
    for (int i = 0; i < hashTable.size(); i++) {
        cout << "\nHASH = " << hashTable.at(i).hash << "   ";
        for (int j = 0; j < hashTable.at(i).buckets.size(); j++) {
            cout << " { " << hashTable.at(i).buckets.at(j).name << " : " << hashTable.at(i).buckets.at(j).pasport << " } ->";
        }
    }
    cout << "\n--------------------------------------------------------------------------------\n";
}

void loadFromFile(char* fileName, vector<Bucket>& hashTable) {
    ifstream in(fileName);

    string line, name, pasport;

    int count = 0;
    if (in.is_open()) {
        while (getline(in, line)) {
            if (count == 0) {
                name = line;
                count++;
            } else {
                pasport = line;
                count = 0;
                insert(hashTable, name, pasport);
            }
        }
    }

    in.close();
}

void save(char* fileName, vector<Bucket>& hashTable) {
    ofstream out(fileName, ios::trunc);
    if (out.is_open()) {
        for (int i = 0; i < hashTable.size(); i++) {
            for (int j = 0; j < hashTable.at(i).buckets.size(); j++) {
                out << hashTable.at(i).buckets.at(j).name << endl;
                out << hashTable.at(i).buckets.at(j).pasport << endl;
            }
        }
    }

    out.close();
}

void countConflict(vector<Bucket>& hashTable) {
    int count = 0;
    for (int i = 0; i < hashTable.size(); i++) {
        if (hashTable.at(i).buckets.size() > 1) {
            count += hashTable.at(i).buckets.size() - 1;
        }
    }

    cout << "\nFind conflicts: " << count << "\n";
}

