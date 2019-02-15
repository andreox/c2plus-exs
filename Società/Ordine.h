#ifndef ORDINE_H
#define ORDINE_H


#include "Cliente.h"
#include "Prodotto.h"
#include "BadIns.h"

namespace Societa {

	struct Record {

		Prodotto * p ;
		int num_ord ;
		float eff_cost ;

	};

	class Ordine {


	private :

		Record v[MAX] ;
		Cliente c ;
		int riemp ;

	public :

		Ordine() ;
		Ordine( const Cliente cli ) {  c= cli ; riemp = 0 ;}
		bool aggiungiProdotto( Prodotto& , int n ) throw(BadIns) ;
		float TOT() const ;
		void stampa() const ;

	};
}
#endif
