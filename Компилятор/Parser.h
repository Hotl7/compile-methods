#ifndef PARSER_H
#define PARSER_H

#define	N 100
#define VAR 257
#define ARRAY 258
#define MJFALSE 260//метка перехода по "ложь" для ОПС
#define ERROR_P -1
#define MJTRUE 261 //метка безусловного перехода для ОПС
#define INDEX 262  //метка массива для ОПС для индексации


#define NONE	"-1" //другой символ

#include "utilities.h"

#include <vector>
#include <stack>

class Parser
{
public:
	Parser(std::vector<Token> input_tokens);
	~Parser();

private:
	enum OPSType
	{
		IDE,		//ПЕРЕМЕННАЯ
		MAS,		//МАССИВ
		NUMBER,		//КОНСТАНТА
		SIGN,		//ОПЕРАЦИЯ
		POINT,		//ТОЧКА ПЕРЕХОДА
		IND,		//ИНДЕКСАТОР
		JUMPFALSE,	//ОПЕРАЦИЯ ПЕРЕХОДА ПРИ УСЛОВИИ FALSE
		JUMPTRUE,	//ОПЕРАЦИЯ БЕЗУСЛОВНОГО ПЕРЕХОДА
		INP,		//ОПЕРАЦИЯ ЧТЕНИЯ
		OUTP		//ОПЕРАЦИЯ ВЫВОДА

	};

	struct OPSElem {			//элемент опс
		std::string elem;		//значение элемента ОПС?
		OPSType type;	//тип элемента ОПС

	};

	struct StackElem	///элемент стека
	{
		int* value;
		OPSType type;

	};
	
	std::map<std::string, std::vector<int>> massivint;			//таблица массивов (его имя и сам массив)
	std::map<std::string, int> variables;			//таблица переменных(имя переменной и ее значение)
	

	std::vector<Token> tokens;	//Токены от лексического анализатора, этот вектор определяется в конструкторе
	std::vector<Token>::iterator it = tokens.begin();				//Итератор для вектора

	int n;					//символьная длина элемента в ОПС
	int OPScount = 0;		/*счётчик элементов в ОПС*/
	OPSElem OPSarr[9999]; /*генерируемая ОПС*/

	void OPSGenerate(int sym, std::string tval);	//Генерация ОПС
	void NextLexem(int sym);			//Следующая лексема, проверяем соответствует ли она той что в sym

	std::string LookNext();				//смотрим значение следующей лексемы, костыль для массива

	void MulDelExpr();					//Умножение и деление 
	void MulDel();						//Сложное выражение деления и умножения
	void LocExpr();						//Выражение в скобках
	void PlusMinus();					//Плюс и минус
	void PlusMinusExpr();				//Сложное выражение плюса и минуса
	void ConditionInBrackets();			//Выражение в if и while
	void VarExpr();							//Грамматика с объявлениями 
	void QExpr();					//Грамматика Q
	void CompareExpr();						//Операторы сравнения

	void CreateArray(std::string name);
	void CreateVariable(std::string name);
	
	void OPSProcessing();					//Обработка ОПС




};




#endif // !PARSER.H


