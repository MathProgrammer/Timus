#include <iostream>

using namespace std;

int main()
{
      int a_with_berries, b_with_berries, a_with_everything, b_empty, a_empty, b_with_everything;

      cin >> a_with_berries >> b_with_berries;
      cin >> a_with_everything >> b_empty;
      cin >> a_empty >> b_with_everything;

      cout << (a_with_berries - a_empty) << " " << (b_with_berries - b_empty) << "\n";
      return 0;
}
