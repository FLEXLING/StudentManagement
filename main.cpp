#include<iostream>
#include<vector>
#include<conio.h>
#include <cstring>
#include <fstream>
#include<windows.h>
#include <iomanip>

using namespace std;

//全局文件指针变量
ifstream collegeFile("college.txt");
ifstream countryFile("country.txt");
ifstream nationFile("nation.txt");
ifstream politicsStatusFile("politicsStatus.txt");

//获取系统时间
SYSTEMTIME sysTime={0};

bool includeChinese(string);
int judge(int,int,int);
int isRun(int);
/*学号、姓名、性别、国别、出生日期、民族、婚姻状况、政治面貌、身份证号、
  学生类别、入学年月、入学方式、学院、专业、学制、培养层次、年级、班级号、辅导员等*/

//Date类开始
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
//Date类结束

//Student类开始
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
//Student类结束

//Date类关联函数
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
    cout<<" ______________学生信息管理系统_______________ "<<endl;
    cout<<"|                                             |"<<endl;
    cout<<"|  1.录入学生信息                             |"<<endl;
    cout<<"|  2.查询学生信息                             |"<<endl;
    cout<<"|  3.修改学生信息                             |"<<endl;
    cout<<"|  4.删除学生信息                             |"<<endl;
    cout<<"|  5.分析学生信息                             |"<<endl;
    cout<<"|  6.排序学生信息                             |"<<endl;
    cout<<"|  7.输出学生信息                             |"<<endl;
    cout<<"|  8.退出                                     |"<<endl;
    cout<<"|_____________________________________________|"<<endl;
}

void readIn(){
    Student temp;
    string number;
    string name;
    int sex;
    int country;
    string birthday;
    int nation;
    string marrige;
    int politicsStatus;
    string IDNumber;
    int type;
    string enrollmentDate;
    int entranceWay;
    string college;
    string major;
    int schoolLength;
    int trainingLevel;
    int grade;
    string classNum;
    string counsellor;

    //设置学号
    cout<<"请输入学号：(必须为9位)";
    cin>>number;
    int numberRight=1;
    do{
        numberRight=1;
        if(number.length()!=9){//判断学号长度
            numberRight=0;
        }else{
            string temp=number.substr(0,2);//判断学院是否正确
            char buf[100]="\0";
            int is=0;
            collegeFile.clear();
            collegeFile.seekg(0,ios::beg);
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
                //判断入学年份是否为当前年份
                if((number[2]-48)!=(sysTime.wYear-2000)/10||(number[3]-48)!=(sysTime.wYear-2000)%10){
                    numberRight=0;
                }
            }
        }

        if(numberRight==0){
            cout<<"输入学号有误，请重新输入：";
            cin>>number;
        }
    }while(numberRight==0);

    temp.setCollege(number.substr(0,2));
    temp.getEnrollmentDate().setYear(sysTime.wYear);

    //设置姓名
    cout<<"请输入姓名(2-20个汉字或40个以内字母)：";
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
                temp.setName(name);//TODO 检验“abc”等名称
                nameRight=true;
            }
        }
        if(nameRight==false){
            cout<<"输入错误，请重新输入：";
            cin>>name;
        }
    }

    //设置性别
    cout<<"请选择性别(男/女)："<<endl<<"1.男   2.女"<<endl;
    cin>>sex;
    while(sex<1||sex>2){
        cout<<"输入错误，请重新输入：";
        cin>>sex;
    }
    temp.setSex(sex);

    //设置国别
    cout<<"国籍录入，可选择国籍如下："<<endl;
    char countryBuf[100]="\0";
    int item=0;
    string countryChoice;
    while(!countryFile.eof()){
        countryFile.getline(countryBuf,100);
        cout<<left<<setw(30)<<countryBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择国籍：";
    cin.get();
    countryChoice=cin.get();
    if(countryChoice=="\n"){
        temp.setCountry(40);
        cout<<"无有效输入，已将国籍设为默认值：中国"<<endl;
    }else{
        countryFile.clear();
        countryFile.seekg(0,ios::beg);
        int countryNum;
        while(!countryFile.eof()){
            countryFile.getline(countryBuf,100);
            countryNum=((countryBuf[0]-48)*100+(countryBuf[1]-48)*10+(countryBuf[2]-48));
            if(atoi(countryChoice.c_str())==countryNum){
                cout<<"已选择："<<countryBuf<<endl;
                break;
            }else if(countryFile.eof()&&atoi(countryChoice.c_str())!=countryNum){
                cout<<"输入错误，请重新选择：";
                cin>>countryChoice;
                countryFile.clear();
                countryFile.seekg(0,ios::beg);
            }
        }
        temp.setCountry(atoi(countryChoice.c_str()));
    }

    //设置出生日期
    cout<<"请输入出生日期："<<endl;
    cin>>birthday;
    int birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());//出生日期分割，并将其转化为int
    int birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
    int birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    while(!(judge(birthY,birthM,birthD)&&(sysTime.wYear-birthD)>=10&&(sysTime.wYear-birthD)<=100)){
        cout<<"出生日期输入错误，请重新输入：";
        cin>>birthday;
        birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());
        birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
        birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    }
    temp.getBirthday().setDate(birthY,birthM,birthD);

    //设置民族
    cout<<"民族录入，可选择民族如下："<<endl;
    char nationBuf[100]="\0";
    item=0;
    string nationChoice;
    while(!nationFile.eof()){
        nationFile.getline(nationBuf,100);
        cout<<left<<setw(30)<<nationBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择民族：";
    cin.get();
    nationChoice=cin.get();
    if(nationChoice=="\n"){
        temp.setNation(1);
        cout<<"无有效输入，已将民族设为默认值：汉族"<<endl;
    }else{
        nationFile.clear();
        nationFile.seekg(0,ios::beg);
        int nationNum;
        while(!nationFile.eof()){
            nationFile.getline(nationBuf,100);
            nationNum=((nationBuf[0]-48)*10+(nationBuf[1]-48));
            if(atoi(nationChoice.c_str())==nationNum){
                cout<<"已选择："<<nationBuf<<endl;
                break;
            }else if(nationFile.eof()&&atoi(nationChoice.c_str())!=nationNum){
                cout<<"输入错误，请重新选择：";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
        }
        temp.setNation(atoi(nationChoice.c_str()));
    }

    //设置婚姻状况
    cout<<"请选择婚姻状况："<<endl<<"1.未婚   2。已婚    3.丧偶    4.离婚    9.其他"<<endl;
    cin.get();
    marrige=cin.get();
    if(marrige!="\n"){
        int int_marrige=atoi(marrige.c_str());
        while(int_marrige!=1&&int_marrige!=2&&int_marrige!=3&&int_marrige!=4&&int_marrige!=9){
            cout<<"输入错误，请重新输入：";
            cin>>marrige;
            int_marrige=atoi(marrige.c_str());
        }
        temp.setMarrige(int_marrige);
    }else{
        temp.setMarrige(1);
        cout<<"无有效输入，已将婚姻状况设为默认值：未婚"<<endl;
    }

    //设置政治面貌
    cout<<"政治面貌，可选择政治面貌如下："<<endl;
    char politicsStatusBuf[100]="\0";
    item=0;
    string politicsStatusChoice;
    while(!politicsStatusFile.eof()){
        politicsStatusFile.getline(politicsStatusBuf,100);
        cout<<left<<setw(30)<<politicsStatusBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择政治面貌：";
    cin.get();
    politicsStatusChoice=cin.get();
    if(politicsStatusChoice=="\n"){
        temp.setPoliticsStatus(1);
        cout<<"无有效输入，已将政治面貌设为默认值：共青团员"<<endl;
    }else{
        politicsStatusFile.clear();
        politicsStatusFile.seekg(0,ios::beg);
        int politicsStatusNum;
        while(!politicsStatusFile.eof()){
            politicsStatusFile.getline(politicsStatusBuf,100);
            politicsStatusNum=((politicsStatusBuf[0]-48)*10+(politicsStatusBuf[1]-48));
            if(atoi(politicsStatusChoice.c_str())==politicsStatusNum){
                cout<<"已选择："<<politicsStatusBuf<<endl;
                break;
            }else if(politicsStatusFile.eof()&&atoi(politicsStatusChoice.c_str())!=politicsStatusNum){
                cout<<"输入错误，请重新选择：";
                cin>>politicsStatusChoice;
                politicsStatusFile.clear();
                politicsStatusFile.seekg(0,ios::beg);
            }
        }
        temp.setPoliticsStatus(atoi(politicsStatusChoice.c_str()));
    }




}

Student search(){
    //TODO
    Student temp;
    return temp;
}

void change(){

}

void deleteInfo(){

}

void analyze(){

}

void sort(){

}
/*------------------Student成员函数结束----------------------*/

bool includeChinese(string str){
    char temp;
    char tempNext;
    for(int i=0;i<str.length();i++){
        temp=str[i];
        tempNext=str[i+1];
        if(temp&0x80||tempNext&0x80){//如果字符高位为1且下一字符高位也是1则有中文字符
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
    choice-=48;
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
            cout<<"谢谢使用。"<<endl;
            goto end;
    }
    end:return 0;
}