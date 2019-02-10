#ifndef PACCOREGALO_H
#define PACCOREGALO_H

#include <iostream>
#include <cstring>

using namespace std ;

namespace Pacco {

	class PaccoRegalo {

		friend ostream& operator<< ( ostream& , const PaccoRegalo& ) ;
		friend istream& operator>> ( istream&, PaccoRegalo& ) ;

	private :

		int cod ;
		float weight ;
		char * address ;

	public :

		PaccoRegalo() ;
		PaccoRegalo( const int, const float, const char* ) ;
		PaccoRegalo( const PaccoRegalo& ) ;
		const PaccoRegalo& operator=( const PaccoRegalo&) ;

		void setCod( const int c ) { cod = c ; } ;
		void setWeight( const float w ) { weight = w ; } ;
		inline void setAddress( const char* a ) { delete [] address ; address = new char[strlen(a)+1] ; strcpy(address,a) ; } ;

		const int getCod() const { return cod ; } ;
		const float getWeight() const { return weight ; } ;
		const char * getAddress() const { return address ;} ;

		~PaccoRegalo() { delete [] address ; }

	};
}

#endif
