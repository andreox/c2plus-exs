#ifndef VETTORE_H
#define VETTORE_H
#define MAX 100

#include "Rilevamento.h"

namespace Temperature {

	typedef Rilevamento T ;

	class Vettore {

	protected :

		T *v ;
		int dim ;
		int riemp ;

	public :

		Vettore() { v = new T[MAX]; dim = MAX ; riemp = 0 ; }
		Vettore( const int d ) { dim = d ; v = new T[dim] ; riemp = 0 ;}
		Vettore( const Vettore& ) ;
		const Vettore& operator=( const Vettore& ) ;
		bool push( const T& ) ;
		bool full() const { if( riemp == dim ) return true ; return false ;}

		virtual void stampa( ostream& ) const ;

		virtual ~Vettore() { delete [] v ; }

	};
}

#endif

