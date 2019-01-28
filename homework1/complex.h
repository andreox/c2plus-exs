
struct Complex {

	double Re ;
	double Imm ;
} ;

typedef struct Complex Complesso ;

void leggiComplex( Complesso & ) ;
void stampaComplex( const Complesso ) ;
Complesso sommaComplex( const Complesso, const Complesso ) ;
Complesso prodottoComplex( const Complesso, const Complesso ) ;
double moduloComplex( const Complesso ) ;