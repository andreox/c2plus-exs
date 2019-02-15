#include "Servizio.h"

namespace Societa {

	Servizio::Servizio( const char* i ,  const float uc , const char* t ) : Prodotto(i,"Servizio",uc) {

		type_ser = new char[strlen(t)+1] ;
		strcpy(type_ser,t) ;

	}

	Servizio::Servizio( const Servizio& s) : Prodotto(s.ID,"Servizio",s.unity_cost) {

		type_ser = new char[strlen(s.type_ser)+1] ;
		strcpy(type_ser,s.type_ser) ;

	}

	Servizio& Servizio::operator=( const Servizio& s ) {

		if ( this != &s ) {

			Prodotto::operator=(s) ;
			delete [] type_ser ;
			type_ser = new char[strlen(s.type_ser)+1] ;
			strcpy(type_ser,s.type_ser) ;

		}

		return *this;
	}

	float Servizio::IVA( const char* cod_cli ) const {

		if ( cod_cli[0] == 'I' ) return 0 ;
		float iva = (unity_cost/10) ;
		return iva ;

	}

}
