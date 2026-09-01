#include <iostream>
using namespace std;

void tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << a << " to " << c << endl;
        return;
    }

    tower(n - 1, a, c, b);

    cout << "Move disk " << n << " from " << a << " to " << c << endl;

    tower(n - 1, b, a, c);
}

int main()
{ int n;
     cout<<"enter the no plates "<<endl;
    cin>>n;
    tower(n, 'A', 'B', 'C');
    return 0;
}
