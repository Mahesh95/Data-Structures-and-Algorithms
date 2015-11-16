#include <iostream>
#include "stack.h"

using namespace std;

int main(){

	stack<int> stack_1(6);

	stack_1.push(1);
	stack_1.push(6);
	stack_1.push(3);

	cout << stack_1.get_top();

	while(!(stack_1.is_empty())){
		cout << stack_1.pop() << endl;	
	}
	
}