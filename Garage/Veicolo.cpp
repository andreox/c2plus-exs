#include "Veicolo.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace mynsp {

	Veicolo::Veicolo() {

		NomeTipo = new char[1] ;
		strcpy( NomeTipo, "" ) ;
		Marca = new char[1] ;
		strcpy( Marca, "") ;

	}

	Veicolo::Veicolo( const char* nt , const char* m ) {

		NomeTipo = new char[strlen(nt)+1] ;
		strcpy( NomeTipo, nt) ;
		Marca = new char[ strlen(m) +1] ;
		strcpy( Marca, m ) ;

	}

	Veicolo::Veicolo( const Veicolo& v ) {

		NomeTipo = new char[strlen(v.NomeTipo)+1] ;
		strcpy( NomeTipo, v.NomeTipo) ;
		Marca = new char[ strlen(v.Marca) +1] ;
		strcpy( Marca, v.Marca ) ;
	}

	const Veicolo& Veicolo::operator=( const Veicolo &v ) {

		if ( this != &v ) {

			delete [] NomeTipo ;
			delete [] Marca ;
			NomeTipo = new char[strlen(v.NomeTipo)+1] ;
			strcpy( NomeTipo, v.NomeTipo) ;
			Marca = new char[ strlen(v.Marca) +1] ;
			strcpy( Marca, v.Marca ) ;
		}

		return *this ;
	}

	ostream& Veicolo::print( ostream& out ) const {

		out << NomeTipo << " " << Marca << endl ;
		return out ;
	}

	istream& Veicolo::read( istream& in ) {

		char buffer[100] ;
		cout << "Inserisci nome tipo : " ;
		in.ignore() ;
		in.getline(buffer,100) ;
		strcpy( NomeTipo, buffer ) ;

		cout << "Inserisci marca : " ;
		in.ignore() ;
		in.getline( buffer,100 ) ;
		strcpy( Marca, buffer) ;

		return in ;
	}

	ostream& operator<<( ostream& out, const Veicolo& v ) {

		return v.print(out) ;
	}

	istream& operator>>( istream& in, Veicolo &v ) {

		return v.read(in) ;

	}

}
