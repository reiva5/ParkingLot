#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car {
	public:
		Car(string id, string colour);		// Constructor with Parameter
		Car(const Car& otherCar);							// Copy Constructor
		Car& operator=(const Car& otherCar);				// Copy Assignment

		/* Method */
		string getColour() const;							// Get colour of a car
		string getId() const;								// Get id of a car
		void setColour(string colour);						// Set colour of a car
		void setId(string id);								// Set id of a car
		friend bool operator<(const Car& A, const Car& B);	// Implementation compare of Operator < between two cars
		friend bool operator>(const Car& A, const Car& B);	// Implementation compare of Operator > between two cars
		friend bool operator==(const Car& A, const Car& B); // Implementation compare of Operator == between two cars

	private:
		string colour;
		string id;
};

#endif