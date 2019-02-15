#ifndef PRODOTTO_H
#define PRODOTTO_H
#define MAX 10

#include <cstring>

namespace Societa {

	class Prodotto {

	protected :

		char ID[MAX] ;
		char * genere ;
		float unity_cost ;

	public :

		Prodotto() { genere = new char[1] ; strcpy(genere,"") ; strcpy(ID,"") ; unity_cost = 0 ; }
		Prodotto( const char* , const char* , const float ) ;
		Prodotto( const Prodotto& );
		Prodotto& operator=(const Prodotto& ) ;

		const char* getID() const { return ID ; }
		const char* getGenere() const { return genere ; }
		float getUCost() const { return unity_cost; }
		virtual const char* getDesc() const = 0 ;

		virtual float IVA( const char* ) const = 0 ;

		virtual ~Prodotto() { delete [] genere ; }
	};
}
#endif
