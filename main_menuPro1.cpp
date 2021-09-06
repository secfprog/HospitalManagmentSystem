#include<iostream>
#include <string.h>
using namespace std;
const int Max_working_set = 3;

//structure for any phone number related issues
struct phone
{
  int area_code,exchange_number, u_number;
};

//structure for the address that are needed in the patients, doctors or any related informations
struct address
{
  int house_number;
  char country[20],region[20],town[20],city[20],sub_city[20],kebele[20];
};

// date related issues like birthday, arrival date and others
struct date
{
  int day,month,year;
};

//patient's relative information
struct relative
{
    char relative_fname[50],relative_lname[50], relative_address[50];
    string relation;
    int relative_contact;
};

//inpatient registration date and time
struct reg_date_time
{
    int dd1, mm1, yy1, hr, Min;
};

//information provided by hospital representative about patients
struct hospital_treatment
{
    string reasonofvisit;
    string treatment_condition;
    string treatment_outcome;
    int dateofattendance, dateofservice;
    int checkintime, checkouttime;
    string primary_diagnosis, secondary_diagnosis;
    int outdate;
};

//structure for hospital information
struct hospital
{
    char hospital_name[20];
    int hospital_id;
    char hospital_address;
    char specialization[20];
    char standard;
    char patient_code;
};

// structure used for accessing any patient related informations
struct patient
{
  char patient_fname[25], patient_lname[25];
  int patient_age,patient_id;
  char patient_email[100];
  char patient_sex;
  address patient_address;
  float patient_weight,patient_hegiht;
  date patient_birthday;
  reg_date_time date_time;
  phone patient_phone_number;
  char patient_history[100000];
  string martial_status;
  relative r_info;
  hospital detail;
  hospital_treatment t_info;
};

// structure for hospital rooms information
struct hospital_model
{
    string name;
    int rooms[50];
    char room_type[10];
    char free_room; // if a room is available, 0 else if not available, -1
};

//structure for doctors information
struct Doctor_model
{
    char doctor_name[20];
    int doctor_id;
    int doctor_age;
    char doctor_qualification;
    char doctor_speciality;
    date doctor_graduation;
    phone doctor_phone_number;
    address doctor_address;
    int Work_hours[Max_working_set][2]; // multiple Work hours which begin and end time(expressed in int) for this every doctor has 3 work set morning afternoon and evening and each have time start and end
    int Max_patients;
    string Working_days[7];
};

//structure for resolving financial cases
struct finance
{
    float card_cost,room_cost,xray_cost,mri_cost;
};

float bmindex(float w,float h);//function to calculate bmi
float range(char x,float bmi);//function to determine bmi range
void read();//function to accept patient information and display their bmi
void inpatient_reg();   //inpatient registration form filled by patient
void hospital_info();   //hospital information filled by hospital representative during inpatient registration
void outpatient_reg();   //out patient registration form filled by the patient
void treatment_authen(); // out patient treatment authentication to be filled by hospital representative
void treatment_nature(); //treatment information of out patient filled by specialist/ consultant at the health facility
bool is_working_at_hours(Doctor_model *Doctor, int hour);
bool is_working_at_day(Doctor_model *Doctor, string day);
bool is_room_available(hospital_model *hospital, int room_number);
bool is_doctor_at_max_capacity(Doctor_model *Doctor, int Current_patient);
hospital_model init_hospital();
Doctor_model init_Doctor();
void disease_severity();
void cases();
void cost(float x,float y,float z,float w);
struct MenuInterface
{
    void mainMenu()
    {
        int input;

        cout<<"\n\n\t\tWELCOME TO HOSPITAL MANAGENT SYSTEM\n\n\n";
        cout<<"\t\tPress\n\n";
        cout<<"\t\t1. Login\n";
        cout<<"\t\t2. Sign Up\n";
        cout<<"\t\t3. Quit\n";

        cout<<"\n\t\tInput: ";
        cin>>input;

        if(input==1)
        {
            loginMenu();
        }
        else if(input==2)
        {
            signUpMenu();
        }
    }

    void loginMenu()
    {
        int input;

        cout<<"\n\n\t\t-----------Login AS-----------\n\n";

        cout<<"\t\t1. Service Administrator\n";
        cout<<"\t\t2. Doctor\n";
        cout<<"\t\t3. Press 0 to Return\n";
        cout<<"\t\tAny other key to exit\n";

        cout<<"\t\tInput: ";
        cin>>input;

        if(input==1)
        {
            SA_Login();
            SA_subMenu();
        }
        else if(input==2)
        {
            LoginDetails("Doctor's");
        }
	    else if(input==0)
        {
            mainMenu();
        }
	else 
	{
	    terminate();
	}
        
    }

    void signUpMenu()
    {
        int input;

        cout<<"\t\t-----------Sign Up AS-----------\n";

        cout<<"\t\t1. Patient\n";
        cout<<"\t\tTo Return Press 0\n";

        cout<<"\n\n\t\tInput: ";
        cin>>input;

        if(input==1)
        {
            signUpDetails();
        }
    }

    void LoginDetails(string role)
    {
         string hospitalID;
        char password[50];
        char default_password[50]="doctor1234";
        int input,choice,option;

        cout<<"\t\t-----------"<<role<<" Login Page-----------\n";

        line_d:cout<<"\n\t\t Hospital ID: ";
        cin>>hospitalID;

        cout<<"\n\t\t Password: ";
        cin>>password;
       if((strcmp(password,default_password)==0))
        {
            cout<<"!!!!!!!!!!!!!!!!!! Login Successfully !!!!!!!!!!!!!!!!!!! "<<endl;
            cout<<"*********** What do you want to do next ***************** "<<endl;
            cout<<"press\n 1. To check on disease severity\n 2. For treatment authentication\n 3. For treatment nature\n 4. To check on cases\n 5. To calculate and read patient's BMI\n 6. exit: "<<endl;
            cin>>choice;
            switch(choice)
            {
               case 1: disease_severity();
                        cout<<"If you want to go to treatment authentication press 1: "<<endl;
                        cout<<"If you want to go to treatment nature press 2: "<<endl;
                        cout<<"If you want to go to cases press 3: "<<endl;
                        cout<<"If you want to calculate and read BMI press 4: "<<endl;
                        cout<<"Press any other key to exit: "<<endl;
                        cin>>option;
                        switch(option)
                        {
                            case 1: treatment_authen();
                                    break;
                            case 2: treatment_nature();
                                    break;
                            case 3: cases();
                                    break;
                            case 4: read();
                                    break;
                            default: break;
                        }
                        break;
                case 2: treatment_authen();
                        cout<<"If you want to go to disease severity press 1: "<<endl;
                        cout<<"If you want to go to treatment nature press 2: "<<endl;
                        cout<<"If you want to go to cases press 3: "<<endl;
                        cout<<"If you want to calculate and read BMI press 4: "<<endl;
                        cout<<"Press any other key to exit: "<<endl;
                        cin>>option;
                         switch(option)
                        {
                            case 1: disease_severity();
                                    break;
                            case 2: treatment_nature();
                                    break;
                            case 3: cases();
                                    break;
                            case 4: read();
                                    break;
                            default: break;
                        }
                        break;
               case 3: treatment_nature();
                        cout<<"If you want to go to disease severity press 1: "<<endl;
                        cout<<"If you want to go to treatment authentication press 2: "<<endl;
                        cout<<"If you want to go to cases press 3: "<<endl;
                        cout<<"If you want to calculate and read BMI press 4: "<<endl;
                        cout<<"Press any other key to exit: "<<endl;
                        cin>>option;
                         switch(option)
                        {
                            case 1: disease_severity();
                                    break;
                            case 2: treatment_authen;
                                    break;
                            case 3: cases();
                                    break;
                            case 4: read();
                                    break;
                            default: break;
                        }
                        break;
                case 4: cases();
                        cout<<"If you want to go to disease severity press 1: "<<endl;
                        cout<<"If you want to go to treatment authentication press 2: "<<endl;
                        cout<<"If you want to go to treatment nature press 3: "<<endl;
                        cout<<"If you want to calculate and read BMI press 4: "<<endl;
                        cout<<"Press any other key to exit: "<<endl;
                        cin>>option;
                         switch(option)
                        {
                            case 1: disease_severity();
                                    break;
                            case 2: treatment_authen();
                                    break;
                            case 3: treatment_nature;
                                    break;
                            case 4: read();
                                    break;
                            default: break;
                        }
                        break;
                case 5: read();
                        cout<<"If you want to go to disease severity press 1: "<<endl;
                        cout<<"If you want to go to treatment authentication press 2: "<<endl;
                        cout<<"If you want to go to treatment nature press 3: "<<endl;
                        cout<<"If you want to see cases press 4: "<<endl;
                        cout<<"Press any other key to exit: "<<endl;
                        cin>>option;
                         switch(option)
                        {
                            case 1: disease_severity();
                                    break;
                            case 2: treatment_authen();
                                    break;
                            case 3: treatment_nature;
                                    break;
                            case 4: cases();
                                    break;
                            default: break;
                        }
                        break;

                default: break; 
            }




        }
        else
        {
            cout<<"!!!!!!!!!!!!!!!!!  Please try again  !!!!!!!!!!!!!!!!!!!!! "<<endl;
            goto line_d;
        }
    }

    void signUpDetails()
    {

        cout<<"\n\n\t\t-----------Patient Sign Up Page-----------\n";
        inpatient_reg();

    }

    void SA_Login()
    {
        string userName;
        char password[50];
        char default_password[50]="systemadministrator1234";

       line202: cout<<"\n\t\tEnter UserName: ";
        cin>>userName;

        cout<<"\n\t\tEnter Password: ";
        cin>>password;
       if((strcmp(password,default_password)==0))
        {
            cout<<"!!!!!!!!!!!!!!!!!!! Login Successfully !!!!!!!!!!!!!!!!!!!! "<<endl;
        }
        else
        {
            cout<<"!!!!!!!!!!!!!!!!!!!  Please try again  !!!!!!!!!!!!!!!!!!!!!! "<<endl;
            goto line202;
        }
    }

    void SA_subMenu()
    {
        int input;

        cout<<"\n\n\t\t-----------Service Administrator-----------\n\n";
        cout<<"\t\tPress\n";

        cout<<"\n\t\t1. To Manage the DataBase";
        cout<<"\n\t\t2. To Manage the Pricing";
        cout<<"\n\t\t3. To Reset\n";

        cout<<"\n\n\t\tInput : ";
        cin>>input;

        if(input==1)
        {
            manageDatabase();
        }

        else if(input==2)
        {
            managePricing();
        }

        else if(input==3)
        {
            reset();
        }

        if(input==0)
        {
            mainMenu();
        }
    }

    void manageDatabase()
    {
        int input,hour,current_patient;
        string day;
        Doctor_model doctor_name;

        cout<<"\n\n\t\t-----------Manage Database-----------\n\n";
        cout<<"\t\tPress\n";

        cout<<"\n\t\t1. To print Doctor's Information";
        cout<<"\n\t\t2. To print Patient's Information";
        cout<<"\n\t\t3. To Write a Query";
        cout<<"\n\t\tPress 0 To Return";

        cout<<"\n\n\t\tInput: ";
        cin>>input;

        if(input==1)
        {
            cout<<"Please enter doctors name: "<<endl;
            cin>>doctor_name.doctor_name;
            cout<<"Please enter the day you want to check the availability of doctor "<<doctor_name.doctor_name<<endl;
            cin>>day;
            cout<<"In what time do you want to check the availability of doctor "<<doctor_name.doctor_name<<endl;
            cin>>hour;
            cout<<"Please enter the total number of patients you have currently: "<<endl;
            cin>>current_patient;
            cout<<endl;
            Doctor_model init_Doctor();
            cout<<"Is "<<doctor_name.doctor_name<<" available at this hour: "<<endl;
            is_working_at_hours(&doctor_name, hour);
            cout<<endl;
            cout<<"Is "<<doctor_name.doctor_name<<" available in this day: "<<endl;
            is_working_at_day(&doctor_name, day);
            cout<<"Are the doctors at their maximum capacity: "<<endl;
            is_doctor_at_max_capacity(&doctor_name, current_patient);
        }

      else if(input==0)
      {
        SA_subMenu();
      }
      else
        terminate();

    }

    void managePricing()
    {
        float w,x,y,z;
        int input;
        cout<<"\n\n\t\t-----------Manage Pricing-----------\n";
        cout<<"\n\t\tEnter\n";
        cout<<"\n\t\t1. To Calculate total cost: ";
        cout<<"\n\t\t2. To Return Press 0";
        cout<<"\n\t\tPress any other key to exit\n";

        cout<<"\n\n\t\tInput: ";
        cin>>input;

        if(input==1)
        {
            cost(x,y,z,w);
        }
        else if(input==0)
        {
            SA_subMenu();
        }
        else
            terminate();
    }

    void reset()
    {
         int input;

         cout<<"\n\n\t\t-----------To Reset Information-----------\n";
         cout<<"\n\tPress\n";

         cout<<"\n\t\t1. To Reset Whole Information";
         cout<<"\n\t\t2. To Reset Specific Role\n";

         cout<<"\n\t\t To Return Press 0";
         cout<<"\n\t\t Input: ";
         cin>>input;

         if(input==0)
         {
             SA_subMenu();
         }
    }

};

int main()
{

    MenuInterface interface;
    interface.mainMenu();
    return 0;
}
float bmindex(float w,float h)
{
  float bmi;
  bmi=w/(h*h);
  return bmi;
}
float range(char x,float bmi)
{
	if (x=='f'||x=='F')
	{ if (bmi>30){cout<<"obese";}
	    else if(bmi>24.8){cout<<"over weight";}
	     else if(bmi>18.5){cout<<"normal";}
	     else{cout<<"underweight";}
	}
	else 
	{  if (bmi>30){cout<<"obese";}
	     else if(bmi>25){cout<<"over weight";}
	     else if(bmi>18.5){cout<<"normal";}
	     else{cout<<"underweight";}	
	}
}
void read()
{  
int n;
cout<<"Number of patients: "<<endl;;
cin>>n;	      
patient pb[n];
  for(int i=0;i<n;i++)
  { 
	  cout<<"Enter your first name: "<<endl;	  
    	  cin>>pb[i].patient_fname;
	  cout<<"Enter your last name: "<<endl;
	  cin>>pb[i].patient_lname;
    	  cout<<"Your gender: "<<endl;
	  cin>>pb[i].patient_sex;
    	  cout<<"Your weight: "<<endl;
	  cin>>pb[i].patient_weight;
    	  cout<<"Your height: "<<endl;
	  cin>>pb[i].patient_hegiht;
    	  cout<<"Your bmi: "<<endl;;		
	  bmindex(pb[i].patient_weight,pb[i].patient_hegiht);
    	  cout<<bmindex(pb[i].patient_weight,pb[i].patient_hegiht)<<endl;
    	  int BMI=bmindex(pb[i].patient_weight,pb[i].patient_hegiht);
    	  cout<<"you are  "<<endl; 
	  range(pb[i].patient_sex,BMI);
    	  cout<<endl;
     
  }
}
void inpatient_reg()
{
        int numofpatient;
        cout<<"\n\t\tPlease enter the number of patient you want to register: ";
        cin>>numofpatient;
        patient patient_info[numofpatient];
        cout<<"\n\t\t-----------Hospital Patient Registration Form-----------\n"<<endl;
        cout<<"\t\t------------------New Patient Registration---------------\n";

        for(int i=0;i<numofpatient;++i)
        {
            cout<<"\t\tPatient first name: ";
            cin>>patient_info[i].patient_fname;
            cout<<endl;
            cout<<"\t\tPatient last name: ";
            cin>>patient_info[i].patient_lname;
            cout<<endl;
            cout<<"\t\tAge: ";
            cin>>patient_info[i].patient_age;
            cout<<endl;
            cout<<"\t\tWeight: ";
            cin>>patient_info[i].patient_weight;
            cout<<endl;
            cout<<"\t\tEnter address: "<<endl;
            cout<<"\t\tCountry: ";
            cin>>patient_info[i].patient_address.country;
            cout<<endl;
            cout<<"\t\tRegion: ";
            cin>>patient_info[i].patient_address.region;
            cout<<endl;
            cout<<"\t\tCity: ";
            cin>>patient_info[i].patient_address.city;
            cout<<endl;
            cout<<"\t\tTown: ";
            cin>>patient_info[i].patient_address.town;
            cout<<endl;
            cout<<"\t\tSub-city: ";
            cin>>patient_info[i].patient_address.sub_city;
            cout<<endl;
            cout<<"\t\tKebele: ";
            cin>>patient_info[i].patient_address.kebele;
            cout<<endl;
            cout<<"\t\tHouse number: ";
            cin>>patient_info[i].patient_address.house_number;
            cout<<endl;
            cout<<"\t\tEnter phone number-cell phone/work "<<endl;
            cout<<"\t\tArea code: ";
            cin>>patient_info[i].patient_phone_number.area_code;
            cout<<endl;
            cout<<"\t\tExchange number: ";
            cin>>patient_info[i].patient_phone_number.exchange_number;
            cout<<endl;
            cout<<"\t\tU_number: ";
            cin>>patient_info[i].patient_phone_number.u_number;
            cout<<endl;
            cout<<"\t\tEmail(optional): ";
            cin>>patient_info[i].patient_email;
            cout<<endl;
            cout<<"\t\tSex: ";
            cin>>patient_info[i].patient_sex;
            cout<<endl;
            cout<<"\t\tRegistration date and time"<<endl;
            cout<<"\t\tMonth: ";
            cin>>patient_info[i].date_time.mm1;
            cout<<endl;
            cout<<"\t\tDate: ";
            cin>>patient_info[i].date_time.dd1;
            cout<<endl;
            cout<<"\t\tYear: ";
            cin>>patient_info[i].date_time.yy1;
            cout<<endl;
            cout<<"\t\tHour: ";
            cin>>patient_info[i].date_time.hr;
            cout<<endl;
            cout<<"\t\tMinute: ";
            cin>>patient_info[i].date_time.Min;
            cout<<endl;
            cout<<"\t\tDate of Birth"<<endl;
            cout<<"\t\tMonth: ";
            cin>>patient_info[i].patient_birthday.month;
            cout<<endl;
            cout<<"\t\tDate: ";
            cin>>patient_info[i].patient_birthday.day;
            cout<<endl;
            cout<<"\t\tYear: ";
            cin>>patient_info[i].patient_birthday.year;
            cout<<endl;
            cout<<"\t\tMarital Status: ";
            cin>>patient_info[i].martial_status;
            cout<<"\n\n";
            cout<<"\t\tIn case of emergency\n\n";
            cout<<"\t\tEmergency/relative Contact: "<<endl;
            cout<<"\t\tRelative's first name: ";
            cin>>patient_info[i].r_info.relative_fname;
            cout<<endl;
            cout<<"\t\tRelative's last name: ";
            cin>>patient_info[i].r_info.relative_lname;
            cout<<endl;
            cout<<"\t\tRelative's address: ";
            cin>>patient_info[i].r_info.relative_address;
            cout<<endl;
            cout<<"\t\tRelation ship: ";
            cin>>patient_info[i].r_info.relation;
            cout<<endl;
            cout<<"\t\tContact number: ";
            cin>>patient_info[i].r_info.relative_contact;
            cout<<endl;
            cout<<"\t\tTaking any medication, currently?"<<endl;
            cin>>patient_info[i].patient_history;
            cout<<endl;
      }
  }

void outpatient_reg()
{
    int numofpatient;
    patient patient_info[numofpatient];
    cout<<"           OUT PATIENT CLAIM FORM\n\n\n";
    cout<<"   Patient information\n";
    cout<<"    *to be filled by the patient*\n";
    for(int i=0;i<numofpatient;++i){
    cout<<"Patient first name: ";
    cin>>patient_info[i].patient_fname;
    cout<<endl;
    cout<<"Patient last name: ";
    cin>>patient_info[i].patient_lname;
    cout<<endl;
    cout<<"Age: ";
    cin>>patient_info[i].patient_age;
    cout<<endl;
    cout<<"Enter address: "<<endl;
    cout<<"Country: ";
    cin>>patient_info[i].patient_address.country;
    cout<<endl;
    cout<<"Region: ";
    cin>>patient_info[i].patient_address.region;
    cout<<endl;
    cout<<"City: ";
    cin>>patient_info[i].patient_address.city;
    cout<<endl;
    cout<<"Town: ";
    cin>>patient_info[i].patient_address.town;
    cout<<endl;
    cout<<"Sub-city: ";
    cin>>patient_info[i].patient_address.sub_city;
    cout<<endl;
    cout<<"Kebele: ";
    cin>>patient_info[i].patient_address.kebele;
    cout<<endl;
    cout<<"House number: ";
    cin>>patient_info[i].patient_address.house_number;
    cout<<endl;
    cout<<"Enter phone number-cell phone/work "<<endl;
    cout<<"Area code: ";
    cin>>patient_info[i].patient_phone_number.area_code;
    cout<<endl;
    cout<<"Exchange number: ";
    cin>>patient_info[i].patient_phone_number.exchange_number;
    cout<<endl;
    cout<<"U_number: ";
    cin>>patient_info[i].patient_phone_number.u_number;
    cout<<endl;
    cout<<"Email(optional): ";
    cin>>patient_info[i].patient_email;
    cout<<endl;
    cout<<"Sex: ";
    cin>>patient_info[i].patient_sex;
    cout<<endl;
    cout<<"I certify that the above information is correct.I understand that it is an offence to knowingly make any false statements for the purpose of any benefit.\n\n";
    cout<<"Patient first name: ";
    cin>>patient_info[i].patient_fname;
    cout<<endl;
    cout<<"Patient last name: ";
    cin>>patient_info[i].patient_lname;
    cout<<endl;
    cout<<"Date: ";
    cin>>patient_info[i].t_info.outdate;
    cout<<endl;
  }
}

void hospital_info()
{
    int numofpatient;
    patient patient_info[numofpatient];
    cout<<"please enter the neccessary information below\n\n";

    for(int i=0;i<numofpatient;++i)
    {
      cout<<"Hospital name: ";
      cin>>patient_info[i].detail.hospital_name[20];
      cout<<endl;
      cout<<"Hospital address: ";
      cin>>patient_info[i].detail.hospital_address;
      cout<<endl;
      cout<<"Hospital id: ";
      cin>>patient_info[i].detail.hospital_id;
      cout<<endl;
      cout<<"Hospital speciazation: ";
      cin>>patient_info[i].detail.specialization;
      cout<<endl;
      cout<<"Hospital standard: ";
      cin>>patient_info[i].detail.standard;
      cout<<endl;
      cout<<"Patient code: ";
      cin>>patient_info[i].detail.patient_code;
      cout<<endl;

    }
}

void treatment_authen()
{
  int numofpatient;
  patient patient_info[numofpatient];

  cout<<"           OUT PATIENT CLAIM FORM\n\n\n";
  cout<<"   TREATMENT AUTHENTICATION \n";
  cout<<"    *to be filled by hospital representative*\n";

  for(int i=0;i<numofpatient;++i)
  {
      cout<<"Patient's date of attendance(DOA): ";
      cin>>patient_info[i].t_info.dateofattendance;
      cout<<endl;
      cout<<"Check in time: ";
      cout<<patient_info[i].t_info.checkintime;
      cout<<endl;
      cout<<"Check out time: ";
      cin>>patient_info[i].t_info.checkouttime;
      cout<<endl;
      cout<<"Primary diagnosis: ";
      cin>>patient_info[i].t_info.primary_diagnosis;
      cout<<endl;
      cout<<"Secondary diagnosis: ";
      cin>>patient_info[i].t_info.secondary_diagnosis;
      cout<<endl;
      cout<<"Date of service: ";
      cin>>patient_info[i].t_info.dateofservice;
      cout<<endl;
      cout<<"I declare that to the best of my knowledge the foregoing statements are true in every respect.\n\n";
      cout<<endl;
      cout<<"Date: ";
      cin>>patient_info[i].t_info.outdate;
      cout<<endl;

  }
}

void treatment_nature()
{

  int numofpatient;
  patient patient_info[numofpatient];
  cout<<"           OUT PATIENT CLAIM FORM\n\n\n";
  cout<<"   NATURE OF TREATMENT\n";
  cout<<"    *to be filled by specialist/consult at the health facility*\n";

  for(int i=0;i<numofpatient;++i)
  {
      cout<<"Reason for visit: ";
      cin>>patient_info[i].t_info.reasonofvisit;
      cout<<endl;
      cout<<"Treatment condition: ";
      cin>>patient_info[i].t_info.treatment_condition;
      cout<<endl;
      cout<<"Treatment outcomes: ";
      cin>>patient_info[i].t_info.treatment_outcome;
      cout<<endl;
  }
}

bool is_working_at_hours(Doctor_model *Doctor, int hour)
{

    for (int i = 0; i != Max_working_set; i++)
    {
        if (Doctor->Work_hours[i][0] < hour || Doctor->Work_hours[i][1] < hour)
        {
            return true;
        }
    }
    return false;
}

bool is_working_at_day(Doctor_model *Doctor, string day)
{
    for (int i = 0; i != 7; i++)
    {
        if (Doctor->Working_days[i] == day)
        {
            return true;
        }
    }
    return false;
}

bool is_room_available(hospital_model *hospital, int room_number)
{
    if (hospital->rooms[room_number] == 0)
    {
        return true;
    }
    return false;
}

bool is_doctor_at_max_capacity(Doctor_model *Doctor, int Current_patient)
{
    if (Doctor->Max_patients >= Current_patient)
    {
        return true;
    }
    return false;
}

hospital_model init_hospital()
{
    hospital_model h1;
    h1.name = " ";
    h1.rooms[0] = 0;
    h1.rooms[1] = -1;
    return h1;
}

Doctor_model init_Doctor()
{
    Doctor_model Doctor;
    Doctor.doctor_name;
    Doctor.Work_hours[0][0] = 8;
    Doctor.Work_hours[0][1] = 17;
    Doctor.Working_days[0] = "Monday";
    return Doctor;
}

void appointmentDateChecker()
{

    cout << "Hello World! >.<" << endl;

    hospital_model h1 = init_hospital();
    Doctor_model Doctors[10];
    Doctors[0] = init_Doctor();

    int hour = 10;
    int room = 10;
    string day = "";

    cout << "\t\tEnter hour your good with: " << endl;
    cin >> hour;

    cout << "\t\tEnter room your good with: " << endl;
    cin >> room;

    cout << "\t\tEnter day your good with: " << endl;
    cin >> day;

    cout << "\t\tIs_working_at_hours: " << hour << "\t";

    if (is_working_at_hours(&Doctors[0], hour))
    {
        cout << "OK!" << endl;
    }

    else
    {
        cout << "NOT OK!" << endl;
    }

    cout << "\t\tIs_working_at_day: " << day << "\t";

    if (is_working_at_day(&Doctors[0], day))
    {
        cout << "OK!" << endl;
    }

    else
    {
        cout << "NOT OK!" << endl;
    }

    cout << "\t\tIs_room_available: " << hour << "\t";

    if (is_room_available(&h1, room))
    {
        cout << "OK!" << endl;
    }

    else
    {
        cout << "NOT OK!" << endl;
    }

    int Current_patient = 10;

    cout << "\t\tIs_doctor_at_max_capacity: " << Current_patient << "\t";

    if (is_doctor_at_max_capacity(&Doctors[0], Current_patient))
    {
        cout << "OK!" << endl;
    }

    else
    {
        cout << "NOT OK!" << endl;
    }

}

void disease_severity()
{
    int estimation;
    char sever[100],desc[1000];
    Doctor_model name;
    char password[50];
    char defualt_passsword[]="doctor123";
    linex: cout<<"Please verify that you are a doctor: "<<endl;
    cout<<"Please enter your name: "<<endl;
    cin>>name.doctor_name;
    cout<<"Please enter your id: "<<endl;
    cin>>name.doctor_id;
    cin.ignore();
    cout<<"Please enter you password: "<<endl;
    cin.get(password,50);
    cin.ignore();

    if((strcmp(password,defualt_passsword))==0)
    {
        cout<<"Now you can fill the following questions: "<<endl;
        cout<<"How sever is the disease in 100 words: "<<endl;
        cin.get(sever,100);
        cout<<"How long will the patient survive: "<<endl;
        cin>>estimation;
        cin.ignore();
        cout<<"Description about the disease in less than 1000 words: "<<endl;
        cin.get(desc,1000);
    }

    else
    {
        cout<<"Your names, id or password is incorrect, Please Try Again: "<<endl;
        goto linex;
    }

}
void cases()    //function for the medical assessment and updating patient's history
{
    Doctor_model name;
    int choice,option;
    char password[50];
    char default_password[50]="doctor123";
    patient info;
    line114:cout<<"Please verify that you are a doctor: "<<endl;
    cout<<"Please enter your name: "<<endl;
    cin>>name.doctor_name;
    cout<<"Please enter your id: "<<endl;
    cin>>name.doctor_id;
    cin.ignore();
    cout<<"Please enter you password: "<<endl;
    cin.get(password,50);
    if((strcmp(password,default_password))==0)
    {
        cout<<"Now you are verified to check and update the history of the patient: "<<endl;
        cout<<"Enter\n 1. For checking patients history: \n 2. For updating: \n 3. Other to exit: "<<endl;
        cin>>choice;
        switch(choice)
        {
           case 1: cout<<"You have chosen to check on the history of the patient: "<<endl;
                   cout<<"Please enter patient's id: "<<endl;
                   cin>>info.patient_id;
                   cout<<"Patient's information: "<<endl;
                   cout<<"Patient's Name: "<<info.patient_fname<<endl;
                   cout<<"Patient's Age: "<<info.patient_age<<endl;
                   cout<<"Patient's Email: "<<info.patient_email<<endl;
                   cout<<"Patient's Gender: "<<info.patient_sex<<endl;
                   cout<<"Patient's Weight: "<<info.patient_weight<<endl;
                   cout<<"Patient's Arrival Date: "<<info.date_time.dd1<<" \ "<<info.date_time.mm1<<" \ "<<info.date_time.yy1<<endl;
                   cout<<"Patient's Birthday: "<<info.patient_birthday.day<<" \ "<<info.patient_birthday.month<<" \ "<<info.patient_birthday.year<<endl;
                   cout<<"Patient's Phone Number: "<<info.patient_phone_number.area_code<<" \ "<<info.patient_phone_number.exchange_number<<" \ "<<info.patient_phone_number.u_number<<endl;
                   cout<<"Patient's Country: "<<info.patient_address.country<<endl;
                   cout<<"Patient's Region: "<<info.patient_address.region<<endl;
                   cout<<"Patient's Town: "<<info.patient_address.town<<endl;
                   cout<<"Patient's City: "<<info.patient_address.city<<endl;
                   cout<<"Patient's Sub-City: "<<info.patient_address.sub_city<<endl;
                   cout<<"Patient's Kebele: "<<info.patient_address.kebele<<endl;
                   cout<<"Patient's House Number: "<<info.patient_address.house_number<<endl;
                   cout<<"The history of the patient you are looking for is: "<<endl;
                   cout<<"..........................";
                   cout<<".................................";
                   cout<<".....................................";
                   cout<<"........................................";
                   cout<<"Press \n 1. if you want to update patient's history: \n 2. Other to exit: "<<endl;
                   cin>>option;
                   if(option==1)
                   {
                       goto line142;
                   }
                       break;
    line142:case 2: cout<<"You have chosen to update patient's history: "<<endl;
                    cout<<"Please enter patient's id: "<<endl;
                    cin>>info.patient_id;
                    cout<<"Patient's information: "<<endl;
                    cout<<"Patient's Name: "<<info.patient_fname<<endl;
                    cout<<"Patient's Age: "<<info.patient_age<<endl;
                    cout<<"Patient's Email: "<<info.patient_email<<endl;
                    cout<<"Patient's Gender: "<<info.patient_sex<<endl;
                    cout<<"Patient's Weight: "<<info.patient_weight<<endl;
                    cout<<"Patient's Arrival Date: "<<info.date_time.dd1<<" \ "<<info.date_time.mm1<<" \ "<<info.date_time.yy1<<endl;
                    cout<<"Patient's Birthday: "<<info.patient_birthday.day<<" \ "<<info.patient_birthday.month<<" \ "<<info.patient_birthday.year<<endl;
                    cout<<"Patient's Phone Number: "<<info.patient_phone_number.area_code<<" \ "<<info.patient_phone_number.exchange_number<<" \ "<<info.patient_phone_number.u_number<<endl;
                    cout<<"Patient's Country: "<<info.patient_address.country<<endl;
                    cout<<"Patient's Region: "<<info.patient_address.region<<endl;
                    cout<<"Patient's Town: "<<info.patient_address.town<<endl;
                    cout<<"Patient's City: "<<info.patient_address.city<<endl;
                    cout<<"Patient's Sub-City: "<<info.patient_address.sub_city<<endl;
                    cout<<"Patient's Kebele: "<<info.patient_address.kebele<<endl;
                    cout<<"Patient's House Number: "<<info.patient_address.house_number<<endl;
                    cout<<"Now you can update patient's history: "<<endl;
                    cin>>info.patient_history;
                    break;
        }

    }
    else
        {
          cout<<"Please Try Again: "<<endl;
            goto line114;
        }
}
void cost(float x,float y,float z,float w) //function for calculating the total cost of the patient
{
    float t_cost;
    int n_days;
    cout<<"Please enter the number of days the patient stayed in the hospital: "<<endl;
    cin>>n_days;
    cout<<"Please enter the price of MRI "<<endl;
    cin>>x;
    cout<<"Please enter the price of X-RAY "<<endl;
    cin>>z;
    cout<<"Please enter the price of room per day "<<endl;
    cin>>y;
    cout<<"Please enter Card, Hospital Service Charge and Other extra costs "<<endl;
    cin>>w;
    t_cost=x+n_days*y+z+w;
    cout<<"The total cost is: "<<t_cost<<" BIRR ONLY "<<endl;
}



