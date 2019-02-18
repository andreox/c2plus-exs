#include "EntryStudente.h"

namespace Reg {

	EntryStudente::EntryStudente( const char* n , const char* c , const char* i ) {

		strcpy(ID,i) ;
		nome = new char[strlen(n)+1] ;
		strcpy(nome,n) ;
		cognome = new char[strlen(c)+1] ;
		strcpy(cognome,c) ;
	}

	EntryStudente::EntryStudente( const EntryStudente& e ) {

		strcpy(ID,e.ID) ;
		nome = new char[strlen(e.nome)+1] ;
		cognome = new char[strlen(e.cognome)+1] ;
		strcpy(nome,e.nome) ;
		strcpy(cognome,e.cognome) ;

	}

	const EntryStudente& EntryStudente::operator=( const EntryStudente& e ) {

		if ( this != &e ) {

			delete [] nome ;
			delete [] cognome ;
			strcpy(ID,e.ID) ;
			nome = new char[strlen(e.nome)+1] ;
			cognome = new char[strlen(e.cognome)+1] ;
			strcpy(nome,e.nome) ;
			strcpy(cognome,e.cognome) ;
		}

		return *this ;
	}

	ostream& EntryStudente::print( ostream& out ) const {

		out << "Nome : " << nome << endl ;
		out << "Cognome : " << cognome << endl ;
		//Non stampo ID
		return out ;
	}

	istream& EntryStudente::read( istream& in ) {

		char buffer[100] ;
		in.getline(buffer,100) ;
		setNome(buffer) ;
		in.getline(buffer,100) ;
		setCognome(buffer) ;
		in.getline(buffer,11) ;
		setID(buffer) ;
		return in ;
	}
}
