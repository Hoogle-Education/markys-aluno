#include "Contato.h"
#include <iostream>

using namespace std;

Contato::Contato()
{
	cout << "new contact created\n";
}

Contato::Contato(string nome, string telefone, string data, string hora)
{
	this->nome = nome;
	this->telefone = telefone;
	this->data = data;
	this->hora = hora;
}

string Contato::getNome()
{
	return nome;
}

void Contato::setNome(string nome)
{
	this->nome = nome;
}

string Contato::getTelefone()
{
	return telefone;
}

void Contato::setTelefone(string telefone)
{
	this->telefone = telefone;
}

string Contato::getData()
{
	return data;
}

void Contato::setData(string data)
{
	this->data = data;
}

string Contato::getHora()
{
	return hora;
}

void Contato::setHora(string hora)
{
	this->hora = hora;
}
