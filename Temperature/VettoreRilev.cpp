#include "VettoreRilev.h"
#include <iostream>
#include <cstring>
#include "Rilevamento.h"
#include "Vettore.h"

using namespace std ;

namespace Temperature {

	VettoreRilev::VettoreRilev( ) : Vettore() {

		Periodo = new char[1] ;
		strcpy( Periodo,"") ;

	}

	VettoreRilev::VettoreRilev( const VettoreRilev& vr ) : Vettore(vr) {

		Periodo = new char[strlen(vr.Periodo)+1] ;
		strcpy( Periodo, vr.Periodo) ;


	}

	const VettoreRilev& VettoreRilev::operator=( const VettoreRilev& vr ) {

		if ( this != &vr) {
			Vettore::operator=(vr) ;
			delete [] Periodo ;
			Periodo = new char[strlen(vr.Periodo)+1] ;
			strcpy(Periodo,vr.Periodo) ;
		}

		return *this ;
	}

	bool VettoreRilev::Carica_Tmax( string nf ) {

		ifstream in("file.txt") ;
		if ( !in.is_open() ) {

			cout << "Errore nell'apertura" << endl ;
			return false ;

		}

		int t ;
		int dont_care;
		for ( int i = 0 ; i < riemp ; i++ ) {

			in >> t >> dont_care  ;
			v[i].setTmax(t) ;

		}

		in.close() ;
		return true ;
	}

	bool VettoreRilev::Carica_Tmin( string nf) {

		ifstream in("file.txt") ;
		if ( !in.is_open() ) {

			cout << "Errore nell'apertura" << endl ;
			return false ;

		}

		int t ;
		int dont_care;
		for ( int i = 0 ; i < riemp ; i++ ) {

			in >> dont_care >> t  ;
			v[i].setTmin(t) ;
		}

		in.close() ;
		return true ;
	}

	void VettoreRilev::MedieT( float& med_max, float& med_min) const {

		float med1 = 0  ;
		float med2 = 0 ;
		int iterator = 0 ;
		if ( strcmp("Settimanale",Periodo) == 0 ) iterator = 4 ; //Test
		else if ( strcmp("Mensile",Periodo) == 0 ) iterator = 31 ;

		for ( int i = 0 ; i< iterator; i++ ) {

			med1 += v[i].getTmax() ;
			med2 += v[i].getTmin() ;
		}

		med1 = ( med1 / iterator ) ;
		med2 = ( med2 / iterator ) ;
		med_max = med1 ;
		med_min = med2 ;

	}

	void VettoreRilev::stampa( ostream& out ) const {

		for ( int i = 0 ; i < riemp ; i++ ) out << v[i] << Periodo << endl  ;

	}
}

