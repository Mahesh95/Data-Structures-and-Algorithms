#include <iostream>
#include <string.h>

//returns the prefixArray of the pattern

/*
 *returns an array prefixArray
 *PrefixArray[i] = length of proper prefix which is also
 *a proper suffix of pattern[0...i].
 */

int* longestProperPrefix(char *pattern, int lengthOfPattern){
	int *prefixArray = new int[lengthOfPattern];
	prefixArray[0] = 0;
	int i,len;
	i = 1;
	len = 0; // stores the current longest length of prefix and suffix

	while(i < lengthOfPattern){
		if(pattern[i] == pattern[len]){
			prefixArray[i] = len+1;
			len++;
			i++;
		}else if(len > 0){
			//tricky part think of aacaaa and i = 5
			//also note that we do not increment i here, so when i is 2 , len is also 2, which enentually changes to 0 after 2 iterations
			len = prefixArray[len-1];

		}else{
			prefixArray[i] = 0;
			i++;
		}
	}

	return prefixArray;
}

void KMPSearch(char *text, char* pattern){
	int lengthOfPattern = strlen(pattern);
	int lengthOfText = strlen(text);

	int *lps = longestProperPrefix(pattern, lengthOfPattern);

	int i = 0;		//pointer for text
	int j = 0;		//pointer for pattern

	while(i < lengthOfText){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}

		if(j == lengthOfPattern){
			std::cout<<"pattern occured at:" << i-j << std::endl;
			j = lps[j-1]; 
		}else if(i < lengthOfText && text[i] != pattern[j]){
			if(j == 0){
				i++;
			}else{
				j = lps[j-1];
			}
		}
	}
}

int main(){

	char text[200];
	char pattern[20];

	std::cin>>pattern;
	std::cin>>text;

	KMPSearch(text, pattern);

}