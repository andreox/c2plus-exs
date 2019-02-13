#ifndef OGGETTO_H
#define OGGETTO_H

#include <iostream>
#include <cstring>

using namespace std ;

namespace ONSP {

	class Oggetto {

		friend ostream& operator<<( ostream& , Oggetto& ) ;
		friend istream& operator>>( istream&, Oggetto& ) ;

	protected :

		int cod ;
		char *desc ;
		char *forma ;

	public :

		Oggetto() ;
		Oggetto( const int, const char* , const char* ) ;
		Oggetto( const Oggetto& );
		const Oggetto& operator=( const Oggetto& ) ;

		int getCod() const { return cod ; }
		const char* getDesc() const { return desc ; }
		const char* getForma() const { return forma ; }

		virtual ostream& print(ostream&) ;
		virtual istream& read(istream&) ;

		void setCod( int c ) { cod= c ; }
		inline void setDesc( const char* d ) { delete [] desc ; desc = new char[strlen(d)+1] ; strcpy(desc,d) ; }
		inline void setForma( const char* f ) { delete [] forma ; forma = new char[strlen(f)+1] ; strcpy(forma,f) ; }
		bool operator==(const Oggetto& ) const ;

		virtual ~Oggetto() { delete [] desc ; delete[] forma ; }
	};
}

#endif
