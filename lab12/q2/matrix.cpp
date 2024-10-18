/* DO NOT MODIFY THIS FILE*/

#include <iostream>
using namespace std;

class Matrix {
    bool **mat;
    int n;

public:
    Matrix(int n)
    {
        this->n = n;
        mat = new bool *[n];
        for (int i = 0; i < n; i++)
            mat[i] = new bool[n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = false;
        
    }
    Matrix Multiply(Matrix &m2, Matrix &m3)
    {
        int n = m2.getN();
        Matrix m4(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m4.mat[i][j]=0;
                for(int k=0;k<n;k++){
                    m4.mat[i][j]=m4.mat[i][j]||(mat[i][k]&&m2.mat[k][j]);
                }
            }
        }
        return m4;
    }

    int getN()
    {
        return n;
    }
   
    void set(int i, int j, bool val)
    {
        mat[i][j] = val;
    }

    void set_false()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = false;
    }

    bool get_value(int i,int j)
    {
        return mat[i][j];
    }
};