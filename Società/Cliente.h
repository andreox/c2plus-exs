#ifndef CLIENTE_H
#define CLIENTE_H
#define MAX 10

#include <string>
#include <cstring>

using namespace std ;

namespace Societa {

	class Cliente {

	private :

		char codice[MAX];
		string indirizzo ;

	public :

		Cliente() { strcpy(codice,""); }
		Cliente( const char* s , const string s2 ) { strcpy(codice,s) ; indirizzo= s2; }
		inline Cliente& operator=(const Cliente& c) {
			if ( this != &c ) { strcpy(codice,c.codice) ; indirizzo = c.indirizzo ; } return *this ;
		}

		const char* getCodice() const { return codice ; }

	};
}

#endif
