#include "PaccoRegalo.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace Pacco {

	PaccoRegalo::PaccoRegalo() {

		cod = 0 ;
		weight = 0 ;
		address = new char[1] ;
		strcpy(address,"") ;

	}

	PaccoRegalo::PaccoRegalo( const int c , const float w , const char* a ) {

		cod = c ;
		weight = w ;
		address = new char[strlen(a)+1] ;
		strcpy( address, a) ;

	}

	PaccoRegalo::PaccoRegalo( const PaccoRegalo &p ) {

		cod = p.cod ;
		weight = p.weight ;
		address = new char[ strlen(p.address)+1] ;
		strcpy( address, p.address) ;
	}

	const PaccoRegalo& PaccoRegalo::operator=( const PaccoRegalo& p ) {

		if ( this != &p ) {

			delete [] address ;
			cod = p.cod ;
			weight = p.weight ;
			address = new char[ strlen(p.address)+1] ;
			strcpy( address, p.address) ;

		}

		return *this;
	}

	ostream& operator<<( ostream& out, const PaccoRegalo &p ) {

		out << "Codice : " << p.cod << "\nPeso : " << p.weight << "\nIndirizzo : " << p.address << endl ;
		return out ;
	}

	istream& operator>>( istream& in, PaccoRegalo &p ) {

		in >> p.cod ;
		in >> p.weight ;
		char buffer[100] ;
		in.ignore() ;
		in.getline( buffer,100) ;
		delete [] p.address ;
		p.address = new char[ strlen(buffer)+1] ;
		strcpy( p.address, buffer) ;

		return in ;

	}

}
