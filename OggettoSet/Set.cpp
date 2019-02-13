#include "Set.h"
#include "Oggetto.h"
#include "BadItem.h"
#include <iostream>
#include <fstream>

using namespace std ;

namespace ONSP {

	bool Set::push( const T& elem ) throw(BadItem) {

		if (!full()){
			for ( int i = 0 ; i < riemp ; i++ ) {

				if ( elem == v[i] ) {

					BadItem b("Elemento già inserito",0) ;
					throw b ;
					return false ;
				}
			}

			v[riemp] = elem ;
			riemp++ ;
			return true ;
		}
		return false ;
	}

	bool Set::pop( const T& elem ) {

		Oggetto * o ; //Oggetto nullo
		for ( int i =0 ; i < riemp ; i++ ) {

			if ( elem == v[i] ) {
				v[i] = o ;
				return true ;
			}
		}

		return false ;
	}

	void Set::intersection( const Set& s) {

		T v_tmp[MAX];
		int riemp_tmp = 0 ;
		for ( int i = 0 ; i < riemp ; i++ ) {

			for ( int j = 0 ; j < s.getRiemp() ; j++) {

				if ( v[i] == s[j] ) {
					v_tmp[riemp_tmp] = v[i] ;
					riemp_tmp++ ;
				}
			}
		}

		for ( int i = 0 ; i < riemp_tmp ; i++ ) v[i] = v_tmp[i] ;
		riemp = riemp_tmp ;

	}

	void Set::print( ostream& out ) const {

		for ( int i = 0 ; i < riemp ; i++ ) {

			out << *v[i] << endl ;

		}

	}

	void Set::uniion( const Set& s) {

		for ( int i = 0 ; i < s.getRiemp() ; i++ ) {

			try {

				push(s[i]) ;
			}
			catch(BadItem &b) {}

		}
	}

	void Set::difference( const Set& s) {

		T v_tmp[MAX];
		int riemp_tmp = 0 ;
		for ( int i = 0 ; i < riemp ; i++ ) {

			bool tr = false ;
			for ( int j = 0 ; j < s.getRiemp() && !tr ; j++) {

				if ( v[i] == s[j] )
					tr = true ;
			}
			if ( !tr ) {
				v_tmp[riemp_tmp] = v[i] ;
				riemp_tmp++ ;
			}
		}

		for ( int i = 0 ; i < riemp_tmp ; i++ ) v[i] = v_tmp[i] ;
		riemp = riemp_tmp ;
	}
}

