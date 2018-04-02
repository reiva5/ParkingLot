/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define Jehian using
#define Norman namespace
#define Saviero std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(0);}

Jehian Norman Saviero;

#include "park.h"
#include "car.h"

/* MACROS FOR TYPE */
typedef long l;
typedef long double ld;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

/* MACROS FOR PRINT */
#define nl printf("\n")
#define sp printf(" ")

/* MACROS FOR FUNCTION AND METHOD */
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define eb emplace_back
#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) for(int _je = sizeof(x)/sizeof(x[0]); _je--;) x[_je] = y
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define ALL(x) (x).begin(), (x).end()t
#define ALLSIZE(x,n) (x), (x)+(n)

/* MACROS FOR ATTRIBUTE */
#define fi first
#define se second

/* MACROS FOR SCAN */
#define scc(x) scanf("%c", &x)
#define scd(x) scanf("%Lf", &x)
#define scf(x) scanf("%f", &x)
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scld(x) scanf("%Lf", &x)
#define scui(x) sci(x)
#define scul(x) scl(x)
#define scull(x) scll(x)


int idx;
int size;
string colour;
string id;
string query;
Park< Car > parkir;

void test_for_class_park(void); // Implementation test for Class Park
void test_for_class_car(void); // Implementation test for Class Car
const string currentDateTime(); // Get Current Time with format YYYY-MM-DD.HH:mm:ss

int main(int argc, char** argv){
	if (argc == 1){
		fprintf(stderr, "Program exited because there isn't file input\n");
		exit(-1);
	}
	isTest = true;
	ifstream in(argv[1]);
	test_for_class_park();
	test_for_class_car();
	isTest = false;
	while (in >> query){
		if (query == "create_parking_lot"){
			in >> size;
			parkir.~Park();
			new(&parkir) Park<Car>(size);
		} else if (query == "park"){
			in >> id >> colour;
			parkir.addElement(Car(id,colour));
		} else if (query == "leave"){
			in >> idx;
			parkir.removeElementAt(idx);
		} else if (query == "status"){
			parkir.printAll();
		} else if (query == "registration_numbers_for_cars_with_colour"){
			in >> colour;
			parkir.findCarsIdWithColour(colour);
		} else if (query == "slot_numbers_for_cars_with_colour"){
			in >> colour;
			parkir.findCarsIndexWithColour(colour);
		} else if (query == "slot_number_for_registration_number"){
			in >> id;
			parkir.findCarsIndexWithId(id);
		}
	}
	return 0;
}


void test_for_class_park(){
	fprintf(stderr, "=============================== BEGIN OF TESTING ===============================\n");
	/* Test Constructor */
	Park < Car > p1;
	fprintf(stderr, "[%s]: Begin Test Constructor\n", currentDateTime().c_str());
	assert(p1.isEmpty());
	fprintf(stderr, "[%s]: Check is empty passed (0 = 0)\n", currentDateTime().c_str());
	assert(!p1.isFull());
	fprintf(stderr, "[%s]: Check not full passed\n", currentDateTime().c_str());
	fprintf(stderr, "[%s]: Test Constructor Passed\n", currentDateTime().c_str());

	p1.~Park();
	/* Test Constructor with Parameter */
	new(&p1) Park<Car>(100);
	fprintf(stderr, "[%s]: Begin Test Constructor with Parameter\n", currentDateTime().c_str());
	p1.addElement(Car("1","White"));
	p1.addElement(Car("2","Blue"));
	p1.addElement(Car("3","Black"));
	assert(p1.getSize() == 3);
	fprintf(stderr, "[%s]: Check p1 size == 3 passed\n", currentDateTime().c_str());
	p1.removeElementAt(1);
	assert(p1.getSize() == 2);
	fprintf(stderr, "[%s]: Check p1 size == 2 passed\n", currentDateTime().c_str());
	p1.removeElementAt(2);
	assert(p1.getSize() == 1);
	fprintf(stderr, "[%s]: Check p1 size == 1 passed\n", currentDateTime().c_str());
	p1.removeElementAt(2);
	assert(p1.getSize() == 1);
	fprintf(stderr, "[%s]: Check p1 size keep like before passed (1 == 1)\n", currentDateTime().c_str());
	fprintf(stderr, "[%s]: Test Constructor with parameted passed (%d == %d)\n", currentDateTime().c_str(), p1.getSize(), 1);

	/* Test Copy Constructor */
	Park < Car > p2(p1);
	fprintf(stderr, "[%s]: Begin Test Copy Constructor\n", currentDateTime().c_str());
	assert(p1.getSize() == p2.getSize());
	fprintf(stderr, "[%s]: Check size of p1 and p2 passed (%d == %d)\n", currentDateTime().c_str(), p1.getSize(), p2.getSize());
	fprintf(stderr, "[%s]: Check Copy Constructor passed (%d == %d)\n", currentDateTime().c_str(), p1.getSize(), p2.getSize());

	/* Test All Method */
	new(&p2) Park<Car>(10);
	p2.addElement(Car("5","Pink"));
	p2.addElement(Car("6","Yellow"));
	p2.addElement(Car("7","Green"));
	assert(p2.getSize() == 3);
	fprintf(stderr, "[%s]: Check size of p2 passed (%d == %d)\n", currentDateTime().c_str(), p2.getSize(), 3);
	assert(p2.getCarsIndexWithId("7") == 3);
	fprintf(stderr, "[%s]: Check method get cars index with id 7 is 3\n", currentDateTime().c_str());
	assert(p2.getCarsColourWithId("6") == "Yellow");
	fprintf(stderr, "[%s]: Check method get cars colour with id 6 is Yellow\n", currentDateTime().c_str());
	assert(p2.getCarsIndexWithColour("Pink").size() == 1);
	fprintf(stderr, "[%s]: Check method all cars with colour Pink is only one passed\n", currentDateTime().c_str());
	fprintf(stderr, "[%s]: All method already succesfully passed all test\n", currentDateTime().c_str());
}

void test_for_class_car(){
	Car car("B-6587-PAU", "White");
	fprintf(stderr, "[%s]: Begin Test Constructor with Parameter and all method\n", currentDateTime().c_str());
	assert(car.getColour() == "White");
	fprintf(stderr, "[%s]: Check colour passed, colour is %s == %s\n", currentDateTime().c_str(), car.getColour().c_str(), "White");
	assert(car.getId() == "B-6587-PAU");
	fprintf(stderr, "[%s]: Check id passed, id is %s == %s\n", currentDateTime().c_str(), car.getId().c_str(), "B-6587-PAU");
	fprintf(stderr, "[%s]: Test Constructor with Parameter and all method\n", currentDateTime().c_str());
	fprintf(stderr, "================================ END OF TESTING ================================\n");
}

const string currentDateTime() {
	time_t		now = time(0);
	struct tm	tstruct;
	char		buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}
