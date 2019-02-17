#include "PilaFile.h"
#include <fstream>


namespace File {

	bool PilaFile::write() const {

		ofstream file("file.txt") ;
		if (!file.is_open()) return false ;

		for ( int i = 0 ; i < nelem ;i++ ){

			v[i]->memorizza_dati(file) ;
			file << endl ;
		}

		return true ;
	}
}
