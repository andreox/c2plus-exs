#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std ;

namespace Cartansp {

	class Data {

		inline friend ostream& operator<<( ostream& , const Data& ) ;

	private :

		int gg ;
		int mm ;
		int yyyy ;

	public :

		Data() : gg(0) , mm(0) , yyyy(0) {}  ;
		Data( int g , int m , int y ) { gg = g ; mm = m ; yyyy = y ; } ;

		void setDay(int d) { gg = d ; } ;
		void setMonth( int m ) { mm = m ; } ;
		void setYear( int y ) { yyyy = y ; } ;

		const int getDay() const { return gg ; } ;
		const int getMonth() const { return mm ; } ;
		const int getYear() const { return yyyy ; } ;


	};

	inline ostream& operator<<( ostream& out , const Data & d) {

		out << d.gg << " " << d.mm << " " << d.yyyy << endl ;
		return out ;
	}
}
#endif
