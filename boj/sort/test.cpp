#include <iostream>
using namespace std;
int main(void)
{
    int n, i, j;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        cout << 1 << " ";
        cout << endl;
    }

    return 0;
}