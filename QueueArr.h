#pragma once

template<typename T>
class QueueArr {
	T* que;
	int size = ; // размер массива
	int length; //длина очереди
	int head;
	int tail;
public:
	QueueArr() {
		head = 0;
		tail = -1;
		length = 0;
		que = new int[size];
	}

	~QueueArr(){
		delete[] que;
		que = nullptr;
	}
	QueueArr(const Queue& other){

	}
	void enque(T elem){
		if (length < size) {
			tail++;
			tail = tail % size;
			que[tail] = elem;
			length++;
		}
	}
	void deque(){
		/*if (length > 1) {
			head++;
			head %= size;
			length--;
		}
		else if (length == 1) {
			head = 0;
			tail = -1;
			length = 0;
		}*/
		if (!isEmpty()) {
			head++;
			head %= size;
			length--;
		}
	}
	T peek(){
		if(head>0)
			return que[head];
		else
			throw runtime_error("Queueueueueueueu peek what???? ueueu is empty");
	}
	bool isEmpty(){
		return length == 0;
	}
	int getLength(){
		return length;
	}
};