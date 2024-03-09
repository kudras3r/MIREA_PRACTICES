#include "Table.hpp"
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Table table;

    table.drawTable();

    return 0;
}