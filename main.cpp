#include<iostream>
#include<vector>
#include<conio.h>
#include <cstring>
#include <fstream>
#include<windows.h>
#include <iomanip>

using namespace std;

//ȫ���ļ�ָ�����
ifstream collegeFile("college.txt");
ifstream countryFile("country.txt");

//��ȡϵͳʱ��
SYSTEMTIME sysTime={0};

bool includeChinese(string);
int judge(int,int,int);
int isRun(int);
/*ѧ�š��������Ա𡢹��𡢳������ڡ����塢����״����������ò�����֤�š�
  ѧ�������ѧ���¡���ѧ��ʽ��ѧԺ��רҵ��ѧ�ơ�������Ρ��꼶���༶�š�����Ա��*/

//Date�࿪ʼ
class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(){
        year=2000;
        month=1;
        day=1;
    }

    Date(int year,int month,int day);

    void setDate(int,int,int);
    void getDate(int &,int &,int &);

    int getYear() const{
        return year;
    }

    int getMonth() const{
        return month;
    }

    int getDay() const{
        return day;
    }

    void setYear(int year){
        Date::year=year;
    }

    void setMonth(int month){
        Date::month=month;
    }

    void setDay(int day){
        Date::day=day;
    }

};

Date::Date(int year,int month,int day){
    if(judge(year,month,day)==0){
        this->year=year;
        this->month=month;
        this->day=day;
    }else{
        this->year=2000;
        this->month=1;
        this->day=1;
    }
}

void Date::setDate(int y,int m,int d){
    if(judge(y,m,d)==0){
        this->year=y;
        this->month=m;
        this->day=d;
    }
}

void Date::getDate(int &y,int &m,int &d){
    y=this->year;
    m=this->month;
    d=this->day;
}
//Date�����

//Student�࿪ʼ
class Student{
public:
    const string getName(){
        return name;
    }

    const string getNumber(){
        return number;
    }

    int getSex(){
        return sex;
    }

    int getCountry(){
        return country;
    }

    int getNation(){
        return nation;
    }

    int getMarrige(){
        return marrige;
    }

    int getPoliticsStatus(){
        return politicsStatus;
    }

    const string getIDNumber(){
        return IDNumber;
    }

    int getType(){
        return type;
    }

    int getEntranceWay(){
        return entranceWay;
    }

    const string getCollege(){
        return college;
    }

    const string getMajor(){
        return major;
    }

    int getSchoolLength(){
        return schoolLength;
    }

    int getTrainingLevel(){
        return trainingLevel;
    }

    int getGrade(){
        return grade;
    }

    string getClassNum(){
        return classNum;
    }

    const string getCounsellor(){
        return counsellor;
    }

    void setName(const string &name){
        Student::name=name;
    }
    void setNumber(const string number){
        Student::number=number;
    }

    void setSex(int sex){
        Student::sex=sex;
    }

    void setCountry(int country){
        Student::country=country;
    }

    void setNation(int nation){
        Student::nation=nation;
    }

    void setMarrige(int marrige){
        Student::marrige=marrige;
    }

    void setPoliticsStatus(int politicsStatus){
        Student::politicsStatus=politicsStatus;
    }

    void setIdNumber(const string idNumber){
        IDNumber=idNumber;
    }

    void setType(int type){
        Student::type=type;
    }

    void setEntranceWay(int entranceWay){
        Student::entranceWay=entranceWay;
    }

    void setCollege(const string college){
        Student::college=college;
    }

    void setMajor(const string major){
        Student::major=major;
    }

    void setSchoolLength(int schoolLength){
        Student::schoolLength=schoolLength;
    }

    void setTrainingLevel(int trainingLevel){
        Student::trainingLevel=trainingLevel;
    }

    void setGrade(int grade){
        Student::grade=grade;
    }

    void setClassNum(const string classNum){
        Student::classNum=classNum;
    }

    void setCounsellor(const string counsellor){
        Student::counsellor=counsellor;
    }

    Date getBirthday(){
        return birthday;
    }

    void setBirthday(const Date birthday){
        Student::birthday=birthday;
    }

    Date getEnrollmentDate(){
        return enrollmentDate;
    }

    void setEnrollmentDate(const Date enrollmentDate){
        Student::enrollmentDate=enrollmentDate;
    }

private:
    string number;
    string name;
    int sex;
    int country;
    Date birthday;
    int nation;
    int marrige;
    int politicsStatus;
    string IDNumber;
    int type;
    Date enrollmentDate;
    int entranceWay;
    string college;
    string major;
    int schoolLength;
    int trainingLevel;
    int grade;
    string classNum;
    string counsellor;
};
//Student�����

//Date���������
int judge(int y,int m,int d){
    int isWrong=0;
    if(y>0&&m>0&&m<13&&d>0&&d<32){
        if(m==2){
            if(!(y%4==0&&y%100!=0||y%400==0)&&d>28){
                isWrong=1;
            }else if((y%4==0&&y%100!=0||y%400==0)&&d>29){
                isWrong;
            }
        }else if((m==4||m==6||m==9||m==11)&&d==31){
            isWrong=1;
        }
    }else{
        isWrong=1;
    }
    return isWrong;
}

int isRun(int year){
    if(year%400==0||(year%4==0&&year%100!=0)){
        return 1;
    }else{
        return 0;
    }
}

int mouths(int mouth,int year){
    if(mouth==1||mouth==3||mouth==5||mouth==7||mouth==8||mouth==10||mouth==12){
        return 31;
    }else if(mouth==4||mouth==6||mouth==9||mouth==11){
        return 30;
    }else{
        if(isRun(year)){
            return 29;
        }else{
            return 28;
        }
    }
}



void menu(){
    cout<<" ______________ѧ����Ϣ����ϵͳ_______________ "<<endl;
    cout<<"|                                             |"<<endl;
    cout<<"|  1.¼��ѧ����Ϣ                             |"<<endl;
    cout<<"|  2.��ѯѧ����Ϣ                             |"<<endl;
    cout<<"|  3.�޸�ѧ����Ϣ                             |"<<endl;
    cout<<"|  4.ɾ��ѧ����Ϣ                             |"<<endl;
    cout<<"|  5.����ѧ����Ϣ                             |"<<endl;
    cout<<"|  6.����ѧ����Ϣ                             |"<<endl;
    cout<<"|  7.���ѧ����Ϣ                             |"<<endl;
    cout<<"|  8.�˳�                                     |"<<endl;
    cout<<"|_____________________________________________|"<<endl;
}

void readIn(){
    Student temp;
    string number;
    string name;
    int sex;
    int country;
    int birthday[3];
    int nation;
    int marrige;
    int politicsStatus;
    string IDNumber;
    int type;
    int enrollmentDate[2];
    int entranceWay;
    string college;
    string major;
    int schoolLength;
    int trainingLevel;
    int grade;
    string classNum;
    string counsellor;

    //����ѧ��
    cout<<"������ѧ�ţ�"<<endl;
    cin>>number;
    int numberRight;
    do{
        numberRight=1;
        if(number.length()!=9){//�ж�ѧ�ų���
            numberRight=0;
        }else{
            string temp=number.substr(0,1);//�ж�ѧԺ�Ƿ���ȷ
            char buf[100]="0";
            int is=0;
            while(!collegeFile.eof()){
                collegeFile.getline(buf,100);
                if(temp[0]==buf[0]&&temp[1]==buf[1]){
                    is=1;
                    break;
                }
            }
            if(is==0){
                numberRight=0;
            }else{
                //�ж���ѧ����Ƿ�Ϊ��ǰ���
                if((number[2]-48)!=(sysTime.wYear-2000)/10&&(number[3]-48)!=(sysTime.wYear-2000)%10){
                    numberRight=0;
                }
            }
        }

        if(numberRight==0){
            cout<<"����ѧ���������������룺";
            cin>>number;
        }
    }while(numberRight==0);

    temp.setCollege(number.substr(0,2));
    temp.getEnrollmentDate().setYear(sysTime.wYear);

    //��������
    cout<<"����������(2-20�����ֻ�40��������ĸ)��";
    cin>>name;
    bool nameRight=0;
    while(nameRight==false){
        if(includeChinese(name)){
            if(name.length()>=4&&name.length()<=40){
                temp.setName(name);
                nameRight=true;
            }
        }else{
            if(name.length()>0&&name.length()<=40){
                temp.setName(name);//TODO ���顰abc��������
                nameRight=true;
            }
        }
        if(nameRight==false){
            cout<<"����������������룺";
            cin>>name;
        }
    }

    //�����Ա�
    cout<<"��ѡ���Ա�(��/Ů)��"<<endl<<"1.��   2.Ů"<<endl;
    cin>>sex;
    while(sex<1||sex>2){
        cout<<"����������������룺";
        cin>>sex;
    }
    temp.setSex(sex);

    //���ù���
    cout<<"��ѡ��������£�"<<endl;
    char buf[100]="0";
    int item=0;
    int countryChoice;
    while(!countryFile.eof()){
        countryFile.getline(buf,100);
        cout<<setw(15)<<buf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<"��ѡ�������";
    cin>>countryChoice;
    countryFile.seekg(0,ios::beg);
    int countryNum;
    while(!countryFile.eof()){
        countryFile>>countryNum;
        if(countryChoice==countryNum){
            countryFile.getline(buf,100);
            cout<<"��ѡ��"<<countryNum<<" "<<buf<<endl;
        }else if(countryFile.eof()&&countryChoice!=countryNum){
            cout<<"�������������ѡ��";
            cin>>countryChoice;
            countryFile.seekg(0,ios::beg);
        }
    }
    temp.setCountry(countryChoice);

    //���ó�������
    cout<<"������������ڣ�"<<endl;
    cin>>birthday
    cout<<""<<endl;
}

Student search(){
    //TODO
    return ;
}

void change(){

}

void deleteInfo(){

}

void analyze(){

}

void sort(){

}
/*------------------Student��Ա��������----------------------*/

bool includeChinese(string str){
    char temp;
    char tempNext;
    for(int i=0;i<str.length();i++){
        temp=str[i];
        tempNext=str[i+1];
        if(temp&0x80||tempNext&0x80){//����ַ���λΪ1����һ�ַ���λҲ��1���������ַ�
            return true;
        }
    }
    return false;
}
int main(){
    GetLocalTime(&sysTime);

    vector<Student> all;
    menu();
    int choice;
    choice=getch();
    choice=toupper(choice);
    cout<<choice<<endl;
    switch(choice){
        case 1:
            readIn();
            break;
        case 2:
            search();
            break;
        case 3:
            change();
            break;
        case 4:
            deleteInfo();
            break;
        case 5:
            analyze();
            break;
        case 6:
            sort();
            break;
        case 7:
            cout<<"ллʹ�á�"<<endl;
            goto end;
    }
    end:return 0;
}