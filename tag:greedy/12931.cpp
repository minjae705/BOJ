#include <iostream>
using namespace std;

int ary[51];
int count;
int main ()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> ary[i];
  
  while (1) {
      bool zero = true;
      bool inc = false;
      for (int i = 0; i < n; i++) {
		    if (ary[i] != 0)
	    	    zero = false;
	    	if (ary[i] % 2 != 0) {
		      ary[i] -= 1;
		      count++;
		      inc = true;
		     }
		  }
    
	    if (zero)
		    break;
      if (!inc) {
		    for (int i = 0; i < n; i++)
	        ary[i] /= 2;
				count++;
		  }
 }
 cout << count;
 return 0;
}
