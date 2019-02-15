#ifndef IMMAGINE_H
#define IMMAGINE_H

#include <string>
#include <iostream>

using namespace std ;

namespace Vector {

	class Immagine {

		friend ostream& operator<<( ostream& , const Immagine&) ;
		friend istream& operator>>( istream& , Immagine& ) ;
	private :

		string Nomefile ;
		int Dimension ;

	public :

		Immagine() { Nomefile = "" ; Dimension = 0 ; }
		Immagine( const string n , const int d ) : Nomefile(n) , Dimension(d) {}

		void setNomefile( string s ) { Nomefile = s ; }
		void setDimension( int d ) { Dimension = d ; }
		string getNomefile() const { return Nomefile ; }
		int getDimension() const { return Dimension ; }

		inline bool operator==( const Immagine& i ) { if ( Nomefile==i.Nomefile && Dimension==i.Dimension) return true ; return false ;}
		inline bool operator>(const Immagine& i ) { if ( Dimension > i.Dimension ) return true ; return false ;}

	};
}
#endif
