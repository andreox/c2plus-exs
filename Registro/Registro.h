#ifndef REGISTRO_H
#define REGISTRO_H
#define MAXR 30

#include "Data.h"
#include "Excep.h"
#include "EntryStudente.h"
#include "EntryStudenteReg.h"
#include <string>

using namespace std ;

namespace Reg {

	class Registro {


	private :
		string materia ;
		string docente ;
		string classe ;
		int num_alunni ;
		Data date ;
		EntryStudenteReg reg[MAXR] ;

	public :

		Registro( const string , const string , const string , const int , const Data& ) ;
		bool Test() const { return ( num_alunni==MAXR) ; }
		bool Inserisci( const EntryStudenteReg& ) throw(Excep) ;
		bool check_if_present( const EntryStudenteReg &e ) const ;
		bool Interrogazione( const char ID ) ;
		bool check_if_greater( const char * , const char * ) ;
		const string getMateria() const { return materia ; }
		const string getClasse() const { return classe ; }
		const string getDocente() const { return docente ; }
		const int getAlunni() const { return num_alunni ; }
		const Data& getData() const { return date ; }
		float calc_media_voti() const ;
		void print() const ;

	};
}
#endif
