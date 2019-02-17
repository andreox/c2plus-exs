#ifndef VIDEO_H
#define VIDEO_H

#include "FileMultimediale.h"
#include <iostream>
#include <cstring>

using namespace std ;

namespace File {

	class Video : public FileMultimediale {

		friend ostream& operator<<( ostream& o, Video& v) { return v.print(o) ; }
		friend istream& operator>>( istream& i, Video& v) { return v.read(i) ; }

	private :

		char * Autore ;
		char * Soggetto ;
		char * Data ;
		virtual ostream& print( ostream& ) ;
		virtual istream& read( istream& ) ;

	public :

		Video() : FileMultimediale() { Autore = new char[1] ; Soggetto = new char[1] ; Data = new char[1] ; strcpy(Autore,"") ; strcpy(Soggetto,"") ; strcpy(Data,"") ;}
		Video( const char* , const int , const char*, const char* , const char* , const char* ) ;
		Video( const Video& ) ;
		const Video& operator=( const Video& );
		virtual bool memorizza_dati( ofstream& ) ;

		virtual ~Video() { delete [] Autore ; delete [] Soggetto ; delete [] Data ; }
	};
}
#endif
