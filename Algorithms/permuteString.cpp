#include <iostream>
using namespace std;

void swap(char * const a, char * const b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permuteString(char * const str, int leftIndex, int rightIndex){
	if(leftIndex == rightIndex){
		cout << str << endl;
	}else{
		for(int i = leftIndex; i <= rightIndex; i++){
			swap((str+leftIndex), (str+i));
			permuteString(str, leftIndex+1, rightIndex);
			swap((str+leftIndex),(str+i));
		}
	}
}

int main(){
	char str[100];
	cout << "enter string:";
	cin >> str;
	int length;
	for(length = 0; str[length] != '\0'; length++);
	permuteString(str,0,length-1);
}

