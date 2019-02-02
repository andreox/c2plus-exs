#ifndef AUTOVETTURA_H
#define AUTOVETTURA_H

#include <iostream>
#include "Veicolo.h"

class AutoVettura : public Veicolo {

	friend std::ostream& operator<<( std::ostream& , const AutoVettura& ) ;
	friend std::istream& operator>>( std::istream& , AutoVettura& ) ;

protected :

	char * Modello ;
	int Classe ;
	const float pedaggi[7] = { 1, 1.60, 2.05, 2.55, 3.00, 3.45, 3.90 } ;


public :

	AutoVettura( const char* , const char* , const char* , const int ) ;
	AutoVettura( const AutoVettura& ) ;
	const AutoVettura& operator=( const AutoVettura& ) ;


	void setModello( const char* ) ;
	void setClasse( const int ) ;

	char* getModello() const { return Modello ; } ;
	int getClasse() const { return Classe ; } ;

	bool operator==( const AutoVettura& ) const ;
	bool operator!=( const AutoVettura& ) const ;
	bool operator<(const AutoVettura& ) const ;
	bool operator>( const AutoVettura& ) const ;

	virtual float calc_pedaggio() const ;

	virtual ~AutoVettura() ;

};

#endif
