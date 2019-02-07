#include "Bancomat.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace Cartansp {

	Bancomat::Bancomat( const char * t , const char* in , const char* num , const Data d ) : Carta(t,in,num) { // @suppress("Class members should be properly initialized")

		attivato = false ;
		DataScadenza = d ;

	}

	Bancomat::Bancomat( const Bancomat&b ) : Carta(b) { // @suppress("Class members should be properly initialized")

		attivato = b.attivato ;
		DataScadenza = b.DataScadenza;

	}

	const Bancomat& Bancomat::operator=( const Bancomat&b ) {

		if ( this != &b ) {

			Carta::operator=(b) ;
			attivato = b.attivato ;
			DataScadenza = b.DataScadenza ;

		}

		return *this ;

	}

	void Bancomat::Attiva() {

		attivato = true ;
		setPin() ;

	}

	bool Bancomat::Check( const char* c ) const {

		if ( attivato ) {

			if ( strcmp( Pin, c ) == 0 ) return true ;

		}

		return false ;
	}

	void Bancomat::setPin() {

		Pin = new char[strlen(NumCarta)+2] ;
		for ( int i = 0 ; i < strlen(NumCarta) ; i++ ) Pin[i] = NumCarta[i] ;
		Pin[strlen(Pin)-1] = 'O' ; //Offset? :O

	}

	Bancomat::~Bancomat() {

		if ( attivato ) delete [] Pin ;

	}

	ostream& Bancomat::print( ostream & out ) const {

		Carta::print(out) ;
		out << DataScadenza << endl ;
		return out ;

	}
	ostream& operator<<( ostream& out, const Bancomat &b ) {

		return b.print(out) ;

	}

}
