#include <iostream>
#include <list>
#include "matrix.h"
#include "IntIterator.h"

using namespace std;

void insertAverageToList(list<float>* floatList) {
    float average = 0;
    for (float num : *floatList) {
        average += num;
    }
    floatList->push_back(average/floatList->size());
}

void print(list<float>* floatList) {
    cout << endl;
    for (float num : *floatList) {
        cout << num << " ";
    }
}

int main()
{
    //1 task
    {
        list<float> floatList{ 1.0, 2.0 };
        print(&floatList);
        insertAverageToList(&floatList);
        print(&floatList);
    }

    //2 task
    {
        float** arr = new float*[2];
        for (int i = 0; i < 3; i++) {
            arr[i] = new float[2];
        }
        int y = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i][j] = (float)(y++);
            }
        }
        for (int i = 0; i < 3; i++) {
            cout << endl;
            for (int j = 0; j < 3; j++) {
                cout << " " << arr[i][j];
            }
        }
            
        Matrix m(arr, 3);
        cout << endl << endl << m.getDeterminant() << endl;
    }

    //task3
    {
        int numbers[] = { 2,3,2,8,9 };
        IntIterator<5> intIt(numbers);

        for (IntIterator<5> it = intIt.begin(); it != intIt.end(); it++) {
            cout << " " << it.val();
        }
    }
}