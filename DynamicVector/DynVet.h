#ifndef DYNVET_H
#define DYNVET_H

typedef int T ;

class DynVet {

public :

	DynVet( int ) ;
	void operator=( const DynVet& ) ;
	void push_back(int) ;
	void pop_back() ;
	int size() const ;
	int capacity() const ;
	bool empty() const ;
	void resize() ;
	void print() ;



private :

	int dim ;
	T* vector ;
	int *first, *last, *last_ins ;


};

#endif
