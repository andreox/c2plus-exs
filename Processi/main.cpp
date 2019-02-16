#include "Attivita.h"
#include "Processo.h"
#include "CodaProcessi.h"
#include "BadIns.h"
#include <iostream>

using namespace std ;
using namespace Processi ;

int main( int argc, char** argv ) {

	Attivita *a1 = new Attivita( 0 , "attivita1" , false ) ;
	Attivita *a2 = new Attivita( 1 , "attivita2" , true ) ;
	Attivita *a3 = new Attivita( 2 , "attivita3" , true ) ;
	Attivita *a4 = new Processo( 3 , "processo4" , true , "nome1" , 'R') ;
	Attivita *a5 = new Processo( 4 , "processo5" , true , "nome2" , 'R' ) ;
	Attivita *a6 = new Processo( 5 , "processo6" , false , "nome3" , 'P') ;
	Attivita *a7 = new Processo(6,"processo7",false,"nome4",'W') ;
	CodaProcessi c ;
	c.push(a1) ;
	c.push(a2) ;
	c.push(a3) ;
	c.push(a4) ;
	c.push(a5) ;
	a6->Attiva() ;
	c.push(a6) ;
	try {
		c.push(a2) ;

	}
	catch( BadIns &b ) { cout << b.what() << endl ;}
	cout << c.getP() << endl ;
	c.Show() ;
	c.Store("file.txt") ;

	Attivita * a ;
	c.pop(a) ;
	cout << *a << endl ;
	c.Store("file.txt") ;
	return 0 ;
}
