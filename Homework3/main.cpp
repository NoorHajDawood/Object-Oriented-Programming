#include <iostream>
#include "Palindrome.h"
#define LEN 3
int main(int argc, char const *argv[])
{
    Palindrome *pali[LEN] = {nullptr};

    int op = 0, index1, index2, index3;
    char c;
    std::string str;

    while (op != 10)
    {
        std::cin >> op;
        switch (op)
        {
        case 1:
            std::cin >> index1;
            std::cin >> str;
            if (index1 < 0 || index1 >= LEN)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            if (pali[index1] != nullptr)
                continue;
            pali[index1] = new Palindrome(str);
            break;
        case 2:
            std::cin >> index1;
            std::cin >> str;
            if (index1 < 0 || index1 >= LEN || pali[index1] == nullptr)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            *pali[index1] = str;
            break;
        case 3:
            std::cin >> index1;
            std::cin >> index2;
            std::cin >> index3;
            if (index1 < 0 || index1 >= LEN || index2 < 0 || index2 >= LEN || index3 < 0 || index3 >= LEN || pali[index1] == nullptr || pali[index2] == nullptr)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            if (index1 == index3)
                *pali[index1] += *pali[index2];
            else if (pali[index3] == nullptr)
                pali[index3] = new Palindrome(*pali[index1] + *pali[index2]);
            else
                *pali[index3] = *pali[index1] + *pali[index2];
            break;
        case 4:
            std::cin >> index1;
            std::cin >> index2;
            if (index1 < 0 || index1 >= LEN || index2 < 0 || index2 >= LEN || pali[index1] == nullptr || pali[index2] == nullptr)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            *pali[index1] -= *pali[index2];
            break;
        case 5:
            std::cin >> index1;
            std::cin >> c;
            if (index1 < 0 || index1 >= LEN || pali[index1] == nullptr)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            *pali[index1] += c;
            break;
        case 6:
            std::cin >> index1;
            std::cin >> index2;
            if (index1 < 0 || index1 >= LEN || index2 < 0 || index2 >= LEN || pali[index1] == nullptr || pali[index2] == nullptr)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            if (*pali[index1] == *pali[index2])
                std::cout << "0" << std::endl;
            else if (*pali[index1] < *pali[index2])
                std::cout << "-1" << std::endl;
            else
                std::cout << "1" << std::endl;
            break;
        case 7:
            std::cin >> index1;
            if (index1 < 0 || index1 >= LEN || pali[index1] == nullptr)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            (*pali[index1])++;
            break;
        case 8:
            std::cin >> index1;
            std::cin >> index2;
            if (index1 < 0 || index1 >= LEN || pali[index1] == nullptr)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            std::cout << (*pali[index1])[index2] << std::endl;
            break;
        case 9:
            std::cin >> index1;
            if (index1 < 0 || index1 >= LEN || pali[index1] == nullptr)
            {
                std::cerr << "error" << std::endl;
                continue;
            }
            std::cout << *pali[index1] << std::endl;
            break;
        case 10:
            for (int i = 0; i < LEN; i++)
                delete pali[i];
        }
    }
    return 0;
}
