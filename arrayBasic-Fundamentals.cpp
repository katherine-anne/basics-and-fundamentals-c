//Author: Katherine Anne S. Liwanag

/* This is a program that ask users to input elements for two arrays which are
re-arrange to descending order.*/

#include <iostream>
using namespace std;

//Checks if the input is an integer
bool validInput (string input) {
    if (input.empty()) return false;  // Ensures that input is not empty
    int start = 0;  //set to zero to validate positive numbers

    if (input[0] == '-') {  //if negative sign skip for digit checking
        start = 1;
    }

    for (int i = start; i < input.length(); i++) {  
        if (!isdigit(input[i])) {   //checks if each character in inputs are digit
            return false;
        }
    }
    return true;
}

//Get array inputs
void inputArray (int array[], int &size) {
    string inputSize;  

     do {
        cout<<"\n Size of Array (1-10): ";
        cin>>inputSize;

        if (validInput(inputSize)) { 
            size = stoi (inputSize);  //converts string input to int
        } else {
            size=0;
            cout<<"Invalid Input. Try Again. \n";
        }

    } while (size<1||size>10); 

    cout<<"\n Enter " <<size <<" Element(s) (Integers Only)\n";

        for (int i=0; i<size; i++) {   //loops the array size
            do {
                string input;
                cout<<"Index "<<i<<": ";
                cin>>input; //get each elements on the indices of the array

                if (validInput(input)) {
                    array[i] = stoi (input);    //converts string input to int
                    break;
                } else {
                    cout<<"Invalid Input. Try Again.\n"; 
                }
            } while (true);
        }
}

int main () {
    int size1, size2, mergeSize;
    int array1[10], array2[10], mergeArrays[20];

    inputArray (array1, size1);
    inputArray (array2, size2);

    mergeSize = size1 + size2; 

    //Copying arrays 1 and 2 to mergeArrays
    for (int i=0; i<mergeSize; i++) {
        if (i<size1) {
            mergeArrays[i] = array1[i]; //stats from adding array1 to the mergeArrays
        } else {mergeArrays [i]= array2[i-size1];   //after 1>=size1, array2 fill in the mergedArrays starting on array2[0]
        }
    }

    //Using bubble sort for descending order
    for (int i=0; i<mergeSize-1; i++) { //number of passes is n-1
        for (int j=0; j<mergeSize-i-1; j++) {   //number of swapping
            if (mergeArrays[j]<mergeArrays[j+1]) {   //compares adjacent elements
            int temp = mergeArrays[j];  //first index element is assigned to a temporary variable
            //Swapping of elements
            mergeArrays[j] = mergeArrays[j + 1];    //first index has now have the element of second index
            mergeArrays[j + 1] = temp;  //the second index has the element of first index
            }
        }
    }

    cout<<"\n Descending order of the Merged Array Elements: \n";
    for (int i =0; i<mergeSize; i++) {
        cout<<mergeArrays[i]<<" ";
    }

    return 0;
}