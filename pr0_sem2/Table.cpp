#include "Table.hpp"

// Constructor / Destructor
Table::Table()
{

    this->title = "Характеристики ПЭВМ";
    this->footer = "Тип: C - CISC-процессор, R - RISC-процессор";

    this->contents = { "Процессор", "Частота(Mgz)", "RAM(Mb)", "Тип", "Дата начала производства" };

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
    std::cout << "Введите количество строк вашей таблицы >> ";
    int rowsCount;
    std::cin >> rowsCount;
    if (rowsCount <= 0)
    {
        std::cout << "Неправильное значение!";
        exit(0);
    }

    std::cout << "Вводите данные, (Процессор, Частота, RAM, Тип, Дата начала производства)" << std::endl;
    std::cout << "Ввод >>" << std::endl;

    std::string input;
    for (auto row = 0; row < rowsCount; row++)
    {
        std::vector<std::string> line;
        for (auto col = 0; col < 5; col++)
        {
            std::cin >> input;
            if (input.size() > 29)
            {
                std::cout << "Слишком длинное поле!";
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
    std::cout << "Введите тип отображения >>" << std::endl;
    std::cout << "Ручной ввод (1)" << std::endl << "Стандартная таблица (2)" << std::endl << ">> ";
    std::cin >> choise;
    if (choise != 1 && choise != 2)
    {
        std::cout << "Некорректный ввод!";
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


