/* Josue Ballona
 * CS2250
 * Project 2 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// function definitions
void read_array(int[], int, int min_range, int max_range);
void print_array(int[], int);
void frequent(int[], int);
void two_largest(int[], int, int*, int*, int*, int*);
int* half_size(int[], int);

int main() {
  // PART 1

  cout << setw(10) << "PART 1\n";

  // constant integer for randomNumbers30 size
  const int SIZE1 = 100;
  // array definition.
  int randomNumbers30[SIZE1];

  // Function calls to insert data into array, read the array, and find the most
  // frequent number(s)
  read_array(randomNumbers30, SIZE1, 1, 30);
  print_array(randomNumbers30, SIZE1);
  frequent(randomNumbers30, SIZE1);

  // PART 2

  cout << setw(10) << "PART 2\n";
  // char variable to let the user decide whether or not
  // to continue the do-while loops
  int doWhileStop = 0;
  char doWhileCont;

  // array for part 2, random numbers from 1-200 will be
  // stored here
  int randNum2[SIZE1];
  // pointers to accept largest number, second largest number, and their
  // subscripts
  int largest, largestsub, secondlargest, secondlargestsub;

  // do-while loop that stops when user enters -1
  do {
    // function read_array to fill the array
    // print_array to display the new array
    // two_largest to find the two largest numbers in the array
    read_array(randNum2, SIZE1, 1, 200);
    print_array(randNum2, SIZE1);
    two_largest(randNum2, SIZE1, &largest, &largestsub, &secondlargest,
                &secondlargestsub);

    // display the two largest numbers and their subscripts in the array.
    cout << "The two largest elements are: " << largest;
    cout << " with a subscript of " << largestsub;
    cout << " and " << secondlargest << " ";
    cout << "with a subscript of " << secondlargestsub << ".\n";
    cout << "Would you like to do another array? [Y/N] ";

    // do while loop to ask the user to stop or continue with this loop.
    do {
      cin >> doWhileCont;
      if (doWhileCont == 'n' || doWhileCont == 'N')
        doWhileStop = -1;
      else if (doWhileCont == 'y' || doWhileCont == 'Y')
        doWhileStop = 0;
      // safeguard in case user does not enter y or n
      else
        cout << "Error. Enter a valid choice. [Y/N] ";
    } while (doWhileCont != 'y' && doWhileCont != 'Y' && doWhileCont != 'n' &&
             doWhileCont != 'N');
    cout << endl;
  } while (doWhileStop != -1);

  // PART 3

  cout << setw(10) << "PART 3\n";
  // Array definition, array pointer definition, size declarator
  int Array3[SIZE1];
  int* Array3Ptr = 0;
  int SIZE3 = SIZE1 / 2;

  // read_array to store the array with random integers
  // from 10 to 30 and print_array to print it out
  read_array(Array3, SIZE1, 10, 30);
  cout << "The Array is: \n";
  print_array(Array3, SIZE1);
  cout << endl;

  // calls half_size which dynamically allocates a new
  // array of integers of half the size of the first array.
  // This array stores the summations of every two subscripts in one
  // Stores the address of the new array in the variable.
  Array3Ptr = half_size(Array3, SIZE1);

  // Print the new array
  cout << "The new Array is: \n";
  print_array(Array3Ptr, SIZE3);
  // Print the original array
  cout << endl << "The original array is: \n";
  print_array(Array3, SIZE1);
  cout << endl;

  return 0;
}

/*
 * read_array feeds the random numbers into the array
 */
void read_array(int randNumb[], int size, int min_range, int max_range) {
  // random number generator seed
  srand(time(NULL));

  // for loop to enter in a random number to every spot
  for (int randnumbindex = 0; randnumbindex < size; randnumbindex++) {
    randNumb[randnumbindex] = (rand() % max_range + min_range);
  }
}

/*
 * print_array reads the array that was just filled with random numbers
 */
void print_array(int randnumarray[], int size) {
  // for loop just to read out the array
  for (int printindex = 0; printindex < size; printindex++) {
    cout << randnumarray[printindex] << " ";
    // makes it so there are only 10 numbers per line.
    if ((printindex + 1) % 10 == 0) cout << endl;
  }
}

/*
 * goes through the array of random numbers and finds the most frequent ones,
 * then displays them.
 */
void frequent(int randnumarray[], int size) {
  // array to count the frequency of the numbers
  int arrCounter[31];

  // for loop initializes the new array to 0 for every subscript
  // was getting large numbers without this loop
  for (int countindex = 0; countindex < 31; countindex++) {
    arrCounter[countindex] = 0;
  }

  // for loop will go through the array of random numbers and
  // add 1 to the subscript corresponding to each number in the second array to
  // count the frequency
  for (int frequentindex = 0; frequentindex < size; frequentindex++) {
    arrCounter[randnumarray[frequentindex]] += 1;
  }

  // sets the maxvalue at a number that is under the range
  int maxvalue = -1;

  // for loop finds the number of times that the most frequent number was
  // generated in the first array
  for (int index = 0; index < 31; index++) {
    if (arrCounter[index] > maxvalue) maxvalue = arrCounter[index];
  }

  // for loop displays every number that was most frequently found in array 1
  cout << "The number(s) that appear(s) the most is/are: ";
  for (int i = 0; i < 31; i++) {
    if (arrCounter[i] == maxvalue) cout << i << ", ";
  }
  cout << endl << endl;
}

/*
 * goes through the array of random numbers and finds the TWO most frequent ones
 * and their subscripts
 * stores them in variables
 */
void two_largest(int randNumArr2[], int size, int* a, int* b, int* c, int* d) {
  // intergers to find the largest and second largest numbers
  int largest = 0, secondlargest = 0;

  // for loop to store the largest number in largest and second largest in
  // secondlargest
  for (int i = 0; i < size; i++) {
    // if the number is bigger than the number stored in largest, store it in
    // largest
    if (randNumArr2[i] > largest) largest = randNumArr2[i];
    // else if its greater than the second largest,
    // store it in secondlargest
    else if (randNumArr2[i] > secondlargest)
      secondlargest = randNumArr2[i];
  }

  // for loop to store the numbers and their subscripts in the pointers
  for (int i = 0; i < size; i++) {
    if (randNumArr2[i] == largest) {
      *a = randNumArr2[i];
      *b = i;
    } else if (randNumArr2[i] <= largest && randNumArr2[i] >= secondlargest) {
      *c = randNumArr2[i];
      *d = i;
    }
  }
}

/*
 * takes an array and its size as parameters
 * dynamically allocates a new array with half the size
 * of the first array.
 * stores the sum of the first two integers in the first array
 * in the new one and then the sum of the next two in the next spot
 * and so on.
 */
int* half_size(int Arr[], int size) {
  // pointer to the array
  int* arrptr = NULL;
  // pointer points to the new array
  int size2 = size / 2;

  // if the size is an odd number, round it up.
  if (size % 2 != 0) size2 = size2 + 1;

  arrptr = new int[size2];

  for (int i = 0; i < size2; i++) *(arrptr + i) = 0;

  // counters to make sure the right numbers get added
  int flag1 = 0, flag2 = 1;
  // for loop to fill in the new array
  for (int i = 0; i < size2; i++) {
    *(arrptr + i) = *(Arr + flag1) + *(Arr + flag2);
    flag1 += 2;
    flag2 += 2;
  }

  // returns the address of the new array
  return arrptr;
}
