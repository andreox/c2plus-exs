#include "Oggetto.h"

Oggetto::Oggetto() {

	Codice = 0 ;
	Descrizione = new char[1] ;
	strcpy( Descrizione, "" ) ;

	Forma = new char[1] ;
	strcpy( Forma, "") ;

}


Oggetto::Oggetto(const int c, const char* d, const char* f ) : Codice(c) {

	Descrizione = new char[ strlen(d)+1] ;
	strcpy( Descrizione, d ) ;

	Forma = new char[ strlen(f)+1] ;
	strcpy( Forma, f ) ;

}

Oggetto::Oggetto( const Oggetto& o ) : Codice(o.Codice) {

	Descrizione = new char[ strlen(o.Descrizione)+1] ;
		strcpy( Descrizione, o.Descrizione ) ;

		Forma = new char[ strlen(o.Forma)+1] ;
		strcpy( Forma, o.Forma ) ;

}

const Oggetto& Oggetto::operator=( const Oggetto& o ) {

	if ( this != &o ) {

		delete [] Descrizione ;
		delete [] Forma ;
		Descrizione = new char[ strlen(o.Descrizione)+1] ;
		strcpy( Descrizione, o.Descrizione ) ;

		Forma = new char[ strlen(o.Forma)+1] ;
		strcpy( Forma, o.Forma ) ;

	}

	return *this;
}

ostream& operator<<( ostream& out, const Oggetto& o ) {

	out << "Codice : " << o.Codice << endl  ;
	out << "Descrizione : " << o.Descrizione << endl ;
	out << "Forma : " << o.Forma << endl  ;

	return out ;

}

istream& operator>>( istream& in, Oggetto& o ) {

	in >> o.Codice ;
	char buffer[100];
	in.ignore() ;
	in.getline(buffer,100);
	o.setDescrizione(buffer) ;

	in.ignore() ;
	in.getline(buffer,100) ;
	o.setForma(buffer) ;

	return in ;
}


