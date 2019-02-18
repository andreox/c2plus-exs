#ifndef EXCEP_H
#define EXCEP_H

#include <string>

using namespace std ;

namespace Reg {

	class Excep {

	private :

		string exc ;
		int err ;

	public :

		Excep( const string s , const int n ) : exc(s) , err(n) {}
		const string what() const { return exc ; }
		const int error() const { return err ; }

	};
}

#endif
