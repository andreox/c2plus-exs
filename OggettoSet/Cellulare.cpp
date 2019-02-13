#include "Cellulare.h"
#include "Oggetto.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace ONSP {


	Cellulare::Cellulare( const int c , const char* d , const char* f , const char* m, const float num) : Oggetto(c,d,f) {

		modello = new char[strlen(m)+1] ;
		strcpy(modello,m) ;
		costo = num ;
	}

	Cellulare::Cellulare( const Cellulare& c ) {

		modello = new char[strlen(c.modello)+1] ;
		strcpy(modello,c.modello) ;
		costo =c.costo ;
	}

	const Cellulare& Cellulare::operator=( const Cellulare& c ) {

		if ( this != &c ) {

			Oggetto::operator=(c) ;
			delete[] modello ;
			modello = new char[strlen(c.modello)+1] ;
			strcpy(modello,c.modello) ;
			costo =c.costo ;
		}

		return *this ;
	}

	ostream& operator<<( ostream& out, Cellulare& c ) {

		return c.print(out) ;

	}

	istream& operator>>( istream& in, Cellulare& c ) {

		return c.read(in) ;
	}

	ostream& Cellulare::print( ostream& out ) {

		Oggetto::print(out) ;
		out << modello << " " << costo << endl ;
		return out ;
	}

	istream& Cellulare::read( istream& in ) {

		Oggetto::read(in) ;
		char buffer[100] ;
		in.getline(buffer,100) ;
		delete [] modello ;
		strcpy(modello,buffer) ;
		in >> costo ;
		return in ;
	}

	bool Cellulare::operator==( const Cellulare& c ) const{

		if ( Oggetto::operator==(c) && strcmp(modello,c.modello) == 0 && costo == c.costo ) return true ;
		return false ;
	}
}
