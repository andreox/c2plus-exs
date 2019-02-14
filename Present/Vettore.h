#ifndef VETTORE_H
#define VETTORE_H
#define MAX 100

#include <iostream>
#include "PacchettoRegalo.h"
#include "BadIndex.h"

using namespace std ;

namespace Present {

	typedef PacchettoRegalo T ;

	class Vettore {

		friend ostream& operator<<(ostream& , const Vettore& ) ;
		friend istream& operator>>(istream& , Vettore& ) ;

	private :

		T * v ;
		int Nelem ;

	public :

		Vettore() { v = new T[MAX] ; Nelem = 0 ; }
		Vettore(const int n) : Nelem(n) { v = new T[n] ; }
		Vettore( const Vettore& );
		Vettore& operator=( const Vettore& ) ;
		bool push( const T& ) ;
		bool full() const { if ( Nelem == MAX-1 ) return true ; return false; }
		T& operator[]( int i) { return v[i] ; }
		const T& operator[]( int i ) const { return v[i] ; }

		const T* getV() const { return v ; }
		int getNelem() const { return Nelem ; }
		T& Access( int ) throw( BadIndex );
		void Elimina() ;

		~Vettore() { delete [] v ; }

	};
}

#endif
