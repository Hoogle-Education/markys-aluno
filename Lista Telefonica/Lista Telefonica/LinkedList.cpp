#include "LinkedList.h"

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
