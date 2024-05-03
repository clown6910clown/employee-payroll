#include<stdio.h>

//initiating structure 
// defining all the details
struct employee{
	char name[30];
	int ID;
	float salary;
	char designation[50];
    char department[50];
    char bank[10];
    char location[20];
    
    
};
 
//starting a function to print all the information and calculation of allowance and deduction
void pay(struct employee emp){
    int tax;
	int HRA;
    int conveyans_A;
    int medical_A;
    int special_A;
    int pro_tax;
    int dear_allowances;
    int employees_providient_fund;
    int total=0;
    int total_deduction=0;
    int netsalary;
    
    //printing personal infomration of an employee
	printf("\t\t\tPay Slip Of An Employee\t\t\t\t\n\n\n");
	printf("Employee name : \t\t\t%s\n",emp.name);
	printf("Employee ID : \t\t\t\t%d\n",emp.ID);
	printf("Designation: \t\t\t\t%s\n", emp.designation);
    printf("Department: \t\t\t\t%s\n", emp.department);
    printf("Location: \t\t\t\t\t%s\n",emp.location);
    printf("Bank\t\t\t\t\t\t%s\n\n\n", emp.bank);
	
	
    float deductions = 0.05 * emp.salary; // 5% of basic salary as deduction
    
    //house rent allowance 
    HRA = emp.salary*0.5;
    
    //convience allowance
    conveyans_A= 2000;
    
    //medical allowance
    medical_A = 5000;
    
    //special allowance
    special_A = 25000;
    
    //dearness allowance
    dear_allowances = 0.1 * emp.salary;
    
    
    //printing all the allowances in tabular form for easy understaning of user
    printf("\t\t\tEARNING\t\t\t\n\n");
    printf("1\t\t Basic salary \t\t\t\t %.2lf\n", emp.salary);
    printf("2\t\t Dearness Allowance \t\t\t %d\n",dear_allowances);
    printf("3\t\t House Rent Allowance \t\t\t %d\n", HRA);
    printf("4\t\t Conveyance Allowance \t\t\t %d\n",conveyans_A);
    printf("5 \t\t Medical Allowance \t\t\t %d\n",medical_A);
    printf("6 \t\t Special Allownace \t\t\t %d\n\n",special_A);
    
    //adding all the allowances and printing the total
    total+= emp.salary + dear_allowances + HRA + conveyans_A + medical_A + special_A;
    printf("\t\t Toatal salary : \t\t\t%d\n", total);
    
    printf("\t\t\t\n------------------------\n");
    printf("\t\t\t\n------------------------\n\n");
    
    //checking the basic salary and then finding best category so that we can apply tax
   if(emp.salary<250000){
        printf("for salary less than 250000 TAX is 0%\n\n");
        tax = emp.salary*0;
    }
    else if((emp.salary>250000) && (emp.salary<500000)){
        printf("for salary between 250000 and 500000  TAX is 5%\n\n");
        tax = emp.salary*0.05;
    }
    else if((emp.salary>500000) && (emp.salary<750000)){
        printf("for salary between 500000 and 750000 TAX is 10%\n\n");
        tax = emp.salary*0.1;
    }
    else if((emp.salary>750000) && (emp.salary<1000000)){
        printf("for salary between 750000 and 1000000 TAX is 15%\n\n");
        tax = emp.salary*0.15;
    }
    else if((emp.salary>1000000) && (emp.salary<1250000)){
        printf("for salary between 1000000 and 1250000 TAX is 20%\n\n");
        tax = emp.salary*0.2;
    }
    else if((emp.salary>1250000) && (emp.salary<1500000)){
        printf("for salary between 1250000 and 1500000 TAX is 25%\n\n");
        tax = emp.salary*0.25;
    }
    else if(emp.salary>1500000 ){
        printf("for salary more than 1500000 TAX is 30%\n\n");
        tax = emp.salary*0.3;
    }
    
    //professional tax 
    pro_tax = 500;
    
    //providient tax
    employees_providient_fund = 4500;
    
   
    
    printf("\t\t\tDEDUCTION\t\t\t\n\n");
    printf("1 \t\t Professional Tax \t\t\t%d\n", pro_tax);
    printf("2 \t\tEmployee providient fund \t\t %d\n",employees_providient_fund);
    printf("3 \t\t TAX on salary  \t\t\t\t%d\n\n", tax);
    
    //adding all the taxes and printng them
    total_deduction += pro_tax +  employees_providient_fund + tax;
    
    printf("\t\t Toatal deduction : \t\t\t%d\n\n", total);
    
    printf("\t\t\t\n**********\n");
    printf("\t\t\t\n**********\n\n");
    
    //displaying total allowance and deduction of an employee according to their salary
    printf("\t\tTotal Earning \t\t\t%d\n", total);
    printf("\t\tTotal Deduction \t\t%d\n\n", total_deduction);
    netsalary = total-total_deduction;
    
    // displaying gross salary he/she got after all
    printf("\t\tNET SALARY of %s is: \t\t%d",emp.name,netsalary);
}

int main(){
	int n,i;
	
	// asking for how many employees to be enter
	printf("enter the number of employee\n");
	scanf("%d",&n);
	
	//define structure for that many employees 
	struct employee emp[n];
	
	//starting for loop for n number of employee 
	for(i=0;i<n;i++){
		//openning file and checking if its opened coorectly of not
		 FILE *fptr = fopen("emp_dets.txt", "a");
    	if(fptr == NULL){
        	printf("error in openning");
        	return 1;
		}
		
		//taking input from user of personal information
		printf("enter the name\n");
		scanf("%s",&emp[i].name);
	
		printf("enter the id\n");
		scanf("%d",&emp[i].ID);
		
		printf("Enter Designation:\n ");
        scanf(" %[^\n]s", emp[i].designation);
    
        printf("Enter Department:\n ");
        scanf(" %[^\n]s", emp[i].department);
	
		printf("enter the salary\n");
		scanf("%f",&emp[i].salary);
		
		printf("enter the current location\n");
		scanf("%s",&emp[i].location);
		
		printf("enter the Bank\n");
		scanf("%s",&emp[i].bank);
		
		//printing in text file that we opened earlier
		fprintf(fptr,"Name: %s, id: %d , salary: %d Designation: %s , Department: %s", emp[i].name, emp[i].ID, emp[i].salary, emp[i].department,emp[i].department);
		
		//closing the file to save our appended info
		fclose(fptr);
		
		
		printf("\n------------------------\n");
	}
	
	//openning the loop and checking that if any employee has same id 
	// because id is unique for everyone 
	for(i=0;i<n;i++){
	    if(emp[i].ID==emp[i-1].ID){
	        printf("OOPS same ID of two employee, plz input corretly");
	        break;
	    }
	    //if everyone has unique id it will print all the cacluated values 
	    //allowance deduction gross salary persoanl infomartion
	    else{
		printf("\n------------------------\n");
		pay(emp[i]);
	}
	}
}
