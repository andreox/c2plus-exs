#include "AutoVettura.h"
#include "Lista.h"
#include "Veicolo.h"
#include <iostream>
#include <fstream>

using namespace std ;

int main( int argc, char** argv ) {

	AutoVettura * audi = new AutoVettura("Auto","AUDI","A1",2) ;
	AutoVettura * benz = new AutoVettura( "Auto", "MECCEDE", "CLA" , 3 ) ;
	AutoVettura * range = new AutoVettura("Auto","RANGE ROVER","VELAR",4) ;

	Lista L ;
	L.append(audi) ;
	L.append(benz) ;
	L.append(range) ;

	Veicolo * v[3] ;

	cout << "Simulazione di pagamento del pedaggio : " << endl ;
	ofstream out("stampa.txt") ;

	L.pop(v[0]) ;
	cout << *v[0] ;
	cout << " Pedaggio da pagare : " << v[0]->calc_pedaggio() << endl ;

	out << *v[0] ;
	out << " Pedaggio da pagare : " << v[0]->calc_pedaggio() << endl ;

	L.pop(v[1]) ;
	cout << *v[1] ;
	cout << " Pedaggio da pagare : " << v[1]->calc_pedaggio() << endl ;

	out << *v[1] ;
	out << " Pedaggio da pagare : " << v[1]->calc_pedaggio() << endl ;

	L.pop(v[2]) ;
	cout << *v[2] ;
	cout << "Pedaggio da pagare : " << v[2]->calc_pedaggio() << endl ;

	out << *v[2] ;
	out << " Pedaggio da pagare : " << v[2]->calc_pedaggio() << endl ;

	//L.print(cout) ;

	out.close() ;
	return 0 ;
}
