#include <iostream>
#include "DynVet.h"

using namespace std ;

DynVet::DynVet( int n ) {

	dim = 5 ;
	vector = new T[dim] ;
	for ( int i = 0 ; i < n ; i++ ) cin >> vector[i] ;

	first = vector ;
	last = vector+dim ;
	last_ins = vector+n ;

}

void DynVet::operator=( const DynVet& v2 ) {

	delete [] vector ;
	vector = new T[v2.dim] ;
	dim = v2.dim ;
	first = v2.first ;
	last = v2.last ;
	last_ins = v2.last_ins ;
	//copy all the elements
}

void DynVet::push_back( int elem_to_push ) {

	if ( last_ins == last ) {

		resize() ;
		vector[dim] = elem_to_push ;

	}


	else {//*(last_ins) = elem_to_push ;
		last_ins++ ;
		vector[dim] = elem_to_push ;

	}

}

void DynVet::pop_back() {

	*(last_ins) = 0 ;
	last_ins-- ;

}

int DynVet::size() const {

	return (last_ins-vector) ;

}

int DynVet::capacity() const { return (last-vector) ; }

bool DynVet::empty() const {

	if ( vector-last_ins == 0 ) return true ;
	return false ;

}

void DynVet::resize() {

	cout << "Resize!" << endl ;
	T* v = new T[dim] ;
	int real_dim = last_ins-vector ;

	for ( int i = 0 ; i <= real_dim ; i++  ) v[i] = vector[i] ;

	delete [] vector ;
	dim += 1 ;
	vector = new T[dim] ;
	last = vector+dim ;
	last_ins = last ;
	first = vector ;

	for ( int i = 0 ; i <= real_dim ; i++ ) vector[i] = v[i] ;



}

void DynVet::print() {

	for ( int i = 0 ; i < dim ; i++ ) cout << vector[i] << " " ;
	cout << endl ;

}
