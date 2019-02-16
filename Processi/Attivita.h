#ifndef ATTIVITA_H
#define ATTIVITA_H

#include <iostream>
#include <cstring>

using namespace std ;

namespace Processi {

	class Attivita {

		friend ostream& operator<<( ostream& , Attivita& ) ;
		friend istream& operator>>( istream& , Attivita& ) ;

	protected :

		int PID ;
		char * descrizione;
		bool started ;
		virtual ostream& stampa( ostream& ) ;
		virtual istream& leggi( istream& ) ;

	public :

		Attivita() { descrizione = new char[1] ; strcpy(descrizione,""); PID = 0 ; started = false; }
		Attivita( const int , const char* , const bool ) ;
		Attivita( const Attivita& ) ;
		const Attivita& operator=( const Attivita& ) ;

		void setPID(int p ) { PID = p ; }
		inline void setDescrizione( const char* d ) { delete [] descrizione ; descrizione = new char[strlen(d)+1] ; strcpy(descrizione,d) ;}
		void setStarted(bool t) { started = t ; }
		int getPID() const { return PID ; }
		const char* getDescrizione() const { return descrizione ;}
		bool hasStarted() const { return started ; }

		virtual inline bool Attiva() { if ( !started) { started=true ; return true ; } return false ;}
		virtual ~Attivita() { delete [] descrizione ; }

	};
}
#endif
