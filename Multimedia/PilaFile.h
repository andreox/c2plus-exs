#ifndef PILAFILE_H
#define PILAFILE_H
#define MAX 10


#include "FileMultimediale.h"
#include <iostream>

using namespace std ;

namespace File {

	typedef FileMultimediale* T ;

	class PilaFile {

	private :

		T v[MAX] ;
		int nelem ;

	public :

		PilaFile() { nelem = 0 ; }
		bool full() const { if ( nelem == MAX ) return true ; return false ; }
		bool empty() const { if ( nelem == 0 ) return true ; return false;}
		inline bool push( const T& elem) { if ( !full()) {v[nelem++] = elem ; return true ;} return false ; }
		inline bool pop( T& elem ) { if ( !empty() ) { elem = v[nelem--] ; return true ; } return false ;}
		bool write() const ;


	};
}
#endif
