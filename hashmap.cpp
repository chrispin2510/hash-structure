#include <iostream>

using std::cout;
using std::endl;

const int SIZE = 10;

// hashing function f: K -> L
int hash(int key)
{
    return (key % SIZE);
}

int probe(int (&H)[SIZE], int key)
{
    int index = hash(key);
    int i = 1;

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
    int HT[SIZE] = {0};         // init hash-table with 0s

    insert(HT,22);
    insert(HT,25);
    insert(HT,35);
    insert(HT,26); 

    display(HT);
}