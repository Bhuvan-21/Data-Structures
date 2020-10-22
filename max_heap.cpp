#include <iostream>

using namespace std;

class Heap
{
private:
    int num;
    int arr[100];

public:
    Heap()
    {
        num = 0;
    }

    void Insert(int x)
    {   
        arr[num++] = x;
        //cout<<"inserted"<<x<<endl;
        int i = num-1;
        while(Max_Heapify(parent(i)))
        {
            i = parent(i);
        }
        Display();
        
    }
    
    

    int get_size()
    {
        return num;
    }

    int get_max()
    {
        return arr[0];
    }

    void extract_max()
    {
        arr[0] = arr[num-1];
        num--;
        Max_Heapify(0);
    }

    bool Max_Heapify(int i)
    {
        int l = left(i), r = right(i);
        int largest = i;
        //cout<<arr[l]<<" "<<arr[r]<<" "<<arr[i]<<endl;
        if(l < num && arr[l] > arr[largest])
        {
            largest = l;
    	}
		if(r < num && arr[r] > arr[largest])
        {
		   largest = r;
    	}
		if(largest != i)
        {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            Max_Heapify(largest);
            return true;
        }
        return false;
    }

	void Display()
	{
		for(int i = 0; i < num; i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

    void Heap_Sort()
    {
        while(num)
        {
            cout<<get_max()<<" ";
            extract_max();
        }
    }

    int left(int x)
    {
        return 2*x+1;
    }

    int right(int x)
    {
        return 2*x+2;
    }

    int parent(int i)
    {
        return (i-1)/2;
    }


};

void Build_Max_Heap(Heap &A)
{
    for(int i = A.get_size()/2-1; i >= 0; i--)
    {	
        A.Max_Heapify(i);
    }
}



int main()
{
    Heap h;
    h.Insert(5);
    h.Insert(51);
    h.Insert(23);
    h.Insert(15);
    h.Insert(25);
    h.Insert(53);
    h.Insert(42);
    h.Insert(12);
    h.Insert(7);
    h.Insert(81);
    h.Insert(121);
    h.Insert(96);
    h.Insert(-2);
    h.Insert(-12);
    h.Insert(39);
    
    //Build_Max_Heap(h);
    h.Heap_Sort();


    return 0;
}
