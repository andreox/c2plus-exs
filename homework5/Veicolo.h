#ifndef VEICOLO_H
#define VEICOLO_H

#include <iostream>

class Veicolo {

	friend std::ostream& operator<<( std::ostream& , const Veicolo& ) ;
	friend std::istream& operator>>( std::istream& , Veicolo& ) ;

protected :

	char * Tipo ;
	char * Marca ;

public :

	Veicolo( const char* , const char* ) ;
	Veicolo( const Veicolo& ) ;
	const Veicolo& operator=( const Veicolo& ) ;

	void setTipo( const char* ) ;
	void setMarca( const char* ) ;

	char* getTipo() const { return Tipo ; } ;
	char* getMarca() const { return Marca ; } ;
	bool operator==( const Veicolo&) const ;


	virtual float calc_pedaggio() const = 0 ;

	virtual ~Veicolo() ;

};

#endif
