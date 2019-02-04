#include "Motocicletta.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std ;

namespace mynsp {

	Motocicletta::Motocicletta() : Veicolo() {

		Tipo = new char[1] ;
		strcpy( Tipo, "" ) ;

	}

	Motocicletta::Motocicletta( const char* nt, const char* m, const char* t ) : Veicolo( nt, m ) {

		Tipo = new char[ strlen(t)+1] ;
		strcpy( Tipo, t ) ;

	}

	Motocicletta::Motocicletta( const Motocicletta &m ) : Veicolo(m) {

		Tipo = new char[ strlen(m.Tipo)+1] ;
		strcpy(Tipo, m.Tipo) ;

	}

	const Motocicletta& Motocicletta::operator=( const Motocicletta &m ) {

		if ( this != &m ) {

			Veicolo::operator=(m) ;
			delete [] Tipo ;
			Tipo = new char[ strlen(m.Tipo)+1] ;
			strcpy( Tipo, m.Tipo ) ;

		}

		return *this ;

	}

	const string Motocicletta::ToText() const {

		string r1 = NomeTipo ;
		string r2 = Marca ;
		string r3 = Tipo ;
		string ret = r1+" "+r2+" "+r3 ;
		return ret ;
	}


	ostream& Motocicletta::print( ostream& out ) const {

		Veicolo::print(out) ;
		out << Tipo << endl ;
		return out ;
	}

	istream& Motocicletta::read( istream& in ) {

		Veicolo::read(in) ;

		char buffer[100] ;
		cout << "Inserisci alimentazione : " ;
		in.ignore() ;
		in.getline(buffer,100) ;
		strcpy( Tipo, buffer ) ;


		return in ;
	}

	ostream& operator<<( ostream& out, const Motocicletta& m ) {

		return m.print(out) ;
	}

	istream& operator>>( istream& in, Motocicletta &m ) {

		return m.read(in) ;

	}
}

