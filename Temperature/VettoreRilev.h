#ifndef VETTORERILEV_H
#define VETTORERILEV_H

#include "Rilevamento.h"
#include "Vettore.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std ;

namespace Temperature {

	class VettoreRilev : public Vettore {

	private :

		char * Periodo ;

	public :

		VettoreRilev() ;
		VettoreRilev( const char * p ) : Vettore() { Periodo = new char[strlen(p)+1] ; strcpy(Periodo,p) ; }
		VettoreRilev( const VettoreRilev& ) ;
		const VettoreRilev& operator=( const VettoreRilev& ) ;

		bool Carica_Tmax( string ) ;
		bool Carica_Tmin( string ) ;
		void MedieT( float& , float& ) const ;

		virtual void stampa( ostream& ) const ;

		virtual ~VettoreRilev() { delete [] Periodo ; }

	};
}


#endif
