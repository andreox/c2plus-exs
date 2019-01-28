#include "complex.h"

#define N 20

typedef Complesso Vettore[N] ;

void LeggiElementi( Vettore vet , int & nelem ) ;
void StampaVettore( const Vettore vet, const int nelem ) ;
void ModuloBubbleSort( Vettore vet, const int nelem ) ;