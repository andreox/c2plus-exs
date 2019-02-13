#ifndef SET_H
#define SET_H
#define MAX 100

#include <iostream>
#include "Oggetto.h"
#include "BadItem.h"

using namespace std ;

namespace ONSP {

	typedef Oggetto* T ;
	class Set {

		friend int is_there( const T& , const Set& ) ;
	private :

		T v[MAX] ;
		int riemp ;

	public :

		Set() { riemp =0 ; }
		int getRiemp() const { return riemp ; }
		bool push( const T& ) throw(BadItem) ;
		bool pop( const T& ) ;
		void intersection( const Set& )  ;
		void uniion( const Set&)  ;
		void difference( const Set& )  ;
		bool full() { if ( riemp == MAX) return true ; return false ; }
		bool empty() { if ( riemp== 0 ) return true ; return false ; }
		void print( ostream& ) const ;
		void read( const char* name_file ) ;
		const T& operator[](int index) const { return v[index] ; }

	};
}

#endif
