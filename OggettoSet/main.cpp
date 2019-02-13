#include "Oggetto.h"
#include "Libro.h"
#include "Cellulare.h"
#include "BadItem.h"
#include "Set.h"
#include <iostream>

using namespace std ;
using namespace ONSP ;

int main( int argc, char** argv ) {

	Oggetto * v[4] ;
	Libro l(0,"Quadrato","BreveDesc","Ciao",100) ;
	Libro l2(1,"Quadrato","BreveDesc","Ciao2",110) ;
	Cellulare c1(2,"Rettangolare","BreveDesc","S1",200) ;
	Cellulare c2(3,"Rettangolare","BreveDesc","S2",300) ;

	v[0] = &l ;
	v[1] = &l2 ;
	v[2] = &c1 ;
	v[3] = &c2 ;

	Set s ;
	s.push(v[0]) ;
	s.push(v[1]) ;
	s.push(v[2]) ;
	s.push(v[3]) ;
	s.print(cout) ;
	cout << endl << endl ;
	Set s2 ;
	s2.push(v[0]) ;
	s2.push(v[1]) ;

	s.intersection(s2) ;
	s.print(cout) ;
	cout << endl << endl ;

	s2.push(v[2]) ;
	s2.push(v[3]) ;
	s.uniion(s2) ;
	s.print(cout) ;
	cout << endl << endl ;

	Set s3 ;
	s3.push(v[0]) ;

	s.difference(s3) ;
	s.print(cout);

	return 0 ;
}

