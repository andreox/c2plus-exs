#include "UtentePosta.h"

namespace Posta {

	UtentePosta& UtentePosta::operator=( const UtentePosta &u ) {

		if ( this!= &u ) {

			Utente::operator=(u) ;
			delete [] mail ;
			mail = new char[strlen(u.mail)+1] ;
			strcpy(mail,u.mail) ;

		}
		return *this ;
	}

	ostream& operator<<( ostream& out, UtentePosta& u ) { return u.print(out) ; }
	istream& operator>>( istream& in , UtentePosta& u ) { return u.leggi(in) ; }

	ostream& UtentePosta::print( ostream& out ) {

		Utente::print(out) ;
		out << "E-MAIL : " << mail << endl;
		return out ;
	}

	istream& UtentePosta::leggi( istream& in ) {

		Utente::leggi(in) ;
		char buffer[100] ;
		delete [] mail ;
		mail = new char[strlen(buffer)+1] ;
		strcpy(mail,buffer) ;
		return in ;
	}

	bool UtentePosta::check() throw(BadIns) {

		if ( Utente::check() ) {

			int count = 0 ;
			for ( int i = 0 ; i< strlen(mail) ; i++ ) if( mail[i] == '@') count++ ;
			if ( count == 0 || count > 1 ) {

				BadIns b("Errore nella mail",2) ;
				throw b ;
				return false ;
			}

		}

		return true ;
	}
}
