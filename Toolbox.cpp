#include "Toolbox.hpp"
#include <Windows.h>
#include <iostream>
#include <string>
#include<random>

unsigned tb::rand(unsigned end){

    return tb::rand(0,end);
}

unsigned tb::rand(unsigned begin, unsigned end){
     std::random_device rd;
     std::mt19937 generator(rd());
     std::uniform_int_distribution<> dist(begin, end - 1);
    return dist(generator);
}

bool tb::chance(unsigned percent){
    return tb::rand(101) <= percent;

}

void tb::place_cursor(unsigned x, unsigned y){
   static HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord{ x, y };
    SetConsoleCursorPosition(handler, coord);
}

void tb::place_text(unsigned x, unsigned y, const char* text){
    tb::place_cursor(x, y);
    std::cout << text;
}

void tb::place_timer(unsigned x, unsigned y, unsigned delay, const char* text){
    for (unsigned s = delay; s > 0; --s) {
        std::string tmp = std::to_string(s);
        place_text(x, y, (tmp + "...").c_str());
        Sleep(1000);
    }
    tb::place_text(x, y, text);
}
