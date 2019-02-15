#include "MyVet.h"
#include <iostream>

using namespace std ;
using namespace Vector ;

int main( int argc, char** argv ) {

	Immagine i1("fiore.jpg",1000) ;
	Immagine i2("sole.png",2000) ;
	Immagine i3("pixel.jpg",10) ;
	Immagine i4("cappella.png",30000) ;
	MyVet V ;
	V.push_back(i1) ;
	V.push_back(i2) ;
	V.push_back(i3) ;
	V.push_back(i4) ;

	V.print(cout) ;
	cout << endl << endl ;

	try {

		V.BinarySearch(i3) ;

	}
	catch( NotSorted &n ) { cout << n.what() << endl ; }

	V.sort() ;
	V.print(cout) ;
	cout << endl << endl ;

	try {
	cout << V.BinarySearch(i4) << endl ; //Restituisce 3
	}
	catch( NotSorted &n2 ) { cout << n2.what() << endl ; }

	return 0 ;
}

