#ifndef NOAUTH_H
#define NOAUTH_H

#include <string>

using std::string ;

class NoAuth {

private :

	string Message ;
	int Err ;

public :
	NoAuth( string m, int e) { Message = m ; Err = e ; } ;
	const string what() { return Message ; } ;
	const float value() { return Err ; } ;


};

#endif
