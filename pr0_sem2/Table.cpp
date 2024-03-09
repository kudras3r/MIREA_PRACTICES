#include "Table.hpp"

// Constructor / Destructor
Table::Table()
{

    this->title = "�������������� ����";
    this->footer = "���: C - CISC-���������, R - RISC-���������";

    this->contents = { "���������", "�������(Mgz)", "RAM(Mb)", "���", "���� ������ ������������" };

    this->colLenghts = { 11, 14, 9, 5, 26 };
    
    int mode = userChoise();
    if (mode == 2) {
        this->data.push_back({ "Pentium-III", "233", "16", "C", "10.10.2020" });
        this->data.push_back({ "AMD-K6", "166", "8", "C", "11.11.2011" });
        this->data.push_back({ "PowerPC-620", "2000", "16", "R", "10.10.2010" });
    }
    else
    {
        userInput();
    }
}


// Private
void Table::drawBorderLine()
{
    for (unsigned i = 0; i <= this->lineLenght; i++)
    {
        std::cout << '-';
    }
    std::cout << std::endl;
}

void Table::drawTitle()
{
    drawBorderLine();

    unsigned space;
    space = this->lineLenght - title.size() - 3;
    std::cout << "| ";
    std::cout << this->title;
    this->drawEmptyLine(space);
    std::cout << '|' << std::endl;

    drawBorderLine();
}

void Table::drawData()
{

    for (auto& content : contents)
    {
        std::cout << "| ";
        std::cout << content << "   ";
    }
    std::cout << " |" << std::endl;

    drawBorderLine();

    for (auto& row : data)
    {
        for (unsigned i=0; i < row.size(); i++)
        {
            unsigned space = this->colLenghts[i] - row[i].size();
            std::cout << "| " << row[i];
            drawEmptyLine(space);
        }
        std::cout << " |" << std::endl;
    }

    drawBorderLine();
}

void Table::drawFooter()
{
    std::cout << "| " << this->footer;
    unsigned space = this->lineLenght - 3 - this->footer.size();
    drawEmptyLine(space);
    std::cout << "|" << std::endl;
    drawBorderLine();
}

void Table::drawEmptyLine(const unsigned lenght)
{
    for (auto i=0; i <= lenght; i++)
    {
        std::cout << ' ';
    }
}

int Table::userInput()
{
    std::cout << "������� ���������� ����� ����� ������� >> ";
    int rowsCount;
    std::cin >> rowsCount;
    if (rowsCount <= 0)
    {
        std::cout << "������������ ��������!";
        exit(0);
    }

    std::cout << "������� ������, (���������, �������, RAM, ���, ���� ������ ������������)" << std::endl;
    std::cout << "���� >>" << std::endl;

    std::string input;
    for (auto row = 0; row < rowsCount; row++)
    {
        std::vector<std::string> line;
        for (auto col = 0; col < 5; col++)
        {
            std::cin >> input;
            if (input.size() > 29)
            {
                std::cout << "������� ������� ����!";
                exit(0);
            }
            line.push_back(input);
        }
        this->data.push_back(line);
    }
}


// Public
int Table::userChoise()
{
    int choise;
    std::cout << "������� ��� ����������� >>" << std::endl;
    std::cout << "������ ���� (1)" << std::endl << "����������� ������� (2)" << std::endl << ">> ";
    std::cin >> choise;
    if (choise != 1 && choise != 2)
    {
        std::cout << "������������ ����!";
        exit(0);
    }
    return choise;
}

void Table::drawTable()
{
    drawTitle();
    drawData();
    drawFooter();
}


