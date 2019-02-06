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


	return 0 ;
}
