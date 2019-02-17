#include "Brano.h"
#include <fstream>

namespace File {

	Brano::Brano( const char* u , const int k , const char* f , const char* b , const float d , const char* i ) : FileMultimediale(u,k,f) {

		bra = new char[strlen(b)+1] ;
		strcpy(bra,b) ;
		Interprete = new char[strlen(i)+1] ;
		strcpy(Interprete,i) ;
		durata = d ;
	}

	Brano::Brano( const Brano& b ) : FileMultimediale(b) {

		bra = new char[strlen(b.bra)+1] ;
		strcpy(bra,b.bra) ;
		Interprete = new char[strlen(b.Interprete)+1] ;
		strcpy(Interprete, b.Interprete ) ;
		durata = b.durata ;
	}

	const Brano& Brano::operator=( const Brano& b ) {

		if ( this != &b ) {

			FileMultimediale::operator=(b) ;
			delete [] bra ;
			delete [] Interprete ;
			bra = new char[strlen(b.bra)+1] ;
			strcpy(bra,b.bra) ;
			Interprete = new char[strlen(b.Interprete)+1] ;
			strcpy(Interprete, b.Interprete ) ;
			durata = b.durata ;

		}

		return *this ;
	}

	bool Brano::memorizza_dati( ofstream& file ) {

		if ( !file.is_open() ) return false ;
		file << *this ;
		return true ;

	}

	ostream& Brano::print( ostream& out ) {

		FileMultimediale::print(out) ;
		out << "Brano: " << bra << endl ;
		out << "Interprete : "<< Interprete << endl ;
		out << "Durata : " << durata << endl ;
		return out ;
	}

	istream& Brano::read( istream& in ) {

		FileMultimediale::read(in) ;
		in.ignore() ; //cin nell'ultimo metodo richiamato
		char buffer[100] ;
		in.getline(buffer,100) ;
		delete [] bra ;
		bra = new char[strlen(buffer)+1] ;
		strcpy(bra,buffer) ;

		delete [] Interprete ;
		in.getline(buffer,100) ;
		Interprete = new char[strlen(buffer)+1] ;
		strcpy(Interprete,buffer) ;

		in >> durata ;
		return in ;
	}
}




