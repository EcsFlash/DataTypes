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
	}
	QueueArr(const Queue& other){

	}
	void enque(T elem){
		tail++;
		tail = tail % size;
		que[tail] = elem;
		length++;
	}
	void deque(){
		if (length > 1) {
			head++;
			head% = size;
			length--;
		}
		else if (length == 1) {
			head = 0;
			tail = -1;
			length = 0;
		}
	}
	T peek(){
		return *que;
	}
	bool isEmpty(){
		return length == 0;
	}
	int getLength(){
		return length;
	}
};