#ifndef LISTA_H
#define LISTA_H

#include "Veicolo.h"
#include <iostream>

using namespace std ;

typedef Veicolo * T ;

struct Record {

	T key ;
	Record * next ;

};

class Lista {

private :

	Record * testa ;

public :

	Lista() { testa = 0 ; };
	bool push( const T & ) ;
	bool pop( T & ) ;
	bool top( T & ) ;
	bool empty() const { return ( testa == 0 ) ; } ;
	bool full() const { return false ; }
	bool inlist( const T & ) const ;
	bool append( const T & ) ;
	ostream &print( ostream & ) const ;
	~Lista() ;
};

#endif
