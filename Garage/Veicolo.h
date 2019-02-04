#ifndef VEICOLO_H
#define VEICOLO_H

#include <iostream>
#include <string>

using namespace std ;

namespace mynsp {

	class Veicolo {

		friend ostream& operator<<( ostream& , const Veicolo& ) ;
		friend istream& operator>>( istream& , Veicolo& ) ;

	protected :

		char * NomeTipo ;
		char * Marca ;
		virtual ostream& print( ostream& ) const ;
		virtual istream& read( istream& ) ;

	public :

		Veicolo() ;
		Veicolo( const char* , const char* ) ;
		Veicolo( const Veicolo &) ;
		const Veicolo& operator=( const Veicolo& ) ;


		virtual const string ToText() const = 0 ;
		const char* getNomeTipo() const { return NomeTipo ;}  ;

		virtual ~Veicolo() { delete [] NomeTipo ; delete [] Marca ; } ;


	};
}

#endif
