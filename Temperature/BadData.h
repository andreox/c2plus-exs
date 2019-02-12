#ifndef BADDATA_H
#define BADDATA_H

#include <string>

using namespace std ;

namespace Temperature {

	class BadData {

	private :

		string err ;
		int n_err ;

	public :

		BadData( const string s, const int n ) : err(s), n_err(n) {} ;
		string what() const { return err ; } ;
		int error() const { return n_err ; } ;

	};
}

#endif
