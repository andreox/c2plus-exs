#ifndef ENTRYSTUDENTE_H
#define ENTRYSTUDENTE_H
#define MAX 10

#include <iostream>
#include <cstring>

using namespace std ;

namespace Reg {

	class EntryStudente {

		friend ostream& operator<<(ostream& out , const EntryStudente& e) { return e.print(out); }
		friend istream& operator>>( istream& in , EntryStudente& e) { return e.read(in) ; }

	protected :

		char * nome ;
		char * cognome ;
		char ID[MAX] ;
		virtual ostream& print( ostream& ) const ;
		virtual istream& read( istream& ) ;

	public :

		EntryStudente() { nome = new char[1] ; cognome = new char[1] ; strcpy(nome,"") ; strcpy(cognome,"") ;}
		EntryStudente( const char* , const char* , const char* ) ;
		EntryStudente( const EntryStudente& ) ;
		const EntryStudente& operator=( const EntryStudente& ) ;

		void setNome( const char* n ) { delete [] nome ; nome = new char[strlen(n)+1] ; strcpy(nome,n) ; }
		void setCognome( const char* c ) { delete [] cognome ; cognome = new char[strlen(c)+1] ; strcpy(cognome,c) ; }
		void setID( const char* i ) { strcpy(ID,i) ; }

		const char* getNome() const { return nome ; }
		const char* getCognome() const { return cognome ; }
		const char* getID() const { return ID ; }

		virtual ~EntryStudente() { delete [] nome ; delete [] cognome ; }
	};
}
#endif
