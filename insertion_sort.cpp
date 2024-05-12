#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size, int& comparisions){

    int i , key , j;
    for(int i = 0; i < size; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j]>key){
            comparisions++;
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int size;
    cout<<"Enter the size of the array:"; 
    cin>>size;
    int arr[size];
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    int comparisions = 0;

    insertion_sort(arr, size, comparisions);

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
}
cout<<"\nNumber of comparisons made : "<<comparisions;
    return 0;
}