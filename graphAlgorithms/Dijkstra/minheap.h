#ifndef MINHEAP_H
#define MINHEAP_H
#include "compareFn.h"

/* Implementation of templated min heap, function for comparision of the templated type
** should be implemented in compareFn.h file.
*/

template <typename type>
class Heap{
	
	type *array;
	int capacity;		// maximum size of heap
	int heap_size;		// current no of elements in heap
	void swap(int index1, int index2);

public:

	Heap(int capacity);
	int indexOf(type);
	type getElementAt(int index);
	void decreaseKey(int index, int newVal);
	int parent(int index);
	int left_child(int index);
	int right_child(int index);
	void reheapup(int index);
	void reheapdown(int index);
	type dequeue();
	void enqueue(type data);
	bool isEmpty();
	bool isFull();
};


template <typename type>
Heap<type>::Heap(int capacity){
	this->capacity = capacity;
	array = new type[capacity];
	heap_size = 0;
}

template <typename type>
bool Heap<type>::isFull(){
	return (this->heap_size == this->capacity);
}

template <typename type>
bool Heap<type>::isEmpty(){
	return this->heap_size == 0;
}

template <typename type>
void Heap<type>::swap(int index1, int index2){
	type swapVar = this->array[index1];
	this->array[index1] = this->array[index2];
	this->array[index2] = swapVar;
}

template <typename type>
int Heap<type>::parent(int index){
			return (index-1)/2;
}

template <typename type>
int Heap<type>::left_child(int index){
		return 2*index + 1;
}

template <typename type>
int Heap<type>::right_child(int index){
		return 2*index + 2;
} 

template <typename type>
void Heap<type>::reheapup(int index){
	
	if(index == 0 || isGreater(array[index], array[parent(index)])){
		return;
	}

	/*otherwise swap parent and child to retain heap property*/

	swap(index, parent(index));

	reheapup(parent(index));
}

template <typename type>
void Heap<type>::enqueue(type data){
	
	if(isFull()){
		return;
	}
	
	array[heap_size++] = data;

	reheapup(heap_size-1);

	/*for(int i = 0; i < heap_size; i++){
		std::cout << this->array[i] << " "; 
	}

	std::cout << std::endl;
	*/
}

template <typename type>
type Heap<type>::dequeue(){
	if(isEmpty()){
		return NULL;
	}

	if(heap_size == 1){
		return array[--heap_size];
	}

	type element = array[0];
	array[0] = array[--heap_size];
	
	reheapdown(0);

	return element;
}

template <typename type>
void Heap<type>::reheapdown(int index){
	
	int smallest = index;
	
	if(left_child(index) < heap_size && isGreater(array[smallest], array[left_child(index)])){
		smallest = left_child(index);
	}

	if(right_child(index) < heap_size && isGreater(array[smallest], array[right_child(index)])){
		smallest = right_child(index);
	}

	if(smallest != index){
		swap(index, smallest);
		reheapdown(smallest);
	}
}

template <typename type>
int Heap<type>::indexOf(type element){
	for(int i = 0; i < this->heap_size; i++){
		if(this->array[i].equals(element)){
			return i;
		}
	}

	return -1;
}

template <typename type>
type Heap<type>::getElementAt(int index){
	if(index < 0 || index >= this->heap_size){
		throw "invalid index";
	}

	return this->array[index];
}

template <typename type>
void Heap<type>::decreaseKey(int index, int newVal){
	
	if(index < 0 || index >= heap_size){
		throw "invalid index";
	}

	//setVal function should be defined in compareFn.h
	setVal(this->array[index], newVal);

	reheapup(index);
}


#endif

