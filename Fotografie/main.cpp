#include "Fotografia.h"
#include "CodaFotografia.h"
#include "BadPop.h"
#include <iostream>
#include <fstream>

using namespace std ;
using namespace Foto ;

int main( int argc, char** argv ) {

	Fotografia f1("Albero","jpg") ;
	Fotografia f2("Pianta","png") ;
	Fotografia f3("Muro","jpg") ;
	Fotografia f4 ;
	cin >> f4 ;
	Fotografia f5 ;
	f5.setTitolo("Cuore") ;
	f5.setFormato("png") ;

	ofstream file("file.txt") ;
	file << f1 ;
	file << f2 ;
	file << f3 ;
	file << f4 ;
	file << f5 ;

	CodaFotografia c ;
	try {
		c.pop(f2) ;
	}
	catch( BadPop & p ) { cout << p.what() << endl ; }

	CodaFotografia c2("file.txt") ;

	Fotografia f6("NuovaFoto","png") ;
	c2.append(f6) ;
	c2.stampa() ;
	return 0 ;

}
