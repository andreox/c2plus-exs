#include <iostream>
#include "Registro.h"
#include "Excep.h"
#include "Data.h"
#include "EntryStudenteReg.h"
#include "EntryStudente.h"

using namespace std ;
using namespace Reg ;

int main( int argc, char** argv ) {

	EntryStudenteReg e1("Andreozzi","Alessio","101",false) ;
	EntryStudenteReg e2("Cacciapuoti","Luigi","102",false) ;
	EntryStudenteReg e3("Andreozzo","Pino","103",false) ;
	EntryStudenteReg e4 = e3 ;

	Data d(20,10,2015) ;
	Registro r("P1","Vittorini Valeria","C1",0,d) ;
	try {

		r.Inserisci(e1) ;
		r.print() ;
	} catch (Excep &e ) { cout << e.what() << endl ;}

	try {

		r.Inserisci(e2) ;
		r.print() ;
	} catch (Excep &e ) { cout << e.what() << endl ;}

	try {

		r.Inserisci(e3) ;
		r.print();
	} catch (Excep &e ) { cout << e.what() << endl ;}

	try {

		r.Inserisci(e4) ;
	} catch (Excep &e ) { cout << e.what() << endl ;}

	r.print() ;
	return 0 ;
}
