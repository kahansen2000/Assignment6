#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Sorter {
  private:
    int numElements;//number of elements in the array
    //4 copies of the unsorted list, one for each type of sort
	double *bubbleArr;
    double *insertionArr;
    double *quickArr;
    double *cocktailArr;

  public:
    Sorter();//constructor
    ~Sorter();//destructor

	//method to read the information from the file
    void fileRead(string file);

	//methods for each sort
	void bubbleSort(double arr[]);
	void insertionSort(double arr[]);
    void quickSort(double arr[], int left, int right);
    int partition(double arr[], int left, int right);//used in quick sort
    void cocktailSort(double arr[]);

    void runSorts();//runs all the sorts
    void swap(double arr[], int a, int b);//swaps two elements in a given array
};
