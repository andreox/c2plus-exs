#include "ContoCorrenteOrdinario.h"
#include <string>

namespace mynsp {

	ContoCorrenteOrdinario::ContoCorrenteOrdinario( const std::string s, const int num, const int max_mv, const float p, const int op) : ContoCorrente( s, num, max_mv ) {

		operations = op ;
		price = p ;

	}

	ContoCorrenteOrdinario::ContoCorrenteOrdinario( const ContoCorrenteOrdinario &c ) {

		titolare = c.titolare ;
		num_conto = c.num_conto ;
		movimenti = new float[c.max_move_allowed] ;
		for ( int i = 0 ; i < c.max_move_allowed ; i++ ) movimenti[i] = c.movimenti[i] ;
		max_move_allowed = c.max_move_allowed ;
		movements = c.movements ;

		operations = c.operations ;
		price = c.price ;

	}

	const ContoCorrenteOrdinario& ContoCorrenteOrdinario::operator=( const ContoCorrenteOrdinario &c ) {

		if ( this != &c ) {

			delete [] movimenti ;
			titolare = c.titolare ;
			num_conto = c.num_conto ;
			movimenti = new float[c.max_move_allowed] ;
			for ( int i = 0 ; i < c.max_move_allowed ; i++ ) movimenti[i] = c.movimenti[i] ;
			max_move_allowed = c.max_move_allowed ;
			movements = c.movements ;

			operations = c.operations ;
			price = c.price ;

		}

		return *this ;
	}

	float ContoCorrenteOrdinario::calc_spese_conto() const {

		return price*(movements/operations) ;

	}
}
