#include "Rilevamento.h"
#include "BadData.h"
#include <iostream>

using namespace std ;

namespace Temperature {


	Rilevamento::Rilevamento() {

		regione = "";
		provincia = "" ;
		citta = "" ;
		anno = 0;
		mese = 0  ;
		giorno = 0  ;
		T_max = 0 ;
		T_min = 0 ;
	}
	void Rilevamento::setMese( const int m ) throw(BadData) {

		if ( m <= 0 || m > 12 ) {

			BadData b("Mese incorretto",m) ;
			throw b ;
		}

		else mese = m ;

	}

	void Rilevamento::setGiorno( const int g ) throw(BadData) {

		if ( g <= 0 || g > 31 ) {

			BadData b("Giorno incorretto",g) ;
			throw b ;
		}

		else giorno = g ;
	}

	ostream& operator<<( ostream& out , const Rilevamento& r ) {

		out << r.regione << " "
				<< r.citta << " "
				<< r.provincia << " "
				<< r.giorno << "/"
				<< r.mese << "/"
				<< r.anno << " "
				<< r.T_max << "C° "
				<< r.T_min << "C° " << endl ;

		return out ;

	}

	istream& operator>>( istream& in , Rilevamento &r ) {

		in >> r.regione ;
		in >> r.citta ;
		in >> r.provincia ;
		in >> r.giorno ;
		in >> r.mese ;
		in >> r.anno ;
		in >> r.T_max ;
		in >> r.T_min ;

		return in ;

	}

	const Rilevamento& Rilevamento::operator=( const Rilevamento &r ) {

		if ( this != &r ) {

			regione = r.regione ;
			citta = r.citta ;
			provincia = r.provincia ;
			giorno = r.giorno ;
			mese = r.mese ;
			anno = r.anno;
			T_max = r.T_max ;
			T_min = r.T_min ;
		}

		return *this ;
	}
}
