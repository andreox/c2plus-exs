#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H

#include <string>

namespace mynsp {

	class ContoCorrente {

	protected :

		std::string titolare ;
		int num_conto ;
		float *movimenti ;
		int max_move_allowed ;
		int movements ;

	public :

		ContoCorrente() ;
		ContoCorrente( const std::string , const int, const int) ;
		ContoCorrente( const ContoCorrente &c) ;
		const ContoCorrente& operator=( const ContoCorrente &c ) ;

		void prelievo( float ) ;
		void versamento( float ) ;
		float calc_saldo() const ;
		virtual float calc_spese_conto() const = 0 ;
		void print_saldo() const ;
		void print_movements() const ;

		void setTitolare( std::string s ) { titolare = s ;} ;
		void setNum_conto( int n ) { num_conto = n ;}  ;

		virtual ~ContoCorrente() { delete[] movimenti ; } ;

	};

}

#endif
