


#include "Lexer.h"
#include "Parser.h"
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream inputFile("D:\\МЕТОДЫ КОМПИЛЯЦИИ\\che\\example.TXT");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1;
    }
    // Создаем строковый поток
    std::stringstream buffer;
    buffer << inputFile.rdbuf(); // читаем всё из файла в поток

    // Получаем содержимое файла как строку
    std::string fileContent = buffer.str();

    inputFile.close();

    Lexer lex(fileContent);
    
    Parser parser(lex.get_tokens());

    parser.VarExpr();

    parser.OPSoutput();

    parser.OPSProcessing();

}


