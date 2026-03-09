//  ============================================================================
//  Determinant Project
//
//  Author: Heng Dararithy
//  Date:   March 2026
//  Course: CSCI 221 - Computer Science II
//
//  Description:
//      Calculates the determinant of an NxN square matrix using recursive
//      cofactor (Laplace) expansion along row 0. Supports both long and double
//      data types via C++ templates. Uses a class hierarchy:
//          matrix<T>   - base class for general matrices
//          sqMatrix<T> - derived class for square matrices
//          det<T>      - determinant calculator with verbose output support
//
//  Verify determinants: https://Matrix.reshish.com/determinant/
//  ============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <new>
#include <type_traits>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ostream;
using std::ofstream;
using std::is_same;
using std::nothrow;
using std::ios;

const int MAX_MATRIX_ROWCOL_SIZE = 12;
const int MAX_NUM_SIZE = 99;
const int MAX_PRECISION = 7;

int SET_WIDTH;
bool NEGATIVE = true;


// =============================================================================
//  MatrixDetSkylar Namespace
//  Contains: matrix<T>   - base matrix class
//            sqMatrix<T>  - derived square matrix class
//            det<T>       - determinant calculator class
// =============================================================================
namespace MatrixDetSkylar
{
    template <class> class det;  // Forward declare det so it can be a friend of sqMatrix


    // =========================================================================
    //  BASE MATRIX CLASS
    //
    //  Template base class representing a general row x col matrix.
    //  Data is stored in a protected struct containing a 1D dynamically
    //  allocated array in row-major order, along with row/col dimensions.
    //
    //  Template parameter T: numeric type (long or double)
    // =========================================================================
    template <class T>
    class matrix
    {
    protected:
        // Protected struct holding the matrix data
        struct Matrix {
            T* arr;         // 1D array storing matrix elements (row-major order)
            size_t row;     // Number of rows
            size_t col;     // Number of columns
        };

        // ----- print2dAs1DArr -----
        // Pre-condition:  m points to a valid Matrix struct with allocated arr
        // Post-condition: prints the 1D array in 2D format using setw for alignment
        void print2dAs1DArr(const Matrix* m, ostream& os = cout) const
        {
            for (size_t i = 0; i < m->row; ++i)
            {
                for (size_t j = 0; j < m->col; ++j)
                    os << setw(SET_WIDTH) << m->arr[i * m->col + j];
                os << endl;
            }
            os << endl;
        }

    public:
        // ----- Constructor -----
        // Pre-condition:  arr points to a valid array of r*c elements
        //                 r >= 1 and r <= MAX_MATRIX_ROWCOL_SIZE
        //                 c >= 1 and c <= MAX_MATRIX_ROWCOL_SIZE
        //                 T is either long or double
        // Post-condition: if all validations pass, object is created (base only)
        //                 otherwise prints error and calls exit(-1)
        matrix(T* arr, size_t r, size_t c)
        {
            // Type constraint: T must be long or double
            if (!is_same<T, long>::value && !is_same<T, double>::value)
            {
                cout << "Error: Matrix data type must be either Long or Double." << endl;
                exit(-1);
            }
            // Validate row and col
            if (r < 1 || r > MAX_MATRIX_ROWCOL_SIZE ||
                c < 1 || c > MAX_MATRIX_ROWCOL_SIZE)
            {
                cout << "Error: Matrix dimensions must be between 1 and "
                     << MAX_MATRIX_ROWCOL_SIZE << "." << endl;
                exit(-1);
            }
        }

        // Virtual destructor for proper cleanup in derived classes
        virtual ~matrix() {}

        // ----- print -----
        // Pure interface - derived classes implement their own print
        virtual void print(ostream& os = cout) const = 0;

        // ----- operator<< -----
        // Overloaded insertion operator - calls print
        friend ostream& operator<<(ostream& os, const matrix<T>& m)
        {
            m.print(os);
            return os;
        }
    };


    // =========================================================================
    //  SQUARE MATRIX CLASS (inherits from matrix<T>)
    //
    //  Derived class representing an NxN square matrix. Contains a private
    //  Matrix* member that holds the data. Supports deep copy, formatted
    //  output, and declares det<T> as a friend class.
    //
    //  Template parameter T: numeric type (long or double)
    // =========================================================================
    template <class T>
    class sqMatrix : public matrix<T>
    {
        friend class det<T>;

    private:
        typename matrix<T>::Matrix* sqMat;  // Pointer to Matrix struct

    public:
        // ----- Parameterized Constructor -----
        // Pre-condition:  arr points to a valid array of s*s elements
        //                 s >= 2 and s <= MAX_MATRIX_ROWCOL_SIZE
        // Post-condition: sqMat is allocated and filled with a deep copy of arr
        //                 on failure, prints error and calls exit(-1)
        sqMatrix(T* arr, int s) : matrix<T>(arr, s, s)
        {
            // Validate square matrix size >= 2
            if (s < 2 || s > MAX_MATRIX_ROWCOL_SIZE)
            {
                cout << "Error: Square matrix size must be between 2 and "
                     << MAX_MATRIX_ROWCOL_SIZE << "." << endl;
                exit(-1);
            }

            // Allocate the Matrix struct
            sqMat = new(nothrow) typename matrix<T>::Matrix;
            if (!sqMat)
            {
                cout << "Error: Memory allocation failed for Matrix struct." << endl;
                exit(-1);
            }

            sqMat->row = s;
            sqMat->col = s;
            int len = s * s;

            // Allocate the array inside the struct
            sqMat->arr = new(nothrow) T[len];
            if (!sqMat->arr)
            {
                cout << "Error: Memory allocation failed for matrix array." << endl;
                delete sqMat;
                exit(-1);
            }

            // Deep copy
            for (int i = 0; i < len; ++i)
                sqMat->arr[i] = arr[i];
        }

        // ----- Copy Constructor -----
        sqMatrix(const sqMatrix& other) : matrix<T>(other.sqMat->arr, other.sqMat->row, other.sqMat->col)
        {
            int s = other.sqMat->row;
            sqMat = new(nothrow) typename matrix<T>::Matrix;
            if (!sqMat)
            {
                cout << "Error: Memory allocation failed (copy)." << endl;
                exit(-1);
            }
            sqMat->row = s;
            sqMat->col = s;
            int len = s * s;
            sqMat->arr = new(nothrow) T[len];
            if (!sqMat->arr)
            {
                cout << "Error: Memory allocation failed (copy array)." << endl;
                delete sqMat;
                exit(-1);
            }
            for (int i = 0; i < len; ++i)
                sqMat->arr[i] = other.sqMat->arr[i];
        }

        // ----- Assignment Operator -----
        sqMatrix& operator=(const sqMatrix& other)
        {
            if (this != &other)
            {
                // Free old memory
                delete[] sqMat->arr;
                delete sqMat;

                int s = other.sqMat->row;
                sqMat = new(nothrow) typename matrix<T>::Matrix;
                if (!sqMat)
                {
                    cout << "Error: Memory allocation failed (assign)." << endl;
                    exit(-1);
                }
                sqMat->row = s;
                sqMat->col = s;
                int len = s * s;
                sqMat->arr = new(nothrow) T[len];
                if (!sqMat->arr)
                {
                    cout << "Error: Memory allocation failed (assign array)." << endl;
                    delete sqMat;
                    exit(-1);
                }
                for (int i = 0; i < len; ++i)
                    sqMat->arr[i] = other.sqMat->arr[i];
            }
            return *this;
        }

        // ----- Destructor -----
        // Deallocates array inside struct first, then the struct itself
        ~sqMatrix()
        {
            if (sqMat)
            {
                delete[] sqMat->arr;
                delete sqMat;
            }
        }

        // ----- Accessors -----
        int getSize() const { return static_cast<int>(sqMat->row); }

        T getElement(int row, int col) const
        {
            return sqMat->arr[row * sqMat->col + col];
        }

        // ----- print -----
        // Calls base class print2dAs1DArr to display matrix
        void print(ostream& os = cout) const override
        {
            this->print2dAs1DArr(sqMat, os);
        }
    };


    // =========================================================================
    //  DETERMINANT CLASS
    //
    //  Calculates the determinant of a sqMatrix<T> using recursive cofactor
    //  (Laplace) expansion along row 0.
    //
    //  Algorithm: For an NxN matrix A, expand along row 0:
    //      det(A) = sum_{j=0}^{N-1} (-1)^j * A[0][j] * det(Minor(0,j))
    //
    //  Base case: 2x2 matrix: det = ad - bc
    //
    //  Supports verbose mode showing each expansion step, and can output
    //  to both console and file via an ostream pointer.
    //
    //  Template parameter T: numeric type (long or double)
    // =========================================================================
    template <class T>
    class det
    {
    private:
        T result;           // Stores the computed determinant value
        bool computed;      // Flag: has the determinant been calculated?
        int precision;      // Precision for double output
        bool showProcess;   // Flag: show verbose recursive expansion?
        ostream* out;       // Pointer to output stream (cout or file)

        // ----- setCalculationPrecision -----
        // Pre-condition:  p >= 0
        // Post-condition: sets precision for double output, clamped to [0, MAX_PRECISION]
        //                 applies to both console and file output
        void setCalculationPrecision(int p)
        {
            precision = (p < 0 || p > MAX_PRECISION) ? 2 : p;
            if (is_same<T, double>::value)
            {
                out->setf(ios::fixed);
                out->setf(ios::showpoint);
                out->precision(precision);
                cout.setf(ios::fixed);
                cout.setf(ios::showpoint);
                cout.precision(precision);
            }
        }

        // ----- showDetProcess -----
        // Pre-condition:  size is the dimension of the matrix
        // Post-condition: if size >= 5, warns user about number of operations
        //                 and asks for Y/N confirmation. Sets showProcess flag.
        void showDetProcess(int size, bool wantVerbose)
        {
            if (!wantVerbose)
            {
                showProcess = false;
                return;
            }

            if (size >= 5)
            {
                cout << "Please note that there are " << size << "!/2 operations." << endl
                     << "Are you sure you wish to show the determinant's working out process? (Y/N) ";
                char choice;
                cin >> choice;
                showProcess = (choice == 'Y' || choice == 'y');
            }
            else
            {
                showProcess = true;
            }
        }

        // ----- print2dAs1DArr -----
        // Prints a matrix in determinant format using '|' symbols on both sides
        // Pre-condition:  arr is a valid 1D array of size rows x cols elements
        // Post-condition: matrix is printed with | delimiters and proper alignment
        void print2dAs1DArr(T* arr, int rows, int cols, ostream& os) const
        {
            for (int i = 0; i < rows; ++i)
            {
                os << "| ";
                for (int j = 0; j < cols; ++j)
                    os << setw(SET_WIDTH) << arr[i * cols + j];
                os << " |" << endl;
            }
        }

        // ----- retArr -----
        // Pre-condition:  arr is a valid 1D array of size*size elements
        //                 0 <= excludeCol < size, size >= 3
        // Post-condition: returns a newly allocated 1D array representing the
        //                 minor matrix (row 0 and column excludeCol removed)
        //                 caller is responsible for deallocation
        T* retArr(T* arr, int size, int excludeCol) const
        {
            int newSize = size - 1;
            T* minor = new(nothrow) T[newSize * newSize];
            if (!minor)
            {
                cout << "Error: Memory allocation failed in retArr." << endl;
                exit(-1);
            }

            int idx = 0;
            for (int i = 1; i < size; ++i)         // skip row 0
            {
                for (int j = 0; j < size; ++j)
                {
                    if (j == excludeCol) continue;  // skip excluded column
                    minor[idx++] = arr[i * size + j];
                }
            }
            return minor;
        }

        // ----- determinantP -----
        // Private recursive method - the heart of the determinant algorithm
        // Pre-condition:  arr is a valid 1D array of size*size elements, size >= 2
        // Post-condition: returns the determinant of the matrix
        //                 if showProcess is true, logs each expansion step
        T determinantP(T* arr, int size, ostream& os)
        {
            // Base case: 2x2 matrix (ad - bc)
            if (size == 2)
            {
                T val = arr[0] * arr[3] - arr[1] * arr[2];

                if (showProcess)
                {
                    print2dAs1DArr(arr, 2, 2, os);
                    os << "= (" << arr[0] << " * " << arr[3]
                       << ") - (" << arr[1] << " * " << arr[2]
                       << ") = " << val << endl << endl;
                }
                return val;
            }

            // Recursive case: cofactor expansion along row 0
            T determinant = 0;

            for (int j = 0; j < size; ++j)
            {
                // Get the minor matrix (row 0, column j removed)
                T* minor = retArr(arr, size, j);
                int newSize = size - 1;

                // Show the expansion step: element * minor matrix
                if (showProcess)
                {
                    T element = arr[j];
                    T signedElement = (j % 2 == 0) ? element : -element;
                    os << signedElement << " *" << endl;
                    print2dAs1DArr(minor, newSize, newSize, os);
                    os << endl;
                }

                // Recurse on the minor
                T subDet = determinantP(minor, newSize, os);
                T sign = (j % 2 == 0) ? 1 : -1;
                determinant += sign * arr[j] * subDet;

                // Free the minor array
                delete[] minor;
            }

            return determinant;
        }

    public:
        // ----- Default Constructor -----
        det() : result(0), computed(false), precision(2), showProcess(false), out(&cout) {}

        // ----- determinant -----
        // Main public method to calculate the determinant
        // Pre-condition:  mat is a valid sqMatrix of size >= 2
        //                 precise >= 0 (used for double formatting)
        //                 verbose = whether to show the recursive process
        //                 outStream = output stream (cout or file)
        // Post-condition: prints the original matrix, calculates determinant,
        //                 shows process if requested, prints "Determinant is [value]"
        //                 result is cached
        T determinant(sqMatrix<T>& mat, int precise, bool verbose, ostream& outStream)
        {
            out = &outStream;
            setCalculationPrecision(precise);

            int size = mat.getSize();

            // Ask user confirmation if verbose and size >= 5
            showDetProcess(size, verbose);

            // Print the original matrix
            *out << endl;
            print2dAs1DArr(mat.sqMat->arr, size, size, *out);
            *out << endl;

            // Calculate the determinant recursively
            result = determinantP(mat.sqMat->arr, size, *out);
            computed = true;

            // Print the result
            *out << "Determinant is " << result << endl;

            return result;
        }

        // ----- printDeterminant -----
        // Pre-condition:  mat is a valid sqMatrix
        // Post-condition: prints "Determinant is [value]"
        //                 if not yet computed, calculates first with defaults
        T printDeterminant(sqMatrix<T>& mat)
        {
            if (!computed)
            {
                out = &cout;
                setCalculationPrecision(2);
                showProcess = false;
                int size = mat.getSize();
                print2dAs1DArr(mat.sqMat->arr, size, size, *out);
                result = determinantP(mat.sqMat->arr, size, *out);
                computed = true;
            }
            cout << "Determinant is " << result << endl;
            return result;
        }
    };

} // end namespace MatrixDetSkylar


// =============================================================================
//  randomSquareMatrix (free function template)
//
//  Pre-condition:
//      arr        = one-dimensional representation of a two-dimensional array
//      arrayLen   = length of array (must be a perfect square, minimum 4)
//      maxNumSize = largest number for random generation (range: 2 to MAX_NUM_SIZE)
//                   Since we use modulus, the largest number seen is maxNumSize - 1.
//                   If out of range, maxNumSize defaults to 2 (creates 0/1 matrix)
//      negNum     = default true; if true, negative numbers are allowed
//      precise    = default 0; if T is double, sets decimal precision (1 to 7)
//                   If out of range, precision defaults to 2
//
//  Post-condition:
//      arr is filled with random numbers of type T
//      Global SET_WIDTH and NEGATIVE are updated for output formatting
//
//  Returns: none
// =============================================================================
template<class T>
void randomSquareMatrix(T* arr, const size_t arrayLen, int maxNumSize, bool negNum = true, int precise = 0)
{
    if (!is_same<T, long>::value && !is_same<T, double>::value)
    {
        cout << "Square Matrix data type must be either Long or Double." << endl;
        return;
    }
    if (arrayLen < 4)
    {
        cout << "Square Matrix is too small - minimum size is 4 - 2 rows x 2 cols." << endl;
        return;
    }

    double tmp = static_cast<double>(arrayLen);
    int size = static_cast<int>(sqrt(tmp));

    if (sqrt(tmp) != size)
    {
        cout << "Array is not a square matrix." << endl;
        return;
    }

    // Ternary operator ensures maxNumSize and precision are in valid range
    maxNumSize = (maxNumSize < 2 || maxNumSize > MAX_NUM_SIZE) ? 2 : maxNumSize;
    int precision = (precise < 1 || precise > MAX_PRECISION) ? 2 : precise;

    NEGATIVE = negNum;
    SET_WIDTH = static_cast<int>(ceil(log10(maxNumSize - 1))) + (negNum ? 1 : 0) + 1;

    if (is_same<T, double>::value)
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(precision);
        SET_WIDTH += precision + 1;     // for precision digits and the decimal point
    }

    long long diviser = pow(10, precision);
    maxNumSize *= diviser;

    srand(static_cast<int>(time(NULL)));

    for (size_t i = 0; i < arrayLen; ++i)
        arr[i] = ((rand() % maxNumSize) * ((rand() % 2) ? 1 : (negNum ? -1 : 1))) / static_cast<T>(diviser);
}


// =============================================================================
//  MAIN
// =============================================================================
int main()
{
    //  ----------------------------------------------------------------
    //  Testing arrays (uncomment any one to test with a known matrix)
    //  ----------------------------------------------------------------

//    double arr[4] = {89.234, 100.2,
//                    -55.221, 74.2}; //det = 12,154.307

//    long arr[9] = {1,2,3,
//                   2,3,1,
//                   3,2,1}; //det = -12

//    long arr[9] = {5,2,-1,
//                   3,0,1,
//                   1,4,-2}; //det = -18

//    double arr[9] = {0,0,0,
//                     0,0,0,
//                     0,0,0}; //det = 0

//    long arr[16] = {1,2,-3,-4,
//                    2,-1,0,3,
//                    6,1,1,-2,
//                    0,2,4,3}; //det = -285

//    long arr[16] = {1,0,0,0,
//                    0,1,0,0,
//                    0,0,1,0,
//                    0,0,0,1}; //det = 1

//    long arr[25] = {2, -11, 34, 0, 1,
//                    22, -111, 20, 5, -6,
//                    3, -1, 7, 99, 25,
//                   -47, -50, 26, 33, 0,
//                    9, -7, 88, 21, 32}; //det = 442,908,157

//    long arr[36] = {3, -9, 6, 0, 6, 13,
//                    -3, -8, 6, -11, -12, -4,
//                    -6, -8, -12, -4, 0, -14,
//                    -7, 2, -6, -2, -13, 9,
//                     7, -10, 13, -2, 9, -7,
//                     0, 8, 5, 2, -12, -5}; //det = -245,330

//    double arr[36] = {14.6, -3.2, 2.3, -4.6, 9.4, 1.4,
//                     -6.4, 4.3, -1.1, -9, -14.2, -1.7,
//                     -3.6, 1.4, 7.6, 11.8, 3.9, -12.8,
//                     -12.9, 6, -14.9, 3, 12.6, -8.4,
//                      6.6, 7.8, 7.9, -10.4, 12.2, 0.2,
//                     -4.7, 3.9, 2.3, -7, 14.7, -12.6}; // det = -8,927,545.668610

//    long arr[100] = {0, 0, 1, -1, 0, -2, 0, -1, 0, -2,
//                     0, 2, -2, -2, 1, 0, -2, 0, 1, -1,
//                     0, 2, 1, 2, 1, -1, -1, -2, 2, 0,
//                    -1, 0, 1, -1, 2, 0, 1, -2, 0, -1,
//                     1, 0, -1, -1, 1, -2, -1, 2, -1, 0,
//                     0, 0, -1, 2, -2, 1, 2, 0, 1, 0,
//                     2, 0, 0, -1, 2, 0, 0, 0, 0, -1,
//                    -1, -2, -2, 0, 0, -1, 0, 2, 0, -2,
//                     1, 2, 1, 1, 0, 2, -1, 0, 0, -1,
//                    -2, 2, 0, 1, 2, 0, 2, -1, 2, 0}; //det = -28,048

// ** Note: depending on the speed of your computer, the following determinant will take several
// seconds to compute. If you decide to store the calculation results in a file, it will take a
// while to write, and the file will be very large! 239,500,800 calculations stored!!
//
//    long arr[144] = {-2, -2, -2, 1, 1, -2, -1, -1, 1, 0, 2, 2,
//                    -1, 2, 0, 2, 0, -1, 1, -2, 0, 2, 2, 1,
//                    0, 0, 0, -1, -1, -1, 0, 2, 0, -1, -2, 0,
//                    2, 1, 0, 0, -1, 0, -2, -2, -2, 0, 2, -2,
//                    2, 0, -1, -1, -2, 0, 0, 0, 1, 1, 0, 0,
//                    2, 0, 0, -1, -1, 1, 0, 0, 0, 2, 0, 0,
//                    0, -2, 1, -1, 1, -2, 2, 2, -1, 0, 2, 2,
//                    2, -2, 1, -1, 0, -2, 0, 2, -2, -1, 1, -1,
//                    -1, 2, 0, -2, 2, 0, -1, 1, 2, 0, 2, 2,
//                    1, 2, 2, 1, 1, 1, 0, 1, 2, 0, -1, 0,
//                    2, -2, 1, 1, 0, -2, 1, 2, 0, -1, -1, 0,
//                    2, -2, 1, 0, -1, -1, -2, 2, -1, 0, 0, 0}; // det = 15,320

    using MatrixDetSkylar::sqMatrix;
    using MatrixDetSkylar::det;

    //  ----------------------------------------------------------------
    //  Testing both long and double data types
    //  ----------------------------------------------------------------

// Testing both long and double data types

//    long arr[16] = {1,2,-3,-4,
//                    2,-1,0,3,
//                    6,1,1,-2,
//                    0,2,4,3}; //det = -285
//    SET_WIDTH = 5;
//    long result;
//    det<long> determ;
//    sqMatrix<long> mat(arr, 4);

    double arr[16];
    randomSquareMatrix<double>(arr, 16, 15, true, 3); //arr of len 16, largest num = 15, negative true, precision 3

    double result;
    det<double> determ;
    sqMatrix<double> mat(arr, 4);   //sqMatrix of 4 rows and 4 cols.

    // --- Console output ---
    result = determ.determinant(mat, 2, true, cout); //precision 2

    cout << mat;  //extraction operator overload - same as mat.print()
    //mat.print();

    //cout << endl << determ.printDeterminant(mat); //if determinant not yet called, call determinant

    // --- File output example (3x3 or 4x4 determinant written to file) ---
    ofstream fout;
    fout.open("determinant_output.txt");
    if (fout.is_open())
    {
        det<double> fileDeterm;
        fileDeterm.determinant(mat, 3, false, fout);
        fout.close();
        cout << "\nResults also written to determinant_output.txt" << endl;
    }

    return EXIT_SUCCESS;
}
