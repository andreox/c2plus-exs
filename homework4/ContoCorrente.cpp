#include "ContoCorrente.h"
#include <iostream>
#include <string>


namespace mynsp {

	ContoCorrente::ContoCorrente( const std::string titolare, const int num_conto, const int max_move_allowed) {

		this->titolare = titolare ;
		this->num_conto = num_conto ;
		this->max_move_allowed = max_move_allowed ;
		movimenti = new float[max_move_allowed] ;
		movements = 0 ;

	}

	ContoCorrente::ContoCorrente( const ContoCorrente &c ) {

		titolare = c.titolare ;
		num_conto = c.num_conto ;
		movimenti = new float[c.max_move_allowed] ;
		for ( int i = 0 ; i < c.max_move_allowed ; i++ ) movimenti[i] = c.movimenti[i] ;
		max_move_allowed = c.max_move_allowed ;
		movements = c.movements ;

	}


	const ContoCorrente& ContoCorrente::operator=( const ContoCorrente &c ) {

		if ( this != &c ) {

			delete [] movimenti ;
			titolare = c.titolare ;
			num_conto = c.num_conto ;
			movimenti = new float[c.max_move_allowed] ;
			for ( int i = 0 ; i < c.max_move_allowed ; i++ ) movimenti[i] = c.movimenti[i] ;
			max_move_allowed = c.max_move_allowed ;
			movements = c.movements ;

		}

		return *this ;
	}

	void ContoCorrente::prelievo( float p ) {

		if ( p < 0 ) movimenti[movements++] = p ;
		//else do som

	}

	void ContoCorrente::versamento( float v ) {

		if ( v > 0 ) movimenti[movements++] = v ;
		//else do som

	}

	float ContoCorrente::calc_saldo() const {

		float saldo = 0 ;

		for ( int i = 0 ; i < movements ; i++ ) saldo += movimenti[i] ;

		return saldo ;

	}

	void ContoCorrente::print_saldo() const {

		std::cout << calc_saldo() << std::endl ;

	}

	void ContoCorrente::print_movements() const {

		for ( int i = 0 ; i < movements ; i++ ) std::cout << movimenti[i] << std::endl ;

	}

}
