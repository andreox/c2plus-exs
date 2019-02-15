#include "Prodotto.h"

namespace Societa {

	Prodotto::Prodotto( const char* i , const char* g , const float uc ) : unity_cost(uc) {

		strcpy(ID,i) ;
		genere = new char[strlen(g)+1] ;
		strcpy(genere,g) ;

	}

	Prodotto::Prodotto( const Prodotto& p ) {

		strcpy(ID,p.ID) ;
		unity_cost = p.unity_cost ;
		genere = new char[strlen(p.genere)+1] ;
		strcpy(genere,p.genere) ;
	}

	Prodotto& Prodotto::operator=( const Prodotto& p ) {

		if ( this != &p ) {

			delete [] genere ;
			strcpy(ID,p.ID) ;
			unity_cost = p.unity_cost ;
			genere = new char[strlen(p.genere)+1] ;
			strcpy(genere,p.genere) ;
		}

		return *this;
	}


}
