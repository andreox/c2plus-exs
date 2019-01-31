#include "ContoCorrentePacchetto.h"

namespace mynsp {

	ContoCorrentePacchetto::ContoCorrentePacchetto( const std::string t, const int num, const int max_mv, const float pr, const int op, const int can, const bool fr, const int n_op_gr  ) : ContoCorrenteOrdinario( t, num, max_mv, pr, op) {

		canone = can ;
		franchigia = fr ;
		num_op_grat = n_op_gr ;

	}

	ContoCorrentePacchetto::ContoCorrentePacchetto( const ContoCorrentePacchetto &c ) {

		titolare = c.titolare ;
		num_conto = c.num_conto ;
		movimenti = new float[c.max_move_allowed] ;
		for ( int i = 0 ; i < c.max_move_allowed ; i++ ) movimenti[i] = c.movimenti[i] ;
		max_move_allowed = c.max_move_allowed ;
		movements = c.movements ;

		operations = c.operations ;
		price = c.price ;
		canone = c.canone ;
		franchigia = c.franchigia ;
		num_op_grat = c.num_op_grat ;

	}


	const ContoCorrentePacchetto& ContoCorrentePacchetto::operator=( const ContoCorrentePacchetto &c ) {

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
			canone = c.canone ;
			franchigia = c.franchigia ;
			num_op_grat = c.num_op_grat ;

		}

		return *this ;
	}

	virtual float ContoCorrentePacchetto::calc_spesa_conto() const {

		if ( !franchigia || num_op_grat >= movements ) return canone ;

		return ( canone + price*( (movements-num_op_grat)/operations)) ;
	}
}
