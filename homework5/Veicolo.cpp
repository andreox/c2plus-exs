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

bool Veicolo::operator==( const Veicolo &v) const {

	if ( strcmp( Tipo, v.Tipo ) && strcmp( Marca, v.Marca ) ) return true ;

	return false ;
}
std::ostream& operator<<( std::ostream &out , const Veicolo &v ) {

	std::cout << v.Tipo << " " << v.Marca << std::endl ;

	return out ;
}

std::istream& operator>>( std::istream &in, Veicolo &v ) {

	std::cin >> v.Tipo ;
	std::cin >> v.Marca ;

	return in ;
}
