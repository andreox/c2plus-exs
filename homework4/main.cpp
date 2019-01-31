#include <iostream>
#include <string>
#include "ContoCorrentePacchetto.h"

using namespace std ;
using mynsp::ContoCorrenteOrdinario ;
using mynsp::ContoCorrentePacchetto ;
using mynsp::ContoCorrente ;

int main( int argc, char** argv ) {

	string name1 = "Alessio Andreozzi" ;
	string name2 = "Pino Mauro" ;
	ContoCorrenteOrdinario c1( name1 , 123, 10 , 0.2 , 3) ;
	ContoCorrentePacchetto c2( name2, 124, 10, 0.2, 3, 3,true,3) ;

	ContoCorrente * v[2] ;
	v[0] = &c1 ;
	v[1] = &c2 ;

	v[0]->calc_spese_conto() ;
	v[1]->calc_spese_conto() ;

}
