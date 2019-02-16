#ifndef BADINS_H
#define BADINS_H

#include <string>

using namespace std ;

namespace Processi {

	class BadIns {

	private :

		string e ;
		int n_e ;

	public :

		BadIns() ;
		BadIns( string err , int n ) : e(err) , n_e(n) {}
		string what() const { return e ; }
		int err() const { return n_e ;}

	};
}
#endif
