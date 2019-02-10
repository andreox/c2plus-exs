#include "PilaPacco.h"
#include "PaccoRegalo.h"
#include <fstream>

using namespace std ;

namespace Pacco {

	PilaPacco::PilaPacco() {

		testa = 0 ;

	}

	bool PilaPacco::push( const T& elem ) {


		if ( !empty() ) {

			Pila* tmp = testa ;

			while ( tmp->next ) {

				tmp = tmp->next ;

			}

			Pila* new_elem = new Pila ;
			new_elem->key = elem ;
			tmp->next = new_elem ;
			new_elem->next = 0;
			return true ;

		}

		else {

			Pila * new_elem = new Pila ;
			new_elem->key = elem ;
			testa = new_elem ;
			return true ;

		}

		return false;
	}

	bool PilaPacco::pop( T& elem ) {

		if ( !empty() ) {
			Pila * tmp = testa ;
			while ( tmp->next ) tmp = tmp->next ;

			elem = tmp->key ;
			tmp = 0 ;
			return true ;
		}

		return false ;

	}

	void PilaPacco::top( T& elem ) { elem = testa->key ; }

	void PilaPacco::leggidafile( const char* n_file ) {

		ifstream file(n_file, ios::in | ios::binary ) ;

	}
}
