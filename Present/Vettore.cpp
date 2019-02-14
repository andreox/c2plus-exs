#include "Vettore.h"
#include "BadIndex.h"

namespace Present {

	Vettore::Vettore( const Vettore &v2 ) {

		Nelem = v2.Nelem ;
		v = new T[v2.Nelem] ;
		for ( int i = 0 ;i < Nelem ; i++ ) v[i] = v2[i] ;

	}

	Vettore& Vettore::operator=( const Vettore &v2 ) {

		if ( this != &v2 ) {

			delete [] v ;
			Nelem = v2.Nelem ;
			v = new T[v2.Nelem] ;
			for ( int i = 0 ;i < Nelem ; i++ ) v[i] = v2[i] ;
		}

		return *this ;
	}

	T& Vettore::Access( int index ) throw(BadIndex) {

		if ( index <= 0 || index > Nelem ) {

			BadIndex b("Errore indice",index) ;
			throw b ;
		}

		return v[index] ;
	}

	void Vettore::Elimina() {
		PacchettoRegalo p ;

		for ( int i = 0 ; i< Nelem ; i++ ) {

			if ( v[i].getPeso() >= 500 ) v[i] = p ; //Assegno elemento nullo... altrimenti come elimino?
		}
	}

	bool Vettore::push( const T& elem ) {

		if ( !full() ) {

			v[Nelem++] = elem ;
			return true ;
		}
		return false ;
	}
	ostream& operator<<( ostream& out, const Vettore& v) {

		int i = 0 ;
		for( ; i < v.Nelem ; i++) out << v[i] ;
		return out ;

	}

	istream& operator>>( istream& in , Vettore& v) {

		T k ;
		in >> k ;
		v.Nelem++ ;
		v[v.Nelem] = k ;
		return in ;
	}
}
