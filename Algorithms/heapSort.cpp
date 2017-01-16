#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


// this method heapifies a subtree given the root index

void maxHeapify(int *array, int root, int lastIndex){
	int largest = root;
	int leftChild = 2*root+1;
	int rightChild = 2*root+2;

	if(leftChild < lastIndex && array[largest] < array[leftChild])
		largest = leftChild;
	
	if(rightChild < lastIndex && array[largest] < array[rightChild])
		largest = rightChild;

	if(largest != root){
		swap(&array[root], &array[largest]);
		maxHeapify(array,largest,lastIndex);
	}
}

/* this function max heapifies an array of given size 
*/

void maxHeapifyArray(int *array, int lastIndex){

	//heapify all subtrees starting from the deepest subtree

	for(int i = (lastIndex/2)-1; i >=0; i--){
		maxHeapify(array, i, lastIndex);
	}

}

int main(){
	int array[] = {0,1,5,34,4,25,7,45};
	maxHeapifyArray(array, 7);
	int size = 8;

	for(int i = size-1; i>=0; i--){
		swap(&array[i], &array[0]);
		maxHeapify(array, 0, i);
	}

	for(int i = 0; i < size; i++){
		cout<<array[i] << endl;
	}

}