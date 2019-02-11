#ifndef PILAOGGETTO_H
#define PILAOGGETTO_H

#include <iostream>
#include "Pila.h"
#include "Oggetto.h"

using namespace std ;

class PilaOggetto : public Pila {

private :

	char * Forma ;

public :

	PilaOggetto() ;
	PilaOggetto( const char* ) ;
	PilaOggetto( const PilaOggetto& ) ;
	const PilaOggetto& operator=( const PilaOggetto& ) ;

	virtual bool push( const T& ) ;
	bool check( const char* ) const ;

	virtual ~PilaOggetto() { delete [] Forma ; } ;

};

#endif
