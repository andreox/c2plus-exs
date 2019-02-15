#ifndef BADINS_H
#define BADINS_H

#include <string>

using namespace std ;

namespace Societa {

	class BadIns {

	private :

		string e ;
		int ne ;

	public :

		BadIns() ;
		BadIns( string s , int n ) : e(s) , ne(n) {}
		string what() const { return e ; }
		int n_what() const { return ne ; }

	};
}
#endif



