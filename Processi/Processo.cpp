#include "Processo.h"

namespace Processi {

	Processo::Processo( const int p , const char* d , bool t , const char* n , const char s ) : Attivita(p,d,t) {

		nome_img = new char[strlen(n)+1] ;
		strcpy(nome_img,n) ;
		state = s ;
	}

	Processo::Processo( const Processo& p ) : Attivita(p) {

		nome_img = new char[strlen(p.nome_img)+1] ;
		strcpy(nome_img,p.nome_img) ;
		state = p.state ;

	}

	const Processo& Processo::operator=( const Processo &p ) {

		if( this != &p ) {

			Attivita::operator=(p) ;
			delete [] nome_img ;
			nome_img = new char[strlen(p.nome_img)+1] ;
			strcpy(nome_img,p.nome_img) ;
			state = p.state ;
		}

		return *this;
	}

	ostream& operator<<(ostream& out , Processo& p ) { return p.stampa(out) ; }
	istream& operator>>(istream& in , Processo& p ) { return p.leggi(in) ; }

	ostream& Processo::stampa( ostream& out ) {

		Attivita::stampa(out) ;
		out << "Nome Immagine : " << nome_img << endl ;
		out << "Stato : " << state << endl ;
		return out ;
	}

	istream& Processo::leggi( istream& in ) {

		Attivita::leggi(in) ;
		in.ignore() ;
		char buffer[100] ;
		in.getline(buffer,100) ;
		setnome_img(buffer) ;
		in >> state ;

		return in ;
	}
}



