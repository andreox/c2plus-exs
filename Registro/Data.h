#ifndef DATA_H
#define DATA_H

namespace Reg {

	class Data {

	private :
		int g , m , y ;

	public :

		explicit Data() : g(0) , m(0) , y(0) {}
		explicit Data( const int gg, const int mm, const int yy ) : g(gg) , m(mm) , y(yy) {}
		explicit Data( const Data& d) : g(d.g) , m(d.m) , y(d.y) {}
		void setDay(const int d) { g = d ; }
		void setMonth(const int mo ) { m = mo ; }
		void setYear( const int ye ) { y=ye ; }
		const int getDay() const { return g ; }
		const int getMonth() const { return m ; }
		const int getYear() const { return y ; }

	};
}
#endif


