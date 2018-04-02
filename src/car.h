#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car {
	public:
		Car(const string& id, const string& colour);			// Constructor with Parameter
		Car(const Car& otherCar);							// Copy Constructor
		Car& operator=(const Car& otherCar);				// Copy Assignment

		/* Method */
		string getColour() const;
		string getId() const;
		void setColour(string colour);
		void setId(string id);
		friend bool operator<(const Car& A, const Car& B);
		friend bool operator>(const Car& A, const Car& B);
		friend bool operator==(const Car& A, const Car& B);

	private:
		string colour;
		string id;
};

#endif