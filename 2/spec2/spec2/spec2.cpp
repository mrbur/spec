#include <iostream>
#include <vector>
#include <algorithm> 
#include <fstream>
#include <sstream>

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
        const string name = "book";
        string line;
        int count_if_count_find = 0;
        int count_if_count_for = 0;
        int for_count_find = 0;
        int for_count_for = 0;


        ifstream book(name);

        if ((book).is_open()) {
            while (!book.eof()) {
                book >> line;
                
                count_if_count_find += count_if(line.begin(), line.end(), isVowel);

                count_if_count_for += count_if(line.begin(), line.end(), [](char c) {
                    for (size_t i = 0; i < vowelsChars.size(); i++) {
                        if (vowelsChars[i] == c) return true;
                    }
                    return false;
                    });

                for (size_t i = 0; i < line.size(); i++) {
                    if (vowelsChars.find(line[i]) != -1) {
                        for_count_find++;
                    }
                }

                for (size_t i = 0; i < line.size(); i++) {
                    for (size_t j = 0; j < vowelsChars.size(); j++) {
                        if (line[i] == vowelsChars[j]) {
                            for_count_for++;
                            break;
                        }
                    }
                }
            }
        }

        cout << endl << endl << "count_if_count_find = " << count_if_count_find << endl;
        cout << endl << endl << "count_if_count_for = " << count_if_count_for << endl;
        cout << endl << endl << "for_count_find = " << for_count_find << endl;
        cout << endl << endl << "for_count_for = " << for_count_for << endl;
    }
}

