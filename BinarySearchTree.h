#include <queue>
#include "Node.h"

using namespace std;

//I do most of the groundwork in Node because it makes it easier for recursion.

class BST
{
	Node * trunk = nullptr;
public:
	BST()
	{

	}

	void Add(string n, int w)
	{
		if (trunk == nullptr)
		{
			trunk = new Node(n,w);
		}
		else
		{
			trunk->Add(n,w);
		}
	}

	void preOrder()
	{
		trunk->preOrder();
	}

	void inOrder()
	{
		trunk->inOrder();
	}

	void postOrder()
	{
		trunk->postOrder();
	}

	int getHeight()
	{
		return trunk->getHeight();
	}

	void Search(string n)
	{
		trunk->Search(n);
	}

	int getLeaves()
	{
		return trunk->getLeaves();
	}

	int minWeight()
	{
		queue<Node*> q;
		int minWeight = trunk->weight;
		Node * trace; //variable used for traversing children.
		q.push(trunk);
		while (q.empty() == false) {
			trace = q.front();
			q.pop();
			if (trace->weight < minWeight)
				minWeight = trace->weight;
			if(trace->Left != nullptr)
				q.push(trace->Left);
			if(trace->Right != nullptr)
				q.push(trace->Right);
		}

		return minWeight;
	}

	void firstInAlphabet()
	{
		Node * trace = trunk;
		while (trace->Left != nullptr)
		{
			trace = trace->Left;
		}

		cout << "The first name in alphabetical order is " << trace->name << "\n\n";
	}

};