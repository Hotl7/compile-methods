#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <map>

// ���� ����������� �������
enum Type
{
    ERROR = -1,           // ������
    NAME = 1,             // ���
    INTEGER = 106,          // ����� �����
    REAL = 107,             // ������������ �����
    EQUAL = 4,           // ���� ��������� ==
    NOT_EQUALS = 5,       // ���� ��������� !=
    GREATER_OR_EQUAL = 6, // ������ ��� ����� >=
    LESS_OR_EQUAL = 7,    // ������ ��� ����� <=
    END_OF_INPUT = 8, // \0
    PLUS = '+', //43
    MINUS = '-', //45
    MULTIPLY = '*', //42
    DIVIDE = '/', //47
    LESS = '<', //60
    GREATER = '>', //62
    ASSIGN = '=', //61
    READ = 104,
    PRINT = 103,
    IF = 100,
    ELSE = 105,
    WHILE = 102,
    LPAREN = '(',      // 40
    RPAREN = ')',      // 41
    LBRACKET = '[',    // 91
    RBRACKET = ']',    // 92
    LBRACE = '{',      // {
    RBRACE = '}',      // }
    SEMICOLON = ';',
    INT = 108,

};

/*enum Type
{
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LESS,
    GREATER,
    LESS_OR_EQUAL,
    GREATER_OR_EQUAL,
    EQUAL,
    NOT_EQUALS,
    ASSIGN,
    READ,
    PRINT,
    IF,
    ELSE,
    WHILE,
    LPAREN,      // (
    RPAREN,      // )
    LBRACKET,    // [
    RBRACKET,    // ]
    LBRACE,      // {
    RBRACE,      // }
    SEMICOLON,
    COMMA,
    END_OF_FILE,

};*/

struct Token
{
    Type type;
    std::string value;
    int line;
    int column;
};

// ������� ��������� ����
const std::map<std::string, int> table_encoding = {
    {"if", 100},
    {"else", 101},
    {"while", 102},
    {"print", 103},
    {"read", 104},
    {"else", 105},
    {"int", 108},
    {"real", 109}
};

#endif // UTILITIES_H