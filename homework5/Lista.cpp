#include "Lista.h"
#include "NoAuth.h"
#include <iostream>

using namespace std ;

bool Lista::push( const T & el ) {

	if ( !full() ) {

		Record * q = new Record ;
		q->key = el ;
		q->next = testa ;
		testa = q ;
		return true ;

	}

	return false ;
}

bool Lista::append( const T & el ) {

	if ( !full() ) {

		if ( el->calc_pedaggio() == -1 ) {

			NoAuth a( "Classe sbagliata",4) ;
			throw a ;

		}
		if ( empty() ) {

			push (el) ;
			return true ;
		}


		Record * temp = testa ;
		while( temp->next) temp = temp->next ;

		Record * q = new Record ;
		temp->next = q ;
		return true ;

	}

	return false ;
}

bool Lista::top( T & el ) {

	if ( !empty() ) {

		el = testa->key ;
		return true ;

	}

	return false ;
}

bool Lista::pop( T & el ) {

	if ( !empty() ) {

		Record * tmp = testa ;
		el = testa->key ;
		testa = testa->next ;
		delete tmp ;
		return true ;

	}

	return false ;

}

bool Lista::inlist( const T & el ) const {

	if ( !empty() ) {

		Record * tmp= testa ;
		bool tr = false ;
		while ( tmp && !tr ) {

			if ( *(tmp->key) == *el ) tr = true ;
			tmp = tmp->next ;
		}

		return tr ;
	}

	return false ;
}

ostream & Lista::print(ostream & out) const {

        Record * temp=testa;
        while(temp) {
        	out << *(temp->key) << ' ';
        	temp=temp->next;
		}
		return out;
}

Lista::~Lista() {
	 Record * temp;
	 cout << "distruttore Lista" << endl;
	 while(testa) {
	 	temp=testa;
	 	testa=testa->next;
	 	delete temp;
	 }
}


