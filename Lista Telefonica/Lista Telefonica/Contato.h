#ifndef CONTATO_H
#define CONTATO_H
#include <string>

using namespace std;

class Contato {
private:
	string nome;
	string telefone;
	string data;
	string hora;
public:
	Contato();
	Contato(string nome,
		string telefone,
		string data,
		string hora);

	string getNome();
	void setNome(string nome);

	string getTelefone();
	void setTelefone(string telefone);

	string getData();
	void setData(string data);

	string getHora();
	void setHora(string hora);
};

#endif CONTATO_H