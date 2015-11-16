// Header file for implementation of stack

// Author : Mahesh Yadav

// templated class for stack

using namespace std;

template <typename element>
class stack{
	
	element *items;
	int size;
	int top;

public:
	bool is_empty();
	bool is_full();
	stack(int x);
	element get_top();
	void push(element);
	element pop();
	void show();
};

template <typename element> stack<element>::stack(int x){
	size = x;
	top = -1;
	items = new element[size];
}

template <typename element> bool stack<element>::is_empty(){
	return (top == -1);
}


template <typename element> bool stack<element>::is_full(){
	return (top == size-1);
}

template <typename element> element stack<element>::get_top(){
	

	return items[top];
}

template <typename element> void stack<element>::push(element new_element){
	if(!is_full()){
		top++;
		items[top] = new_element;
	}
	 
}

template <typename element> element stack<element>::pop(){
	if(!is_empty()){
		return items[top--];
	}
}
