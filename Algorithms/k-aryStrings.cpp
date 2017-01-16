#include <iostream>
using namespace std;

void permuteChars(char* string, int length, char* permutationString){
	if(length < 1){
		cout << permutationString << endl;
	}else{
		for(int i = 0; string[i] != '\0'; i++){
			permutationString[length - 1] = string[i];
			permuteChars(string, length-1, permutationString);
		}
	}
}

int main(){
	char string[3] = {'a','b','c'};
	char permutationString[4];
	permutationString[4] = '\0';
	permuteChars(string, 4, permutationString);

	return 0;
}