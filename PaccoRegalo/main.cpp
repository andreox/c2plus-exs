#include "PaccoRegalo.h"
#include "PilaPacco.h"
#include <iostream>

using namespace Pacco ;
using namespace std ;

int main( int argc, char** argv ) {

	PaccoRegalo p1( 01, 22, "Via 1") ;
	PaccoRegalo p2( 02, 23, "Via 2") ;
	PaccoRegalo p3( 03, 24, "Via 3") ;

	cout << p1 << p2 << p3 ;

	PaccoRegalo p4 = p3 ;
	PaccoRegalo p5 ;
	cin >> p5 ;

	cout << p4 << p5 ;

	PilaPacco p ;
	cout << p.push( p1 ) << endl ;
	cout << p.push( p2 ) << endl ;
	cout << p.push( p3 ) << endl ;
	cout << p.push( p4 ) << endl ;

	PaccoRegalo p6 ;
	p.pop( p6 ) ;

	cout << p6 ;

	return 0 ;
}
