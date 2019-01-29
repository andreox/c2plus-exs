#include "Voci.h"
#include <iostream>
#include <cstring>

using namespace std ;

void create( Voce &v ) {

	v.key = 0 ;
	v.descr = new char[buff] ;

}

void create( Voce &v , const int k , const char* descr ) {

	v.key = k ;
	v.descr = new char[strlen(descr)+1] ;
	strcpy( v.descr, descr ) ;

}

void read( Voce& e) {

	char str[buff+1] ;

	cout << "Inserire la chiave : " ;
	cin >> e.key ;

	cout << "Inserire la descrizione : " ;
	cin.ignore() ;
	cin.getline( str, buff) ;

	e.descr = new char[strlen(str)+1] ;
	strcpy( e.descr, str) ;

}

void write( const Voce e ) {

	cout << "KEY : " << e.key << endl ;
	if ( e.descr != nullptr ) cout << "DESCRIZIONE : " << e.descr << endl ;
	else cout << "DESCRIZIONE : NULL" << endl ;
	

}

void copy( Voce &e1 , Voce &e2 ) {

	e1.key = e2.key ;
	strcpy( e1.descr, e2.descr ) ;

}

bool greater_than( const Voce e1, const Voce e2) {

	if ( e1.key >= e2.key ) return true ;
	return false ;

}

bool equal( const Voce e1, const Voce e2 ) {

	if ( e1.key == e2.key && strcmp(e1.descr,e2.descr)==0 ) return true ;
	return false ;
}

void destroy( Voce &e ) {

	delete [] e.descr ;
	e.key = 0 ;
	e.descr = nullptr ;

}