#include "Utente.h"
#include "UtentePosta.h"
#include "BadIns.h"
#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std ;
using namespace Posta ;

int main( int argc, char** argv ) {

	ofstream f("file.txt") ;
	Data d(10,7,2000) ;
	Utente * v[5] ;
	Utente u("NDRLSS98L07F8323","Andreozzi",d) ;
	Utente p("KKKKKKKKKKKKKKKK","Mauro",d) ;
	Utente q("OOOOOOOOOOOOOOOO","Gino",d) ;
	UtentePosta u2("9999999999999999","Rossi",d,"rossi@prova.com") ;
	UtentePosta u3("1111111111111111","Verdi",d,"verdiprova.com") ;

	v[0] = &u ;
	v[1] = &p ;
	v[2] = &q ;
	v[3] = &u2 ;
	v[4] = &u3 ;

	for( int i = 0 ; i < 5 ; i++ ) {
		try {

			v[i]->check();
			f << *v[i] << endl ;
		}
		catch(BadIns &b) { cout << b.what() << " " << b.e() << " " << i << endl ; }
	}

	return 0 ;
}
