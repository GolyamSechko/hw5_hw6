#include "CustomString.h"

int main()
{
    CustomString s1 = "Hello";
    CustomString s2 = '_';
    CustomString s3 = "World!";
    CustomString s4 = "Sonet";
    CustomString s5 = "ny.";

    std::cout << "~~~ Variables ~~~" << std::endl;
    std::cout << "s1-> " << s1 << " s2-> " << s2 << " s3-> " << s3 << std::endl;
    std::cout << "s4-> " << s4 << " s5-> " << s5 << std::endl;

    std::cout << "~~~ Logical Examples ~~~" << std::endl;
    std::cout << "s1 == s3-> " << ((s1 == s3) ? "True" : "False") << std::endl;
    std::cout << "s1 != s3-> " << ((s1 != s3) ? "True" : "False") << std::endl;

    std::cout << "~~~ Operators Examples ~~~" << std::endl;
    std::cout << "s1+s2-> " << s1+s2 << std::endl;
    s1+=s2;
    std::cout << "s1+=s2. s1-> " << s1 << std::endl;

    std::cout << "~~~ Functions Examples ~~~" << std::endl;
    std::cout << "s1.append(s3)-> " << s1.append(s3) << std::endl;
    std::cout << "s1.len()-> " << s1.len() << std::endl;
    std::cout << "s1.resize(5)-> " << s1.resize(5) << std::endl;
    std::cout << "s1.len()-> " << s1.len() << std::endl;
    std::cout << "s1.clear()" << s1.clear() << std::endl;
    std::cout << "s1.len()-> " << s1.len() << std::endl;
    std::cout << "s4.insert(s5, 2)-> " << s4.insert(s5, 2) << std::endl;
    s4.swap(s5);
    std::cout << "s4.swap(s5). s4-> " << s4 << " s5-> " << s5 << std::endl;
    std::cout << "s4.compare(s5)-> " << s4.compare(s5) << std::endl;
    std::cout << "s5.compare(s4)-> " << s5.compare(s4) << std::endl;
    std::cout << "s4.compare(s4)-> " << s4.compare(s4) << std::endl;
    std::cout << "s5.substr(s4)-> " << s5.substr(s4) << std::endl;
    s4 = std::move(s5);
    std::cout << "s4 = std::move(s5). s4-> " << s4 << " s5-> " << s5 << std::endl;
    CustomString s6 = std::move(s4);   
    std::cout << "CustomString s6 = std::move(s4).  s4-> " << s4 << " s6-> " << s6 << std::endl;

    

    return 0;
}
