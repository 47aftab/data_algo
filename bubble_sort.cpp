#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size){
    int count = 1;
    while(count < size){
    for(int i = 0; i < size - count; i++){
        if(arr[i+1] < arr[i]){
            swap(arr[i], arr[i+1]);
        }
    }
    count++;
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
    bubble_sort(arr, size);
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
}
    return 0;
}


