#include<iostream>
#include<vector>
#include <chrono>
#include <unistd.h>
using namespace std;

class DyArr{

    private:
        long rows,cols;
        long *arr=nullptr;


    public:

        //basic constructor
        DyArr(long rows1, long cols1){

            cout<<"Executing basic constructor"<<endl;
            rows=rows1;
            cols=cols1;
            arr=new long [rows*cols]{};
            cout<<"Executed basic constructor"<<endl;

        }

        //copy constructor
        DyArr(const DyArr &Da1){
            cout<<"Executing copy constructor"<<endl;
            arr=Da1.arr;
            cout<<"Executed copy constructor"<<endl;
        }

        //move constructor
        DyArr(DyArr &&Da1){
            cout<<"Executing move constructor"<<endl;
            rows = Da1.rows;
            cols = Da1.cols;
            arr=Da1.arr;
            Da1.arr=nullptr;
            Da1.rows=0;
            Da1.cols=0;
            cout<<"Executed move constructor"<<endl;
        }

        //destructor
       /* ~DyArr(){
            delete[] arr;
        }*/

        // copy assignment operator
       DyArr &operator=(const DyArr &rhs) {
            cout<<"Executing copy assignment operator"<<endl;
            rows=rhs.rows;
            cols=rhs.cols;
            arr=rhs.arr;
            cout<<"Executed copy assignment operator"<<endl;
            return *this;

        }

        // move assignment operator
        DyArr &operator=(DyArr &&other) {
            cout<<"Executing move assignment operator"<<endl;
            if (this != &other){
                    rows=other.rows;
                    cols=other.cols;
                    arr=other.arr;
            }
            other.arr=nullptr;
            other.rows=0;
            other.cols=0;
            cout<<"Executed move assignment operator"<<endl;
            //DyArr temp(std::move(rhs)); // moves the array
            //temp.swap(*this);
            delete[] other.arr;
            return *this;
        }

};

int main(){

    auto start22 = chrono::steady_clock::now();
        DyArr Da1(10000,10000); //calling basic constructor
    auto end22 = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end22 - start22).count()
        << " ms" << endl;

    auto start1 = chrono::steady_clock::now();
        DyArr Da2=Da1; // calling copy constructor
    auto end1 = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end1 - start1).count()
        << " ms" << endl;

    auto start2 = chrono::steady_clock::now();
        Da1 = std::move(Da2); //calling move constructor
    auto end2 = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count()
        << " ms" << endl;

    DyArr Da3(10000,10000),Da4(10000,10000);

    auto start3 = chrono::steady_clock::now();
        Da3=Da4; //calling copy assignment operator
    auto end3 = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end3 - start3).count()
        << " ms" << endl;

    auto start4 = chrono::steady_clock::now();
        Da1 = std::move(DyArr(1,2));//calling move assignment operator
    auto end4 = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end4 - start4).count()
        << " ms" << endl;

}
