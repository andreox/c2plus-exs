#include <cstddef>

typedef struct {

	int key ;
	char *descr ;

} Voce ;

const int buff = 100 ;
void create( Voce& ) ;
void create( Voce& , const int , const char* descr ) ;
void read( Voce& ) ;
void write( const Voce ) ;
void copy( Voce& , Voce&) ;
bool equal( const Voce, const Voce ) ;
bool greater_than( const Voce, const Voce) ;
void destroy( Voce& ) ;