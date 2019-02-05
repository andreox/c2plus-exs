#ifndef GARAGE_H
#define GARAGE_H
#define MAX 6

#include "Veicolo.h"

using mynsp::Veicolo ;

typedef Veicolo * T ;


class Garage {

private :

	T garage[MAX] ;
	int last_ins ;

public :

	Garage() { last_ins = 0  ; } ;
	int push( const T& ) ;
	T& pop( int pos ) ;
	void print() const ;
	void print( ostream& of ) const ;


};

#endif
