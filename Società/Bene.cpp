#include "Bene.h"

namespace Societa {

	Bene::Bene( const char* i ,  float u , const char* d , bool fn) : Prodotto(i,"Bene",u) {

		desc = new char[strlen(d)+1] ;
		strcpy(desc,d) ;
		first_nec = fn ;
	}

	Bene::Bene( const Bene& b ) : Prodotto(b) {

		desc = new char[strlen(b.desc)+1] ;
		strcpy(desc,b.desc) ;
		first_nec = b.first_nec ;

	}

	Bene& Bene::operator=( const Bene& b) {

		if ( this != &b) {

			Prodotto::operator=(b) ;
			delete [] desc ;
			desc = new char[strlen(b.desc)+1] ;
			strcpy(desc,b.desc) ;
			first_nec = b.first_nec ;

		}

		return *this ;

	}

	float Bene::IVA( const char* cod_cli ) const {

		float iva ;
		if ( cod_cli[0] == 'I' )
			return 0 ;

		if ( first_nec ) {

			iva = (unity_cost/100)*4;
			return iva;
		}

		iva = (unity_cost/100)*22 ;
		return iva ;

	}
}


