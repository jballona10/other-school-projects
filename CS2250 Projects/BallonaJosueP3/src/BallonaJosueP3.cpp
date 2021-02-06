#include <iostream>
using namespace std;

int DEFAULT_VALUE = 0;
class List
{
public:
	static int objectCount;
	int * list;
	int numItems;
	List()
	{
      objectCount++;
    }
	// constructor that initializes the items to 0;
    List(int a)
    {
    numItems = a;
    list = new int[a];
    for (int i = 0; i < a; i++)
    {
      list[i] = DEFAULT_VALUE;
    }

    objectCount++; // incrementing objectCount by 1
    }

  //fill the list with values from user
  void readList()
  {
    cout << "Enter " << numItems << " integers to add to the list."
         << endl;
    for (int i = 0; i < numItems; i++)
    {
      cin >> list[i];
    }
    cout << "read values successfully" << endl;
  }

  //prints out your list
  void print()
  {
    cout << endl << "Here is the list: " << endl;
    for (int i = 0; i < numItems; i++) {
      cout << list[i] << " ";
    }
    cout << endl << endl;

  }

  // return the average of the list
  float getAverage()
  {
    float average;
    int total = 0;

    for (int i = 0; i < numItems; i++)
    {
      total += list[i];
    }
    average = static_cast<float>(total) / numItems;
    return average;
  }

  // return the number of objects created
  int getObjectCount()
  {
    return objectCount;
  }

  // copy constructor
  List(const List & list1)
  {
    numItems = list1.numItems;
    list = new int[numItems];
    int i;
    for (i = 0; i < numItems; i++)
      list[i] = list1.list[i];

    objectCount++;

  }

  // adds to items of list 1 to list 2
  List operator + (List const & list1)
  {
    List list2 = List(numItems);
    list2.numItems = numItems;
    for (int i = 0; i < numItems; i++)
    {
      list2.list[i] = list1.list[i] + list[i];
    }
    return list2;
  }

  // subtracts the items of list 2 from list 1
  List operator - (List const & list1)
  {
    List list3 = List(numItems);
    list3.numItems = numItems;
    for (int i = 0; i < numItems; i++)
    {
      list3.list[i] = list1.list[i] - list[i];
    }
    return list3;
  }

  //increments all the values of the list by 1
  void operator++()
  {
    for (int i = 0; i < numItems; i++)
      list[i]++;
  }

  // copies the items in list 1 to the new list
  void operator = (List const & list1) {
    numItems = list1.numItems;
    for (int i = 0; i < numItems; i++){
      list[i] = list1.list[i];
    }
  }

  // compares the two lists
  bool operator == (List const & list1)
  {

    bool flag = 0;
    for (int i = 0; i < numItems; i++)
    {
      if (list[i] != list1.list[i])
      {
        flag = 1;
      }
    }
    return flag;
  }
};

// initialize the static variable to -
int List::objectCount = 0;

int main()
{

  List list1 = List(10);
  list1.print();
  int choice;

  do {
	  cout << "Please choose one of the options or 7 to quit" << endl;
	  cout << "1. Read list (to enter values)" << endl;
	  cout << "2. Print list (print in the list)" << endl;
	  cout << "3. Get Average" << endl;
	  cout << "4. Get objects count" << endl;
	  cout << "5. Copy constructor" << endl;
	  cout << "6. Add two lists" << endl;
	  cout << "7. Subtract Two list" << endl;
	  cout << "8. Compare Two lists" << endl;
	  cout << "9. Copy one list to another" << endl;
	  cout << "10. Increment the items in a list by 1" << endl;
	  cout << "11. Quit" << endl;

    cin >> choice;
    switch (choice)
    {
    case 1:
    {
      list1.readList();
      break;
    }
    case 2:
    {
      list1.print();
      break;
    }
    case 3:
    {
      float avg;
      avg = list1.getAverage();
      cout << "the average is " << avg << endl;
      break;
    }
    case 4:
    {
      int count;
      count = list1.getObjectCount();
      cout << "the object Count is " << count << endl;
      break;
    }
    case 5:
      {
        List secondlist = list1;
        cout << "Heres the list made: " << endl;
        secondlist.print();
        break;
      }
    case 6:
      {
    	  List sumlist = List(10);
    	  sumlist.readList();
    	  List sumfinal = sumlist + list1;
    	  cout << "Added list: " << endl;
    	  sumfinal.print();
    	  break;
      }
    case 7:
    {
    	List diff = List(10);
    	diff.readList();
    	List diffFinal = list1 - diff;
    	cout << "Subtracted list: " << endl;
    	diffFinal.print();
    	break;
    }
    case 8:
    {
    	List compare = List(10);
    	compare.readList();
    	bool compfinal = compare == list1;
    	if (compfinal)
    		cout << "true" << endl;
    	else
    		cout << "false" << endl;
    	break;
    }
    case 9:
    {
    	 List copy = List(10);
    	 copy.readList();
    	 list1 = copy;
    	 cout << "Copied list: " << endl;
    	 copy.print();
    	 break;
    }
    case 10:
    {
    	++list1;
    	cout << "Newly incremented list: " << endl;
    	list1.print();
    	break;
    }
    case 11:
    {
    	return 0;
    	break;
    }
    default:
    {
    	cout << "Please enter a valid choice.\n";
    	break;
    }
    }

  } while (choice != 0);

  return 0;
}
