#include "EntryStudenteReg.h"

namespace Reg {

	ostream& EntryStudenteReg::print( ostream& out ) const {

		EntryStudente::print(out) ;
		if ( presente ) out << "Presente" << endl ;
		else out << "Assente" << endl ;
		if ( voto == -1 ) out << "Voto : *" << endl ;
		else out << "Voto : " << voto << endl ;
		return out ;
	}

	istream& EntryStudenteReg::read( istream& in) {

		EntryStudente::read(in) ;
		//Che cazzo di altro vuori fare....
	}
}
