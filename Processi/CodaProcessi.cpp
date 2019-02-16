#include "CodaProcessi.h"
#include <fstream>

namespace Processi {

	bool CodaProcessi::push( const T& elem )  throw ( BadIns ) {

		if ( full() ) return false ;
		if ( yet_inserted(elem) ) {

			BadIns b("Processo già in coda",0) ;
			throw b ;
			return false ;
		}

		if ( empty() ) {

			Record * tmp = new Record ;
			tmp->key = elem ;
			tmp->next = testa ;
			testa = tmp ;
			cout << "what" << endl;
			return true ;

		}

		Record * tmp = testa ;
		while (tmp->next) {

			tmp = tmp->next ;
			cout << "iter" << endl ;
		}
		Record *tmp2 = new Record ;
		tmp2->key = elem ;
		tmp2->next = tmp->next ;
		tmp->next = tmp2 ;
		if (elem->hasStarted()) num_ready_proc++ ;
		return true ;

	}

	bool CodaProcessi::pop( T& elem ) {

		if ( empty() ) return false ;
		if ( num_ready_proc==0) return false ;

		Record * tmp2 = testa ;
		Record * tmp = tmp2->next ;
		bool tr = false ;
		while ( tmp->next && !tr ) {

			if ( tmp->key->hasStarted() ) tr = true ;

			else {
				tmp2 = tmp2->next ;
				tmp = tmp->next ;
			}
		}
		tmp2->next = tmp->next ;
		elem = tmp->key ;
		delete tmp ;
		return true ;
	}

	void CodaProcessi::Show() const {

		Record * tmp = testa ;
		while ( tmp ) {
			cout << *(tmp->key) ;
			tmp = tmp->next ;
		}

	}

	void CodaProcessi::Store(const char* nf ) const {

		ofstream f(nf) ;
			Record * tmp = testa ;
			while ( tmp ){
				f << *(tmp->key) ;
				tmp = tmp->next ;
			}

	}

	bool CodaProcessi::yet_inserted( const T& elem ) const {

		if ( empty() ) return false ;

		Record * tmp = testa ;
		while ( tmp->next ) {
			if ( tmp->key->getPID() == elem->getPID() ) return true ;
			tmp = tmp->next ;
		}
		return false ;
	}
}



