#include "Attivita.h"

namespace Processi {

	Attivita::Attivita( const int p , const char* d , bool t ) {

		PID = p ;
		descrizione = new char[strlen(d)+1] ;
		strcpy(descrizione,d) ;
		started = t;
	}

	Attivita::Attivita( const Attivita& a ) {
		PID = a.PID ;
		descrizione = new char[strlen(a.descrizione)+1] ;
		strcpy(descrizione,a.descrizione) ;
		started = a.started ;
	}

	const Attivita& Attivita::operator=( const Attivita &a ) {

		if ( this != &a ) {

			delete [] descrizione ;
			PID = a.PID ;
			descrizione = new char[strlen(a.descrizione)+1] ;
			strcpy(descrizione,a.descrizione) ;
			started = a.started ;
		}

		return *this ;
	}

	ostream& Attivita::stampa( ostream& out ) {

		out << "PID : " << PID << endl  ;
		out << "Descrizione : " << descrizione << endl ;
		if ( started ) out << "Attivato" << endl ;
		else out << "Inattivo" << endl ;

		return out ;
	}
	ostream& operator<<( ostream& out , Attivita &a ) {

		return a.stampa(out) ;
	}

	istream& Attivita::leggi( istream& in ) {

		in >> PID ;
		in.ignore() ;
		char buffer[100] ;
		in.getline(buffer,100) ;
		setDescrizione(buffer) ;
		in >> started ;

		return in ;
	}
	istream& operator>>( istream& in , Attivita &a ) {

		return a.leggi(in) ;

	}
}
