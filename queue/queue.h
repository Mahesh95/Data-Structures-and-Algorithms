// Queue implementation using array



// templated class for Queue

template <typename element>
class queue{

	int front,rear,capacity;
	element *array;

public:
	queue(int queue_size);
	void enqueue(element data);
	element dequeue();
	bool is_empty();
	bool is_full();
};

template <typename element> queue<element>::queue(int queue_size){
	
	front = rear = -1;
	capacity = queue_size;
	array = new element[queue_size];
}

template <typename element> bool queue<element>::is_empty(){
	return (front == -1);
}

template <typename element> bool queue<element>::is_full(){
	return (rear+1)%capacity == front;
}

template <typename element> void queue<element>::enqueue(element data){
	
	if(is_full()){
		std::cout << "queue full........." << std::endl;
		return;
	}	

	if(is_empty()){
		front = rear = 0;
		array[rear] = data;
		return;
	}

	array[++rear] = data;

	return;
}

template <typename element> element queue<element>::dequeue(){
	
	if(is_empty()){
		std::cout << "queue is empty" << std::endl;
		return 0;
	}

	element data = array[front];

	if(front == rear){
		front = rear = -1;
		return data;
	}
		
	front++;
	
	return data;
}









