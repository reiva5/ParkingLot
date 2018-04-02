/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#ifndef PARK_H
#define PARK_H

#define DEF_SIZE 10

template<class T>
class Park {
	public:
		Park();								// Constructor
		Park(const int&);					// Constructor with parameter
		Park(const Park<T>&);				// Copy constructor
		~Park();							// Destructor

		/* Method */
		bool isEmpty() const;				// To check the queue is empty or not
		bool isFull() const;				// To check the queue already full or not
		void addElement(T element);			// Add element to park space if not full
		void removeElementAt(int index);	// Remove an element at choosen index if exist
		void printAll();					// Print all car in the park
		void findCarsColourWithId(string id);	// Print a car colour with given id if exist
		void findCarsIndexWithId(string id);	// Print a car index with given id if exist
		void findCarsIdWithColour(string colour);	// Print all car id with given colour if exist
		void findCarsIndexWithColour(string colour);	// Print all car index with given colour if exist

	private:
		const int size;
		priority_queue< int, vector<int>, greater<int> > nomorQueue;
		set< pair< int, T > > data;
		map< string, set<string> > dataColourId;
		map< string, set<int> > dataColourIndex;
		map< string, string > dataIdColour;
		map< string, int > dataIdIndex;
		bool* used;
		T* cars;
};

template<class T>
Park<T>::Park() : size(DEF_SIZE){
	this->used = (bool*) malloc((size+1) * sizeof(bool));
	memset(this->used, false, sizeof(this->used));
	for (int i = 1; i <= size; ++i){
		nomorQueue.push(i);
	}
}

template<class T>
Park<T>::Park(const int& size) : size(size){
	this->used = (bool*) malloc((size+1) * sizeof(bool));
	this->cars = (T*) malloc((size+1) * sizeof(T));
	memset(this->used, false, sizeof(this->used));
	for (int i = 1; i <= size; ++i){
		nomorQueue.push(i);
	}
	printf("Created a parking lot with %d slot%c\n", size, (size > 1 ? 's' : '\0'));
}

template<class T>
Park<T>::Park(const Park& park) : size(park.size){
	this->nomorQueue = park.nomorQueue;
	this->data = park.data;
	this->used = (bool*) malloc(this->size * sizeof(bool));
	for (int i = 1; i <= size; ++i){
		this->used[i] = park.used[i];
		this->cars[i] = park.cars[i];
	}
	this->dataColourId = park.dataColourId;
	this->dataColourIndex = park.dataColourIndex;
	this->dataIdColour = park.dataIdColour;
	this->dataIdIndex = park.dataIdIndex;
}

template<class T>
Park<T>::~Park(){
	free(this->used);
}

template<class T>
bool Park<T>::isEmpty() const {
	return this->nomorQueue.size() == this->size;
}

template<class T>
bool Park<T>::isFull() const {
	return this->nomorQueue.size() == 0;
}

template<class T>
void Park<T>::addElement(T element){
	if (this->isFull()){
		printf("Sorry, parking lot is full\n");
	} else {
		this->data.insert(make_pair(nomorQueue.top(), element));
		this->used[nomorQueue.top()] = 1;
		this->cars[nomorQueue.top()] = element;
		this->dataIdColour[element.getId()] = element.getColour();
		this->dataIdIndex[element.getId()] = nomorQueue.top();
		this->dataColourId[element.getColour()].insert(element.getId());
		this->dataColourIndex[element.getColour()].insert(nomorQueue.top());
		printf("Allocated slot number: %d\n", nomorQueue.top());
		this->nomorQueue.pop();
	}
}

template<class T>
void Park<T>::removeElementAt(int index){
	if (this->used[index]){
		this->nomorQueue.push(index);
		T temp = cars[index];
		this->dataIdColour.erase(temp.getId());
		this->dataIdIndex.erase(temp.getId());
		this->dataColourId[temp.getColour()].erase(temp.getId());
		if (this->dataColourId[temp.getColour()].empty()){
			this->dataColourId.erase(temp.getColour());
		}
		this->dataColourIndex[temp.getColour()].erase(index);
		if (this->dataColourIndex[temp.getColour()].empty()){
			this->dataColourIndex.erase(temp.getColour());
		}
		data.erase(data.lower_bound(make_pair(index, temp)));
		this->cars[index] = T("","");
		this->used[index] = 0;
		printf("Slot number %d is free\n", index);
	} else {
		printf("Park number %d is not used\n", index);
	}
}

template<class T>
void Park<T>::printAll(){
	printf("Slot No\tRegistration No.\tColour\n");
	for (auto& it : this->data){
		printf("%d\t%s\t%s\n", it.first, it.second.getId().c_str(), it.second.getColour().c_str());
	}
}

template<class T>
void Park<T>::findCarsIdWithColour(string colour){
	if (this->dataColourId.find(colour) != dataColourId.end()){
		int cnt = 0;
		for (auto& it : this->dataColourId[colour]){
			printf("%s%s", (cnt++ ? ", " : ""), it.c_str());
		}
		printf("\n");
	} else {
		printf("Not found\n");
	}
}

template<class T>
void Park<T>::findCarsIndexWithColour(string colour){
	if (this->dataColourIndex.find(colour) != dataColourIndex.end()){
		int cnt = 0;
		for (auto& it : this->dataColourIndex[colour]){
			printf("%s%d", (cnt++ ? ", " : ""), it);
		}
		printf("\n");
	} else {
		printf("Not found\n");
	}
}

template<class T>
void Park<T>::findCarsColourWithId(string id){
	if (this->dataIdColour.find(id) != dataIdColour.end()){
		printf("%s\n", dataIdColour[id].c_str());
	} else {
		printf("Not found\n");
	}
}

template<class T>
void Park<T>::findCarsIndexWithId(string id){
	if (this->dataIdIndex.find(id) != dataIdIndex.end()){
		printf("%d\n", dataIdIndex[id]);
	} else {
		printf("Not found\n");
	}
}
#endif