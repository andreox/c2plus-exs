#ifndef NOTSORTED_H
#define NOTSORTED_H

#include <string>
using namespace std ;

namespace Vector {

	class NotSorted {

	private :

		string err ;
		int n ;

	public :

		NotSorted() ;
		NotSorted( string e , int k ) : err(e) , n(k) {}
		string what() const { return err ; }
		int error() const { return n ; }

	};
}

#endif
