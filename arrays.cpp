#include <iostream>

using namespace std;

class Array
{
private:
int arr[1000];
int size;


public:
Array()
{
	size = 0;
}

int GetSize() const
{
	return size;
}


void Add(int element, int pos)
{
	if(pos < 0 || pos > size)
	{
		cout<<"Enter valid position\n";	
	}
	else
	{
		for(int i = size; i > pos; i--)
		{
			arr[i] = arr[i-1];	
		}	
		arr[pos] = element;
		size++;
	} 
}

void Delete(int pos)
{
	if(pos < 0 || pos >= size)
	{
		cout<<"Enter valid position\n";	
	}
	else
	{
		for(int i = pos; i < size - 1; i++)
		{
			arr[i] = arr[i+1];
		}
		size--;
	}
}	

int Search(int element)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == element)
			return i;
	}
	return -1;	
}

void Show()
{
	for(int i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


};



int main()
{
	Array students;
	students.Add(5, 0);
	students.Add(4, 1);
	students.Add(6, 1);
	students.Add(3, 2);
	students.Show();
	cout<<students.Search(3)<<endl;
	students.Delete(2);
	students.Show();
	
	
	
	
	
	return 0;
}
