#ifndef ENTRYSTUDENTEREG_H
#define ENTRYSTUDENTEREG_H

#include "EntryStudente.h"
#include <iostream>

using namespace std ;

namespace Reg {

	class EntryStudenteReg : public EntryStudente {

		friend ostream& operator<<( ostream& out, const EntryStudenteReg& e ) { return e.print(out) ; }
		friend istream& operator>>( istream& in , EntryStudenteReg& e ) { return e.read(in) ; }

	private :

		bool presente ;
		int voto ;
		virtual ostream& print(ostream&) const ;
		virtual istream& read(istream& ) ;

	public :

		explicit EntryStudenteReg() : EntryStudente() { presente = false ; voto = -1 ; }
		explicit EntryStudenteReg( const char* n , const char* c , const char* i , bool p , const int v = -1) : EntryStudente(n,c,i) { presente = p ; voto = v ;}
		const EntryStudenteReg& operator=( const EntryStudenteReg& e) { if ( this != &e ) { EntryStudente::operator=(e) ; presente = e.presente ; voto=e.voto; } return *this ;}
		void setPresente() { presente = true ;}
		void setVoto(const int v ) { voto = v ; }
		bool isPresente() const { return presente ; }
		const int getVoto() const { return voto ; }

	};
}

#endif
