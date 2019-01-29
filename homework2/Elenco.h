#include "Voci.h"

const int max = 100 ;
typedef Voce Elenco[max] ;

void read( Elenco& , int& ) ;
void write( const Elenco, const int ) ;
bool in( const Elenco, const int, const Voce, int& ) ;
void sort( Elenco& , const int ) ;
bool full( const Elenco, const int ) ;
bool empty( const Elenco, const int ) ;
void insert( Elenco& , int&, Voce ) ;
void insert_ord( Elenco&, int&, Voce ) ;
void remove( Elenco&, int&, const Voce ) ;
bool is_sorted( const Elenco, const int ) ;