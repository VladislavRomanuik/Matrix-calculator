//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matrix.h"
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
bool IsFail = false;
Matrix::Matrix(int m,int n,double d,...) {
	rows = m;  cols = n;
	double*s=&d;
	p=new double[rows*cols];
	if(p==NULL){
		throw CMatrixException('a');
	}
	for (int i=0;i<rows*cols;i++,++s)p[i]=*s;
}
Matrix::Matrix(int m,int n,  int d,...) {
	rows = m;  cols = n;
	int*s=&d;
	p=new double[rows*cols];
	if(p==NULL){
		throw CMatrixException('a');
	}
	for (int i=0;i<rows*cols;i++,++s)p[i]=*s;
}
Matrix::Matrix(Matrix const & a) {
	rows = a.rows;
	cols = a.cols;
	p=new double[rows*cols];
	if(p==NULL){
		throw CMatrixException('a');
	}
	for (int i=0;i<rows*cols;i++)p[i]=a.p[i];
}
Matrix::Matrix(int m, int n){
	rows = m;
	cols = n;
	p=new double[rows*cols];
	if(p==NULL){
		throw CMatrixException('a');
	}
}
Matrix::Matrix(int i){
	rows = 1;
	cols = 1;
	p=new double[1];
	if(p==NULL){
		throw CMatrixException('a');
	}
	p[0]=i;
}
Matrix::Matrix(double d){
	rows = 1;
	cols = 1;
	p=new double[1];
	if(p==NULL){
		throw CMatrixException('a');
	}
	p[0]=d;
}
Matrix const& Matrix::operator=(Matrix const & a){
	if(rows!=a.rows||cols!=a.cols){
		throw CMatrixException('=');
	}
	for (int i=0;i<rows*cols;i++)p[i]=a.p[i];
	return*this;
}
Matrix::operator double()const{
	if(rows!=1||cols!=1){
		throw CMatrixException('d');
	}
	return (*this)(0,0);
}

double operator+(double d,Matrix const&m){
	if(m.rows!=1||m.cols!=1){
		throw CMatrixException('+');
	}
	return d+m(0,0);
}
Matrix Matrix::operator+(Matrix const&a)const{
	if(rows!=a.rows||cols!=a.cols){
		ShowMessage("Матрицы разных размерностей!");
	}
	else
	{
		if(rows == a.rows)
		{
			Matrix c(*this);
			for(int i=0;i<rows*cols;i++)c.p[i]+=a.p[i];
			return c;
		}
	}
}
Matrix Matrix::operator-()const{
	Matrix a(rows,cols);
	for(int i=0;i<rows*cols;i++)a.p[i]=-p[i];
	return a;
}
double operator-(double d,Matrix const&m){
	if(m.rows!=1||m.cols!=1){
		throw CMatrixException('-');
	}
	return d-m(0,0);
}
Matrix Matrix::operator-(Matrix const&a)const{
	if(rows!=a.rows||cols!=a.cols){
		throw CMatrixException('-');
	}
	Matrix c(*this);
	for(int i=0;i<rows*cols;i++)c.p[i]-=a.p[i];
	return c;
}
Matrix Matrix::operator*(Matrix const& a)const{
	if(cols!=a.rows){
		ShowMessage("Посчитать невозможно, введите другие значения!!!");
		IsFail = true;
	}
	else
	{
		Matrix c(rows,a.cols);
		int i=0,j,k;
		for(;i<rows;++i)
		{
			for(j=0;j<a.cols;++j)
			{
				c(i,j)=0;
				for(k=0;k<cols;++k)c(i,j)+=(*this)(i,k)*a(k,j);
			}
		}
		return c;
	}
}
Matrix Matrix::operator*(double d)const{
	Matrix c(*this);
	for(int i=0;i<rows*cols;i++)c.p[i]*=d;
	return c;
}

double& Matrix::operator()(int i, int j)const{
	if(i>=rows || j>=cols || i<0 || j<0){
		throw CMatrixException('i');
	}
	return p[i*cols+j];
}

Matrix Matrix::T(Matrix const&a)const{
	if(a.rows!=a.cols){
		throw CMatrixException('T');
	}
	Matrix c(*this);
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++) c(i,j)=a(j,i);

	return c;
}

int Proverka(double *a, int n)
{
  double e1, d, *b, *c, y, w, p;
  int i, j, k, *z;

  e1=1.e-6;
  d=1;
  z= new int[n];
  c= new double[n];
  b= new double[n];


  for(i=0; i<n; i++)
	 *(z+i)=i;

  for(i=0; i<n; i++)
   {
	k=i;
	y=*(a+i*n+i);
	if(i+1 <= n )
	  for(j=1+i; j<n; j++)
	   {
		w=*(a+n*i+j);
		if(fabs(w)>fabs(y))
		 {
		   k=j;
		   y=w;
		 }
	   }
	d=d*y;
//проверка на близость к вырождению матрицы
   if(fabs(y)<e1)
   {
		ShowMessage("Введіть другі числа");
		return 2;
   }
   return 0;
	}
}

int matr_inv_gause(double *a, int n)
{
  double e1, d, *b, *c, y, w, p;
  int i, j, k, *z;

  e1=1.e-6;
  d=1;

  z= new int[n];
  c= new double[n];
  b= new double[n];


  for(i=0; i<n; i++)
	 *(z+i)=i;

  for(i=0; i<n; i++)
   {
	k=i;
	y=*(a+i*n+i);
	if(i+1 <= n )
	  for(j=1+i; j<n; j++)
	   {
		w=*(a+n*i+j);
		if(fabs(w)>fabs(y))
		 {
		   k=j;
		   y=w;
		 }
	   }
	d=d*y;
//проверка на близость к вырождению матрицы
   if(fabs(y)<e1)
   {
		ShowMessage("Введіть другі числа");
		return 2;
   }
   y=1./y;
   for(j=0; j<n; j++)
	{
	  *(c+j)=*(a+n*j+k);
	  *(a+n*j+k)=*(a+n*j+i);
      *(a+j*n+i)=-(*(c+j))*y;
      *(b+j)=*(a+i*n+j)*y;
      *(a+i*n+j)=*(b+j);
    }
   j=*(z+i);
   *(z+i)=*(z+k);
   *(z+k)=j;
   *(a+i*n+i)=y;

   for(k=0; k<n; k++)
    if(k != i)
      for(j=0; j<n; j++)
        if(j != i)
         *(a+k*n+j)=*(a+k*n+j)-(*(b+j))*(*(c+k));
   }
  for(i=0; i<n; i++)
    while(1)
    {
      k=*(z+i);
      if(k == i) break;
       for(j=0; j<n; j++)
        {
         w=*(a+i*n+j);
         *(a+i*n+j)=*(a+k*n+j);
         *(a+k*n+j)=w;
        }
      p=*(z+i);
      *(z+i)=*(z+k);
      *(z+k)=(int)p;
      d=-d;
    }

 delete[] z;
 delete[] b;

 delete[] c;

 return 0;
}

Matrix Matrix::Inv(Matrix const&a)const{
	if(a.rows!=a.cols)
	{
		throw CMatrixException('I');
	}
	if(Proverka(a.p,rows)!=0)
	{
		ShowMessage("Детерминант матрицы = 0, заполните матрицу другими числами!");
		for (int i = 0; i < a.rows*a.cols; i++)
		{
			a.p[i] = 0;
		}
	}
	if (Proverka (a.p, rows)==0)
	{
		matr_inv_gause(a.p,rows);
	}
	return a;
}

void Matrix::Print(TStringGrid &s)const
{
	s.RowCount = rows;
	s.ColCount = cols;
	s.Height =  rows*s.DefaultRowHeight + rows*4;
	s.Width =  cols*s.DefaultColWidth + cols*4;

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			s.Cells[j][i] = (*this)(i,j);
		}
	}
}

void Matrix::Print2 (TStringGrid &s) const
{
	s.RowCount = rows;
	s.ColCount = 2;
	s.Height = rows* (s.DefaultRowHeight + 4);

	for (int i = 0; i < rows; i++)
	{
		s.Cells[0][i] = "X" + IntToStr(i+1);
		s.Cells[1][i] = (*this)(i,0);
	}
}
