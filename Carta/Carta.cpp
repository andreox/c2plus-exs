#include "Carta.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std ;

namespace Cartansp {

	Carta::Carta() {

		Tipo = new char[1] ;
		strcpy( Tipo, "" ) ;
		Intestatario = new char[1] ;
		strcpy( Intestatario, "" ) ;
		NumCarta = new char[1] ;
		strcpy( NumCarta, "" ) ;

	}

	Carta::Carta( const char* t , const char* i, const char* n ) {

		Tipo = new char[ strlen(t)+1] ;
		strcpy( Tipo , t ) ;

		Intestatario = new char[ strlen(i)+1] ;
		strcpy( Intestatario, i ) ;

		NumCarta = new char[ strlen(i)+1] ;
		strcpy( NumCarta, n ) ;

	}

	Carta::Carta( const Carta& c ) {

		Tipo = new char[ strlen(c.Tipo)+1] ;
		strcpy( Tipo , c.Tipo ) ;

		Intestatario = new char[ strlen(c.Intestatario)+1] ;
		strcpy( Intestatario, c.Intestatario ) ;

		NumCarta = new char[ strlen(c.NumCarta)+1] ;
		strcpy( NumCarta, c.NumCarta ) ;

	}

	const Carta& Carta::operator=( const Carta &c ) {

		if ( this !=&c ) {

			delete [] Tipo ;
			delete [] Intestatario ;
			delete [] NumCarta ;

			Tipo = new char[ strlen(c.Tipo)+1] ;
			strcpy( Tipo , c.Tipo ) ;

			Intestatario = new char[ strlen(c.Intestatario)+1] ;
			strcpy( Intestatario, c.Intestatario ) ;

			NumCarta = new char[ strlen(c.NumCarta)+1] ;
			strcpy( NumCarta, c.NumCarta ) ;
		}

		return *this ;
	}

	void Carta::setTipo( const char* t ) {

		delete [] Tipo ;
		Tipo = new char[ strlen(t)+1] ;
		strcpy( Tipo,t ) ;


	}

	void Carta::setIntestatario( const char* i ) {

		delete [] Intestatario ;
		Intestatario = new char[ strlen(i)+1] ;
		strcpy( Intestatario ,i ) ;

	}

	void Carta::setNumCarta( const char* nc ) {

		delete [] NumCarta ;
		NumCarta = new char[ strlen(nc)+1] ;
		strcpy( NumCarta,nc ) ;

	}

	bool Carta::ControllaNumCarta() const {

		string err ;
		if ( strlen(NumCarta) >= 8 ) {

			return true ;
		}

		else {

			err = "Inserisci almeno 8 caratteri" ;
			throw err ;
		}

		return false ;
	}

	ostream& Carta::print( ostream& out ) const {

		out << Tipo << " " << Intestatario << " " << NumCarta << endl ;
		return out ;

	}

	ostream& operator<<( ostream& out, const Carta& c ) {

		return c.print(out) ;

	}
}
