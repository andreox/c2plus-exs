#include "Oggetto.h"

#include <iostream>
#include <cstring>

using namespace std ;

namespace ONSP {

	Oggetto::Oggetto() {

		cod = 0 ;
		desc = new char[1] ;
		strcpy(desc,"") ;
		forma = new char[1] ;
		strcpy(forma,"") ;
	}

	Oggetto::Oggetto( const int c , const char* d , const char* f ) {

		cod = c ;
		desc = new char[strlen(d)+1] ;
		forma = new char[strlen(f)+1] ;
		strcpy(desc,d) ;
		strcpy(forma,f) ;

	}

	Oggetto::Oggetto( const Oggetto& o ) {

		cod = o.cod ;
		desc = new char[strlen(o.desc)+1] ;
		forma = new char[strlen(o.forma)+1] ;
		strcpy(desc,o.desc) ;
		strcpy(forma,o.forma) ;

	}

	const Oggetto& Oggetto::operator=( const Oggetto& o) {

		if ( this!= &o ) {

			delete [] desc ;
			delete [] forma ;
			cod = o.cod ;
			desc = new char[strlen(o.desc)+1] ;
			forma = new char[strlen(o.forma)+1] ;
			strcpy(desc,o.desc) ;
			strcpy(forma,o.forma) ;

		}

		return *this ;
	}

	bool Oggetto::operator==( const Oggetto& o ) const {

		if ( cod == o.cod && strcmp(desc,o.desc) == 0 && strcmp(forma,o.forma) ) return true ;
		return false ;
	}

	ostream& Oggetto::print( ostream& out ) {

		out << cod << " " << desc << " " << forma << endl ;
		return out ;

	}
	ostream& operator<<( ostream& out, Oggetto& o ) {

		return o.print(out);

	}

	istream& Oggetto::read( istream& in ) {

		delete [] forma ;
		delete [] desc ;
		char buffer[100] ;
		in >> cod ;

		in.ignore() ;
		in.getline(buffer,100) ;
		strcpy(forma,buffer) ;

		in.ignore() ;
		in.getline( buffer,100) ;
		strcpy( desc, buffer) ;
		return in ;
	}

	istream& operator>>( istream& in, Oggetto &o ) {

		return o.read(in) ;

	}
}



