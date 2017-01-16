#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// this method returns the correct position of the rightmost element which is pivot after partitioning

int partition(int *array, int leftIndex, int rightIndex){
	int pivot = array[rightIndex];

	// j is pointing to the last element of the array which is smaller than pivot
	int j = leftIndex -1;
	for(int i = leftIndex; i < rightIndex; i++){
		if(array[i] < pivot){
			// move array[i] next to j and increment j by one
			swap(&array[i], &array[++j]);
		}
	}

	// now move pivot to its right position
	swap(&array[j+1], &array[rightIndex]);
	return j+1;
}

void quickSort(int *array, int leftIndex, int rightIndex){
	if(leftIndex < rightIndex){
		int partitionIndex = partition(array, leftIndex, rightIndex);
		quickSort(array, leftIndex, partitionIndex-1);
		quickSort(array, partitionIndex+1, rightIndex);
	}
}

int main(){

	int array[10], n;
	cout << "Enter array size:";
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> array[i];
	}

	quickSort(array,0,n-1);

	cout << "sorted array is..." << endl; 

	for(int i = 0; i < n; i++){
		cout << array[i] << endl;
	}
	
	return 0;
}