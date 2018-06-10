// BST Assignment.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>


int main()
{
	BST * bst = new BST();
	cout << "Type in Names and Weights to create a BST sorted by weight. \n";
	for (int x = 0; x < 15; x++)
	{
		//No Error handling
		string name;
		int weight;
		cout << "Name: ";
		cin >> name;
		cout << "Weight: ";
		cin >> weight;
		bst->Add(name, weight);
	}
	cout << "\n";
	bst->preOrder();
	bst->inOrder();
	bst->postOrder();
	cout << "The height of the tree is " << bst->getHeight() << "\n\n";
	cout << "The number of leaves is " << bst->getLeaves() << "\n\n";
	string searchval;
	cout << "Search for a name to find the corresponding weight: ";
	cin >> searchval;
	bst->Search(searchval);
	cout << "The lowest weight is " << bst->minWeight()<<"\n\n";
	bst->firstInAlphabet();
	cin.get();
	getchar();
}

/* In this example, the for loop was changed to iterate 3 times

Type in Names and Weights to create a doubly linked list sorted by name and weig
ht.
Name: Paul
Weight: 200
Name: Hochwald
Weight: 150
Name: Lane
Weight: 100

Pre Order traversal:
Paul 200
Hochwald 150
Lane 100

In Order traversal:
Hochwald 150
Lane 100
Paul 200

Post Order traversal:
Lane 100
Hochwald 150
Paul 200

The height of the tree is 2

The number of leaves is 1

Search for a name to find the corresponding weight: Loke
Lokeis not present in the tree.
The lowest weight is 100

The first name in alphabetical order is Hochwald

*/

