#include "Elenco.h"
#include <iostream>
#include <cstring>

using namespace std ;

void read( Elenco& l, int& dim ) {

	cout << "Inserire il numero di elementi da inserire nell'elenco : " ;
	cin >> dim ;

	for ( int i = 0 ;i < dim ; i++ ) 
		read( l[i] ) ;

}

void write( const Elenco l, const int dim ) {

	for ( int i = 0 ; i < dim ; i++ )
		write( l[i] ) ;

}

bool in( const Elenco l, const int dim, const Voce x, int &pos ) {

	bool tr = false ;
	for ( int i = 0 ; i < dim && !tr ; i++ ) {

		if ( equal( l[i] , x) ) {

			tr = true ;
			pos = i ;

		}

	}

	return tr ;
}

void sort( Elenco& l, const int dim ) {

	cout << endl << "Stampo l'elenco ordinato : " << endl ;
	for ( int i = 0 ; i < dim ; i++ ) {

		for ( int j = i+1 ; j < dim ; j++ ) {

			if ( greater_than( l[i], l[j]) ) {

				Voce tmp ;
				tmp.descr = new char[100] ;
				copy( tmp, l[i] ) ;
				copy( l[i] , l[j] ) ;
				copy( l[j] , tmp ) ;

			}
		}
	}
}

bool full( const Elenco l, const int dim ) {

	if ( dim < 100 ) return false ;
	return true ;

}

bool empty( const Elenco l, const int dim ) {

	if ( dim == 0 ) return true ;
	return false ;

}

void insert( Elenco& l, int& dim, Voce e ) {

	bool tr = false ;
	int pos ;
	for ( int i = 0 ; i < dim && !tr ; i++) {

		if ( l[i].key == 0 && l[i].descr == nullptr ) {

			tr = true ;
			pos = i ;

		}
	}

	if ( tr ) {

		l[pos].descr = new char[strlen(e.descr)] ;
		copy( l[pos], e) ;

	}

	else {

		l[dim].descr = new char[strlen(e.descr)] ;
		copy( l[dim], e) ;
		dim++ ;

	}

}

bool is_sorted( const Elenco l, const int dim ) {

	for ( int i = 0 ; i < dim-1 ; i++ ) {

		if ( !greater_than( l[i+1], l[i]) ) {
			cout << "mh" << endl ;
			return false ;
		}
	}

	return true ;
}

void insert_ord( Elenco& l, int& dim, Voce e ) {

	if ( !is_sorted( l, dim ) ) return;

	bool tr = false ;
	Voce tmp ;
	tmp.descr = new char[100] ;
	int i ;

	for( i = 0 ; i < dim && !tr ; i++ ) {

		if ( greater_than(l[i],e) ) {

			tr = true ;
			copy( tmp, l[i] ) ;
			l[i] = e ;

		}
	}

	if ( tr ) {

		l[dim].descr = new char[100] ;
		dim++ ;
		Voce tmp2 ;
		tmp2.descr = new char[100] ;
		for ( ; i < dim ; i++ ) {

			copy( tmp2, l[i] ) ;
			copy( l[i], tmp ) ;
			copy( tmp, tmp2 ) ;

		}

	}

	else insert( l, dim, e) ;
}

void remove( Elenco &l, int &dim, Voce e ) {

	int pos ;
	if ( in( l, dim, e, pos) ) 
		destroy( l[pos] ) ;

	

	else cout << "Elemento non trovato" << endl ;

}
