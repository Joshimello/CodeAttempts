#include "function.h"

Matrix::Matrix(int s){
  size = s;
}

Matrix::Matrix(const Matrix &a){
  for(int i = 0; i < this->size; i++)
    for(int j = 0; j < this->size; j++)
      this->matrix[i][j] = a.matrix[i][j];
}

std::ostream& operator<<(std::ostream &os, const Matrix &m){
  for(int i = 0; i < m.size; i++){
    for(int j = 0; j < m.size; j++)
      os << m.matrix[i][j] << " ";
    os << endl;
  }
  return os;
}

std::istream& operator>>(std::istream &is, Matrix &m){

  m.matrix = new int*[m.size];
  for(int i = 0; i < m.size; i++)
    m.matrix[i] = new int[m.size];

  for(int i = 0; i < m.size; i++)
    for(int j = 0; j < m.size; j++)
      is >> m.matrix[i][j];

  return is;
}

Matrix& Matrix::operator=(const Matrix &a){
  for(int i = 0; i < this->size; i++)
    for(int j = 0; j < this->size; j++)
      this->matrix[i][j] = a.matrix[i][j];
  return *this;
}