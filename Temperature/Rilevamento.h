#ifndef RILEVAMENTO_H
#define RILEVAMENTO_H

#include "BadData.h"
#include <iostream>
#include <string>

using namespace std ;

namespace Temperature {

	class Rilevamento {

		friend ostream& operator<<( ostream& , const Rilevamento& ) ;
		friend istream& operator>>( istream&, Rilevamento& ) ;

	private :

			string regione ;
			string provincia ;
			string citta ;
			int anno ;
			int mese ;
			int giorno ;
			int T_max ;
			int T_min ;

	public :

			Rilevamento() ;
			Rilevamento( string s1, string s2, string s3) : regione(s1), provincia(s2), citta(s3) {}  // @suppress("Class members should be properly initialized")
			const Rilevamento& operator=( const Rilevamento& ) ;
			void setRegione( const string s ) { regione = s ; }
			void setProvincia( const string s ) { provincia = s ; }
			void setCitta( const string s ) { citta = s ; }
			void setAnno( const int a ) { anno = a ; }
			void setMese( const int m ) throw(BadData) ;
			void setGiorno( const int g ) throw(BadData);
			void setTmax( const int t ) { T_max = t ; }
			void setTmin( const int t ) { T_min = t ; }

			const string getRegione() { return regione ; }
			const string getProvincia() { return provincia ; }
			const string getCitta() { return citta ; }
			const int getAnno() { return anno ;}
			const int getMese() { return mese ; }
			const int getGiorno() { return giorno ; }
			const int getTmax() { return T_max ; }
			const int getTmin() { return T_min ; }


	};
}

#endif

