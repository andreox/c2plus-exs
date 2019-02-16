#ifndef UTENTE_H
#define UTENTE_H
#define MAX 16

#include <cstring>
#include "Data.h"
#include "BadIns.h"

namespace Posta {

	class Utente {

		friend ostream& operator<<( ostream& , Utente& ) ;
		friend istream& operator>>( istream& , Utente& ) ;
	protected :

		char cod_fis[MAX] ;
		char * cognome ;
		Data registrazione ;
		virtual ostream& print(ostream&) ;
		virtual istream& leggi(istream&) ;

	public :

		Utente() { cognome = new char[1] ; strcpy(cognome,"") ; }
		Utente( const char* , const char* , const Data& ) ;
		Utente( const Utente& ) ;
		const Utente& operator=( const Utente& ) ;

		inline bool operator==( const Utente& u ) const { return ( strcmp(cod_fis,u.cod_fis) && strcmp(cognome,u.cognome) && registrazione == u.registrazione) ;}
		bool operator!=( const Utente& u ) const { return !(*this==u) ;}

		virtual bool check() throw(BadIns) ;
		virtual ~Utente() { delete [] cognome ; }
	};


}
#endif

