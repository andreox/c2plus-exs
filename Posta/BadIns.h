#ifndef BADINS_H
#define BADINS_H

#include <string>

using namespace std ;

namespace Posta {

	class BadIns {

	private:

		string err ;
		int n_err ;

	public :

		BadIns( string s , int n ) : err(s) , n_err(n) {}
		string what() const { return err ; }
		int e() const { return n_err ;}

	};
}

#endif
