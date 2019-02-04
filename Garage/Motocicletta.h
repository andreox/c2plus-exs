#ifndef MOTOCICLETTA_H
#define MOTOCICLETTA_H

#include "Veicolo.h"
#include <iostream>

using namespace std ;

namespace mynsp {

	class Motocicletta : public Veicolo {

		friend ostream& operator<< ( ostream &out , const Motocicletta &m ) ;
		friend istream& operator>> ( istream &in, Motocicletta &m ) ;

		private :

				char * Tipo ;

		protected :

				virtual ostream& print( ostream &out ) const ;
				virtual istream& read( istream& in ) ;

		public :

				Motocicletta() ;
				Motocicletta( const char* , const char* , const char* ) ;
				Motocicletta( const Motocicletta& ) ;
				const Motocicletta& operator=( const Motocicletta& ) ;

				virtual const string ToText() const ;

				virtual ~Motocicletta() { delete [] Tipo ; } ;
	};
}

#endif
