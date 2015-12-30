// Implementation of min Heap using array


void swap(int *a, int *b){
	int swap_variable = *a;
	*a = *b;
	*b = swap_variable;
}


class Heap{

	int *array;					
	int capacity;		// maximum size of heap
	int heap_size;		// current no of elements in heap

public:

	Heap(int capacity);
	int parent(int index);
	int left_child(int index);
	int right_child(int index);
	void reheapup(int index);
	void reheapdown(int index);
	int dequeue();
	void enqueue(int data);
};

Heap::Heap(int capacity){
	this->capacity = capacity;
	array = new int[capacity];
	heap_size = 0;
}

int Heap::parent(int index){
			return (index-1)/2;
}

int Heap::left_child(int index){
		return 2*index + 1;
}

int Heap::right_child(int index){
		return 2*index + 2;
} 


void Heap::reheapup(int index){
	
	if(index == 0 || array[index] > array[parent(index)]){
		return;
	}

	/*otherwise swap parent and child to retain heap property*/

	swap(&array[index], &array[parent(index)]);

	reheapup(parent(index));
}


void Heap::enqueue(int data){

	if(heap_size + 1 == capacity){
		std::cout << "overflow........." << std::endl;
		return;
	}
	
	array[heap_size++] = data;

	reheapup(heap_size-1);
}

int  Heap::dequeue(){
	if(heap_size == 0){
		return -1;
	}

	if(heap_size == 1){
		return array[heap_size--];
	}

	int element = array[0];
	array[0] = array[--heap_size];
	
	reheapdown(0);

	return element;
}

void Heap::reheapdown(int index){
	
	int smallest = index;
	
	if(left_child(index) < heap_size && array[left_child(index)] < array[smallest]){
		smallest = left_child(index);
	}

	if(right_child(index) < heap_size && array[right_child(index)] < array[smallest]){
		smallest = right_child(index);
	}

	if(smallest != index){
		swap(&array[index], &array[smallest]);
		reheapdown(smallest);
	}
}



