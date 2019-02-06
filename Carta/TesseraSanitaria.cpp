#include "TesseraSanitaria.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std ;

namespace Cartansp {

	TesseraSanitaria::TesseraSanitaria() : Carta() {

		CF = new char[1] ;
		strcpy( CF, "") ;

	}

	TesseraSanitaria::TesseraSanitaria( const char* t, const char* i , const char* nc , const char* cf , const Data d1, const Data d2) : Carta(t,i,nc) {

		CF = new char[strlen(cf)+1] ;
		strcpy( CF, cf) ;

		DataRilascio = d1 ;
		DataScadenza = d2 ;

	}

	TesseraSanitaria::TesseraSanitaria( const TesseraSanitaria &ts ) : Carta(ts) {

		CF = new char[strlen(ts.CF)+1] ;
		strcpy( CF, ts.CF) ;

		DataRilascio = ts.DataRilascio ;
		DataScadenza = ts.DataScadenza ;

	}

	const TesseraSanitaria& TesseraSanitaria::operator=( const TesseraSanitaria &ts ) {

		if ( this != &ts) {

			Carta::operator=(ts) ;
			delete [] CF ;

			CF = new char[strlen(ts.CF)+1] ;
			strcpy( CF, ts.CF) ;

			DataRilascio = ts.DataRilascio ;
			DataScadenza = ts.DataScadenza ;

		}

		return * this ;
	}

	void TesseraSanitaria::setCF( const char* s ) {

		delete [] CF ;
		CF = new char[ strlen(s)+1] ;
		strcpy( CF, s ) ;

	}

	bool TesseraSanitaria::Check( const char* s ) const {

		if ( strcmp( CF, s) ) return true ;
		return false ;

	}

	ostream& TesseraSanitaria::print( ostream& out ) const {

		Carta::print(out) ;
		out << DataScadenza << " " << DataRilascio << " " << CF << endl  ;
				return out ;
	}


	ostream& operator<<( ostream& out, const TesseraSanitaria &ts ) {

		return ts.print(out) ;

	}
}
