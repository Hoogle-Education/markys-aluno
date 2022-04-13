#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Contato.h"

class Node {
public:
	Contato contato;
	Node* next;
	Node(Contato contato);
};

class LinkedList {
private:
public:
	Node* first;
	Node* last;
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

#endif LINKEDLIST_H