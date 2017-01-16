#include <iostream>

using namespace std;

int countInversions(int*,int,int);
int countSplitInversions(int*,int,int,int);

int main(){
	int array[] = {1,3,5,2,4,6};
	cout << countInversions(array, 0, 5) << endl;

	return 0;
}

int countInversions(int *array, int leftIndex, int rightIndex){
	int middleIndex = (leftIndex+rightIndex)/2;
	int leftInversions;
	int rightInversions;
	int splitInversions;

	if(leftIndex < rightIndex){
		leftInversions = countInversions(array, leftIndex, middleIndex);
		rightInversions = countInversions(array, middleIndex+1, rightIndex);

		splitInversions = countSplitInversions(array,leftIndex,middleIndex,rightIndex);
		return leftInversions + rightInversions + splitInversions;	
	}else{
		return 0;
	}
}

int countSplitInversions(int *array, int leftIndex, int middleIndex, int rightIndex){
	int leftArraySize = middleIndex - leftIndex + 1;
	int rightArraySize = rightIndex - middleIndex;

	int leftArray[leftArraySize];
	int rightArray[rightArraySize];

	int i,j;						//pointers for leftArray and rightArray
	int k = leftIndex;

	for(int i = 0; i < leftArraySize; i++){
		leftArray[i] = array[leftIndex + i];
	}

	for(int i = 0; i < rightArraySize; i++){
		rightArray[i] = array[middleIndex+1+i];
	}

	i = j = 0;
	int splitInversions = 0;
	
	// merge and count slpit inversions

	while(i < leftArraySize && j < rightArraySize){
		if(leftArray[i] < rightArray[j]){
			array[k] = leftArray[i++];
		}else{
			array[k] = rightArray[j++];
			splitInversions += leftArraySize-i;
		}
		k++;
	}

	//merge leftover elements from the temperory arrays

	while(i != leftArraySize){
		array[k++] = array[i++];
	}

	while(j != rightArraySize){
		array[k++] = rightArray[j++];
	}

	return splitInversions;
}