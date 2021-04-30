#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    int range;
    string result;
    int randn;
    vector<int> numlist;

    cout << "[Push_swap helper]" << endl;
    cout << "n = ";
    cin >> n;
    cout << "range = ";
    cin >> range;
    result = "ARG=\"";
    srand(time(NULL));
    while (1)
    {
        if (numlist.size() == n)
            break;
        randn = rand() % range;
        bool isd = false;
        for (auto vn : numlist)
        {
            if (vn == randn)
            {
                isd = true;
                break;
            }
        }
        if (!isd)
            numlist.push_back(randn);
    }
    for (auto vn : numlist)
    {
        result += to_string(vn);
        result += " ";
    }
    result += "\"; ./push_swap $ARG | ./checker $ARG";
    cout << "result = " << endl << result << endl;
    return (0);
}
