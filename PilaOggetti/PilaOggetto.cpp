#include "PilaOggetto.h"
#include "Oggetto.h"
#include "Pila.h"
#include "BadInsert.h"
#include <cstring>

PilaOggetto::PilaOggetto() : Pila() {

	Forma = new char[1] ;
	strcpy( Forma, "" ) ;

}

PilaOggetto::PilaOggetto( const char * f ) : Pila() {

	Forma = new char[strlen(f)+1] ;
	strcpy( Forma , f  ) ;

}

PilaOggetto::PilaOggetto( const PilaOggetto& po ) : Pila(po) {

	Forma = new char[strlen(po.Forma)+1] ;
	strcpy( Forma , po.Forma ) ;

}

const PilaOggetto& PilaOggetto::operator=( const PilaOggetto& po ) {

	Pila::operator=(po) ;

	if ( this !=&po) {

		delete [] Forma ;
		Forma = new char[strlen(po.Forma)+1] ;
		strcpy( Forma, po.Forma ) ;

	}

	return *this ;

}


bool PilaOggetto::push( const T& elem ) {

	if ( empty() && check(elem.getForma()) ) {

		P[riemp] = elem ;
		riemp++ ;
		return true ;

	}
	else if ( check(elem.getForma()) )  {

		T * tmp_P = new T[riemp] ;
		for ( int i = 0 ; i < riemp ; i++ ) tmp_P[i] = P[i] ;

		delete [] P ;
		riemp++ ;
		P = new T[riemp] ;

		for ( int i = 0 ; i < riemp-1 ; i++ ) P[i] = tmp_P[i] ;
		P[riemp-1] = elem ;
		return true ;

	}

	else {
		BadInsertExcep b("Errore Forma",0) ;
		throw b ;
		return false ;
	}

}

bool PilaOggetto::check(  const char* str ) const {


	if ( strcmp( Forma, str ) == 0 ) return true ;
	return false ;

}




