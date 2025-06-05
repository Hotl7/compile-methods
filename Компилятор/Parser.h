#ifndef PARSER_H
#define PARSER_H

#define	N 100
#define VAR 257
#define ARRAY 258
#define MJFALSE 260//����� �������� �� "����" ��� ���
#define ERROR_P -1
#define MJTRUE 261 //����� ������������ �������� ��� ���
#define INDEX 262  //����� ������� ��� ��� ��� ����������


#define NONE	"-1" //������ ������

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
		IDE,		//����������
		MAS,		//������
		NUMBER,		//���������
		SIGN,		//��������
		POINT,		//����� ��������
		IND,		//����������
		JUMPFALSE,	//�������� �������� ��� ������� FALSE
		JUMPTRUE,	//�������� ������������ ��������
		INP,		//�������� ������
		OUTP		//�������� ������

	};

	struct OPSElem {
		std::string elem;		//�������� �������� ���?
		OPSType type;	//��� �������� ���

	};
	//������ � ������� ����������
	struct LexEntry
	{
		char* lexptr;
		int token;
	}; // �������� �����

	/*������ � ������� ��������*/
	struct ArrEntry
	{
		char* masptr;
		int* mas;
	};

	// ��� �������, �������� ��������� �������
	struct ElMas
	{
		int mas;
		int elem;
	};

	struct StackElem 
	{
		int* value;
		OPSType type;

	};


	//LexEntry symtable[N];	//������� ��������?
	//LexEntry number[N];		//������� ���������� � �� ��������?
	//ArrEntry massiv[N];		//������� ��������� � �� ��������?
	std::map<std::string, std::vector<int>> massivint;			//������� �������� (��� ��� � ��� ������)
	std::map<std::string, int> variables;			//������� ����������(��� ���������� � �� ��������)
	

	std::vector<Token> tokens;	//������ �� ������������ �����������, ���� ������ ������������ � ������������
	std::vector<Token>::iterator it = tokens.begin();				//�������� ��� �������

	//int lextype;			//��� �������
	//int tokenval;			//�������� ������� , ��� ��� ���������� ������ ���� � ������, ����� ��� ��� ����������
	int n;					//���������� ����� �������� � ���
	int OPScount = 0;		/*������� ��������� � ���*/
	OPSElem OPSarr[9999]; /*������������ ���*/

	void OPSGenerate(int sym, std::string tval);	//��������� ���
	void NextLexem(int sym);			//��������� �������, ��������� ������������� �� ��� ��� ��� � sym
	std::string LookNext();				//������� �������� ��������� �������, ������� ��� �������

	void MulDelExpr();					//��������� � ������� 
	void MulDel();						//������� ��������� ������� � ���������
	void LocExpr();						//��������� � �������
	void PlusMinus();					//���� � �����
	void PlusMinusExpr();				//������� ��������� ����� � ������
	void ConditionInBrackets();			//��������� � if � while
	void VarExpr();							//���������� � ������������ 
	void QExpr();					//���������� Q

	void CompareExpr();						//��������� ���������?

	void CreateArray(std::string name);
	void CreateVariable(std::string name);
	
	void OPSProcessing();					//��������� ���




};




#endif // !PARSER.H


