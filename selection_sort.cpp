#include <iostream>
using namespace std;

void selection_sort(int arr[], int size){
    int i, j, min;
    for(i = 0; i< size-1; i++){
        min = i;
        for(j = i+1; j < size; j++){
            if(arr[j]< arr[min]){
                min = j;
            }
        }
        if(min != i){
            swap(arr[min],arr[i]);
        }
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size];
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }

    selection_sort(arr, size);

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
}
  
    return 0;
}

