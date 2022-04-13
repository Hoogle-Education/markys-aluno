#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "Contato.h"
#include "LinkedList.h"

using namespace std;

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
		<< "5 - Exportar a lista para um arquivo binário\n"
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

void writeBinary(LinkedList list) {
	ofstream binaryFile("contacts.dat", ios::out | ios::binary);
	if (!binaryFile) {
		cout << "Cannot open file!" << endl;
		return;
	}

	Node* current = list.first;
	while (current != NULL) {
		binaryFile.write((char*) &current->contato, sizeof(Contato));
		current = current->next;
	}

	binaryFile.close();
	if (!binaryFile.good()) {
		cout << "Houve um erro para escrever o arquivo\n";
	}
	else {
		cout << "Arquivo binario gerado com sucesso!\n";
	}
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
				writeBinary(list);
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