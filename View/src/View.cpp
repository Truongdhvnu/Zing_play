#include "View.h"
#include <iostream>

int View::displayWidth(const std::string& str) {
    // Chuyển đổi từ UTF-8 sang UTF-32 để tính toán độ dài hiển thị
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    auto utf16 = convert.from_bytes(str);
    return utf16.length();
}

std::string View::alignLeft(const std::string& str, const char& gap, int width) {
    std::locale::global(std::locale(""));
    int dataWidth = displayWidth(str);
    std::ostringstream oss;
    oss << std::left << std::setw(width + (str.length() - dataWidth)) << std::setfill(gap) << str;
    return oss.str();
}

std::string View::alignRight(const std::string& str, const char& gap, int width) {
    std::locale::global(std::locale(""));
    int dataWidth = displayWidth(str);
    std::ostringstream oss;
    oss << std::right << std::setw(width + (str.length() - dataWidth)) << std::setfill(gap) << str;
    return oss.str();
}

std::string View::alignMiddle(const std::string& str, const char& gap, int width) {
    std::locale::global(std::locale(""));
    int dataWidth = displayWidth(str);
    int leftWidth = (width - dataWidth) / 2;
    int rightWidth = width - dataWidth - leftWidth;
    std::ostringstream oss;
    oss << alignLeft("", gap, leftWidth) << "" << str << std::setw(rightWidth) << std::setfill(gap) << "";
    return oss.str();
}

void View::display_bottom() {
    string home = "-Home: [";
    home = home + HOME + "]";
    string goback = "Go back: [";
    goback = goback + GO_BACK + "]";
    string forward = "Forward: [";
    forward = forward + FORWARD + "]";
    string exit = "Exit: [";
    exit = exit + EXIT + "]";
    cout << alignLeft("",'-', WIDTH) << endl;
    cout << alignLeft(home,' ', 30)
         << alignLeft(goback,' ', 30)
         << alignLeft(forward,' ', 30)
         << alignLeft(exit,' ', 9) << "-" 
         << endl;
    cout << alignLeft("",'-', WIDTH) << endl;
}
