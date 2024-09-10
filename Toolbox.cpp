#include "Toolbox.hpp"
#include <Windows.h>
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

void tb::place_title(unsigned x, unsigned y, std::string text, unsigned widht, char space) {
    unsigned textless_width = widht - text.size();
    unsigned left_spaces = textless_width / 2;
    unsigned right_spaces = widht - text.size() - left_spaces;
    tb::place_cursor(x, y);
    for (unsigned i = 0; i < left_spaces; ++i) std::cout << space;
    std::cout << text;
    for (unsigned i = 0; i < right_spaces; ++i) std::cout << space;
}

void tb::place_timer(unsigned x, unsigned y, unsigned delay, const char* text){
    for (unsigned s = delay; s > 0; --s) {
        std::string tmp = std::to_string(s);
        place_text(x, y, (tmp + "...").c_str());
        Sleep(1000);
    }
    tb::place_text(x, y, text);
}
