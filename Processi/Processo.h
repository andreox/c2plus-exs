#ifndef PROCESSO_H
#define PROCESSO_H

#include "Attivita.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace Processi {

	class Processo : public Attivita {

		friend ostream& operator<<(ostream& , Processo&) ;
		friend istream& operator>>( istream& , Processo& ) ;

	private :

		char * nome_img ;
		char state ;
		virtual ostream& stampa( ostream& ) ;
		virtual istream& leggi( istream& ) ;

	public :

		Processo() : Attivita() { nome_img = new char[1] ; strcpy(nome_img,"") ; state = 'W' ;}
		Processo( const int , const char* , bool , const char* , const char ) ;
		Processo( const Processo& ) ;
		const Processo& operator=( const Processo& ) ;

		void setnome_img( const char* n ) { delete [] nome_img ; nome_img = new char[strlen(n)+1] ; strcpy(nome_img,"") ;}
		void setstate( const char c ) { state = c;}
		const char* getnome_img() const { return nome_img ;}
		const char getstate() const { return state ;}

		virtual inline bool Attiva() { started = true ; if ( state == 'R') {state = 'P' ; return true ; } return false ;}

		virtual ~Processo() { delete [] nome_img ;}

	};
}
#endif

