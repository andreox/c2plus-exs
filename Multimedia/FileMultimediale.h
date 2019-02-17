#ifndef FILEMULTIMEDIALE_H
#define FILEMULTIMEDIALE_H

#include <cstring>
#include <iostream>

using namespace std ;

namespace File {

	class FileMultimediale {

		friend ostream& operator<<( ostream& o, FileMultimediale& f) { return f.print(o) ; }
		friend istream& operator>>( istream& i, FileMultimediale& f) { return f.read(i) ; }

	protected :

		char * URL ;
		int Kbyte ;
		char * format ;
		virtual ostream& print( ostream& ) ;
		virtual istream& read( istream& ) ;

	public :

		FileMultimediale() { Kbyte = 0 ; URL = new char[1] ; format = new char[1] ; strcpy(URL,"") ; strcpy(format,"") ;}
		FileMultimediale( const char* , const int , const char* ) ;
		FileMultimediale( const FileMultimediale& ) ;
		const FileMultimediale& operator=( const FileMultimediale& );
		virtual bool memorizza_dati( ofstream& ) ;

		virtual ~FileMultimediale() { delete [] URL ; delete [] format ; }
	};
}
#endif
