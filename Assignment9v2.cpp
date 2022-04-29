#include<iostream>
#include <ios>
#include<vector>
using namespace std;




class Student{

    public:
        float gpa;
        string name;
        int orderId, totalApp, credits;

        vector<float> gpaV;
        vector<string> nameV;
        vector<int> creditsV;
        vector<int> orderIdV;


        void input(){

            cout<<"Press Ctrl^c when completed entering inputs\n";

            cout<<"\nEnter student OrderID:";
            while(cin>>orderId){

                orderIdV.push_back(orderId);

                cout<<"\nEnter student name:";
                cin>>name;
                nameV.push_back(name);


                cout<<"\nEnter student gpa:";
                cin>>gpa;
                gpaV.push_back(gpa);

                cout<<"\nEnter student credits:";
                cin>>credits;
                creditsV.push_back(credits);

                cout<<"\nEnter student OrderID:";
            }


        }

        void display(){

            totalApp=gpaV.size();
            cout<<"\nTotal Applications: "<<totalApp<<endl;

            for (int i=0;i<gpaV.size();i++){

                cout <<"\nOrderID:" <<orderIdV[i];
                cout <<"\nName:" <<nameV[i];
                cout <<"\nGPA:" <<gpaV[i];
                cout <<"\nCredits:" <<creditsV[i];
                cout<<"\n---";
            }

        }

        void sortApp(){

            for(int i=0;i<gpaV.size();i++){

                    for(int j=i+1;j<gpaV.size();j++){

                        if(gpaV[i]<gpaV[j]){

                            swap(orderIdV[i],orderIdV[j]);
                            swap(nameV[i],nameV[j]);
                            swap(gpaV[i],gpaV[j]);
                            swap(creditsV[i],creditsV[j]);
                    }
                        else if(gpaV[i]==gpaV[j]){

                                if(creditsV[i]<creditsV[j]){

                                        cout<<"\nSorting by credits";

                                        swap(orderIdV[i],orderIdV[j]);
                                        swap(nameV[i],nameV[j]);
                                        swap(gpaV[i],gpaV[j]);
                                        swap(creditsV[i],creditsV[j]);

                                }
                                else if(creditsV[i]==creditsV[j]){

                                        if(orderIdV[i]>orderIdV[j]){

                                            swap(orderIdV[i],orderIdV[j]);
                                            swap(nameV[i],nameV[j]);
                                            swap(gpaV[i],gpaV[j]);
                                            swap(creditsV[i],creditsV[j]);

                                        }
                                        else{continue;}

                                }
                        }
                        else{continue;}
                    }


            }


        }



};

int main(){

    Student s;
    s.input();
    s.display();
    s.sortApp();
    cout<<"\n\nSorting Applications\n";
    s.display();


    return 0;
}
