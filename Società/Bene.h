#ifndef BENE_H
#define BENE_H

#include "Prodotto.h"
#include <cstring>

namespace Societa {

	class Bene : public Prodotto {

	private :

		char * desc ;
		bool first_nec ;

	public :

		Bene() : Prodotto() { desc = new char[1] ; strcpy(desc,"") ; first_nec=0 ; }
		Bene( const char* , float, const char* , bool ) ;
		Bene( const Bene& ) ;
		Bene& operator=( const Bene& ) ;

		virtual float IVA( const char * ) const ;
		virtual const char* getDesc() const { return desc; }
		virtual ~Bene() { delete [] desc ; }

	};
}

#endif
