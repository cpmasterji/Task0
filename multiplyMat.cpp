#include<iostream>

using namespace std;

//class Mat to hold a matrix (float elements)
class Mat {
    float *mat;
    int r, c;

    public:
    void read();
    void releaseData();
    Mat();
    Mat operator *(Mat &b);
    bool checkMultiplication(Mat &b);
    friend ostream& operator<<(ostream& stream, Mat& a);
};

Mat::Mat() {
    mat = nullptr;
    r = c = 0;
}

//read a matrix
void Mat::read()
{
    cout << "\tEnter number of rows: ";
    do {
        cin >> r;
    } while (r <= 0);

    cout << "\tEnter number of columns: ";
    do {
        cin >> c;
    } while (c <= 0);

    mat = new float[r * c];

    for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    {
        cout << "\tEnter element (" << i+1 << ", " << j+1 << "): ";
        cin >> *(mat + i*c+j);
    }
    cout << endl;
}

//matrix multiplication condition
bool Mat::checkMultiplication(Mat &b) {
    return (c == b.r);
}

//overload << operator to print a matrix (Mat object)
ostream& operator<<(ostream& stream, Mat& a) {
    for (int i = 0; i < a.r; i++) {
        for (int j = 0; j < a.c; j++) {
            stream << *(a.mat+i*a.c+j);
            if (i != a.r - 1 || j != a.c - 1)
                stream << ", ";
        }
        stream << endl;
    }
    return stream;
}

//release the allocated data in the heap 
/*
    Note:   should not be called in destructor because when copying objects
            the pointer is only copied, data is the same
*/
void Mat::releaseData(){
    if (mat)
        delete mat;
    r = c = 0;
}

//implement multiplication of two matrices
Mat Mat::operator*(Mat &b){
    Mat c;
    c.mat = new float[r * b.c];
    c.r = r;
    c.c = b.c;
    for (int i = 0; i < c.r; i++)
    for (int j = 0; j < c.c; j++) 
    {
        *(c.mat + i *b.c + j) = 0;
        for (int k = 0; k < this->c; k++)
            *(c.mat + i*b.c + j) += *(mat + i*this->c + k) * *(b.mat + k*b.c + j);
    }
    return c;
}

//sample usage
int main() {
    Mat a, b;

    cout << "Matrix A:\n";
    a.read();

    cout << "Matrix B:\n";
    b.read();

    if (!a.checkMultiplication(b)) {
        cerr << "The dimensions of A and B are incompatible for multiplication!\n";
        return 1;
    }

    cout << "Multiplication results in:\n";
    
    Mat c = a*b;
    cout << c;

    a.releaseData();
    b.releaseData();
    c.releaseData();
    return 0;
}