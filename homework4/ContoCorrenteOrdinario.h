#ifndef CONTOCORRENTEORDINARIO_H
#define CONTOCORRENTEORDINARIO_H

#include "ContoCorrente.h"
#include <string>

namespace mynsp {

	class ContoCorrenteOrdinario : public ContoCorrente {

	protected :

		int operations ;
		float price ;

	public :

		ContoCorrenteOrdinario() ;
		ContoCorrenteOrdinario( const std::string, const int, const int, const float, const int) ;
		ContoCorrenteOrdinario( const ContoCorrenteOrdinario &c ) ;
		const ContoCorrenteOrdinario& operator=( const ContoCorrenteOrdinario &c ) ;

		virtual float calc_spese_conto() const override ;

	};
}

#endif
