#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std ;

namespace Posta {

	class Data {

		friend ostream& operator<<( ostream& , const Data& ) ;
		friend istream& operator>>( istream& , Data& ) ;

	private :

		int gg ;
		int mm ;
		int yyyy ;

	public:

		Data() : gg(0) , mm(0) , yyyy(0) {}
		Data( const int g , const int m , const int y ) : gg(g) , mm(m) , yyyy(y)  {}
		inline const Data& operator=( const Data& d ) { if ( this != &d) {gg=d.gg ; mm=d.mm ; yyyy=d.yyyy;} return *this;}
		int getDay() const { return gg ;}
		int getMonth() const { return mm ; }
		int getYear() const { return yyyy ;}
		void setDay( int d ) { gg = d ;}
		void setMonth( int m ) { mm = m ; }
		void setYear( int y ) { yyyy = y ; }
		bool operator==( const Data& d) const { return ( gg==d.gg && mm==d.mm && yyyy==d.yyyy) ; }

	};
}

#endif
