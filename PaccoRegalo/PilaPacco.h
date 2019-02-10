#ifndef PILAPACCO_H
#define PILAPACCO_H

#include "PaccoRegalo.h"

namespace Pacco {


	typedef PaccoRegalo T ; //non definisco T come puntatore a pacco regalo perchè non devo realizzare il polimorfismo
	struct Pila {

		T key ;
		Pila* next ;

	};

	class PilaPacco {

	private :

		Pila *testa ;


	public :

		PilaPacco() ;
		bool push( const T& ) ;
		bool pop( T& ) ;
		void top( T& ) ;
		void leggidafile( const char* n_file ) ;

		inline bool empty() { if ( testa==0) return true ; return false ;  } ;
		bool full() ; //Non ha senso se non ho una dimensione massima fissata.

	};

}

#endif
