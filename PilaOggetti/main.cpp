#include "Pila.h"
#include "PilaOggetto.h"
#include "Oggetto.h"
#include "BadInsert.h"
#include <iostream>

using namespace std ;

int main( int argc, char** argv ) {

	PilaOggetto p("F01") ;
	Oggetto o1(01,"D01","F01") ;
	Oggetto o2(02,"D02","F02") ;
	Oggetto o3(03,"D03","F01") ;
	Oggetto o5(05,"D05","F01") ;
	Oggetto o6(06,"D06","F01");

	try {

			p.push(o1) ;
			cout << "Inserimento andato a buon fine" << endl ;
		}
	catch( BadInsertExcep &b ) {

			cout << b.getErr() << " " << b.getNumErr() << endl ;

	}

	try {

			p.push(o3) ;
			cout << "Inserimento andato a buon fine" << endl ;
		}
	catch( BadInsertExcep &b ) {

		cout << b.getErr() << " " << b.getNumErr() << endl ;

	}

	try {

			p.push(o5) ;
			cout << "Inserimento andato a buon fine" << endl ;
		}
		catch( BadInsertExcep &b ) {

			cout << b.getErr() << " " << b.getNumErr() << endl ;

		}

	try {

		p.push(o2) ;
		cout << "Inserimento andato a buon fine" << endl ;
	}
	catch( BadInsertExcep &b ) {

		cout << b.getErr() << " " << b.getNumErr() << endl ;

	}

	p.print(cout) ;

	cout << endl << endl ;
	Oggetto o4 ;
	p.pop(o4) ;

	p.print(cout) ;
	cout << endl ;

	return 0 ;
}
