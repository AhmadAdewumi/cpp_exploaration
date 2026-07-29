#include <iostream>
#include <string_view>
//
// Created by ahmad on 7/29/26.
//
constexpr std::string_view getQuantityPhrase(int quantity) {
    if (quantity < 0)
        return "negative";
    if (quantity == 0)
        return "no";
    if (quantity ==  1)
        return "a single";
    if (quantity == 2)
        return "a couple of";
    if (quantity == 3)
        return "a few";
    return "many";
}

constexpr std::string_view getApplesPluralized(int quantity) {
    return (quantity == 1) ? "apple" : "apples";
}

int main() {
    constexpr int dapoApples{3};

    std::cout << "Dapo has " << getQuantityPhrase(dapoApples) << ' ' << getApplesPluralized(dapoApples) << ".\n";

    std::cout << "How many apples do you have, ehn Dapo, How many?: ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "Oshe, Oladapo Baba oni " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}