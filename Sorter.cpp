#include "Sorter.h"

using namespace std;

Sorter::Sorter(){
	
}
Sorter::~Sorter(){
	
}
void Sorter::fileRead(string file){
	string elements;
 	string line;
  	double value;
  	int lineNum = 1;

  	ifstream inputFile;
  	inputFile.open(file.c_str());

  	getline(inputFile, elements);

  	numElements = atoi(elements.c_str());
	
	bubbleArr = new double[numElements];
  	quickArr = new double[numElements];
  	insertionArr = new double[numElements];
  	cocktailArr = new double[numElements];
  	
  	for(int i = 0; i < numElements; i++) {
    	lineNum++;
    	getline(inputFile, line);

    	try {
    		value = atof(line.c_str());
    	}
    	catch(exception e) {
      		cout << "Format is not valid" << endl;
     		return;
    	}	

    	bubbleArr[i] = value;
    	insertionArr[i] = value;
    	quickArr[i] = value;
    	cocktailArr[i] = value;
  	}
  	
	inputFile.close();
  	runSorts();
}
void Sorter::bubbleSort(double arr[]){
   for (int i = 0; i < numElements-1; i++){
       for (int j = 0; j < numElements-i-1; j++) {
           if (arr[j] > arr[j+1]) 
              swap(arr, j, j+1);
		}
	}
}
void Sorter::insertionSort(double arr[]){
	double curr;
	int j;
    for (int i = 1; i < numElements; i++) {  
    	curr = arr[i];  
        j = i - 1;  
  
        //moving each element that is bigger than curr, but currently behind it in the array over
        while (j >= 0 && arr[j] > curr) {  
            arr[j + 1] = arr[j];  
            j--;  
        }  
        arr[j + 1] = curr;  //placing curr in now empty and correct spot
    }  
}
void Sorter::quickSort(double arr[], int left, int right){
	
	if(left < right){
		int pos = partition(arr, left, right);
		quickSort(arr, left, pos - 1); 
        quickSort(arr, pos + 1, right); 
	}
	
}
int Sorter::partition(double arr[], int left, int right){
	int pivot = arr[right];   
    int i = (left - 1);
  
    for (int j = left; j <= right- 1; j++) { 
        if (arr[j] <= pivot) { 
            i++;
            swap(arr, i, j); 
        } 
    } 
    swap(arr, i + 1, right); 
    return (i + 1); 
}
void Sorter::cocktailSort(double arr[]){
	bool swapped = true; 
    int start = 0; 
    int end = numElements - 1; 
  
    while (swapped) {
    	swapped = false; //reset
    	//first iteration is from left to right
        for (int i = start; i < end; i++) { 
            if (arr[i] > arr[i + 1]) { 
                swap(arr, i, i + 1); 
                swapped = true; //something has been swapped
            } 
        } 
  
        if (!swapped) 
            break; //because nothing changed, the list is sorted
        swapped = false; //reset
        --end; //because the end item is in the right place so we don't have to worry about it
  
        // next iteration is from right to left
        for (int i = end - 1; i >= start; --i) { 
            if (arr[i] > arr[i + 1]) { 
                swap(arr, i, i + 1); 
                swapped = true; 
            } 
        } 
        ++start; //because the starting item is in the right place so we don't have to worry about it
    } 
}
void Sorter::swap(double arr[], int a, int b){
	double temp = arr[a];
  	arr[a] = arr[b];
  	arr[b] = temp;
}
void Sorter::runSorts(){
	clock_t clockStart;
  	clock_t clockEnd;
  	float timeCount;

	//Bubble Sort
  	cout <<"Bubble sort \n";
  	clockStart = clock();
  	cout <<"Time Started: ";
  	cout<<clockStart<<endl;
  	bubbleSort(bubbleArr);
  	clockEnd = clock();
  	cout << "Time Ended: ";
  	cout <<clockEnd<<endl;
  	

  	timeCount = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  	cout << timeCount;
  	cout <<"ms to complete "<<endl;

	//Insertion Sort
  	cout <<"Insertion sort \n";
  	clockStart = clock();
  	cout <<"Time Started: ";
  	cout<<clockStart<<endl;
  	insertionSort(insertionArr);
  	clockEnd = clock();
	cout << "Time Ended: ";
  	cout <<clockEnd<<endl;
	
  	timeCount = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  	cout << timeCount;
  	cout <<"ms to complete."<<endl;


  	//Quick Sort
  	cout <<"Quick Sort"<<endl;
  	clockStart = clock();
  	cout <<"Time Started: ";
  	cout<<clockStart<<endl;
  	quickSort(quickArr, 0, numElements - 1);
  	clockEnd = clock();
  	cout << "Time Ended: ";
  	cout <<clockEnd<<endl;

  	timeCount = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  	cout << timeCount;
  	cout << " ms to complete."<<endl;

  	//Cocktail Sort
  	cout <<"Cocktail sort"<<endl;;
  	clockStart = clock();
  	cout <<"Time Started: ";
  	cout<<clockStart<<endl;
  	cocktailSort(cocktailArr);
  	clockEnd = clock();
  	cout << "Time Ended: ";
  	cout <<clockEnd<<endl;

  	timeCount = (float(clockEnd - clockStart)/CLOCKS_PER_SEC) * 1000;
  	cout << timeCount;
  	cout <<" ms to complete. "<<endl;

  	cout <<"Thank you!"<<endl;
}
