
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

struct Matrix {
    int column, row;
    vector<vector<int> > model;

    Matrix() {}

    Matrix(int rows, int cols) {
        model.resize(cols);
        for (int i = 0; i < cols; ++i)
            model[i].resize(rows);
        column = cols;
        row = rows;
    }

    void print() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                printf("%d ", model[j][i]);
            }
            printf("\n");
        }
    }
    Matrix operator+(Matrix other) {
        if (column != other.column || row != other.row)
            return Matrix();
        Matrix result(row, column);
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < column; ++j) {
                result.set(i, j, model[i][j] + other[i][j]);
            }

            return result;
        }

        Matrix operator-(Matrix other) {
            if (column != other.column || row != other.row)
                return Matrix();
            Matrix result(row, column);
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    result.set(i, j, model[i][j] - other[i][j]);
                }
            }
            return result;
        }
        Matrix operator*(Matrix other) {
            if (column != other.row)
                return Matrix();
            Matrix result = Matrix(row, other.column);
            for (int i = 0; i < row; ++i)
                for (int j = 0; j < other.column; ++j)
                    for (int k = 0; k < column; ++k)
                        result.model[i][j] += model[i][k] * other[k][j];
                    return result;
                }
                vector<int> operator[](int index) {
                    if (model.size() > index)
                        return model[index];
                    return vector<int>();
                }
                void set(int i, int j, int value) {
                    model[i][j] = value;
                }
            };

            Matrix strassen(Matrix a, Matrix b) {
                if (a.row <= 1 || a.column <= 1 || b.row <= 1 || b.column <= 1)
                    return a * b;

                Matrix result(a.row, b.column);
                Matrix a11(a.row / 2, a.column / 2), a12(a.row / 2, a.column / 2),
                a21(a.row / 2, a.column / 2), a22(a.row / 2, a.column / 2);
                Matrix b11(b.row / 2, b.column / 2), b12(b.row / 2, b.column / 2),
                b21(b.row / 2, b.column / 2), b22(b.row / 2, b.column / 2);

                int la = a.row / 2, ca = a.column / 2;
                int lb = b.row / 2, cb = b.column / 2;
                for (int i = 0; i < la; ++i)
                    for (int j = 0; j < ca; ++j) {
                        a11.set(i, j, a[i][j]);
                        a12.set(i, j, a[i][j + ca]);
                        a21.set(i, j, a[i + la][j]);
                        a22.set(i, j, a[i + la][j + ca]);
                    }
                    for (int i = 0; i < lb; ++i)
                        for (int j = 0; j < cb; ++j) {
                            b11.set(i, j, b[i][j]);
                            b12.set(i, j, b[i][j + cb]);
                            b21.set(i, j, b[i + lb][j]);
                            b22.set(i, j, b[i + lb][j + cb]);
                        }
                        Matrix m1 = strassen(a11 + a22, b11 + b22);
                        Matrix m2 = strassen(a21 + a22, b11);
                        Matrix m3 = strassen(a11, b12 - b22);
                        Matrix m4 = strassen(a22, b21 - b11);
                        Matrix m5 = strassen(a11 + a12, b22);
                        Matrix m6 = strassen(a21 - a11, b11 + b12);
                        Matrix m7 = strassen(a12 - a22, b21 + b22);

                        Matrix c11 = m1 + m4 - m5 + m7;
                        Matrix c12 = m3 + m5;
                        Matrix c21 = m2 + m4;
                        Matrix c22 = m1 - m2 + m3 + m6;

                        for (int i = 0; i < la; ++i)
                            for (int j = 0; j < cb; ++j) {
                                result.set(i, j, c11[i][j]);
                                result.set(i + la, j, c21[i][j]);
                                result.set(i, j + cb, c12[i][j]);
                                result.set(i + la, j + cb, c22[i][j]);

                            }
                            return result;
                        }

                        Matrix exp(Matrix a, int n) {
                            if (n == 1)
                                return a;
                            Matrix r = strassen(a, a);
                            if (n == 2) return r;
                            for(int i = 1; i < n - 1;++i){
                              r = strassen(r,a);
                          }
                          return r;
                      }

                      int main(){
                        int e, n;
                        scanf("%d %d", &n, &e);
                        Matrix a(n, n);
                        for (int i = 0;i < n;++i) {
                            for(int j = 0;j < n;++j) {
                                scanf("%d", &a.model[j][i]);
                            }
                        }

                        Matrix b = exp(a, e);

                        b.print();

                        return 0;
                    }
