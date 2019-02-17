#include "Video.h"
#include <fstream>

namespace File {

	Video::Video( const char* u , const int k , const char* f , const char* a , const char* s , const char* d ) : FileMultimediale(u,k,f) {

		Autore = new char[strlen(a)+1] ;
		Soggetto = new char[strlen(s)+1] ;
		Data = new char[strlen(d)+1] ;
		strcpy(Autore,a) ;
		strcpy(Soggetto,s) ;
		strcpy(Data,d) ;

	}

	Video::Video( const Video& v ) : FileMultimediale(v) {

		Autore = new char[strlen(v.Autore)+1] ;
		Soggetto = new char[strlen(v.Soggetto)+1] ;
		Data = new char[strlen(v.Data)+1] ;
		strcpy(Autore,v.Autore) ;
		strcpy(Soggetto,v.Soggetto) ;
		strcpy(Data,v.Data) ;
	}

	const Video& Video::operator=( const Video& v ) {

		if ( this != &v ) {

			FileMultimediale::operator=(v) ;
			delete [] Autore ;
			delete [] Soggetto ;
			delete [] Data ;
			Autore = new char[strlen(v.Autore)+1] ;
			Soggetto = new char[strlen(v.Soggetto)+1] ;
			Data = new char[strlen(v.Data)+1] ;
			strcpy(Autore,v.Autore) ;
			strcpy(Soggetto,v.Soggetto) ;
			strcpy(Data,v.Data) ;

		}
		return *this ;
	}

	bool Video::memorizza_dati( ofstream& file ) {

		if ( !file.is_open() ) return false ;
		file << *this ;
		return true ;

	}

	ostream& Video::print( ostream& out ) {

		FileMultimediale::print(out) ;
		out << "Autore: " << Autore << endl ;
		out << "Soggetto : "<< Soggetto << endl ;
		out << "Data : " << Data << endl ;
		return out ;
	}

	istream& Video::read( istream& in ) {

		FileMultimediale::read(in) ;
		in.ignore() ; //cin nell'ultimo metodo richiamato
		char buffer[100] ;
		in.getline(buffer,100) ;
		delete [] Autore ;
		Autore = new char[strlen(buffer)+1] ;
		strcpy(Autore,buffer) ;

		delete [] Soggetto ;
		in.getline(buffer,100) ;
		Soggetto = new char[strlen(buffer)+1] ;
		strcpy(Soggetto,buffer) ;

		delete [] Data ;
		in.getline(buffer,100) ;
		Data = new char[strlen(buffer)+1] ;
		strcpy(Data,buffer) ;

		return in ;
	}

}
