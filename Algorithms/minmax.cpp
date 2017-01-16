# include <iostream>

int findMin(int *array, int startIndex, int endIndex){
   //base case
	if(startIndex == endIndex){
		return array[startIndex];
	}

	if(startIndex + 1 == endIndex){
		if(array[startIndex] > array[endIndex]){
			return array[endIndex];
		}else{
			return array[startIndex];
		}
	}

	//divide

	int mid = (startIndex+endIndex)/2;
	int minLeft = findMin(array, startIndex, mid);
	int minRight = findMin(array, mid+1, endIndex);

	return ((minLeft < minRight) ? minLeft : minRight);
}


int main(){
	int array[] = {23,4,6,12,4,-3,5,8,13,77,9};
	std::cout << findMin(array, 0, 10);
}