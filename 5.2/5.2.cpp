#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    float price;
    int day;
};

const int TABLE_SIZE = 10;

class HashTable {
private:
    Product* table[TABLE_SIZE];
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    int hash(string key) {
        int hashVal = 0;
        for (int i = 0; i < key.length(); i++)
            hashVal += key[i];
        return hashVal % TABLE_SIZE;
    }

    void insert(string key, Product* p) {
        int hashVal = hash(key);
        while (table[hashVal] != NULL && table[hashVal]->name != key)
            hashVal = (hashVal + 1) % TABLE_SIZE;
        table[hashVal] = p;
    }

    Product* search(string key) {
        int hashVal = hash(key);
        while (table[hashVal] != NULL && table[hashVal]->name != key)
            hashVal = (hashVal + 1) % TABLE_SIZE;
        if (table[hashVal] == NULL)
            return NULL;
        else
            return table[hashVal];
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == NULL)
                cout << "NULL" << endl;
            else
                cout << table[i]->name << " " << table[i]->price << " " << table[i]->day << endl;
        }
    }
};

int main() {
    Product products[7];
    products[0] = { "Product 1", 10.0, 1 };
    products[1] = { "Product 2", 20.0, 2 };
    products[2] = { "Product 3", 30.0, 3 };
    products[3] = { "Product 4", 40.0, 4 };
    products[4] = { "Product 5", 50.0, 5 };
    products[5] = { "Product 6", 60.0, 6 };
    products[6] = { "Product 7", 70.0, 7 };

    HashTable ht;

    for (int i = 0; i < 7; i++)
        ht.insert(products[i].name, &products[i]);

    cout << "Original array:" << endl;
    for (int i = 0; i < 7; i++)
        cout << products[i].name << " " << products[i].price << " " << products[i].day << endl;

    cout << endl << "Hash table:" << endl;
    ht.display();

    string searchKey = "Product 5";
    Product* p = ht.search(searchKey);
    if (p != NULL) {
        cout << endl << "Product found:" << endl;
        cout << p->name << " " << p->price << " " << p->day << endl;
    }
    else {
        cout << endl << "Product not found." << endl;
    }

    return 0;
}