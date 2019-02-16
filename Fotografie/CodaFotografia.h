#ifndef CODAFOTOGRAFIA_H
#define CODAFOTOGRAFIA_H
#define N 10
#define F_ELEM 5

#include "Fotografia.h"
#include "BadPop.h"

namespace Foto {

	typedef Fotografia T ;

	class CodaFotografia {

	private :

		T v[N] ;
		int nelem ;

	public :

		CodaFotografia() { nelem = 0 ; }
		CodaFotografia( const char * ) ;
		bool empty() const { return nelem==0; }
		bool full() const { return false ;}
		inline void append(const T& elem ) { if(!full()) {v[(nelem%N)] = elem ; nelem++ ; }}
		void pop( T& ) throw(BadPop) ;
		void stampa() const ;
	};
}

#endif
