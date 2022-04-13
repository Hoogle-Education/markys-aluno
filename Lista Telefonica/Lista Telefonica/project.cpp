#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

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

class Node {
public:
	Contato contato;
	Node* next;
	Node(Contato contato);
};

class LinkedList {
private:
	Node* first;
	Node* last;
public:
	LinkedList();
	LinkedList(Contato contato);

	void addNode(Contato contato);
	void printList();
	const int tamanho();
	Node* encontraContato(string nome);
	void alteraContato(string nome, Contato contato);
	void removeContato(string nome);
	string apresentaContatosHTML();
};

Node::Node(Contato contato) 
{
	this->contato = contato;
	this->next = NULL;
}

const int LinkedList::tamanho()
{
	int count = 0;
	Node* current = first;

	while (current != NULL) {
		current = current->next;
		count++;
	}

	return count;
}

LinkedList::LinkedList()
{
	first = NULL;
	last = NULL;
}

LinkedList::LinkedList(Contato input) 
{
	first = NULL;
	last = NULL;
	this->addNode(input);
}

void LinkedList::addNode(Contato contato) 
{
	if (first == NULL) {
		first = new Node(contato);
		last = first;
	}
	else {
		last->next = new Node(contato);
		last = last->next;
	}
}

void LinkedList::printList()
{
	Node* current = first;

	cout << "-----------------------\n";
	while (current != NULL) {
		cout << "Contato: " << current->contato.getNome() << endl;
		cout << "Telefone: " << current->contato.getTelefone() << endl;
		cout << "Data " << current->contato.getData()
			<< " || Hora: " << current->contato.getHora() << endl;
		current = current->next;
		cout << "-----------------------\n";
	}

}

Node* LinkedList::encontraContato(string nome)
{

	Node* current = first;

	while (current != NULL) {
		if (current->contato.getNome() == nome)
			return current;
		else
			current = current->next;
	}

	return NULL;
}

void LinkedList::alteraContato(string nome, Contato contato) 
{

	Node* toChange = encontraContato(nome);

	if (toChange == NULL)
		cout << "Nome nao encontrado, lista n�o atualizada!\n";
	else
		toChange->contato = contato;

}

void LinkedList::removeContato(string nome)
{

	if (first->contato.getNome() == nome && first == last) {
		first = NULL;
		last = NULL;
		cout << "Removido com sucesso\n";
	}
	else {

		if (first->contato.getNome() == nome) {
			first = first->next;
			cout << "Removido com sucesso\n";
		}
		else {
			Node* current = first;
			while (current->next->contato.getNome() != nome) {
				current = current->next;
				if (current->next == NULL) break;
			}

			if (current->next == NULL) {
				cout << "Nao foi possivel remover\n";
			}
			else {
				current->next = current->next->next;
				cout << "Removido com sucesso\n";
			}
		}
	}
		
}

string LinkedList::apresentaContatosHTML()
{
	string aux = "";
	Node* current = first;

	while (current != NULL) {

		aux += "<tr>\n";
		aux += "<td>" + current->contato.getNome() + "</td>";
		aux += "<td>" + current->contato.getTelefone() + "</td>";
		aux += "<td>" + current->contato.getData() + "</td>";
		aux += "<td>" + current->contato.getHora() + "</td>";
		aux += "</tr>";

		current = current->next;
	}

	return aux;

}


Contato insereContato(string model = NULL) {
	string nome, telefone, data, hora;
	cout << "--------------------------\n";
	if (model == "novo") {
		cout << "Adicionando novo contato!\n";
	}
	else if(model == "atualizando") {
		cout << "Atualizando dados do contato!\n";
	}
	
	cout << "Nome: ";
	getline(cin, nome);
	
	cout << "Telefone: ";
	getline(cin, telefone);

	cout << "Data: ";
	getline(cin, data);

	cout << "Hora: ";
	getline(cin, hora);
	cout << "--------------------------\n";

	return Contato(nome, telefone, data, hora);
}

void menu() {
	cout << "1 - Listar todos os contatos da lista\n"
		<< "2 - Adicionar novo contato a lista\n"
		<< "3 - Atualizar um contato da lista\n"
		<< "4 - Remover um contato da lista\n"
		<< "5 - Exportar a lista para um arquivo bin�rio\n"
		<< "6 - Exportar a lista para arquivo HTML\n"
		<< "0 - Sair do programa\n";
}

void writeHTML(LinkedList list) {
	ofstream file("output.html");
	
	file << "<!DOCTYPE html> \n"
		<< " <body> "
		<< " <table>"
		<< list.apresentaContatosHTML()
		<< "</table> " 
		<< " </ body>\n" 
		<< "< / html> \n";
}

int main() {

	LinkedList list = LinkedList();
	int option;

	do {

		menu();
		cin >> option;
		cin.get();
		string nome;
	
		switch (option) {
			case 1:
				list.printList();
				break;
			case 2:
				list.addNode(insereContato("novo"));
				break;
			case 3:
				cout << "Digite o nome do contato que deseja alterar: ";
				getline(cin, nome);
				list.alteraContato(nome, insereContato("atualizando"));
				break;
			case 4:
				cout << "Digite o nome a ser removido: ";
				getline(cin, nome);
				list.removeContato(nome);
				break;
			case 5:
				break;
			case 6:
				writeHTML(list);
				cout << "Arquivo HTML gerado com sucesso!\n";
				break;
			case 0:
				cout << "Sair do programa!\n";
				break;
			default:
				cout << "Digite uma opcao valida\n";
				break;
		}

	} while (option != 0);

	list.printList();

	return 0;
}