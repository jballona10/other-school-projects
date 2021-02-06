#include <iostream>
#define DEFAULT_VALUE 0;

using namespace std;

class List {

  static int objectCount;
  int * list;
//constructors
  public:
      int numItems;

    List() {
      objectCount++;
    }

    List(int n) {

    numItems = n;
    list = new int[n];

    for (int i = 0; i < n; i++){
      list[i] = DEFAULT_VALUE;
    }
      // initializing every item of the array to 0

    objectCount++; // incrementing objectCount by 1
  }

  //2: to fill the list with integer values from the user

  void readList() {
    cout << "Please enter " << numItems << " integers to add to the list, seperated by spaces."
         << endl;
    for (int i = 0; i < numItems; i++){
      cin >> list[i];
    }
    cout << "read values successfully" << endl;
  }

  void print() {
    cout << endl << "Values: " << endl;
    for (int i = 0; i < numItems; i++) {
      cout << list[i] << " "; // to print the values in the list one by one
    }
    cout << endl << endl;

  }


  double getAverage() {

    double average;
    int sum = 0;

    for (int i = 0; i < numItems; i++){
      sum += list[i];
    }
    average = static_cast<double>(sum) / numItems;
    return average;
  }

  int getObjectCount() {
    return objectCount;
  }


  List(const List & list1) {
    numItems = list1.numItems;
    list = new int[numItems];
    int i;
    for (i = 0; i < numItems; i++)
      list[i] = list1.list[i];

    objectCount++;

  }

  List operator + (List const & list1) {
    // Asuming they are the same
    List added = List(numItems);
    added.numItems = numItems;
    for (int i = 0; i < numItems; i++){
      added.list[i] = list1.list[i] + list[i];
    }
    return added;
  }

  List operator - (List const & list1) {

    List subtracted = List(numItems);
    subtracted.numItems = numItems;
    for (int i = 0; i < numItems; i++){
      subtracted.list[i] = list[i] - list1.list[i];
    }
    return subtracted;
  }

  //e. ++ operator overloading: list1++ increments all the values of the list by 1
  void operator++() {
    for (int i = 0; i < numItems; i++)
      list[i]++; //to increment the values

  }
  void operator = (List const & list1) {
    numItems = list1.numItems;
    for (int i = 0; i < numItems; i++){
      list[i] = list1.list[i];
    }
  }

  bool operator == (List const & list1) {

    if (numItems != list1.numItems)
      return false;
    int isEqualFlag = 0;
    for (int i = 0; i < numItems; i++) {
      if (list[i] != list1.list[i]) {
        isEqualFlag = 1;
      }
    }
    if (isEqualFlag == 0)
      return true;
    else
      return false;
  }
};

void menu() {
  cout << "Welcome to Mohammed Bilal's Project 3! Please choose one of the options or 7 to quit" << endl;
  cout << "1. Read list (to enter values)" << endl;
  cout << "2. Print list (print in the list)" << endl;
  cout << "3. Get Average" << endl;
  cout << "4. Get objects count" << endl;
  cout << "5. Copy constructor" << endl;
  cout << "6. Operator overloading" << endl;
  cout << "7.Quit" << endl;

};

int List::objectCount = 0; // initialize the static variable objectcount with 0

int main() {
  // Any number will work here
  List list1 = List(10);
  list1.print();


  int choice;

  do {
    menu();
    cin >> choice;
    switch (choice) {

    case 1:
      list1.readList();
      break;

    case 2:
      list1.print();
      break;

    case 3:
      float avg;
      avg = list1.getAverage();
      cout << "Average is " << avg << endl;
      break;

    case 4:
      int ctr;
      ctr = list1.getObjectCount();
      cout << "Object Count is " << ctr << endl;
      break;

    case 5:
      {
        List l2 = list1; //used to call the copy constructor
        cout << "copied object created successfully\n";
        l2.print();
      }
      break;

    case 6:
      {
        int overloadChoice;
        cout << "1. Add (+)" << endl
             << "2. Subtract (-) " << endl
             << "3. equal (==) " << endl
             << "4. copy constructor (=)" << endl
             << "5. increment (++)" << endl;
          cin >> overloadChoice;
          int newNumItems = list1.numItems;

          switch (overloadChoice) {
          case 1:
            {
              cout << "This is the + operator" << endl;
              List bill = List(newNumItems);
              bill.readList();
              List final = bill + list1;
              cout << "Added list: " << endl;
              final.print();
              break;
            }
          case 2:
            {
              cout << "This is the - operator" << endl;
              List bill = List(newNumItems);
              bill.readList();
              List final = list1 - bill;
              cout << "Subtracted list: " << endl;
              final.print();
              break;
            }
          case 3:
            {
              cout << "This is the == operator" << endl;
              List bill = List(newNumItems);
              bill.readList();
              bool final = bill == list1;
              if (final)
                cout << "true" << endl;
              else
                cout << "false" << endl;
              break;
            }
          case 4:
            {
              cout << "This is the = operator" << endl;
              List bill = List(newNumItems);
              bill.readList();
              list1 = bill;
              cout << "copied list: " << endl;
              bill.print();
              break;
            }
          case 5:
            {
              cout << "This is the ++ operator" << endl;
              ++list1;
              cout << "incremented list: " << endl;
              list1.print();
              break;
            }
          default:
            cout << "Enter valid Choice" << endl;
            break;
          }
        break;
      }

    case 7:
      return 0;
      break;

    default:
      cout << "Enter valid Choice\n";
      break;
    }

  } while (choice != 0);

}
