#include "Ordine.h"
#include "Cliente.h"
#include "Prodotto.h"
#include "Bene.h"
#include "Servizio.h"
#include "BadIns.h"
#include <iostream>

using namespace std ;
using namespace Societa ;

int main( int argc, char** argv ) {

	Prodotto * v[10] ;
	Bene b1("049",1,"Descr",false) ;
	Bene b2("048",2.5,"Descr",false) ;
	Bene b3("050",50,"Descr",false) ;
	Servizio s1("020",80,"Descr") ;
	Servizio s2("039",100,"Descr") ;
	Servizio s3("040",200,"Descr") ;
	Servizio s4("031",51,"Descr") ;
	Servizio s5("032",90,"Descr") ;
	Cliente c("0111","Via Da Me") ;
	Ordine o(c) ;

	v[0] = &b1 ;
	v[1] = &b2 ;
	v[2] = &b3 ;
	v[3] = &s1 ;
	v[4] = &s2 ;
	v[5] = &s3 ;
	v[6] = &s4 ;
	v[7] = &s5;

	try {

		for ( int i = 0 ; i < 8 ; i++ ) o.aggiungiProdotto(*v[i],i+2) ;
	}


	catch(BadIns& b){ cout << b.what() << endl ; }

	o.stampa() ;
	return 0 ;
}
