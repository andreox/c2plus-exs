#ifndef CONTOCORRENTEPACCHETTO_H
#define CONTOCORRENTEPACCHETTO_H

#include "ContoCorrenteOrdinario.h"
#include <string>

namespace mynsp {

	class ContoCorrentePacchetto : public ContoCorrenteOrdinario {

	protected :

		int canone ;
		bool franchigia ;
		int num_op_grat ;

	public :

		ContoCorrentePacchetto() ;
		ContoCorrentePacchetto( const std::string, const int, const int, const float,const int, const int, const bool, const int) ;
		ContoCorrentePacchetto( const ContoCorrentePacchetto &c ) ;
		const ContoCorrentePacchetto& operator=( const ContoCorrentePacchetto &c ) ;

		virtual float calc_spesa_conto() const override ;

		virtual ~ContoCorrentePacchetto() ;
	};
}

#endif
