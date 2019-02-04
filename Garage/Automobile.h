#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "Veicolo.h"
#include <iostream>

using namespace std ;

namespace mynsp {

	class Automobile : public Veicolo {

		friend ostream& operator<< ( ostream &out , const Automobile &a ) ;
		friend istream& operator>> ( istream &in, Automobile &a ) ;

	private :

		char * Alimentazione ;

	protected :

		virtual ostream& print( ostream &out ) const ;
		virtual istream& read( istream& in ) ;

	public :

		Automobile() ;
		Automobile( const char* , const char* , const char* ) ;
		Automobile( const Automobile& ) ;
		const Automobile& operator=( const Automobile& ) ;

		virtual const string ToText() const ;

		virtual ~Automobile() { delete [] Alimentazione ; } ;

	};
}

#endif
