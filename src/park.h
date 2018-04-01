/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#ifndef PARK_H
#define PARK_H

template<class T>
class Park {
	public:
		Park(const int&);					// Constructor with parameter
		Park(const Park&);					// Copy constructor

		/* Method */
		bool isEmpty();						// To check the queue is empty or not
		bool isFull();						// To check the queue already full or not
		void addElement(T element);			// Add element to park space if not full
		void removeElementAt(int index);	// Remove an element at choosen index if exist
		void printAll();					// Print all car in the park

	private:
		const int size;
		priority_queue< int, vector<int>, greater<int> > nomorQueue;
		set< pair< int, T > > data;
		map< string, vector<T> > 
		bool* used;
};

template<class T>
Park<T>::Park(const int& size) : size(size){
	used = (bool*) malloc((size+1) * sizeof(bool));
	memset(used, false, sizeof(used));
	for (int i = 1; i <= size; ++i){
		nomorQueue.push(i);
	}
}

template<class T>
Park<T>::Park(const Park& park) : size(park.size){
	this->nomorQueue = park.nomorQueue;
	this->data = park.data;
	used = (bool*) malloc(this->size * sizeof(bool));
	for (int i = 1; i <= size; ++i){
		used[i] = park.used[i];
	}
}

template<class T>
bool Park<T>::isEmpty(){
	return this->nomorQueue.size() == this->size;
}

template<class T>
bool Park<T>::isFull(){
	return this->nomorQueue.size() == 0;
}

template<class T>
void Park<T>::addElement(T element){
	if (this->isFull()){
		printf("Sorry, parking lot is full\n");
	} else {
		data.insert(make_pair(nomorQueue.top(), element));
		used[nomorQueue.top()] = 1;
		nomorQueue.pop();
	}
}

template<class T>
void Park<T>::removeElementAt(int index){
	if (this->used[index]){
		nomorQueue.push(index);
		T* temp = (T*) malloc(sizeof(T));
		data.erase(data.lower_bound(make_pair(index, *temp)));
		this->used[index] = 0;
		free(temp);
		printf("Slot number %d is free\n", index);
	} else {
		printf("Park number %d is not used\n", index);
	}
}

template<class T>
void Park<T>::printAll(){
	printf("Slot No\t\tRegistration No.\tColour\n");
	for (auto& it : this->data){
		printf("%d\t\t%d\t%d\n", it.first, it.second.first, it.second.second);
	}
}
#endif