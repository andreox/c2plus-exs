#ifndef FILEEXCEP_H
#define FILEEXCEP_H


#include <string>

namespace Pacco {

	class FileExcep {

	private :
		std::string err ;
		int num_err ;

	public :

		FileExcep() : err(""), num_err(0) {} ;
		FileExcep(const std::string e, const int n) : err(e) , num_err(n) {} ;

		std::string getErr() { return err ; } ;
		int getNum_Err() { return num_err ; } ;

	};

}

#endif
