#include <iostream>
#include "Sorter.h"

int main(int argc, char** argv) {
	Sorter sorter;

  	if (argc < 2) {
    	cout << "No valid file\n" << endl;
  	}
  	else if (argc >= 2) {
    	string file = argv[1];
      	sorter.fileRead(file);
  	}
  	return 0;
}
