
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
double addition (int checkin)

 {
	string cancel,pay;
	double haircuts,dye;


	cout<<"\nNo. of extra haircuts(1 haircut = Ksh50/haircut): ";
	cin>>haircuts;
	cout<<endl;
	cout<<"No. of dye packs for haircut(Ksh15/dye): ";
	cin>>dye;
	cout<<endl;
	cout<<"Do you want free cancellation policy? (Ksh50) (yes/no): " ;
	cin>>cancel;
	cout<<endl;
	cout<<"Do you want to pay now or anytime between the current date and 3 days before the haircut? "<<endl;
	cout<<"If you pay 3 days before the haircut, you will be charged a total of Ksh30 (yes/no)"<<endl;
	cin>>pay;
	double total=0;
	haircuts=haircuts*50*checkin;
	dye=dye*15*checkin;
	if(cancel=="yes")
    {total+=50;}
    else if ( cancel=="no")
    {total+=0;}

    if (pay == "yes")
    {total+=0;}
    else if (pay == "no")
    {total+=30;}

	total=total+haircuts+dye;
	return total;
}


void payment(double sum,double addf,string name,string address,string hpnum,int haircut,int people,int day1,int month1,int year1,int day2,int month2,int year2,int days)
{

  double tax = 0;
  double total = 0;
  tax=(sum+addf)*0.1;
  total=tax+sum+addf;

  string haircut_type;
  if (haircut==1)
  {
      haircut_type="Standard";
  }
  else if (haircut==2)
  {
      haircut_type="Deluxe";
  }

   cout <<"\t\t\t\t*************************\n"<<endl;
   cout <<"\t\t\t\t   Barber Shop Booking"<<endl;
   cout <<"\n\t\t\t\t*************************"<<endl<<endl;
   cout << "Name :"<<name<<endl;
   cout << "Address :"<<address<<endl;
   cout << "Handphone Number :"<<hpnum<<endl<<endl;
   cout << "Haircut \t\t\t: "<<haircut_type<<endl;
   cout << "Clients \t\t: "<<people<<" people"<<endl;
   cout << "Booked on \t\t: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
   cout << "Day of haircut \t\t: "<<day2<<"/"<<month2<<"/"<<year2<<endl;
   cout << "Length between days \t: "<<days<<endl<<endl;
   cout << "Haircut Price\t\t: Ksh"<<sum<<endl;
   cout << "Additional fees \t: Ksh"<<addf<<endl;
   cout << "Service tax (10%)\t: Ksh"<<tax<<endl;
   cout << "Final Total \t\t: Ksh"<<total<<endl<<endl;
   cout << "Thank you for booking with us! Hope you had a good haircut!"<<endl;
   cout << "For more information, contact us at 07-6557889 or visit our instagram @barbershop"<<endl;

  fstream myfile;
   myfile.open ("receipt.txt");
   myfile <<"\t\t\t\t*************************\n"<<endl;
   myfile <<"\t\t\t\t   Barber Shop Booking"<<endl;
   myfile<<"\n\t\t\t\t*************************"<<endl<<endl;
   myfile << "Name :"<<name<<endl;
   myfile << "Address :"<<address<<endl;
   myfile << "Handphone Number :"<<hpnum<<endl<<endl;
   myfile << "Haircut \t\t\t: "<<haircut_type<<endl;
   myfile << "Clients \t\t: "<<people<<" people"<<endl;
   myfile << "Booked on \t\t: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
   myfile << "Day of haircut \t\t: "<<day2<<"/"<<month2<<"/"<<year2<<endl;
   myfile << "Length between days \t: "<<days<<endl<<endl;
   myfile << "Haircut Price\t\t: Ksh"<<sum<<endl;
   myfile << "Additional fees \t: Ksh"<<addf<<endl;
   myfile << "Service tax (10%)\t: Ksh"<<tax<<endl;
   myfile << "Final Total \t\t: Ksh"<<total<<endl<<endl;
   myfile << "Thank you for booking with us! Hope you had a good haircut!"<<endl;
   myfile << "For more information, contact us at 07-6557889 or visit our instagram @barbershop"<<endl;

  myfile.close();

}


double date (int day1,int month1, int year, int day2, int month2, int year4,int haircut )
{   int i;
    double difference;
    month1-=1;
    month2-=1;
    struct tm a = {0,0,0,day1,month1,year};
    struct tm b = {0,0,0,day2,month2,year4}; //104 = 2004
    time_t x = mktime(&a);
    time_t y = mktime(&b);
    double days;
    if ( x != (std::time_t)(-1) && y != (time_t)(-1) )
    {
        double difference = difftime(y, x) / (60 * 60 * 24);
        cout << ctime(&x);
        cout << ctime(&y);
        cout << "difference = " << difference << " days" << endl;
        days=difference;
    }

    cout<<days<<endl;
    return days;

}
int main()
{

    string name;
    string address;
    string hpnum;
    string add;
    int haircut;
    int people;
    int day1,month1,year1;
    int day2,month2,year2;
    int i,year,year4;
    start:
    cout<<"\n\t\t\t\t*************************";
    cout<<"\n\t\t\t\t BARBER BOOKING SERVICE ";
    cout<<"\n\t\t\t\t      * MAIN MENU *";
    cout<<"\n\t\t\t\t*************************";

    cout<<"\n\nEnter day of booking:(Enter Day then click enter, Then Month, Then Year)\n\n"<<endl;;
    cin>>day1>>month1>>year1;
    year=year1-1900;
    system("cls");

    cout<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<"Enter your name"<<endl;
    cin>>name;
    cout<<"Enter your address"<<endl;
    cin>>address;
    cout<<"Enter your Handphone Number"<<endl;
    cin>>hpnum;
    cout<<"Enter the number of clients getting haircuts"<<endl;
    cin>>people;
    cout<<"Choose your preferred haircut"<<endl;
    cout<<"Press '1' for standard haircut"<<endl;
    cout<<"Press '2' for deluxe haircut"<<endl;
    cin>>haircut;
    cout<<"Enter your haircut date(Enter Day then click enter, Then Month, Then Year)"<<endl;
    cin>>day2>>month2>>year2;
    year4=year2-1900;
    double days = date (day1,month1, year, day2, month2, year4,haircut);
    double sum=0;
    double addf=0;

    if (people<=2&&people>0)
    {
        if (haircut==1)
        {
            sum+=100;
            for(i=2;i<=days;i++)
            {
                sum+=70;
            }
        }

        else if (haircut==2)
        {
             sum+=200;
            for(i=2;i<=days;i++)
            {
                sum+=150;
            }
        }

    }
    else if (people<=4&&people>2)
    {
        if (haircut==1)
        {
            sum+=150;
            for(i=2;i<=days;i++)
            {
                sum+=120;
            }
        }

        else if (haircut==2)
        {
             sum+=300;
            for(i=2;i<=days;i++)
            {
                sum+=200;
            }
        }

    }
    else if (people<=6&&people>4)
    {
        if (haircut==1)
        {
            sum+=250;
            for(i=2;i<=days;i++)
            {
                sum+=150;
            }
        }

        else if (haircut==2)
        {
             sum+=400;
            for(i=2;i<=days;i++)
            {
                sum+=250;
            }
        }

    }
    cout<<sum<<endl;
    system("cls");
    cout<<"Do you want an addition of extra haircut or any other services ? Type yes or no"<<endl;
    cin>>add;
   if (add=="yes")
    {
     addf=addition (days);
    }
    cout<<addf<<endl;
    system("cls");
    payment(sum,addf,name,address,hpnum,haircut,people,day1,month1,year1,day2,month2,year2,days);
    string choice;
    cout<<"Do you want to book another haircut.. (yes/no)?"<<endl;
    cin>> choice;
    if (choice=="yes")
    {
        goto start;
    }
    else if (choice=="no")
    {
        return 0;
    }


}
