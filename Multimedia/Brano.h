#ifndef BRANO_H
#define BRANO_H

#include "FileMultimediale.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace File {

	class Brano : public FileMultimediale {

		friend ostream& operator<<( ostream& o, Brano& b) { return b.print(o) ; }
		friend istream& operator>>( istream& i, Brano& b) { return b.read(i) ; }

	private :

		char * bra ;
		float durata ;
		char * Interprete ;
		virtual ostream& print( ostream& ) ;
		virtual istream& read( istream& ) ;

	public :

		Brano() : FileMultimediale() { durata = 0 ; bra = new char[1] ; Interprete = new char[1] ; strcpy(bra,"") ; strcpy(Interprete,"") ;}
		Brano( const char* , const int , const char*, const char* , const float , const char* ) ;
		Brano( const Brano& ) ;
		const Brano& operator=( const Brano& );
		virtual bool memorizza_dati( ofstream& ) ;

		virtual ~Brano() { delete [] bra ; delete [] Interprete ; }
	};
}
#endif
