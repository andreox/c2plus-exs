#ifndef CELLULARE_H
#define CELLULARE_H

#include "Oggetto.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace ONSP {

	class Cellulare : public Oggetto {

		friend ostream& operator<<( ostream&, Cellulare&) ;
		friend istream& operator>>( istream&, Cellulare& ) ;

	private :

		char * modello ;
		float  costo ;

	public :

		Cellulare() : Oggetto() { modello = new char[1]; strcpy(modello,"") ; costo=0; }
		Cellulare( const int, const char*,const char*, const char* , const float ) ;
		Cellulare( const Cellulare& ) ;
		const Cellulare& operator=( const Cellulare& ) ;

		inline void setModello( const char* m ) { delete [] modello ; modello = new char[strlen(m)+1] ; strcpy(modello,m) ;}
		void setCosto( float n ) { costo = n ; }

		const char* getModello() const { return modello ; }
		const float getCosto() const { return costo ; }
		virtual bool operator==(const Cellulare& l ) const ;

		virtual ostream& print(ostream&) ;
		virtual istream& read( istream& ) ;

		virtual ~Cellulare() { delete [] modello ; }
	};
}

#endif

