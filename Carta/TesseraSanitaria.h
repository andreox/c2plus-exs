#ifndef TESSERASANITARIA_H
#define TESSERASANITARIA_H

#include "Carta.h"
#include "Data.h"
#include <iostream>

using namespace std ;

namespace Cartansp {

	class TesseraSanitaria : public Carta {

		friend ostream& operator<<( ostream& , const TesseraSanitaria& ) ;

	private :

		char * CF ;
		Data DataRilascio ;
		Data DataScadenza ;

	protected :

		virtual ostream& print( ostream& ) const ;


	public :

		TesseraSanitaria() ;
		TesseraSanitaria( const char* , const char* , const char* , const char* , const Data , const Data ) ;
		TesseraSanitaria( const TesseraSanitaria& ) ;
		const TesseraSanitaria& operator=( const TesseraSanitaria& ) ;

		const char* getCF() const { return CF ; } ;
		const Data getDataRilascio() const { return DataRilascio ; } ;
		const Data getDataScadenza() const { return DataScadenza ; } ;

		void setCF( const char*  ) ;
		void setDataRilascio( const Data d1 ) { DataRilascio = d1 ; } ;
		void setDataScadenza( const Data d2 ) { DataScadenza = d2 ; } ;

		virtual bool Check( const char* ) const ;

		virtual ~TesseraSanitaria() { delete [] CF ;} ;

	};
}

#endif
