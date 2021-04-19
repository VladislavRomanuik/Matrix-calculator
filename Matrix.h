//---------------------------------------------------------------------------

#ifndef MatrixH
#define MatrixH
//---------------------------------------------------------------------------
#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Dialogs.hpp>
//Вывод отладочных сообщений
//#define debug
class CMatrixException{
	char ne;// ne='a' Не возможно выделить память.
			// ne='+' Сложение не возможно
			// ne='-' Вычитание не возможно
			// ne='*' Уможение не возможно
			// ne='/' Division isn't possble
			// ne='d' Конвертация в тип double не возможна
			// ne='=' Невозможно прировнять матрицу
			// ne='0' Zero division matrix/double
			// ne='i' Index out of range
public:
	CMatrixException(char c){ne=c;}
	void PrintMessage(){
		switch(ne){
		case 'a':ShowMessage("Can't allocate memory");break;
		case '+':ShowMessage("Addition isn't possible");break;
		case '-':ShowMessage("Substruction isn't possible");break;
		case '*':ShowMessage("Multiplication isn't possible");break;
		case '/':ShowMessage("Division isn't possble");break;
		case 'd':ShowMessage("Conversion to double isn't possible");break;
		case '=':ShowMessage("Can't give to matrix");break;
		case '0':ShowMessage("Zero division matrix/double");break;
		case 'i':ShowMessage("Index out of range");break;
		case 'T':ShowMessage("Transporent isn't possible");break;
		case 'I':ShowMessage("Invertation isn't possible");break;
		default	:ShowMessage("Unknown error");
		}
	}
};
class Matrix {
	int rows, cols;

public:
	double* p;
	//Конструктор
	Matrix(int, int);
	Matrix(int, int,double,...);
	Matrix(int, int,   int,...);
	Matrix(double);
			// Функция создает матрицу размеров 1 Х 1, m(0,0)=i
	Matrix(int);
			// Функция создает матрицу размеров 1 Х 1, m(0,0)=i
	Matrix(Matrix const &);
	//Деструктор
	~Matrix(){if(p!=NULL) delete []p;}
	Matrix const& operator=(Matrix const&);
	//Конвертация в тип double
	operator double()const;
	//Опирация сложения
	friend double operator+(double,Matrix const&);
	double operator+(double d){return d+*this;}
	double operator+(   int i){return double(i)+*this;}
	friend double operator+( int i,Matrix const&m){return double(i)+m;}
	Matrix const& operator+()const{return*this;}//unary +
	Matrix  operator+(Matrix const&)const;//binary +
	Matrix& operator+=(Matrix const&a){*this=*this+a;return*this;}

	//Опирация вычитания
	friend double operator-(double,Matrix const&);
	double operator-(double d)const{return -(d-*this);}
	double operator-(   int i)const{return *this-double(i);}
	friend double operator-(int i,Matrix const&m){return -(m-i);}
	Matrix  operator-(Matrix const&)const;//binary -
	Matrix& operator-=(Matrix const&a){*this=*this-a;return*this;}
	Matrix  operator-()const;//unary -
	//Опирация умножения
	Matrix& operator*=(Matrix const&a){*this=(*this)*a;return*this;}
	Matrix  operator*(double)const;
	friend Matrix operator*(double d,Matrix const&a){return a*d;}
	Matrix& operator*=(double d){*this=*this*d;return*this;}
	Matrix operator*(Matrix const&)const;
	//Division operators
	Matrix  operator/(double d)const{
		if(d==0)throw CMatrixException('d');
		return (1./d)*(*this);
	}
	Matrix& operator/=(double d){*this=*this/d;return*this;}
	//Transposition operator
	Matrix  operator*()const;
//	friend Matrix T(Matrix const&a){return *a;}
	//Доступ к элементам матрицы
	double& Matrix::operator()(int i, int j)const;
	//Транспонирование матрицы
	Matrix T(Matrix const&a)const;
	//Обращение матрицы
	Matrix Inv(Matrix const&a)const;
	//Вывод матрицы на экран
	void Print(TStringGrid& s)const;
	void Print2(TStringGrid& s)const;
	//Возврат кол-ва столбцов и строк матрицы
	int GetRows()const{return rows;}
	int GetCols()const{return cols;}
};
#endif
