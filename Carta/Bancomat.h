#ifndef BANCOMAT_H
#define BANCOMAT_H

#include <string>
#include "Carta.h"
#include "Data.h"

using namespace std ;

namespace Cartansp {

	class Bancomat : public Carta {

		friend ostream& operator<<( ostream& , const Bancomat & ) ;

	private :

		char * Pin ;
		bool attivato ;
		Data DataScadenza ;
		void setPin() ;

	protected :

		virtual ostream& print( ostream& ) const ;

	public :

		Bancomat() ;
		Bancomat( const char* , const char*, const char*, const Data ) ;
		Bancomat( const Bancomat& ) ;
		const Bancomat& operator=( const Bancomat& ) ;


		void Attiva() ;
		virtual bool Check( const char* ) const ;

		virtual ~Bancomat() ;
	};
}

#endif
