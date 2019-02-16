#include "Utente.h"
#include <cstdlib>
#include <ctype.h>

namespace Posta {

	Utente::Utente( const char* cod , const char* cog , const Data& d ) {

		for ( int i = 0 ; i < MAX ; i++ ) cod_fis[i] = cod[i] ;
		cognome = new char[strlen(cog)+1] ;
		strcpy(cognome,cog) ;
		registrazione = d ;
	}

	Utente::Utente( const Utente &u ) {

		strcpy( cod_fis , u.cod_fis ) ;
		cognome = new char[strlen(u.cognome)+1] ;
		strcpy(cognome,u.cognome) ;
		registrazione = u.registrazione ;
	}

	const Utente& Utente::operator=( const Utente &u ) {

		if ( this != &u) {

			delete [] cognome ;
			strcpy( cod_fis , u.cod_fis ) ;
			cognome = new char[strlen(u.cognome)+1] ;
			strcpy(cognome,u.cognome) ;
			registrazione = u.registrazione ;
		}

		return *this ;
	}

	ostream& operator<<( ostream& out, Utente& u ) { return u.print(out) ; }
	istream& operator>>( istream& in , Utente& u ) { return u.leggi(in) ; }

	ostream& Utente::print( ostream& out ) {

		out << "CODICE FISCALE : " << cod_fis << endl ;
		out << "COGNOME : " << cognome << endl ;
		out << "DATA REGISTRAZIONE : " << registrazione << endl ;
		return out ;
	}

	istream& Utente::leggi( istream& in ) {

		char buffer[100] ;
		in.getline(buffer,20) ;
		strcpy(cod_fis,buffer) ;
		in.getline(buffer,100) ;
		delete [] cognome ;
		cognome = new char[strlen(buffer)+1] ;
		strcpy(cognome,buffer) ;
		in >> registrazione ;
		return in ;
	}

	bool Utente::check() throw(BadIns)  {

		for ( int i = 0 ; i < MAX ; i++ ) {
			if( !isalnum(cod_fis[i]) ) {
				BadIns b("Errore nel cod fis",i) ;
				throw b ;
				return false ;
			}
		}

		return true ;
	}
}
