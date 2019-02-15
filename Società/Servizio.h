#ifndef SERVIZIO_H
#define SERVIZIO_H

#include "Prodotto.h"
#include <cstring>

namespace Societa {

	class Servizio : public Prodotto {

	private :

		char * type_ser ;

	public :

		Servizio() : Prodotto() { type_ser = new char[1] ; strcpy(type_ser,"") ;  }
		Servizio( const char* , float, const char* ) ;
		Servizio( const Servizio& ) ;
		Servizio& operator=( const Servizio& ) ;

		virtual float IVA( const char * ) const ;
		virtual const char* getDesc() const { return type_ser ; }
		virtual ~Servizio() { delete [] type_ser ; }

	};
}

#endif
