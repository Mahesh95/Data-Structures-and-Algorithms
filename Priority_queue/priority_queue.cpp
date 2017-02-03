#include <iostream>
#include "minheap.h"

int main(){

	Heap<int> min_heap(20);
	min_heap.enqueue(5);
	min_heap.enqueue(2);
	min_heap.enqueue(7);
	min_heap.enqueue(1);
	min_heap.enqueue(34);
	min_heap.enqueue(9);
	min_heap.enqueue(4);
	min_heap.enqueue(55);

	while(!min_heap.isEmpty()){
		std::cout << min_heap.dequeue() << std::endl;
	}

	return 0;
}