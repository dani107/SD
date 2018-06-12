// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include"Tree.h"
#include"InputFile.h"

using namespace std;

void BinaryTreeRelease(InputFile* arr,  int start,int end, Tree<string>& kik)
{
	if (start > end) return;
	int mid = (start + end) / 2;
	kik.insert(arr[mid].data, arr[mid].key);
	BinaryTreeRelease(arr, start, mid - 1, kik);
	BinaryTreeRelease(arr, mid + 1, end, kik);
}

void sortArrayOnStringType(InputFile arr[],const int counter)
{
	InputFile swap;
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = 0; j < counter-i-1; j++)
		{
			if(arr[j+1].data.compare(arr[j].data) <0)
			{
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
	}
}

int main()
{
	
	Tree<string> tree;
	InputFile* elements;
	ifstream file("test.txt", ios::binary);
	int number, size;
	char* text;
	int i=0,counter = 0;
	while (!file.eof())
	{
		file >> number;
		file >> size;
		text = new char[size + 1];
		file >> text;
		counter++;
	}
	file.seekg(0,ios::beg);
	elements = new InputFile[counter];
	while (!file.eof())
	{
		file >> number;
		file >> size;
		text = new char[size + 1];
		file >> text;
		elements[i].data = text;
		elements[i].key = number;
		i++;

	}
	sortArrayOnStringType(elements, counter);
	BinaryTreeRelease(elements, 0, counter - 1, tree);
	
	char end;
	string command;
	string data1;
	int key;


	while (!cin.eof())
	{
		
		cout << "Enter command: ";
		cin >> command;
		if (command.compare("insert") == 0)
		{
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter data: ";
			cin >> data1;
			tree.insert(data1, key);
		}
		else if (command.compare("remove") == 0)
		{
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter data: ";
			cin >> data1;
			cout << tree.remove(data1, key)<<endl;
		}
		else if (command.compare("removeall") == 0)
		{
			cout << "Enter key: ";
			cin >> key;
			cout << "Number of items removed: ";
			cout << tree.removeall(key)<<endl;
		}
		else if (command.compare("search") == 0)
		{
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter data: ";
			cin >> data1;
			cout<<tree.search(data1, key)<<endl;
		}
		else
		{
			cout << "Not correct command!"<<endl;
		}
		
	}
	


	file.close();


 
    
	return 0;
}

