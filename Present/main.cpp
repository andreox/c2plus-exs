#include "PacchettoRegalo.h"
#include "BadIndex.h"
#include "Vettore.h"
#include <iostream>

using namespace std ;
using namespace Present ;

int main( int argc, char** argv){

	PacchettoRegalo p1( "Alessio",550,"Quadrato") ;
	PacchettoRegalo p2( "Luigi",600,"Fallica") ;
	PacchettoRegalo p3( "Marco",200,"Rettangolo") ;
	PacchettoRegalo p4( "Antonio",150,"Triangolo") ;

	Vettore v ;

	v.push(p1) ;
	v.push(p2) ;
	v.push(p3) ;
	v.push(p4) ;

	cout << v ;

	v[1] = p2 ;
	v[0] = p1 ;
	v[3] = p4 ;
	v[2] = p3 ;
	cout << v ;
	cout << v[2] << endl ;

	return 0 ;
}
