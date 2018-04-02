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

int main(int argc, char** argv){
	if (argc == 1){
		fprintf(stderr, "Program exited because there isn't file input\n");
		exit(-1);
	}
	ifstream in(argv[1]);
	cerr << "done" << endl;
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