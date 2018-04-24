#pragma once
#include"AllIncludes.h"
struct Node {
	int index;
	wstring data;
	Node *next;
};

void st_Node(Node *head, int index, wstring data);

void insert_Node(Node *head, int index, wstring data);

Node *search_Node(Node *head, wstring data);

Node *search_Node(Node *head, int index);

bool delete_Node(Node *head, Node *to_delete);

vector <string> split(string str, char delimiter);