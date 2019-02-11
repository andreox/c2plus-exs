#ifndef OGGETTO_H
#define OGGETTO_H

#include <iostream>
#include <cstring>

using namespace std ;

class Oggetto {

	friend ostream& operator<<( ostream& , const Oggetto& ) ;
	friend istream& operator>>( istream&, Oggetto& ) ;
private :

	int Codice ;
	char * Descrizione ;
	char * Forma ;

public :

	Oggetto() ;
	Oggetto( const int, const char* , const char* ) ;
	Oggetto( const Oggetto& ) ;
	const Oggetto& operator=( const Oggetto& ) ;

	const int getCodice() const { return Codice ; } ;
	const char* getDescrizione() const { return Descrizione ; } ;
	char* getForma() const { return Forma ; } ;

	void setCodice( const int c ) { Codice = c ; } ;
	inline void setDescrizione( const char* d ) { delete [] Descrizione ; Descrizione = new char[strlen(d)+1] ; strcpy( Descrizione,d ) ; } ;
	inline void setForma( const char* f ) { delete [] Forma ; Forma = new char[ strlen(f)+1] ; strcpy( Forma,f ) ; } ;

	~Oggetto() { delete [] Descrizione; delete[] Forma ; } ;

};

#endif
