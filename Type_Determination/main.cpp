#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

union U 
{
    int i;
    double d;
    std::string s;

    U() : s("") {}
    ~U() {} 
};

enum class Type 
{
    t_int,
    t_double,
    t_string
};

struct Obj
{
    U u;
    Type t;
};

Type determineType(const std::string& str) 
{
    if(str.size() == 0)
    {
        return Type::t_string;
    }
    if(str[0] != '0')
    {
        bool check = true;
        for(int i = 0 ; i < str.size() ; i++)
        {
            if(!(str[i] >= '0' && str[i] <= '9'))
            {
                check = false;
            }
        }
        if(check)
        {
            return Type::t_int;
        }
    }
    if(str[0] >= '0' && str[0] <= '9')
    {
        bool check = true;
        int cnt = 0;
        for(int i = 0 ; i < str.size() ; i++)
        {
            if(!(str[i] >= '0' && str[i] <= '9'))
            {
                if(str[i] == '.')
                {
                    cnt++;
                }
                else{
                    check = false;
                }
            }
        }
        if(cnt != 1)
        {
            check = false;
        }
        if(check)
        {
            return Type::t_double;
        }
    }
    return Type::t_string;
}

int main() 
{
    try 
    {
        std::ifstream fin("input.txt");
        if (!fin.is_open()) 
        {
            throw std::runtime_error("Error opening file");
        }
        Obj* objs = new Obj[50];
        int ind = 0;
        std::string str;
        while (fin >> str)
        {
            objs[ind].t = determineType(str);
            switch (objs[ind].t) 
            {
                case Type::t_int:
                    objs[ind].u.i = std::stoi(str);
                    std::cout << "We have an int with value " << objs[ind++].u.i << std::endl;
                    break;
                case Type::t_double:
                    objs[ind].u.d = std::stod(str);
                    std::cout << "We have a double with value " << objs[ind++].u.d << std::endl;
                    break;
                case Type::t_string:
                    objs[ind].u.s = str;
                    std::cout << "We have a string with value " << objs[ind++].u.s << std::endl;
                    break;
                default:
                    throw std::runtime_error("Unknown type");
            }
        }
        delete[] objs;
        fin.close();
    } 
    catch (const std::runtime_error& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
