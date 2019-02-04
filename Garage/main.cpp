#include "Veicolo.h"
#include "Automobile.h"
#include "Motocicletta.h"
#include "NoAuth.h"
#include "Garage.h"
#include <iostream>
#include <fstream>

using mynsp::Veicolo ;
using mynsp::Automobile ;
using mynsp::Motocicletta ;
using mynsp::NoAuth ;

int main( int argc, char** argv ) {

	Veicolo * v[10] ;

	Automobile a1( "NT1", "MB" , "Benzina" ) ;
	v[0] = &a1 ;
	Automobile a2( "NT2" , "AUDI", "Diesel") ;
	v[1] = &a2 ;
	Motocicletta m1( "NT3" , "HARLEY" , "Benzina" ) ;
	v[2] = &m1 ;
	Motocicletta m2( "NT4" , "SUZUKI" , "Diesel") ;
	v[3] = &m2 ;

	Garage g ;
	cout << g.push( v[0] ) << endl ;
	cout << g.push( v[1] ) << endl ;
	cout << g.push( v[2] ) << endl ;
	cout << g.push( v[3] )  << endl ;
	Motocicletta m3 = m1 ;
	cout << g.push( &m3 ) << endl ;

	Veicolo *v2 = g.pop(2) ;
	cout << *v2 << endl ;

	ofstream of("output.txt") ;
	g.print() ;
	g.print(of) ;

	return 0 ;

}
