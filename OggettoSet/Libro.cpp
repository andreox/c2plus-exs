#include "Libro.h"
#include "Oggetto.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace ONSP {


	Libro::Libro( const int c , const char* d , const char* f , const char* t, const int num) : Oggetto(c,d,f) {

		titolo = new char[strlen(t)+1] ;
		strcpy(titolo,t) ;
		numpagine = num ;
	}

	Libro::Libro( const Libro& l ) {

		titolo = new char[strlen(l.titolo)+1] ;
		strcpy(titolo,l.titolo) ;
		numpagine = l.numpagine ;
	}

	const Libro& Libro::operator=( const Libro& l ) {

		if ( this != &l ) {

			Oggetto::operator=(l) ;
			delete[] titolo ;
			titolo = new char[strlen(l.titolo)+1] ;
			strcpy(titolo,l.titolo) ;
			numpagine = l.numpagine ;
		}

		return *this ;
	}

	ostream& operator<<( ostream& out, Libro& l ) {

		return l.print(out) ;

	}

	istream& operator>>( istream& in, Libro& l ) {

		return l.read(in) ;
	}

	ostream& Libro::print( ostream& out ) {

		Oggetto::print(out) ;
		out << titolo << " " << numpagine << endl ;
		return out ;
	}

	istream& Libro::read( istream& in ) {

		Oggetto::read(in) ;
		char buffer[100] ;
		in.getline(buffer,100) ;
		delete [] titolo ;
		strcpy(titolo,buffer) ;
		in >> numpagine ;
		return in ;
	}

	bool Libro::operator==( const Libro& l ) const{

		if ( Oggetto::operator==(l) && strcmp(titolo,l.titolo) == 0 && numpagine == l.numpagine ) return true ;
		return false ;
	}
}
