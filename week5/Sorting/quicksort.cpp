#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 100000;

void input(int *a, int size) { 
    for(int i = 0; i < size; ++i) {
        cin >> a[i];
    }
}

void output(int *a, int size) { 
    for(int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
}

void quickSort(int *tempArray, int first, int last) { 
    int middle;
    middle = tempArray[(first + last) / 2];
    int f = first, l = last;
    while (f < l) {
        while (tempArray[f] < middle) f++;
        while (tempArray[l] > middle) l--;
          if (f <= l) {
            std::swap(tempArray[f], tempArray[l]);
            f++;
            l--;
          }
    }
    if (first < l) quickSort(tempArray, first, l);
    if (f < last) quickSort(tempArray, f, last);
}

int main(){
    int size, mainArray[SIZE];
    std::cin >> size;
    input(mainArray, size);
    quickSort(mainArray, 0, size - 1);
    output(mainArray, size);
    return 0;
}