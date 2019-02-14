#ifndef BADINDEX_H
#define BADINDEX_H

#include <string>

using namespace std ;

namespace Present {

	class BadIndex {

	private :

		string err ;
		int num_err ;

	public :

		BadIndex() : err("") , num_err(0) {}
		BadIndex( const string e , const int n ) : err(e) , num_err(n) {}
		string what() const { return err ; }
		int get_index() const { return num_err ; }

	};
}

#endif
