#ifndef BADPOP_H
#define BADPOP_H

#include <string>

using namespace std ;

namespace Foto {

	class BadPop {

	private :
		string err ;
		int n_err ;

	public :

		BadPop() ;
		BadPop( const string s , const int n ) : err(s) , n_err(n) {}
		string what() const { return err ; }
		int e() const { return n_err ; }

	};
}
#endif

