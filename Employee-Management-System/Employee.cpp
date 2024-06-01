#include<iostream>
#include<string>
using namespace std;
//abstract Class
class Employee{
	protected:
		int empId;
		string name;
	public:
		//concrete method
		void InputBasicInfo(){
			cout<<"Enter Employee ID :";
			cin>>empId;
			cout<<"Enter Employee Name :";
			cin.ignore();
			getline(cin,name);
		}
		void DisplayBasicInfo()const{
			cout<<"---------- Basic Information -------------"<<endl;
			cout<<"Employee ID :"<<empId<<endl;
			cout<<"Employee Name :"<<name<<endl;
		}
		//Pure Virtual Function
		virtual void inputInfo() = 0;
		virtual void calculateSalary() const= 0;
};
//dirived Class Visiting Employee 
class visitingEmp : public Employee{
	private:
		int numberOfDays;
		float dailyWages;
	public:
		//@Override
		void inputInfo(){
			cout<<"Enter Daily Wages :";
			cin>>dailyWages;
			cout<<"Enter Number of Days :";
			cin>>numberOfDays;
		}
		//@Override
		void calculateSalary() const{
			float salary = dailyWages*numberOfDays;
			cout<<"Salary :"<<salary<<endl;
		}
};
//darived Class Parmanet Employee 
class ParmanentEmp : public Employee{
	private:
		int monthlySalary;
	public:
		void inputInfo(){
			cout<<"Enter Monthly Salary :";
			cin>>monthlySalary;
			}
		void calculateSalary() const{
			cout<<"Salary :"<<monthlySalary<<" Per Month"<<endl;
		}
		
};
main(){
	Employee *Emp;
	int choice;
	do{
		cout<<"-------- Main Menu ----------\n";
		cout<<"1. Create Visiting Employee \n";
		cout<<"2. Create Parmanent Employee \n";
		cout<<"0. Exit \n";
		cout<<"Enter Your Choice :";
		cin>>choice;
		switch(choice){
			case 1:
				Emp = new visitingEmp();
				break;
			case 2:
				Emp = new ParmanentEmp();
				break;
			case 0:
				cout<<"Exiting The Program \n";
				break;
			default:
				cout<<"Invalid Number : Plz Enter Valid Number \n";
				continue;				
		}
		if(choice != 0){
			Emp->InputBasicInfo();
			Emp->inputInfo();
			cout<<"\nEmployee Information\n";
			Emp->DisplayBasicInfo();
			Emp->calculateSalary();
			
			delete Emp;
		}
	}while(choice!=0);	
	
}
