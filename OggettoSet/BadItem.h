#ifndef BADITEM_H
#define BADITEM_H

#include <string>

using namespace std ;

namespace ONSP {

	class BadItem {

	private :

		string err ;
		int n ;

	public :

		BadItem( const string s , const int nn ) : err(s), n(nn) {}
		string what() const { return err ; }
		int eskere() const { return n ; }

	};
}

#endif
