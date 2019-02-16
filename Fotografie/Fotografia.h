#ifndef FOTOGRAFIA_H
#define FOTOGRAFIA_H

#include <cstring>
#include <iostream>

using namespace std ;

namespace Foto {

	class Fotografia {

		friend ostream& operator<<( ostream& , const Fotografia& ) ;
		friend istream& operator>>( istream& , Fotografia& ) ;

	private :

		char * titolo ;
		char * formato ;

	public :

		Fotografia() { titolo = new char[1] ; formato = new char[1] ; strcpy(titolo,"") ; strcpy(formato,"") ;}
		Fotografia( const char* , const char* ) ;
		Fotografia( const Fotografia& ) ;
		const Fotografia& operator=( const Fotografia& ) ;

		void setTitolo( const char *t ) { delete [] titolo ; titolo = new char[strlen(t)+1] ; strcpy(titolo,t) ;}
		void setFormato( const char *f ) { delete [] formato ; formato = new char[strlen(f)+1] ; strcpy(formato,f) ;}
		const char* getTitolo() const { return titolo ; }
		const char* getFormato() const { return formato ; }

		~Fotografia() { delete [] titolo ; delete [] formato ; }

	};
}
#endif
