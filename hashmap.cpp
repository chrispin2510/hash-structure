#include <iostream>

using std::cout;
using std::endl;
using std::cin;

const int SIZE = 10;

// hashing function f: K -> L
int hash(int key)
{
    return (key % SIZE);
}

int probe(int (&H)[SIZE], int key)
{
    int index = hash(key);
    int i = 0;

    while (H[(index + i) % SIZE] != 0)
    {
        i++;
    }
    return ((index + i) % SIZE);
}

void insert(int (&H)[SIZE], int key)
{
    int index = hash(key);

    if (H[index] != 0)
    {
        index = probe(H,key);
    }
    H[index] = key;           
}

bool hash_contains(int (&H)[SIZE], int key)
{
    bool found = false;
    int index = hash(key);
    int i = 0;

    if (key == H[index])
    {
        found = true;
    }
    else 
    {
        i = (index + 1) % SIZE;

        while ((i != index) && (found == false))
        {
            if (key == H[i])
            {
                found = true;
            }
            else 
            {
                i = (++i) % SIZE;
            }
        }
    }
    return found;
}

void display(int (&H)[SIZE])
{
    for (int i=0; i<SIZE; i++)
    {
        if (H[i] != 0)
        {
            cout << H[i];
        }
        else 
        {
            cout << "_"; 
        }
        if (i < SIZE - 1)
        {
            cout << ",";
        }
    }
    cout << endl;
}

int main()
{
    int key = 0;
    int HT[SIZE] = {0};         // init hash-table with 0s

    insert(HT,22);
    insert(HT,25);
    insert(HT,35);
    insert(HT,26); 

    display(HT);

    cout << "enter key you want to search: ";
    cin >> key; 

    if (key > 0 && hash_contains(HT,key))
    {
        cout << "key present" << endl;
    }
    else 
    {
        cout << "key is not present" << endl;
    }
}