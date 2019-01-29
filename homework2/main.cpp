#include <iostream>
#include "Elenco.h"

using namespace std ;

int main() {

	Elenco l ;
	int dim ;

	Voce v1,v2 ;

	create(v1) ;
	write(v1) ;

	char s[buff] ;
	cin >> s ;

	create( v2, 10 , s) ;
	write(v2) ;

	read( l , dim ) ;
	write( l , dim ) ;

	sort(l,dim) ;

	write(l,dim) ;

	Voce t2 ;
	read(t2) ;
	insert_ord( l, dim, t2 ) ;

	write( l, dim ) ;
	remove( l, dim, t2 ) ;

	cout << endl ;
	write( l,dim ) ;
}