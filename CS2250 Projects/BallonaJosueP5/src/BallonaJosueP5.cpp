#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void recursiveInt(int );
string reverseStringStack(string);
void recursiveSort(int *, int);
void recursiveBubble(int *, int);


int main()
{
    int recursiveint;
    int randomints1[10];
    int randomints2[10];
    int * arrptr1 = '\0';
    int * arrptr2 = '\0';
    string reverse;

    cout << "Enter a multidigit number to be reversed\n";
    cin >> recursiveint;
    recursiveInt(recursiveint);
    cout << recursiveint << endl;

    cout << "Enter a string to reverse\n";
    cin >> reverse;
    reverseStringStack(reverse);
    cout << reverse;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
    	randomints1[i] = rand();
    	cout << randomints1[i] << " ";
    }
    arrptr1 = randomints1;
    recursiveSort(arrptr1, 10);
    for (int i = 0; i < 10; i++)
    {
    	cout << randomints1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
    	randomints2[i] = rand();
    	cout << randomints2[i] << " ";
    }
    arrptr2 = randomints2;
    recursiveBubble(arrptr2, 10);
    for (int i = 0; i < 10; i++)
    {
    	cout << randomints2[i] << " ";
    }
    cout << endl;

}

void recursiveInt(int a)
{
    static int temp, sum;
    if (a > 0)
    {
        temp = a % 10;
        sum = sum*10 + temp;

        recursiveInt(a/10);
    }
    else
    {
        cout << "Number entered is 0 or less than 0\n";
    }
}

string reverseStringStack(string b)
{
    string word = "";
    if (b.length() == 0)
    {
        return " ";
    }
    string last(1, b[b.length()-1]);
    string reversed = reverseStringStack(b.substr(0, b.length()-1));
    return last + reversed;
}

void recursiveSort(int * c, int size)
{
    int maxIndex = 0, temp = 0, index = 0;
    for (index = maxIndex; index < size; index++)
    {
    	if (c[index] > c[maxIndex])
    		maxIndex = index;
    }
    temp = c[size-1];
    c[size-1] = c[maxIndex];
    c[maxIndex] = temp;

    if (size > 1)
    	recursiveSort(c, --size);
}

void recursiveBubble(int * d, int size)
{
	int temp = 0;
	for (int i = 0; i < size-1; i++)
	{
		if (d[i] > d[i+1])
		{
			temp = d[i];
			d[i] = d[i+1];
			d[i+1] = temp;
		}
	}

	recursiveBubble(d, size-1);
}


