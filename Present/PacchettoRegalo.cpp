#include "PacchettoRegalo.h"


namespace Present {

	PacchettoRegalo::PacchettoRegalo() {

		destinatario = new char[1] ;
		forma = new char[1] ;
		strcpy(destinatario,"") ;
		strcpy(forma,"") ;
		peso = 0 ;
	}

	PacchettoRegalo::PacchettoRegalo( const char* d , const float p , const char* f ) {

		destinatario = new char[strlen(d)+1] ;
		forma = new char[strlen(f)+1] ;
		peso = p ;
		strcpy(destinatario,d) ;
		strcpy(forma,f) ;
	}

	PacchettoRegalo::PacchettoRegalo( const PacchettoRegalo& p ) {

		destinatario = new char[strlen(p.destinatario)+1] ;
		strcpy( destinatario, p.destinatario ) ;
		forma = new char[strlen(p.forma)+1] ;
		strcpy(forma,p.forma) ;
		peso = p.peso ;
	}

	const PacchettoRegalo& PacchettoRegalo::operator=( const PacchettoRegalo &p ) {

		if ( this != &p ) {

			delete [] destinatario ;
			delete [] forma ;
			destinatario = new char[strlen(p.destinatario)+1] ;
			strcpy( destinatario, p.destinatario ) ;
			forma = new char[strlen(p.forma)+1] ;
			strcpy(forma,p.forma) ;
			peso = p.peso ;
		}

		return *this ;
	}

	ostream& operator<<( ostream& out , const PacchettoRegalo &p ) {

		out << p.destinatario << " " << p.peso << " " << p.forma << endl ;
		return out ;
	}

	istream& operator>>( istream& in, PacchettoRegalo &p ) {

		char buffer[100] ;
		in.getline(buffer,100) ;
		delete [] p.destinatario ;
		p.destinatario = new char[strlen(buffer)+1] ;
		strcpy( p.destinatario, buffer) ;

		in >> p.peso ;
		in.ignore() ;
		in.getline(buffer,100) ;
		delete [] p.forma ;
		p.forma = new char[strlen(buffer)+1] ;
		strcpy( p.forma, buffer ) ;

		return in ;
	}
}
