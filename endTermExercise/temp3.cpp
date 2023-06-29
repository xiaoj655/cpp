#include<iostream>
#include<chrono>
#include<ctime>

int main () {
    auto now = std::chrono::system_clock::now()\
    ;
    auto timestamp= std::chrono::duration_cast<std::chrono\
                ::seconds>(now).count();

    std::time_t t = timestamp;
    std::string timestamp_str = std::ctime(&t);

    std::cout << "now timestamp is: " << timestamp_str\
                << std::endl;
    return 0;
}