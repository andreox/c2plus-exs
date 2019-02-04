#include "Automobile.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std ;

namespace mynsp {

	Automobile::Automobile() : Veicolo() {

		Alimentazione = new char[1] ;
		strcpy( Alimentazione,"") ;

	}

	Automobile::Automobile( const char* nt, const char* m , const char* a ) : Veicolo( nt, m ) {

		Alimentazione = new char[ strlen(a)+1] ;
		strcpy( Alimentazione, a ) ;

	}

	Automobile::Automobile( const Automobile & a) : Veicolo(a) {

		Alimentazione = new char[ strlen( a.Alimentazione) + 1] ;
		strcpy( Alimentazione, a.Alimentazione ) ;

	}

	const Automobile& Automobile::operator=( const Automobile &a ) {

		if ( this != &a ) {

			Veicolo::operator=(a) ;
			delete [] Alimentazione ;
			Alimentazione = new char[ strlen(a.Alimentazione)+1] ;
			strcpy(Alimentazione, a.Alimentazione) ;


		}

		return *this ;
	}

	const string Automobile::ToText() const {

		string r1 = NomeTipo ;
		string r2 = Marca ;
		string r3 = Alimentazione ;
		string ret = r1+" "+r2+" "+r3 ;
		return ret ;
	}


	ostream& Automobile::print( ostream& out ) const {

		Veicolo::print(out) ;
		out << Alimentazione << endl ;
		return out ;
	}

	istream& Automobile::read( istream& in ) {

		Veicolo::read(in) ;

		char buffer[100] ;
		cout << "Inserisci alimentazione : " ;
		in.ignore() ;
		in.getline(buffer,100) ;
		strcpy( Alimentazione, buffer ) ;


		return in ;
	}

	ostream& operator<<( ostream& out, const Automobile& a ) {

		return a.print(out) ;
	}

	istream& operator>>( istream& in, Automobile &a ) {

		return a.read(in) ;

	}
}
