#ifndef NOAUTH_H
#define NOAUTH_H

#include <iostream>
#include <string>

using namespace std ;

namespace mynsp {

	class NoAuth {

	private :

		string Mess ;
		int Err ;

	public :

		NoAuth( string m, int e ) { Mess = m ; Err = e ; } ;
		const string getMessage() const { return Mess ; } ;
		const int getError() const { return Err ; } ;

	};
}
#endif
