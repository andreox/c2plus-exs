#include "Fotografia.h"

namespace Foto {

	Fotografia::Fotografia( const char * t , const char* f ) {

		titolo = new char[strlen(t)+1] ;
		strcpy(titolo,t) ;
		formato = new char[strlen(f)+1] ;
		strcpy(formato,f) ;
	}

	Fotografia::Fotografia( const Fotografia &f ) {

		titolo = new char[strlen(f.titolo)+1] ;
		strcpy(titolo,f.titolo) ;
		formato = new char[strlen(f.formato)+1] ;
		strcpy(formato,f.formato) ;

	}

	const Fotografia& Fotografia::operator=( const Fotografia& f) {

		if ( this != &f ) {

			delete [] formato ;
			delete [] titolo ;
			titolo = new char[strlen(f.titolo)+1] ;
			strcpy(titolo,f.titolo) ;
			formato = new char[strlen(f.formato)+1] ;
			strcpy(formato,f.formato) ;

		}

		return *this ;
	}

	ostream& operator<<( ostream& out ,const Fotografia & f ) {

		out << f.titolo << endl ;
		out << f.formato << endl ;
		return out ;
	}

	istream& operator>>( istream& in , Fotografia &f ) {

		char buffer[100] ;
		in.getline(buffer,100) ;
		f.setTitolo(buffer) ;
		in.getline(buffer,100) ;
		f.setFormato(buffer) ;
		return in ;
	}
}
