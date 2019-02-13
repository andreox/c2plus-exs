#ifndef LIBRO_H
#define LIBRO_H

#include "Oggetto.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace ONSP {

	class Libro : public Oggetto {

		friend ostream& operator<<( ostream&, Libro&) ;
		friend istream& operator>>( istream&, Libro& ) ;

	private :

		char * titolo ;
		int numpagine ;

	public :

		Libro() : Oggetto() { titolo = new char[1]; strcpy(titolo,"") ; numpagine=0; }
		Libro( const int, const char*,const char*, const char* , const int ) ;
		Libro( const Libro& ) ;
		const Libro& operator=( const Libro& ) ;

		inline void setTitolo( const char* t ) { delete [] titolo ; titolo = new char[strlen(t)+1] ; strcpy(titolo,t) ;}
		void setNumPagine( int n ) { numpagine = n ; }

		const char* getTitolo() const { return titolo ; }
		const int getNumPagine() const { return numpagine ; }
		virtual bool operator==(const Libro& l ) const ;

		virtual ostream& print(ostream&) ;
		virtual istream& read( istream& ) ;

		virtual ~Libro() { delete [] titolo ; }
	};
}

#endif

