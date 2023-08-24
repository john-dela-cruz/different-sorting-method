#include<iostream>

using namespace std;

int InputData(int arr[10])
{
	int count;
	
	cout << "Enter array size: ";
	cin >> count;
	cout << endl;
	
	for(int i = 0; i < count; i++)
	{
		cout << "Enter numbers: ";
		cin >> arr[i];
	}
	
	return(count);
}

void printData(int arr[10], int size)
{
	for(int i = 0; i < size; i++)
    {
        if(i < size - 1)
        cout << arr[i] << ",";
        
        else
        cout << arr[i] << endl;
    }
}

void swap(int *x, int *y)
{
	
	int temp = *x;
	*x = *y;
	*y = temp;
	
}

void changeArray(int arr1[10], int arr2[10], int size)
{
	for(int i = 0; i < size; i++)
	{
		arr2[i] = arr1[i];
	}
}

int Selection(int arr[10], int size)
{	
    int currentMin = 0;

    for(int i = 0; i < size - 1; i++)
    {
        currentMin = i;
        
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[currentMin])
                currentMin = j;
        }
        
    	swap(&arr[currentMin], &arr[i]);
    }

    printData(arr, size);
}

int Bubble(int arr[10], int size)
{
	
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }

    printData(arr, size);
    
}

int Insertion(int arr[10], int size)
{
    int val;
    int j;

    for(int i = 1; i < size; i++)
    {
        val = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > val)
        {
        arr[j + 1] = arr[j];
        j = j - 1;
        }
        arr[j+1] = val;    
    }
	
    printData(arr, size);
}

int Cocktail(int arr[10], int size)
{
    bool swapped = true;
    int leftIndex = 0;
    int rightIndex = size - 1;
    
    while(swapped)
    {
        swapped = false;
        
        for(int i = leftIndex; i < rightIndex; i++)
        {
            if(arr[i] > arr[i + 1]){
                swap(&arr[i], &arr[i+1]);
                swapped = true;
            }
        }
        
        if(!swapped)
        break;
        
        swapped = false;
        
        --rightIndex;
        
        for(int i = rightIndex - 1; i >= leftIndex; --i)
        {
            if(arr[i] > arr[i + 1]){
                swap(&arr[i], &arr[i+1]);
                swapped = true;
            }
        }
        
        ++leftIndex;
    }
    
    printData(arr, size);      
}

int partition(int arr[10], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    
    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int Quick(int arr[10], int low, int high)
{
	if(low < high)
    {
        int pi = partition(arr, low, high);
        
        Quick(arr, low, pi - 1);
        Quick(arr, pi + 1, high);
    }
}

int QuickPrint(int arr[10], int size)
{
	Quick(arr, 0, size-1);
	printData(arr, size);
}

void merge(int arr[10], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}

	for(int j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}

	int i = 0;

	int j = 0;

	int k = l;


	while (i < n1 && j < n2) 
	{

		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		}
		else 
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[10],int l,int r)
{
	if(l>=r)
	{
		return;
	}
	int m = l + (r - l) / 2;
	mergeSort(arr,l,m);
	mergeSort(arr,m + 1,r);
	merge(arr,l,m,r);
}

int MergePrint(int arr[10], int size)
{
	mergeSort(arr, 0, size - 1);
	printData(arr, size);
}

main()
{
	int input[10];
	int inputS[10];
	int inputB[10];
	int inputI[10];
	int inputC[10];
	int inputQ[10];
	int inputM[10];
	
	int n = InputData(input);
	int num[n];
	
	cout << endl;
	
	cout << "Original Array: ";
	printData(input, n);
	cout << endl << endl; 
	
	cout << "Selection Sort:" << endl;
	changeArray(input, inputS, n);
	int s = Selection(inputS, n);
	
	cout << "Bubble Sort:" << endl;
	changeArray(input, inputB, n);
	int b = Bubble(inputB, n);
	
	cout << "Insertion Sort:" << endl;
	changeArray(input, inputI, n);
	int i = Insertion(inputI, n);
	
	cout << "Cocktail Sort:" << endl;
	changeArray(input, inputC, n);
	int c = Cocktail(inputC, n);
	
	cout << "Quick Sort:" << endl;
	changeArray(input, inputQ, n);
	int q = QuickPrint(inputQ, n);
	
	cout << "Merge Sort:" << endl;
	changeArray(input, inputM, n);
	int m = MergePrint(inputM, n);
	
}
