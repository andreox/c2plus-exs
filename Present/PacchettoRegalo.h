#ifndef PACCHETTOREGALO_H
#define PACCHETTOREGALO_H

#include <iostream>
#include <cstring>

using namespace std ;

namespace Present {

	class PacchettoRegalo {

		friend ostream& operator<<( ostream& , const PacchettoRegalo& );
		friend istream& operator>>(istream& , PacchettoRegalo& ) ;

	private :

		char * destinatario ;
		float peso ;
		char * forma ;

	public :

		PacchettoRegalo() ;
		PacchettoRegalo( const char* , const float , const char* ) ;
		PacchettoRegalo( const PacchettoRegalo&) ;
		const PacchettoRegalo& operator=( const PacchettoRegalo& ) ;

		const char* getDestinatario() const { return destinatario ; }
		const char* getForma() const { return forma ; }
		float getPeso() const { return peso ; }

		~PacchettoRegalo() { delete [] destinatario ; delete [] forma ; }
	};
}

#endif
