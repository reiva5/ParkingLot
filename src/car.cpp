#include "car.h"

Car::Car(string id, string colour){
	this->colour = colour;
	this->id = id;
}

Car::Car(const Car& otherCar){
	this->colour = otherCar.colour;
	this->id = otherCar.id;
}

Car& Car::operator=(const Car& otherCar){
	this->colour = otherCar.colour;
	this->id = otherCar.id;
	return *this;
}

string Car::getColour() const {
	return this->colour;
}

string Car::getId() const {
	return this->id;
}

void Car::setColour(string colour){
	this->colour = colour;
}

void Car::setId(string id){
	this->id = id;
}

bool operator<(const Car& A, const Car& B){
	return A.id < B.id || (A.id == B.id && A.colour < B.colour);
}

bool operator>(const Car& A, const Car& B){
	return A.id > B.id || (A.id == B.id && A.colour > B.colour);
}

bool operator==(const Car& A, const Car& B){
	return A.id == B.id && A.colour == B.colour;
}