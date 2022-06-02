#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void bubble_sort(int arr[],int n);
void quick_sort(int arr[],int low,int high);
void merge_sort(int arr[],int low,int high);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void heap_sort(int arr[],int n);

int pad=50, gap=4, size;
float delay_time;

int main()
{
	cout << "Enter the array size (in between the range 100 - 300) : ";
	cin >> size;
	if(size<100)
	{
		cout << "array size should be minimum 100" << endl;
		cout << "minimum array size is considered" << endl;
		size=100;
	}
	else if(size>300)
	{
		cout << "array size should be maximum 300" << endl;
		cout << "maximum array size is considered" << endl;
		size=300;
	}
	int arr[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=1+rand()%size;
	}
	
	cout << "\nUnsorted array : " << endl;
	for(int i=0;i<size;i++)
	  cout << arr[i] << " ";
	cout << endl;
	
    cout<<"\n1. Bubble sort" << endl
		 << "2. Quick sort" << endl
		 << "3. Merge sort"	 << endl
		 << "4. Insertion sort" << endl
		 << "5. Selection sort" << endl
		 << "6. Heap sort" << endl
		 << endl;
		 
	cout << "To visualize any sorting algorithm listed above Enter the serial no. of that" << endl 
		 << "algorithm(for example enter 1 for Bubble sort, 2 for Quick sort): ";
	int sl;
	cin >> sl;
	while(sl<1 || sl>6)
	{
		cout << "\ninvalid input!" << endl
			 <<	"Please enter a valid number(from 1 to 6) : ";
		cin >> sl;
	}
	
	int speed;
	cout << "\nEnter the speed of displaying sorting algorithm (in a scale of 1-10): ";
	cin >> speed;
	while(speed<1 || speed>10)
	{
		cout << "\nYou must enter value between 1 and 10" << endl
			 << "Enter the speed of displaying sorting algorithm (in a scale of 1-10): ";
		cin >> speed;
	}
	delay_time = 10-speed;
	
	initwindow(2*pad+size*gap,size+2*pad,"Sorting Algorithm Visualizer");
	for(int i=0;i<size;i++)
	{
		line(i*gap+pad,size+pad,i*gap+pad,size+pad-arr[i]);
	}	
	
	delay(1000);
	switch(sl)
	{
		case 1:	bubble_sort(arr,size);
				break;
		
		case 2: quick_sort(arr,0,size-1);
				break;
		
		case 3: merge_sort(arr,0,size-1);
				break;
			
		case 4: insertion_sort(arr,size);
				break;
				
		case 5: selection_sort(arr,size);
				break;
				
		case 6: heap_sort(arr,size);
	}
	
	cout << "\nArray after sorting : " << endl;
	for(int i=0;i<size;i++)
	  cout << arr[i] << " " ;
	getch();
	return 0;
}

void my_delay(int time)
{
	int i=size+1;
	for(int j=1;j<=50*time;j++)
	{
		setcolor(BLACK);
	    line(i*gap+pad,size+pad,i*gap+pad,pad);
	}		
}

void swapline(int i, int j, int x, int y)
{
	my_delay(delay_time);
	setcolor(BLACK);
	line(i*gap+pad,size+pad,i*gap+pad,size+pad-x);
	line(j*gap+pad,size+pad,j*gap+pad,size+pad-y);
	setcolor(WHITE);
	line(i*gap+pad,size+pad,i*gap+pad,size+pad-y);
	line(j*gap+pad,size+pad,j*gap+pad,size+pad-x);
}

void bubble_sort(int arr[],int n)
{
	int i=0;
	while(i<n-1)
	{
		int count=0;
		int j=0;
		while(j<n-i-1)
		{
			if(arr[j]>arr[j+1])
			{			
				swapline(j,j+1,arr[j],arr[j+1]);
				swap(arr[j],arr[j+1]);
			}
			else count++;
			j++;
		}
		if(count==n-i-1)
	    	break;
		i++;
	}				
}

int partition(int arr[],int low,int high)
{
	int pivot = arr[high];
	int index = low;
	for(int i=low;i<high;i++)
	{
		if(arr[i]<pivot)
		{
			swapline(i,index,arr[i],arr[index]);
			swap(arr[i],arr[index]);
			index++;
		}
	}
	swapline(high,index,arr[high],arr[index]);
	swap(arr[high],arr[index]);
	return index;
}

void quick_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int index = partition(arr,low,high);
		quick_sort(arr,low,index-1);
		quick_sort(arr,index+1,high);
	}
}

void assignline(int i,int x,int y)
{
	my_delay(delay_time);
	setcolor(BLACK);
	line(i*gap+pad,size+pad,i*gap+pad,size+pad-x);
	setcolor(WHITE);
	line(i*gap+pad,size+pad,i*gap+pad,size+pad-y);
}

void merge(int arr[],int low,int mid,int high)
{
	int size=high-low+1,li=low,ri=mid+1,i=0;
	int sorted_arr[size];
	while((li<=mid)&&(ri<=high))
	{
		if(arr[li]<arr[ri])
		{
			sorted_arr[i] = arr[li];
			li++;
		}
		else
		{
			sorted_arr[i] = arr[ri];
			ri++;
		}
		i++;
	}
	while(li<=mid)
	{
		sorted_arr[i] = arr[li];
		li++;
		i++;
	}
	while(ri<=high)
	{
		sorted_arr[i] = arr[ri];
	    ri++;
		i++;
	}
	
	for(int j=0;j<size;j++)
		assignline(j+low,arr[j+low],sorted_arr[j]);
	for(int j=0;j<size;j++)
	  arr[j+low] = sorted_arr[j];
}

void merge_sort(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
        	assignline(j+1,arr[j+1],arr[j]);
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        assignline(j+1,arr[j+1],key);
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for (int j = i+1; j < n; j++)
        {
        	if (arr[j] < arr[min_index])
        	{
        		my_delay(delay_time);
        		min_index = j;
			}
		}
        swapline(min_index,i,arr[min_index],arr[i]);
        swap(arr[min_index],arr[i]);
    }
}

int left_child(int i)
{
	return (2*i+1);
}

int right_child(int i)
{
	return (2*i+2);
}

void heapify(int arr[],int i,int n)
{
	int lc = left_child(i);
	int rc = right_child(i);
	int highest = i;
	if(lc<=n-1 && arr[lc]>arr[i])
	  highest = lc;
	if(rc<=n-1 && arr[rc]>arr[highest])
	  highest = rc;
	if(highest!=i)
	{
		swapline(i,highest,arr[i],arr[highest]);
		swap(arr[i],arr[highest]);
		heapify(arr,highest,n);
	}		  
}

void create_heap(int arr[],int n)
{
	for(int i=(n-1)/2;i>=0;i--)
	  heapify(arr,i,n);
}

void heap_sort(int arr[],int n)
{
	create_heap(arr,n);
	int m =n;
	for(int i=n-1;i>=1;i--)
	{
		swapline(i,0,arr[i],arr[0]);
		swap(arr[i],arr[0]);
		m--;
		heapify(arr,0,m);
	}
}

