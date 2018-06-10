#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	string name;
	int weight;
	Node * Left = nullptr;
	Node * Right = nullptr;

	Node(string n, int w)
	{
		name = n;
		weight = w;
	}

	void Add(string n, int w) //Adds a value and puts it in the right place, relatively straightfoward
	{
		if (n <= name)
		{
			if (Left == nullptr)
			{
				Left = new Node(n,w);
			}

			else
			{
				Left->Add(n,w);
			}
		}

		if (n > name)
		{
			if (Right == nullptr)
			{
				Right = new Node(n,w);
			}

			else
			{
				Right->Add(n,w);
			}
		}
	}

	void preOrder()
	{
		cout << "Pre Order traversal: \n";
		VLR();
		cout << "\n";
	}

	void VLR()
	{
		cout << name << " "<< weight << "\n";
		
		if (Left != nullptr)
		{
			Left->VLR();
		}

		if (Right != nullptr)
		{
			Right->VLR();
		}
	}

	void inOrder()
	{
		cout << "In Order traversal: \n";
		LVR();
		cout << "\n";
	}

	void LVR()
	{
		if (Left != nullptr)
		{
			Left->LVR();
		}

		cout << name << " " << weight << "\n";

		if (Right != nullptr)
		{
			Right->LVR();
		}
	}

	void postOrder()
	{
		cout << "Post Order traversal: \n";
		LRV();
		cout<<"\n";
	}

	void LRV()
	{
		if (Left != nullptr)
		{
			Left->LRV();
		}

		if (Right != nullptr)
		{
			Right->LRV();
		}

		cout << name << " " << weight << "\n";
	}

	int getHeight()
	{
		if (Left == nullptr && Right == nullptr)
		{
			return 0;
		}

		else
		{
			int lHeight = 0;
			int rHeight = 0;

			if (Left != nullptr)
			{
				lHeight = Left->getHeight() + 1;
			}
			if (Right != nullptr)
			{
				rHeight = Right->getHeight() + 1;
			}

			if (lHeight >= rHeight)
				return lHeight;
			else
				return rHeight;
		}
	}

	int getLeaves()
	{
		if (Left == nullptr && Right == nullptr)
		{
			return 1;
		}

		else if (Left == nullptr)
		{
			return Right->getLeaves();
		}

		else if (Right == nullptr)
		{
			return Left->getLeaves();
		}

		else
		{
			return Left->getLeaves() + Right->getLeaves();
		}
	}

	void Search(string n)
	{
		if (n == name)
		{
			cout << "The weight of " << name << " is " << weight << "lbs.\n";
		}
		else
		{
			if (n < name && Left != nullptr)
			{
				Left->Search(n);
			}

			else if (n > name && Right != nullptr)
			{
				Right->Search(n);
			}

			else
			{
				cout << n << "is not present in the tree.\n";
			}

		}
	}
};