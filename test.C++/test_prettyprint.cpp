#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "prettyprint.hpp"

int main()
{
    {
        std::vector<int> foo;
        foo.push_back(1);
        foo.push_back(2);
        foo.push_back(3);
        std::cout << "My vector: " << foo << std::endl;
    }
  
    {
        typedef std::map<int, std::set<std::string>> map_type;

        map_type foo = { { 1, std::set<std::string>{ std::string("cat"),   std::string("dog"),   std::string("doe")    } },
                         { 3, std::set<std::string>{ std::string("goose"), std::string("moose"), std::string("ruse")   } }
                       };

        std::cout << "My map: " << foo << std::endl;
    }
  
}