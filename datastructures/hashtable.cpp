#include <iostream> 
#include <list> 
#include <windows.h> 
#include <limits> 
 
using namespace std; 
 
class hashing { private: 
    int tablesize; 
    list<int>* table; 
 
public:     hashing(int size) {         tablesize = size; 
        table = new list<int>[tablesize]; 
    } 
 
    ~hashing() {         delete[] table; 
    } 
 
    int hash(int key) {         return key % tablesize; 
    } 
 
    void insert(int key) {         int index = hash(key);         table[index].push_back(key); 
    } 
 
    void display() {         for (int i = 0; i < tablesize; i++) {             cout << "Index " << i << ": "; 
            for (int key : table[i])                 cout << key << " -> "; 
            cout << "NULL" << endl; 
        } 
    } 
}; 
 
int main() {     int size, n, key; 
    char choice; 
 
    do { 
        do { 
            cout << "Enter the hash table size: "; 
            cin >> size;             if (cin.fail() || size <= 0) { 
                cout << "Invalid input. Size must be greater than 0.\n";                 cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } 
        } while (cin.fail() || size <= 0); 
 
        hashing hashTable(size); 
        cout << "----------------------------------------\n";         do { 
            cout << "Enter the number of elements to be inputted: ";             cin >> n;             if (cin.fail() || n <= 0) { 
                cout << "Invalid input. Number of elements must be greater than 0.\n";                 cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } 
        } while (cin.fail() || n <= 0); 
 
        cout << "----------------------------------------\n";         cout << "Enter the numbers:\n";         for (int i = 0; i < n; i++) { 
            do { 
                cout << "Element " << i + 1 << ": "; 
                cin >> key;                 if (cin.fail()) { 
                    cout << "Invalid input. Please enter a valid integer.\n";                     cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                } else {                     break; 
                } 
            } while (true); 
            hashTable.insert(key); 
        } 
 
        cout << "----------------------------------------\n";         hashTable.display(); 
        cout << "----------------------------------------\n";         do { 
            cout << "Repeat (Y/N)? ";             cin >> choice;             choice = tolower(choice);             if (cin.fail() || (choice != 'y' && choice != 'n')) { 
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";                 cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {                 break; 
            } 
        } while (true);         system("cls"); 
 
    } while (choice == 'y'); 
    cout << "Program Closed"; 
 
    return 0; 
} 
