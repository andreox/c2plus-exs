#include "FileMultimediale.h"
#include "Brano.h"
#include "Video.h"
#include "PilaFile.h"

using namespace std ;
using namespace File ;

int main( int argc, char** argv ) {

	FileMultimediale f1("lol.com",100,"jpg") ;
	Video v1("porn.it",200,"mp4","Rocco","Siffredi","20 novembre 2021") ;
	Brano b1("popcorn.com",300,"mp3","StammFort",3.20,"Luche") ;
	FileMultimediale f2 = f1 ;
	FileMultimediale f3(f2) ;

	PilaFile p ;
	p.push(&f1) ;
	p.push(&v1) ;
	p.push(&b1) ;
	p.push(&f2) ;
	p.push(&f3) ;
	p.write() ;

	return 0 ;
}
