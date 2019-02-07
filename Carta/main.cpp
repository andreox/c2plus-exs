#include <iostream>
#include <string>
#include "Data.h"
#include "Carta.h"
#include "TesseraSanitaria.h"
#include "Bancomat.h"

using namespace std ;
using namespace Cartansp ;

int main() {

	Carta * v[8] ;
	Data d(07,07,1998) ;
	Bancomat b1("Bancomat","Alessio","012345678",d) ;
	Bancomat b2("Bancomat","Pino","123456",d) ;
	Bancomat b3 = b2 ;
	Bancomat b4(b3) ;

	TesseraSanitaria t1("Tessera","Martina","5678","ndeejd5",d,d) ;
	TesseraSanitaria t2("Tessera","Mario","8504","COD984",d,d) ;
	TesseraSanitaria t3 = t2 ;
	TesseraSanitaria t4(t3) ;

	b1.Attiva() ;
	b3.Attiva() ;

	v[0] = &b1 ;
	v[1] = &b2 ;
	v[2] = &b3 ;
	v[3] = &b4 ;
	v[4] = &t1 ;
	v[5] = &t2 ;
	v[6] = &t3 ;
	v[7] = &t4 ;

	for ( int i = 0 ; i < 8 ; i++ ) cout << *v[i] << endl ;

	char * cod = new char[10] ;

	for ( int i = 0 ; i < 8 ; i++ ) {

		try {

			v[i]->ControllaNumCarta() ;
			cout << "Numero carta corretto" << endl ;
		}

		catch ( string& s ) {

			cout << s << endl ;
		}

		cout << v[i]->getTipo() << endl ;
		cout << "Inserisci il codice da verificare : " ;
		cin >> cod ;
		cout << v[i]->Check(cod) << endl ; //stampo un booleano
	}

	return 0 ;
}
