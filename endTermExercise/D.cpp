#include <bits/stdc++.h>

using namespace std;

class CSet
{
    int numbers;
    int *data;

public:
    CSet()=default;
    CSet(int numbers, int *data) : numbers(numbers), data(data) {}
    CSet operator-(CSet &);
    CSet operator+(CSet& other)
    {
        CSet res;
        res.numbers = 0;
        res.data = new int[numbers+other.numbers];
        for (int i = 0; i < numbers; i++)
            res.data[res.numbers++] = data[i];
        for (int i = 0; i < other.numbers; i++)
        {
            bool flag = true;
            for (int k = 0; k < res.numbers; k++)
            {
                if (res.data[k] == other.data[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res.data[res.numbers++] = other.data[i];
            }
        }
        return res;
    };
    CSet operator*(CSet &);
    void say()
    {
        for (int i = 0; i < numbers - 1; i++)
            cout << data[i] << ' ';
        cout << data[numbers - 1] << endl;
    }
};

CSet CSet::operator-(CSet &other)
{
    CSet res;
    res.numbers = 0;
    res.data = new int[numbers+other.numbers];
    for (int i = 0; i < numbers; i++)
    {
        bool flag = true;
        for (int k = 0; k < other.numbers; k++)
        {
            if (data[i] == other.data[k])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            res.data[res.numbers] = data[i];
            res.numbers++;
        }
    }
    return res;
}

// CSet CSet::operator+(CSet &other)
// {
//     CSet res;
//     for (int i = 0; i < numbers; i++)
//         res.data[res.numbers++] = data[i];
//     for (int i = 0; i < other.numbers; i++)
//     {
//         bool flag = true;
//         for (int k = 0; k < res.numbers; k++)
//         {
//             if (res.data[k] == other.data[i])
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//         {
//             res.data[res.numbers++] = other.data[i];
//             cout << "added" << endl;
//         }
//     }
//     return res;
// }

CSet CSet::operator*(CSet &other)
{
    CSet res;
    res.numbers = 0;
    res.data = new int[numbers+other.numbers];
    for (int i = 0; i < numbers; i++)
    {
        bool flag = false;
        for (int k = 0; k < other.numbers; k++)
        {
            if (data[i] == other.data[k])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            res.data[res.numbers++] = data[i];
        }
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int numbers;
        cin >> numbers;
        int *data = new int[numbers];
        for (int i = 0; i < numbers; i++)
            cin >> data[i];
        CSet a(numbers, data);
        cin >> numbers;
        int* data2 = new int[numbers];
        for (int i = 0; i < numbers; i++)
            cin >> data2[i];
        CSet b(numbers, data2);
        cout << "A:";a.say();
        cout << "B:";b.say();
        cout << "A+B:";(a+b).say();
        cout << "A*B:";(a*b).say();
        CSet d = a-b;CSet e = b-a;
        cout << "(A-B)+(B-A):";(d+e).say();
        cout << '\n';
    }
}