// WordBreak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

//bool WordInSet(const std::string& s, size_t& curStart, const std::unordered_set<std::string>& words)
//{
//    static size_t maxLength = 0;
//    if (maxLength == 0)
//    {
//        for (auto& w : words)
//            if (w.size() > maxLength)
//                maxLength = w.size();
//    }
//
//    auto start = curStart;
//    for (++curStart; curStart <= s.size(); ++curStart)
//    {
//        if (curStart - start > maxLength)
//            return false;
//
//        if (words.count(s.substr(start, curStart - start)))
//            return true;
//    }
//
//    return false;
//}
//
//bool WordBreak(const std::string& s, const std::vector<std::string>& w)
//{
//    std::unordered_set<std::string> words(w.cbegin(), w.cend());
//
//    size_t curStart = 0;
//    while (curStart != s.size())
//    {
//        if (!WordInSet(s, curStart, words))
//            return false;
//    }
//
//    return true;
//}

bool WordInSet(const std::string& s, size_t& i, const std::unordered_set<std::string>& words)
{
    static size_t maxLength = 0;
    if (maxLength == 0)
    {
        for (auto& w : words)
        if (w.size() > maxLength)
        {
            maxLength = w.size();
        }
    }

    for (size_t j = 1; j <= maxLength && i+j <= s.size(); ++j)
    {
        std::string sub = s.substr(i, j);
        if (words.count(sub))
        {
            i += j;
            return true;
        }
    }

    return false;
}

bool WordBreak(const std::string& s, const std::vector<std::string>& w)
{
    std::unordered_set<std::string> words(w.cbegin(), w.cend());

    for (size_t i = 0; i < s.size();)
    {
        if (!WordInSet(s, i, words))
            return false;
    }
    return true;
}

int main()
{
    while (true)
    {
        std::cout << "Enter your string (\"q\" to exit): ";
        std::string str;
        std::cin >> str;
        if (str == "q" || str == "Q")
            break;

        std::cout << "Enter number of your words: ";
        int count = 0;
        std::cin >> count;
        std::cout << "Enter your strings: ";
        std::vector<std::string> words(count);
        for (int i = 0; i < count; ++i)
            std::cin >> words[i];

        std::cout << (WordBreak(str, words) ? "True" : "False") << std::endl;
    }
    std::cout << std::endl;
}
