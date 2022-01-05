#include <iostream>
#include <vector>

using namespace std;

int m_sort(int indicator_index, vector<int> &numbers)
{
    if (numbers.size() < 2)
    {
        return 0;
    }
    vector<int> numbers_ = numbers;
    vector<int> lowers(0);
    int indicator = numbers.at(indicator_index);

    for (int i = 0; i < numbers_.size(); i++)
    {
        if (numbers_.at(i) < indicator)
        {
            lowers.push_back(numbers_.at(i));
            numbers_.erase(numbers_.begin() + i--);
        }
    }
    int result = lowers.size();

    if (numbers_.size() + lowers.size() < numbers.size())
        lowers.push_back(indicator);
    for (int i : numbers_)
    {
        lowers.push_back(i);
    }
    numbers = lowers;
    return result;
}

void quick_sort(vector<int> &numbers)
{
    if (numbers.size() < 2)
    {
        return;
    }
    int indicator = m_sort(0, numbers);
    vector<int> lowers(0), highers(0);

    for (int i = 0; i < indicator; i++)
    {
        lowers.push_back(numbers.at(i));
    }
    for (int i = indicator + 1; i < numbers.size(); i++)
    {
        highers.push_back(numbers.at(i));
    }
    quick_sort(lowers);
    quick_sort(highers);
    for (int i = 0; i < indicator; i++)
    {
        numbers.at(i) = lowers.at(i);
    }
    for (int i = indicator + 1; i < numbers.size(); i++)
    {
        numbers.at(i) = highers.at(i - indicator - 1);
    }
}

int main()
{
    vector<int> numbers(0);
    int n = 0;
    cin>>n;
    while (n>0)
    {
        int t;
        cin>>t;
        numbers.push_back(t);
        n--;
    }
    
    quick_sort(numbers);
    for (int i : numbers)
    {
        cout << i << " ";
    }
    return 0;
}