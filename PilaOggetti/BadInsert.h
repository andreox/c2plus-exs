#ifndef BADINSERT_H
#define BADINSERT_H

#include <string>

using namespace std ;

class BadInsertExcep {

private :

	string Err ;
	int numerr ;

public :

	BadInsertExcep( const string e, const int nume) : Err(e) , numerr(nume) {} ;
	string getErr() const { return Err ; } ;
	int getNumErr() const { return numerr ; } ;

};

#endif
