#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* makeNode(int x) {
	Node* tmp = new Node;
	tmp->data = x;
	tmp->prev = NULL;
	tmp->next = NULL;
	return tmp;
}

void addLast(Node*& node, int x) {
	Node* tmp = makeNode(x);
	if (node == NULL)
		node = tmp;
	else {
		Node* last = node;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = tmp;
		tmp->prev = last;
	}
}

void addFirst(Node*& node, int x) {
	Node* tmp = makeNode(x);
	if (node == NULL)
		node = tmp;
	else {
		node->prev = tmp;
		tmp->next = node;
		
		node = tmp;
	}
}

void addMiddle(Node*& node, int x, int vitri) {
	Node* tmp = makeNode(x);
	Node* local = node;
	for (int i = 0; i < vitri; i++) {
		local = local->next;
	}
	local = local->prev;
	tmp->next = local->next;
	tmp->prev = local;
	local->next = tmp;
}
void display(Node* node) {
	while (node != NULL) {
		cout << node->data << "  ";
		node = node->next;
	}
	cout << endl;
}

void deleteFirst(Node*& node) {
	node = node->next;
	node->prev = NULL;
}

void deleteLast(Node*& node) {
	Node* tmp = node;
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = NULL;
}

void deleteMiddle(Node*& node, int vitri) {
	Node* tmp = node;
	for (int i = 0; i < vitri; i++) {
		tmp = tmp->next;
	}
	tmp = tmp->next;
	tmp->next->prev = tmp->prev;
}
int main() {
	Node* node = NULL;
	
	int i = 0;
	while (i == 0) {
		cout << "1. them dau\n";
		cout << "2. them cuoi\n";
		cout << "3. them giua\n";
		cout << "4. xoa dau\n";
		cout << "5. xoa cuoi\n";
		cout << "6. xoa giua\n";
		int chon;
		cout << "chon: ";
		cin >> chon;
		switch (chon) {
		case 1: {
			int x; cin >> x;
			addFirst(node, x);
			display(node);
			break;
		}
		case 2: {
			int x; cin >> x;
			addLast(node, x); 
			display(node);
			break;
		}
		case 3: {
			int x; cin >> x;
			cout << "Vi tri: "; int vitri; cin >> vitri;
			addMiddle(node, x, vitri);
			display(node);
			break;
		}
		case 4: {
			
			if (node == NULL)
				cout << "Danh sach da trong\n";
			else {
				deleteFirst(node);
				display(node);
			}
			break;
		}
		case 5: {
			deleteLast(node);
			display(node);
			break;
		}
		case 6: {
			int vitri; cout << "Vi tri: ";
			cin >> vitri;
			deleteMiddle(node, vitri);
			display(node);
			break;
		}
		}
	}

	system("pause");
	return 0;
}