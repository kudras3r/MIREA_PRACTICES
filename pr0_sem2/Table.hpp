#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>


class Table 
{
    private:
        // Data vars
        unsigned lineLenght = 81;
        std::vector<std::vector<std::string>> data;
        std::vector<std::string> contents;
        std::vector<int> colLenghts;
        std::string title;
        std::string footer;

        // Private methods
        void drawBorderLine();
        void drawTitle();
        void drawData();
        void drawFooter();
        void drawEmptyLine(const unsigned lenght);

        int userInput();

    public:
        // Constructor / Destructor
        Table();

        // Public methods
        int userChoise();
        void drawTable();
};