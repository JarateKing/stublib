#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <sstream>

#define STUB(...) _stubhandler::_stub(__COUNTER__, __PRETTY_FUNCTION__, _stubhandler::getargs(#__VA_ARGS__, __VA_ARGS__))
namespace _stubhandler {
    struct retval {
        std::string val;
        retval() : val("") {}
        retval(std::string val) : val(val) {}
        
        operator std::string() { return val; }
        operator bool() { return !(val.size() == 0 || val == "0" || val == "f" || val == "false" || val == "False" || val == "FALSE"); }
        operator char() { return (val.size() > 0) ? val[0] : '\0'; }
        operator int() { return std::stoi(val); }
        operator long() { return std::stol(val); }
        operator long long() { return std::stoll(val); }
        operator unsigned int() { return std::stoul(val); }
        operator unsigned long() { return std::stoul(val); }
        operator unsigned long long() { return std::stoull(val); }
        operator float() { return std::stof(val); }
        operator double() { return std::stod(val); }
        operator long double() { return std::stold(val); }
    };
    std::map<int, std::map<std::string, retval>> cached;
    retval _stub(int id, std::string func, std::string args) {
        if (cached[id].count(args)) return cached[id][args];
        
        std::cout << "\nSTUB " << func << "[" << args << "]: ";
        std::string val;
        std::cin >> val;
        retval ans(val);
        cached[id][args] = ans;
        return ans;
    }
    std::string surrounded(std::string arg) {
        return "\"" + arg + "\"";
    }
    std::string surrounded(char arg) {
        return "'" + std::string(1, arg) + "'";
    }
    std::string surrounded(bool arg) {
        return (arg) ? "true" : "false";
    }
    template <typename T>
    T surrounded(T arg) {
        return arg;
    }
    std::string getargs(const char* name) {
        return "";
    }
    template <typename T>
    std::string getargs(const char* name, T&& arg)
    {
        std::stringstream ans;
        ans << name << '=' << surrounded(arg);
        return ans.str();
    }
    template <typename T, typename... T2>
    std::string getargs(const char* names, T&& arg1, T2&&... args)
    {
        std::stringstream ans;
        const char* next = strchr(names + 1, ',');
        ans.write(names, next - names) << '=' << surrounded(arg1);
        return ans.str() + getargs(next, args...);
    }
}