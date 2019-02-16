#ifndef CODAPROCESSI_H
#define CODAPROCESSI_H

#include "Attivita.h"
#include "Processo.h"
#include "BadIns.h"
#include <iostream>

using namespace std ;

namespace Processi {

	typedef Attivita * T ;

	struct Record {

		T key ;
		Record * next ;
	};

	class CodaProcessi {

	private :

		Record * testa ;
		int num_ready_proc ;

	public :

		CodaProcessi() { testa = 0 ; num_ready_proc=0 ; }
		bool yet_inserted( const T& ) const ;
		bool full( ) { return false ;}
		bool empty() const { if ( testa == 0 ) return true ; return false ; }
		bool push( const T& ) throw(BadIns) ;
		bool pop( T& ) ;
		int getP() const { return num_ready_proc ; }
		bool Schedule( const int pid ) ;
		void Show()const ;
		void Store( const char* ) const ;

	};
}
#endif
