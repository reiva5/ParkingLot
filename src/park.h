/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#ifndef PARK_H
#define PARK_H
bool isTest = false;
#define DEF_SIZE 10

template<class T>
class Park {
	public:
		Park();								// Constructor
		Park(int);							// Constructor with parameter
		Park(const Park<T>&);				// Copy constructor
		~Park();							// Destructor

		/* Method */
		bool isEmpty() const;				// To check the queue is empty or not
		bool isFull() const;				// To check the queue already full or not
		int getSize() const;				// Get number of car(s) right now
		void addElement(T element);			// Add element to park space if not full
		void removeElementAt(int index);	// Remove an element at choosen index if exist
		void printAll();					// Print all car in the park

		string getCarsColourWithId(string id);			// Get a car colour with given id if exist
		int getCarsIndexWithId(string id);				// Get a car index with given id if exist
		set<string> getCarsIdWithColour(string colour);	// Get all car id with given colour if exist
		set<int> getCarsIndexWithColour(string colour);	// Get all car index with given colour if exist

		void findCarsColourWithId(string id);			// Print a car colour with given id if exist
		void findCarsIndexWithId(string id);			// Print a car index with given id if exist
		void findCarsIdWithColour(string colour);		// Print all car id with given colour if exist
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
	this->cars = (T*) malloc((size+1) * sizeof(T));
	for (int i = 1; i <= size; ++i){
		this->used[i] = 0;
		nomorQueue.push(i);
	}
}

template<class T>
Park<T>::Park(int size) : size(size){
	this->used = (bool*) malloc((size+1) * sizeof(bool));
	this->cars = (T*) malloc((size+1) * sizeof(T));
	for (int i = 1; i <= size; ++i){
		this->used[i] = 0;
		nomorQueue.push(i);
	}
	fprintf((isTest ? stderr : stdout), "Created a parking lot with %d slot%c\n", size, (size > 1 ? 's' : '\0'));
}

template<class T>
Park<T>::Park(const Park& park) : size(park.size){
	this->nomorQueue = park.nomorQueue;
	this->data = park.data;
	this->used = (bool*) malloc((this->size+1) * sizeof(bool));
	this->cars = (T*) malloc((this->size+1) * sizeof(T));
	for (int i = 1; i <= park.size; ++i){
		this->used[i] = park.used[i];
		if (this->used[i] == 1){
			this->cars[i] = park.cars[i];
		}
	}
	this->dataColourId = park.dataColourId;
	this->dataColourIndex = park.dataColourIndex;
	this->dataIdColour = park.dataIdColour;
	this->dataIdIndex = park.dataIdIndex;
}

template<class T>
Park<T>::~Park(){
	free(this->used);
	free(this->cars);
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
int Park<T>::getSize() const {
	return this->data.size();
}

template<class T>
void Park<T>::addElement(T element){
	if (this->isFull()){
		fprintf((isTest ? stderr : stdout), "Sorry, parking lot is full\n");
	} else {
		this->data.insert(make_pair(nomorQueue.top(), element));
		this->used[nomorQueue.top()] = 1;
		this->cars[nomorQueue.top()] = element;
		this->dataIdColour[element.getId()] = element.getColour();
		this->dataIdIndex[element.getId()] = nomorQueue.top();
		this->dataColourId[element.getColour()].insert(element.getId());
		this->dataColourIndex[element.getColour()].insert(nomorQueue.top());
		fprintf((isTest ? stderr : stdout), "Allocated slot number: %d\n", nomorQueue.top());
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
		fprintf((isTest ? stderr : stdout), "Slot number %d is free\n", index);
	} else {
		fprintf((isTest ? stderr : stdout), "Park number %d is not used\n", index);
	}
}

template<class T>
void Park<T>::printAll(){
	fprintf((isTest ? stderr : stdout), "Slot No.\tRegistration No.\tColour\n");
	for (auto& it : this->data){
		fprintf((isTest ? stderr : stdout), "%d\t%s\t%s\n", it.first, it.second.getId().c_str(), it.second.getColour().c_str());
	}
}

template<class T>
set<string> Park<T>::getCarsIdWithColour(string colour){
	if (this->dataColourId.find(colour) != dataColourId.end()){
		return this->dataColourId[colour];
	} else {
		set<string> tmp;
		return tmp;
	}
}

template<class T>
set<int> Park<T>::getCarsIndexWithColour(string colour){
	if (this->dataColourIndex.find(colour) != dataColourIndex.end()){
		return this->dataColourIndex[colour];
	} else {
		set<int> tmp;
		return tmp;
	}
}

template<class T>
string Park<T>::getCarsColourWithId(string id){
	if (this->dataIdColour.find(id) != dataIdColour.end()){
		return (dataIdColour[id].c_str());
	} else {
		return "Not found";
	}
}

template<class T>
int Park<T>::getCarsIndexWithId(string id){
	if (this->dataIdIndex.find(id) != dataIdIndex.end()){
		return (dataIdIndex[id]);
	} else {
		return -1;
	}
}

template<class T>
void Park<T>::findCarsIdWithColour(string colour){
	if (getCarsIdWithColour(colour).size() > 0){
		int cnt = 0;
		for (auto& it : getCarsIdWithColour(colour)){
			fprintf((isTest ? stderr : stdout), "%s%s", (cnt++ ? ", " : ""), it.c_str());
		}
		fprintf((isTest ? stderr : stdout), "\n");
	} else {
		fprintf((isTest ? stderr : stdout), "Not found\n");
	}
}

template<class T>
void Park<T>::findCarsIndexWithColour(string colour){
	if (getCarsIndexWithColour(colour).size() > 0){
		int cnt = 0;
		for (auto& it : getCarsIndexWithColour(colour)){
			fprintf((isTest ? stderr : stdout), "%s%d", (cnt++ ? ", " : ""), it);
		}
		fprintf((isTest ? stderr : stdout), "\n");
	} else {
		fprintf((isTest ? stderr : stdout), "Not found\n");
	}
}

template<class T>
void Park<T>::findCarsColourWithId(string id){
	fprintf((isTest ? stderr : stdout), "%s\n", getCarsColourWithId(id).c_str());
}

template<class T>
void Park<T>::findCarsIndexWithId(string id){
	if (getCarsIndexWithId(id) != -1){
		fprintf((isTest ? stderr : stdout), "%d\n", getCarsIndexWithId(id));
	} else {
		fprintf((isTest ? stderr : stdout), "Not found\n");
	}
}

#endif