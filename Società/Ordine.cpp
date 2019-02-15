#include "Ordine.h"
#include <iostream>
using namespace std ;

namespace Societa {

	float Ordine::TOT() const {

		float tot ;
		for ( int i = 0 ; i < riemp ; i++ ) {

			tot = tot + (v[i].eff_cost*v[i].num_ord) ;
		}

		return tot ;

	}

	bool Ordine::aggiungiProdotto( Prodotto& pr , int n ) throw(BadIns) {

		if ( riemp >= MAX ) {

			BadIns b("Eccezione:impossibile aggiungere un altro prodotto all'ordine",riemp) ;
			throw b ;
			return false ;
		}

		v[riemp].p = &pr ;
		v[riemp].num_ord = n ;
		v[riemp].eff_cost = v[riemp].p->getUCost() + v[riemp].p->IVA(c.getCodice()) ; //Realizzo il polimorfismo
		riemp++ ;
		return true ;
	}

	void Ordine::stampa() const {

		cout << "Dettaglio Ordine " << endl ;
		cout << "Codice Cliente : " << c.getCodice() << endl ;
		for ( int i = 0 ; i < riemp ; i++ ) {

			cout << "Prodotto : " << v[i].p->getDesc() << endl ; //Realizzo anche qui il polimorfismo
			cout << "Quantita : " << v[i].num_ord << endl ;
			cout << "Costo : " << v[i].eff_cost << endl ;
			cout << "*************************" << endl ;
		}

		cout << "Costo Totale : " << TOT() << endl ;

	}
}
