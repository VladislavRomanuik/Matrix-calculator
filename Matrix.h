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
//����� ���������� ���������
//#define debug
class CMatrixException{
	char ne;// ne='a' �� �������� �������� ������.
			// ne='+' �������� �� ��������
			// ne='-' ��������� �� ��������
			// ne='*' �������� �� ��������
			// ne='/' Division isn't possble
			// ne='d' ����������� � ��� double �� ��������
			// ne='=' ���������� ���������� �������
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
	//�����������
	Matrix(int, int);
	Matrix(int, int,double,...);
	Matrix(int, int,   int,...);
	Matrix(double);
			// ������� ������� ������� �������� 1 � 1, m(0,0)=i
	Matrix(int);
			// ������� ������� ������� �������� 1 � 1, m(0,0)=i
	Matrix(Matrix const &);
	//����������
	~Matrix(){if(p!=NULL) delete []p;}
	Matrix const& operator=(Matrix const&);
	//����������� � ��� double
	operator double()const;
	//�������� ��������
	friend double operator+(double,Matrix const&);
	double operator+(double d){return d+*this;}
	double operator+(   int i){return double(i)+*this;}
	friend double operator+( int i,Matrix const&m){return double(i)+m;}
	Matrix const& operator+()const{return*this;}//unary +
	Matrix  operator+(Matrix const&)const;//binary +
	Matrix& operator+=(Matrix const&a){*this=*this+a;return*this;}

	//�������� ���������
	friend double operator-(double,Matrix const&);
	double operator-(double d)const{return -(d-*this);}
	double operator-(   int i)const{return *this-double(i);}
	friend double operator-(int i,Matrix const&m){return -(m-i);}
	Matrix  operator-(Matrix const&)const;//binary -
	Matrix& operator-=(Matrix const&a){*this=*this-a;return*this;}
	Matrix  operator-()const;//unary -
	//�������� ���������
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
	//������ � ��������� �������
	double& Matrix::operator()(int i, int j)const;
	//���������������� �������
	Matrix T(Matrix const&a)const;
	//��������� �������
	Matrix Inv(Matrix const&a)const;
	//����� ������� �� �����
	void Print(TStringGrid& s)const;
	void Print2(TStringGrid& s)const;
	//������� ���-�� �������� � ����� �������
	int GetRows()const{return rows;}
	int GetCols()const{return cols;}
};
#endif
