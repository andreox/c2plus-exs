#include "FileMultimediale.h"
#include <fstream>

namespace File {

	FileMultimediale::FileMultimediale( const char* u , const int k , const char* f ) {

		URL = new char[strlen(u)+1] ;
		format = new char[strlen(f)+1] ;
		strcpy(URL,u) ;
		strcpy(format,f) ;
		Kbyte = k ;
	}

	FileMultimediale::FileMultimediale( const FileMultimediale& f ) {

		URL = new char[strlen(f.URL)+1] ;
		format = new char[strlen(f.format)+1] ;
		strcpy(URL,f.URL) ;
		strcpy(format,f.format) ;
		Kbyte = f.Kbyte ;
	}

	const FileMultimediale& FileMultimediale::operator=(const FileMultimediale &f) {

		if ( this != &f ) {
			delete [] URL ;
			delete [] format ;
			URL = new char[strlen(f.URL)+1] ;
			format = new char[strlen(f.format)+1] ;
			strcpy(URL,f.URL) ;
			strcpy(format,f.format) ;
			Kbyte = f.Kbyte ;

		}
		return *this ;
	}

	bool FileMultimediale::memorizza_dati( ofstream& file ) {

		if ( !file.is_open() ) return false ;
		file << *this ;
		return true ;

	}

	ostream& FileMultimediale::print( ostream& out ) {

		out << "URL: " << URL << endl ;
		out << "Kbyte : "<< Kbyte << endl ;
		out << "Formato : " << format << endl ;
		return out ;
	}

	istream& FileMultimediale::read( istream& in ) {

		char buffer[100] ;
		in.getline(buffer,100) ;
		delete [] URL ;
		URL = new char[strlen(buffer)+1] ;
		strcpy(URL,buffer) ;

		delete [] format ;
		in.getline(buffer,100) ;
		format = new char[strlen(buffer)+1] ;
		strcpy(format,buffer) ;

		in >> Kbyte ;
		return in ;
	}
}


