#ifndef UTENTEPOSTA_H
#define UTENTEPOSTA_H

#include "Utente.h"
#include "Data.h"
#include "BadIns.h"

namespace Posta {

	class UtentePosta : public Utente {

		friend ostream& operator<<( ostream& , UtentePosta& ) ;
		friend istream& operator>>( istream& , UtentePosta& ) ;

	private :

		char * mail ;
		virtual ostream& print(ostream&)  ;
		virtual istream& leggi(istream&) ;
	public :

		UtentePosta() : Utente() { mail = new char[1] ; strcpy(mail,"") ; }
		UtentePosta( const char* cf , const char* cg , const Data& d, const char* m) : Utente(cf,cg,d) { mail = new char[strlen(m)+1] ; strcpy(mail,m) ;}
		UtentePosta( const UtentePosta& u ) : Utente(u) { mail = new char[strlen(u.mail)+1] ; strcpy(mail,u.mail) ;}
		UtentePosta& operator=( const UtentePosta& u ) ;

		inline bool operator==( const UtentePosta& u ) const { return ( strcmp(cod_fis,u.cod_fis) && strcmp(cognome,u.cognome) && registrazione == u.registrazione && strcmp(mail,u.mail)) ;}
		bool operator!=( const UtentePosta& u ) const { return !(*this==u) ;}

		virtual bool check() throw(BadIns) ;
		virtual ~UtentePosta() { delete [] mail ;}
	};
}

#endif


