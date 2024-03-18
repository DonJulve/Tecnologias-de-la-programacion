#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include<exception>

#include "shell.h"
#include "arbol_ficheros_error.h"

using namespace std;

int main()
{
	Shell sh;

	for (bool done=false; !done; )
	{
		cout << sh.pwd() << "> " << flush;

		// Leer linea de entrada
		string line;
		if (!getline(cin,line))
		{
			done = true;
			continue;
		}
		if (line.empty())
			continue;

		// Separar tokens
		vector<string> cmd;
		istringstream iss(line);
		for (string tok; iss >> tok; )
			cmd.push_back(tok);

		if (cmd.empty())
			continue;

		try
		{
			if ((cmd[0]=="exit") || (cmd[0]=="by"))
			{
				done = true;
			}
			else if (cmd[0]=="pwd")
			{
				cout << sh.pwd() << endl;
			}
			else if (cmd[0]=="ls")
			{
				cout << sh.ls();
			}
			else if (cmd[0]=="du")
			{
				cout << sh.du();
			}
			else if (cmd[0]=="mkdir")
			{
				sh.mkdir(cmd.at(1));
			}
			else if (cmd[0]=="vi")
			{
				sh.vi(cmd.at(1),stoi(cmd.at(2)));
			}
			else if (cmd[0]=="stat")
			{
				cout << sh.stat(cmd.at(1)) << endl;
			}
			else if (cmd[0]=="cd")
			{
				sh.cd(cmd.at(1));
			}
			else if (cmd[0]=="ln")
			{
				sh.ln(cmd.at(1),cmd.at(2));
			}
			else if (cmd[0]=="rm")
			{
				sh.rm(cmd.at(1));
			}
			else
			{
				cerr << "Error sintactico: comando desconocido" << endl;
			}
		}
		
		catch (const arbol_ficheros_error& e)
		{	
			cerr << e.what() << endl;
		}
		
		catch (const out_of_range& e)
		{
			cerr << "Error sintactico: parametros insuficientes" << endl;
			cerr << e.what() << endl;
		}
	}
	cout << endl << "By!!" << endl;

	return 0;
}
