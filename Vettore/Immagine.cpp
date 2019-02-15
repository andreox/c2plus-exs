#include "Immagine.h"

namespace Vector {

	ostream& operator<<( ostream& out , const Immagine& i ) {

		out << i.Nomefile << " " << i.Dimension << "KB" << endl ;
		return out ;
	}

	istream& operator>>( istream& in , Immagine& i) {

		in >> i.Nomefile ;
		in >> i.Dimension ;
		return in ;
	}
}
