#ifndef VETTORE_H
#define VETTORE_H
#define MAX 10

#include "Immagine.h"

namespace Vector {

	typedef Immagine T ;

	class Vettore {

	protected :

		T * v ;
		int dim ;

	public :

		Vettore() { v = new T[MAX] ; dim = 0 ;}
		Vettore(int d ) { v = new T[d] ; dim = d ; }
		Vettore( const Vettore& ) ;
		Vettore& operator=( const Vettore& ) ;
		bool push_back(const T& ) ;
		bool pop_back(T& ) ;
		T& operator[]( int i) { return v[i] ; }
		const T& operator[](int i) const { return v[i] ; }
		int getDim() const { return dim ; }

		~Vettore() { delete [] v ; }

	};
}

#endif

