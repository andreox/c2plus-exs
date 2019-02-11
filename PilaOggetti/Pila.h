#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Oggetto.h"

using namespace std ;

typedef Oggetto T ;

class Pila {

protected :

	T * P ;
	int riemp ;

public :

	Pila() { P = new T[1] ; riemp = 0 ; };
	Pila( const Pila& p ) ;
	const Pila& operator=( const Pila&  )  ;

	virtual bool push( const T& ) ;
	bool pop(T& ) ;
	inline bool empty() const { if ( riemp == 0 ) return true ; return false ; } ;
	bool full() const { return false ; } ;
	void print( ostream& ) const;
	bool top( T& ) ;

	virtual ~Pila() { delete [] P  ; } ;

};

#endif
