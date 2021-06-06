#include<stdio.h>
#include<iostream>

using namespace std;

void swap(int A[], int pos1, int pos2) {
    int temp = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = temp;
}

void sortTheArray(int A[], int arraySize) {
    //A[0] to A[low -1] : contains 0,
    //A[low] to A[mid -1] : contains 1,
    //A[mid] to A[high] : contains 2,
    int low = 0, mid = 0, high = arraySize - 1;
    while(mid <= high) {
        switch(A[mid]) {
        case 0:
            swap(A, low, mid);
            low += 1;
            mid += 1;
            break;
        case 1:
            mid +=1;
            break;
        case 2:
            swap(A, mid, high);
            high -= 1;
        }
    }
}

void printTheArray(int A[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        cout << A[i] << " ";
    }
}

int main() {
 int n;
 cout << "Number of Element :" ;
 cin >> n;
 cout<< "Enter Element: " ;
 int A[n];
 for(int i = 0; i < n; i++) {
    cin >> A[i];
 }
 sortTheArray(A, n);
 printTheArray(A, n);
 return 0;
}
