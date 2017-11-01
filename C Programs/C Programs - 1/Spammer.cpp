#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    int no_of_names;
    scanf("%d", &no_of_names);

    map <string, int> no_of_submissions;
    while(no_of_names--)
    {
        string name;
        cin >> name;

        no_of_submissions[name]++;
    }

    for(map <string, int> :: iterator i = no_of_submissions.begin(); i != no_of_submissions.end(); i++)
    {
        if(i->second >= 2)
            cout << i->first << "\n";
    }

    return 0;
}
