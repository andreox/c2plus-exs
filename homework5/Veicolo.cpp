#include "Veicolo.h"
#include <iostream>
#include <cstring>

Veicolo::Veicolo( const char* tipo, const char* marca ) {

	Tipo = new char[strlen(tipo)+1] ;
	strcpy( Tipo, tipo ) ;

	Marca = new char[strlen(marca)+1] ;
	strcpy( Marca, marca ) ;


}

Veicolo::Veicolo( const Veicolo& v ) {

	Tipo = new char[strlen(v.Tipo) +1 ] ;
	Marca = new char[strlen(v.Marca) + 1] ;
	strcpy( Tipo, v.Tipo ) ;
	strcpy( Marca, v.Marca ) ;

}

const Veicolo& Veicolo::operator=( const Veicolo &v ) {

	if ( this != &v ) {

		delete [] Tipo ;
		delete [] Marca ;
		Tipo = new char[strlen(v.Tipo) +1 ] ;
		Marca = new char[strlen(v.Marca) + 1] ;
		strcpy( Tipo, v.Tipo ) ;
		strcpy( Marca, v.Marca ) ;

	}

	return *this ;

}

void Veicolo::setTipo( const char* tipo ) {

	delete[] Tipo ;
	Tipo = new char[strlen(tipo)+1] ;
	strcpy( Tipo, tipo ) ;

}

void Veicolo::setMarca( const char* marca ) {

	delete [] Marca ;
	Marca = new char[strlen(marca)+1] ;
	strcpy( Marca, marca ) ;

}

Veicolo::~Veicolo() {

	delete [] Marca ;
	delete [] Tipo ;

}
}
