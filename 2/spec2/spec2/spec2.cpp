#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

template <typename T>
void Swap(T* a, T* b) {
    T c = *a;
    *a = *b;
    *b = c;
}

template <typename T>
void SortPointers(vector<T*> vector) {
    if (vector.size() < 2) return;

    for (size_t i = 0; i < vector.size() - 1; i++) {
        if (*vector[i] > *vector[i + 1]) {
            Swap(vector[i], vector[i + 1]);
        }
    }
}

string vowelsChars = "аеёиоуэюя";
bool isVowel(char c) {
    return vowelsChars.find(c) != -1;
}


int main()
{
    int num1 = 10;
    int num2 = 11;
    int num3 = 15;
    //task1
    {
        cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
        Swap(&num1, &num2);
        cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    }

    //task2
    {
        cout << endl;
        vector<int*> numVector = { &num1, &num2, &num3 };
        for (size_t i = 0; i < numVector.size(); i++) {
            cout << *numVector[i] << " ";
        }
        cout << endl;
        SortPointers(numVector);
        for (size_t i = 0; i < numVector.size(); i++) {
            cout << *numVector[i] << " ";
        }
    }

    //task3
    {
        string str = "Война и мир";

        cout << endl << endl << "Count = " << count_if(str.begin(), str.end(), isVowel) << endl;

        cout << "Count = " << count_if(str.begin(), str.end(), [](char c) {
            for (size_t i = 0; i < vowelsChars.size(); i++) {
                if (vowelsChars[i] == c) return true;
            }
            return false;
        })  << endl;

        int count = 0;
        for (size_t i = 0; i < str.size(); i++) {
            if (vowelsChars.find(str[i]) != -1) {
                count++;
            }
        }
        cout << "Count = " << count << endl;

        count = 0;
        for (size_t i = 0; i < str.size(); i++) {
            for (size_t j = 0; j < vowelsChars.size(); j++) {
                if (str[i] == vowelsChars[j]) {
                    count++;
                    break;
                }
            }
        }
        cout << "Count = " << count << endl;
    }
}

