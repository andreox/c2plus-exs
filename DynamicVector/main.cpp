#include <iostream>
#include "DynVet.h"

using namespace std ;

int main( int argc, char** argv ) {

	DynVet d(4) ;
	d.push_back(6) ;
	cout << "C1 : " << d.capacity() << endl ;
	cout << "S1: " <<  d.size() << endl ;
	d.push_back(7) ;
	cout << "C2 : " << d.capacity() << endl ;
	cout << "S2 : " << d.size() << endl ;
	d.push_back(8) ;
	cout << "C3 : " << d.capacity() << endl ;
	cout << "S3 : " << d.size() << endl ;
	d.push_back(9) ;
	d.push_back(9) ;
	d.push_back(9) ;
	d.push_back(9) ;
	d.push_back(9) ;
	d.push_back(9) ;
	d.print() ;

	return 0 ;


}
