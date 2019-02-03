#include "AutoVettura.h"
#include <cstring>

AutoVettura::AutoVettura( const char* tipo, const char* marca, const char* modello, const int classe ) : Veicolo(tipo,marca) {

	Modello = new char[strlen(modello)+1] ;
	strcpy( Modello, modello) ;

	Classe = classe ;

}

AutoVettura::AutoVettura( const AutoVettura &a ) : Veicolo(a) {

	Tipo = new char[strlen(a.Tipo)+1] ;
	Marca = new char[strlen(a.Marca)+1] ;
	Modello = new char[strlen(a.Modello)+1] ;
	strcpy(Tipo, a.Tipo ) ;
	strcpy( Marca, a.Marca ) ;
	strcpy( Modello, a.Modello ) ;

	Classe = a.Classe ;

}

const AutoVettura& AutoVettura::operator=( const AutoVettura &a ) {

	if ( this != &a ) {

		delete [] Tipo ;
		delete [] Marca ;
		delete [] Modello ;

		Tipo = new char[strlen(a.Tipo)+1] ;
		Marca = new char[strlen(a.Marca)+1] ;
		Modello = new char[strlen(a.Modello)+1] ;
		strcpy(Tipo, a.Tipo ) ;
		strcpy( Marca, a.Marca ) ;
		strcpy( Modello, a.Modello ) ;

		Classe = a.Classe ;
	}

	return *this ;
}

void AutoVettura::setModello( const char* mod ) {

	 delete[] Modello ;
	 Modello = new char[ strlen(mod)+1] ;

	 strcpy( Modello, mod ) ;
}

void AutoVettura::setClasse( const int c ) { Classe = c ; }

bool AutoVettura::operator==( const AutoVettura &a ) const {

	if ( strcmp(Tipo, a.Tipo) && strcmp( Modello, a.Modello) && strcmp(Marca, a.Marca) && Classe == a.Classe ) return true ;
	return false ;
}

bool AutoVettura::operator !=( const AutoVettura&a ) const {

	if ( !strcmp( Tipo, a.Tipo ) || !strcmp(Modello , a.Modello) || !strcmp(Marca, a.Marca) || Classe != a.Classe ) return true ;

	return false ;

}

bool AutoVettura::operator<( const AutoVettura &a ) const {

	if ( Classe < a.Classe ) return true ;
	return false ;
}

bool AutoVettura::operator>( const AutoVettura &a ) const {

	if ( Classe > a.Classe ) return true ;
	return false ;

}

float AutoVettura::calc_pedaggio() const {

	if ( Classe >= 2 && Classe <= 8 )
	return pedaggi[(Classe-2)] ;

	return -1 ;

}

std::ostream& operator<<( std::ostream &out, const AutoVettura &a ) {

	out << "Tipo : " << a.Tipo << std::endl ;
	out << "Marca : " << a.Marca << std::endl ;
	out << "Modello : " << a.Modello << std::endl ;
	out << "Classe : " << a.Classe << std::endl ;

	return out ;
}

std::istream& operator>>( std::istream &in , AutoVettura &a ) {

	in >> a.Tipo ;
	in >> a.Marca ;
	in >> a.Modello ;
	in >> a.Classe ;

	return in ;

}

AutoVettura::~AutoVettura() {

	delete [] Tipo ;
	delete [] Marca ;
	delete [] Modello ;

}
