#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <string>

using namespace std ;

namespace Cartansp {

	class Carta {

		friend ostream& operator<<( ostream& , const Carta & ) ;

	protected :

		char * Tipo ;
		char * Intestatario ;
		char * NumCarta ;
		virtual ostream& print(ostream& ) const ;

	public :

		Carta() ;
		Carta( const char* , const char* , const char* ) ;
		Carta( const Carta& ) ;
		const Carta& operator=( const Carta& ) ;

		const char* getTipo() const { return Tipo ; } ;
		const char* getIntestatario() const { return Intestatario ; } ;
		const char* getNumCarta() const { return NumCarta ; } ;
		void setTipo( const char* ) ;
		void setIntestatario( const char* ) ;
		void setNumCarta( const char* ) ;

		virtual bool Check( const char* ) const = 0 ;
		bool ControllaNumCarta() const ;

		virtual ~Carta() { delete [] Tipo ; delete [] Intestatario ; delete [] NumCarta ; } ;

	};
}

#endif
