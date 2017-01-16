#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* array, int firstIndex, int lastIndex, int pivot){
	int pivotElement = array[pivot];

	int k = firstIndex-1;
	int j;
	for(int i = firstIndex; i <= lastIndex; i++){
		if(array[i] < pivotElement){
			k++;
			swap(&array[k], &array[i]);
		}
	}
	swap(&array[pivot], &array[k+1]);

	return k+1;
}


int nthOrderStatistic(int* array, int firstIndex, int lastIndex, int i){
	int pivot = firstIndex + rand()%(lastIndex-firstIndex+1);
	int j =  partition(array,firstIndex,lastIndex,pivot);
	if(j == i-1){
		return array[j];
	}else{
		if(j < i-1){
			return nthOrderStatistic(array, j+1, lastIndex, i);
		}else{
			return nthOrderStatistic(array, firstIndex, j, i);
		}
	}
}

int main(){
	int array[] = {1,2,9,4,14,7,3,39};
	cout <<nthOrderStatistic(array,0,7,6);
	return 0;
}