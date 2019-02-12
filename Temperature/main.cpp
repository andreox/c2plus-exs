#include "Vettore.h"
#include "VettoreRilev.h"
#include "BadData.h"
#include "Rilevamento.h"
#include <iostream>
#include <fstream>

using namespace std ;
using namespace Temperature ;


int main( int argc, char** argv ) {

	VettoreRilev v("Settimanale");
	Rilevamento r1("Campania","Caserta","Aversa") ;
	try {

		r1.setAnno(2019) ;
		r1.setMese(2) ;
		r1.setGiorno(3) ;
		r1.setTmax(15);
		r1.setTmin(6) ;

	}
	catch(  BadData &b ) {

		cout << b.what() << " " << b.error() ;
	}

	Rilevamento r2("Campania","Caserta","Aversa") ;
	try {

		r2.setAnno(2019) ;
		r2.setMese(2) ;
		r2.setGiorno(4) ;
		r2.setTmax(18);
		r2.setTmin(8) ;

	}
	catch(  BadData &b ) {

		cout << b.what() << " " << b.error() ;
	}

	Rilevamento r3("Campania","Caserta","Aversa") ;
	try {

		r3.setAnno(2019) ;
		r3.setMese(2) ;
		r3.setGiorno(5) ;
		r3.setTmax(18);
		r3.setTmin(8) ;

	}
	catch(  BadData &b ) {

		cout << b.what() << " " << b.error() ;
	}

	Rilevamento r4("Campania","Caserta","Aversa") ;
	try {

		r4.setAnno(2019) ;
		r4.setMese(2) ;
		r4.setGiorno(6) ;
		r4.setTmax(20);
		r4.setTmin(9) ;

	}
	catch(  BadData &b ) {

		cout << b.what() << " " << b.error() ;
	}

	Rilevamento r0("Campania","Caserta","Aversa") ;
	try {

		r1.setAnno(2019) ;
		r1.setMese(13) ;
		r1.setGiorno(3) ;

	}
	catch(  BadData &b ) {

		cout << b.what() << " " << b.error() ;
	}

	v.push(r1) ;
	v.push(r2) ;
	v.push(r3) ;
	v.push(r4) ;
	v.stampa(cout) ;

	float media1 ;
	float media2 ;
	v.MedieT( media1 , media2 ) ;
	cout << media1 << " " << media2 << endl ;

	v.Carica_Tmax("file.txt") ;
	v.Carica_Tmin("file.txt") ;

	v.MedieT(media1,media2) ;
	cout << media1 << " " << media2 << endl ;
	return 0 ;
}

