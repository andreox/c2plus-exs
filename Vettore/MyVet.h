#ifndef MYVET_H
#define MYVET_H

#include "Vettore.h"
#include "NotSorted.h"
#include <iostream>

namespace Vector {

	class MyVet : public Vettore {


	public :

		MyVet() : Vettore() {}
		MyVet(int d) : Vettore(d) {}
		void sort() ;
		bool is_sorted() const ;
		int BinarySearch( T& ) throw(NotSorted); //-1 if not found, index otherwise
		std::ostream& print( std::ostream& ) ;

	};
}

#endif
