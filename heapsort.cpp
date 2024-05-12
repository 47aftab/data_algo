#include <iostream>
using namespace std;

void heapify(int arr[], int s, int i)
{
	int largest = i;

	int l = 2 * i + 1;

	int r = 2 * i + 2;
	
	if (l < s && arr[l] > arr[largest])
		largest = l;

	if (r < s && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, s, largest);
	}
}


void heapSort(int arr[], int s)
{
	for (int i = s / 2 - 1; i >= 0; i--)
		heapify(arr, s, i);

	for (int heap_size = s - 1; heap_size > 0; heap_size--) {
		swap(arr[0], arr[heap_size]);
		heapify(arr, heap_size, 0);
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
    heapSort(arr, s);
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// void heapify1(int arr[], int n, int i){
	
// 	int largest = i;
// 	int left = 2*i;
// 	int right = 2*i+1;

// 	if(left < n && arr[largest] < arr[left]){
// 		largest = left;
// 	}

// 	if(right < n && arr[largest] > arr[right]){
// 		largest = right;
// 	}

// 	if(largest != i){
// 		swap(arr[largest], arr[i]);
// 		heapify1(arr, n, largest);
// 	}



// }




