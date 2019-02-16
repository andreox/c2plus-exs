#include "Data.h"

namespace Posta {

	ostream& operator<<( ostream& out , const Data& d ) {

		out << d.gg << "/" << d.mm << "/" << d.yyyy << endl ;
		return out ;
	}

	istream& operator>>( istream& in , Data& d) {
		in >> d.gg >> d.mm >> d.yyyy ;
		return in ;
	}
}
