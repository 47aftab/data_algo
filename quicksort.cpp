#include <iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    swap(arr[i+1], arr[end]);
    return i+1;
}
}

void quick_sort(int arr[], int start, int end){
    if( start < end){
        int pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot-1);
        quick_sort(arr, pivot+1, end);
    }
}

int main()
{
	int s;
    cout << "Enter the array size ";
    cin >> s;
    int arr[s];
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, s-1);
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


