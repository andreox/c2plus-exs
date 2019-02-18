#include "Registro.h"

namespace Reg {

	Registro::Registro( const string m , const string doc , const string cla , const int n , const Data& r ) {

		materia = m ;
		docente = doc ;
		classe = cla;
		num_alunni = n ;
		date = r ;

	}

	bool Registro::check_if_greater( const char* c1 , const char* c2 ) {

		int min ;
		if ( strlen(c1)>strlen(c2) ) min = strlen(c2) ;
		else min = strlen(c1) ;

		for ( int i = 0 ; i < min ; i++ ) {

			if ( c1[i] > c2[i] ) return true ;
			else if ( c1[i] < c2[i] ) return false ;
			else continue ;
		}

		return false ;
	}

	bool Registro::check_if_present( const EntryStudenteReg& e ) const {

		for ( int i =0 ; i < num_alunni ; i++ ) {

			if ( strcmp(e.getID(),reg[i].getID()) == 0 ) return true ;
		}
		return false ;
	}

	bool Registro::Inserisci( const EntryStudenteReg& e ) throw(Excep) {

		if ( num_alunni == 0 ) {
			reg[num_alunni] = e ;
			num_alunni++ ;
			return true ;
		}

		if ( check_if_present(e) ) {
			Excep e("Alunno già inserito in registro",0) ;
			throw e;
			return false ;
		}

		bool tr = false ;
		char cog_ins[100] ;
		strcpy(cog_ins,e.getCognome()) ;
		char cog2[100] ;
		EntryStudenteReg tmp ;
		int i ;

		for ( i = 0 ; i < num_alunni && !tr ;i++) {

			strcpy(cog2,reg[i].getCognome()) ;
			if ( check_if_greater(cog2,cog_ins) ) {

				tmp = reg[i] ;
				reg[i] = e ;
				tr = true ;
				num_alunni++ ;
			}
		}

		EntryStudenteReg tmp2 ;
		if ( tr ) {
			for ( ; i < num_alunni ; i++ ) {

				tmp2 = reg[i+1] ;
				reg[i+1] = tmp ;
				tmp = tmp2 ;

			}
		}

		else
			reg[num_alunni++] = e ;

		return true ;
	}

	void Registro::print() const {

		for ( int i = 0 ; i < num_alunni ; i++ ) cout << reg[i] << endl ;
	}
}
