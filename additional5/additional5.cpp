//Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
//Удалить из последовательности числа, сумма цифр которых равна 18, 
//а среди оставшихся продублировать числа, произведение цифр которых кратно 35.
#include <iostream>
#include <fstream>
#include <sstream>
#define N 10
using namespace std;
int main()
{
    std::ifstream in("input.txt");
    int c = 0, a, save, sum = 0, pr = 1, n, number = 0;    
    std::cin >> n;
    int mas[N];
    for (int i = 0; i < n; i++)
    {
        in >> mas[i];
        cout << mas[i]<<" ";
    }
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        save =  mas[i];
        pr = 1;
        sum = 0;

        while (save > 0)
        {
            a = save % 10;
            save = save / 10;
            sum += a;//считаем сумму
            pr *= a;// считаем произведение 
        }
        if (sum == 18)// удаляем из последовательности числа сумма которых равна 18
        {
            for (int j = i; j <= n - 1; j++)
                mas[j] = mas[j + 1];
            n--;
            i--;
        }
        if (pr==35)// дублируем проивзедение которых кратно 35
        {
            n++;
            for (int j = n - 1; j >= i + 1; j--)
                mas[j] = mas[j-1];
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << " ";
    }
}