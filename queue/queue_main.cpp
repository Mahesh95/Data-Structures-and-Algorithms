#include <iostream>
#include "queue.h"

using namespace std;

int main(){

	queue<char> my_name(10);

	my_name.enqueue('M');
	my_name.enqueue('a');
	my_name.enqueue('h');
	my_name.enqueue('e');
	my_name.enqueue('s');
	my_name.enqueue('h');


	while(!(my_name.is_empty())){
		cout << my_name.dequeue() << endl;
	}
	
	return 0;
}