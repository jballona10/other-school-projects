
#include <iostream>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstring>
#include <cctype>

using std::memset;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::set;
using std::sqrt;

const int NO_ITEMS = 6;
const int ITEM_W = 4;

void sieve( set<int>& s, const int lower, const int upper) {
	set<int>::iterator sit = s.begin();
	set<int>::iterator count1 = s.begin();
	set<int>::iterator count2 = s.begin();

	if (*count1 == 1 && *count2 == 1)
	{
		count1++;
		count2++;
	}
	
	int temp = *count1;
	while (count1 != s.end())
	{
		for (int x = 2; x <= 10; x++)
		{
			if (*count1 % x == 0 && *count1 == temp)
				count1 = s.erase(count1);
		}
		if (*count1 == temp)
		{
			count1++;
		}
	}
}
void print_primes( const set<int>& s, const int lower, const int upper) {
	cout << "There are " << s.size() << " prime numbers between " << lower;
	cout << " and " << upper << ":\n";

	int count = 0;

	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		if (count == NO_ITEMS)
			cout << endl;
	 	cout << setw(ITEM_W) << *it;
	}
}

void run_game(set<int>& s) {

	bool uplo = false;
	bool cont = true;
	int upper, lower;
	char quit;

	while (!uplo && cont)
	{
		cout << "Enter an upper range value: ";
		cin >> upper;
		cout << "\nEnter a lower range value: ";
		cin >> lower;
		cout << endl;
		
		if (isalpha(upper) || isalpha(lower))
		{
			cout << "Invalid range. Try again? (Y/N): ";
			cin >> quit;
			cout << endl;
	
			if (quit == 'n' || quit == 'N')
				cont = false;
		}
		else if (upper < lower)
		{
			cout << "The lower end is larger than ";
			cout << "the upper end.\n";
			cout << "Would you like to try again? (Y/N):";
			cin >> quit;
			if (quit == 'n' || 'N')
				cont = false;
		}
		else 
		{
			//uplo = true;
			for (int m = lower; m <= upper; m++)
				s.insert(m);
			sieve(s, lower, upper);
			print_primes(s, lower, upper);
			
			cout << "WOW";

		}
	}
	/*if (uplo == true)
	{
		for (int i = lower; i <= upper; i++)
			s.insert(i);
	}*/
}

int main() {
    set<int> s;
    run_game(s);
    return 0;
}
