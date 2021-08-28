#ifndef TIPO_ELEMENTO_H
#define TIPO_ELEMENTO_H
#include<string>
#include<sstream>
using namespace std;
class Tipo_elemento
{
	private:
		int x;
		char c;
		string s="";
		double d;
		float f;
		bool b;
	public:
		Tipo_elemento(string);
		Tipo_elemento(int);
		Tipo_elemento(double);
		Tipo_elemento(char);
		~Tipo_elemento();
		string getValue();
	protected:
};

#endif