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
ifstream nationFile("nation.txt");
ifstream politicsStatusFile("politicsStatus.txt");
ifstream adminDivisionFile("administrativeDivision.txt");
ifstream typeFile("type.txt");
ifstream entranceWayFile("entranceWay.txt");

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
    string birthday;
    int nation;
    string marrige;
    int politicsStatus;
    string IDNumber;
    int type;
    string enrollmentDate;
    string college;
    string major;
    int schoolLength;
    int trainingLevel;
    int grade;
    string classNum;
    string counsellor;

    //����ѧ��
    cout<<"������ѧ�ţ�(����Ϊ9λ)";
    cin>>number;
    int numberRight=1;
    do{
        numberRight=1;
        if(number.length()!=9){//�ж�ѧ�ų���
            numberRight=0;
        }else{
            string temp=number.substr(0,2);//�ж�ѧԺ�Ƿ���ȷ
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
                //�ж���ѧ����Ƿ�Ϊ��ǰ���
                if((number[2]-48)!=(sysTime.wYear-2000)/10||(number[3]-48)!=(sysTime.wYear-2000)%10){
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
    cout<<"ѧ��¼��ɹ���"<<endl<<endl<<endl;


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
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;


    //�����Ա�
    cout<<"��ѡ���Ա�(��/Ů)��"<<endl<<"1.��   2.Ů"<<endl;
    cin>>sex;
    while(sex<1||sex>2){
        cout<<"����������������룺";
        cin>>sex;
    }
    temp.setSex(sex);
    cout<<"�Ա�¼��ɹ���"<<endl<<endl<<endl;


    //���ù���
    cout<<"����¼�룬��ѡ��������£�"<<endl;
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
    cout<<endl<<"��ѡ�������";
    cin.get();
    countryChoice=cin.get();
    if(countryChoice=="\n"){
        temp.setCountry(40);
        cout<<"����Ч���룬�ѽ�������ΪĬ��ֵ���й�"<<endl;
    }else{
        countryFile.clear();
        countryFile.seekg(0,ios::beg);
        int countryNum;
        while(!countryFile.eof()){
            countryFile.getline(countryBuf,100);
            countryNum=((countryBuf[0]-48)*100+(countryBuf[1]-48)*10+(countryBuf[2]-48));
            if(atoi(countryChoice.c_str())==countryNum){
                cout<<"��ѡ��"<<countryBuf<<endl;
                break;
            }else if(countryFile.eof()&&atoi(countryChoice.c_str())!=countryNum){
                cout<<"�������������ѡ��";
                cin>>countryChoice;
                countryFile.clear();
                countryFile.seekg(0,ios::beg);
            }
        }
        temp.setCountry(atoi(countryChoice.c_str()));
    }
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;


    //���ó�������
    cout<<"������������ڣ�"<<endl;
    cin>>birthday;
    int birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());//�������ڷָ������ת��Ϊint
    int birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
    int birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    while(!(judge(birthY,birthM,birthD)&&(sysTime.wYear-birthD)>=10&&(sysTime.wYear-birthD)<=100)){
        cout<<"������������������������룺";
        cin>>birthday;
        birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());
        birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
        birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    }
    temp.getBirthday().setDate(birthY,birthM,birthD);
    cout<<"��������¼��ɹ���"<<endl<<endl<<endl;


    //��������
    cout<<"����¼�룬��ѡ���������£�"<<endl;
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
    cout<<endl<<"��ѡ�����壺";
    cin.get();
    nationChoice=cin.get();
    if(nationChoice=="\n"){
        temp.setNation(1);
        cout<<"����Ч���룬�ѽ�������ΪĬ��ֵ������"<<endl;
    }else{
        nationFile.clear();
        nationFile.seekg(0,ios::beg);
        int nationNum;
        while(!nationFile.eof()){
            nationFile.getline(nationBuf,100);
            nationNum=((nationBuf[0]-48)*10+(nationBuf[1]-48));
            if(atoi(nationChoice.c_str())==nationNum){
                cout<<"��ѡ��"<<nationBuf<<endl;
                break;
            }else if(nationFile.eof()&&atoi(nationChoice.c_str())!=nationNum){
                cout<<"�������������ѡ��";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
        }
        temp.setNation(atoi(nationChoice.c_str()));
    }
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;


    //���û���״��
    cout<<"��ѡ�����״����"<<endl<<"1.δ��   2���ѻ�    3.ɥż    4.���    9.����"<<endl;
    cin.get();
    marrige=cin.get();
    if(marrige!="\n"){
        int int_marrige=atoi(marrige.c_str());
        while(int_marrige!=1&&int_marrige!=2&&int_marrige!=3&&int_marrige!=4&&int_marrige!=9){
            cout<<"����������������룺";
            cin>>marrige;
            int_marrige=atoi(marrige.c_str());
        }
        temp.setMarrige(int_marrige);
    }else{
        temp.setMarrige(1);
        cout<<"����Ч���룬�ѽ�����״����ΪĬ��ֵ��δ��"<<endl;
    }
    cout<<"����״��¼��ɹ���"<<endl<<endl<<endl;


    //����������ò
    cout<<"������ò����ѡ��������ò���£�"<<endl;
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
    cout<<endl<<"��ѡ��������ò��";
    cin.get();
    politicsStatusChoice=cin.get();
    if(politicsStatusChoice=="\n"){
        temp.setPoliticsStatus(1);
        cout<<"����Ч���룬�ѽ�������ò��ΪĬ��ֵ��������Ա"<<endl;
    }else{
        politicsStatusFile.clear();
        politicsStatusFile.seekg(0,ios::beg);
        int politicsStatusNum;
        while(!politicsStatusFile.eof()){
            politicsStatusFile.getline(politicsStatusBuf,100);
            politicsStatusNum=((politicsStatusBuf[0]-48)*10+(politicsStatusBuf[1]-48));
            if(atoi(politicsStatusChoice.c_str())==politicsStatusNum){
                cout<<"��ѡ��"<<politicsStatusBuf<<endl;
                break;
            }else if(politicsStatusFile.eof()&&atoi(politicsStatusChoice.c_str())!=politicsStatusNum){
                cout<<"�������������ѡ��";
                cin>>politicsStatusChoice;
                politicsStatusFile.clear();
                politicsStatusFile.seekg(0,ios::beg);
            }
        }
        temp.setPoliticsStatus(atoi(politicsStatusChoice.c_str()));
    }
    cout<<"������ò¼��ɹ���"<<endl<<endl<<endl;


    //�������֤��
    if(temp.getCountry()!=40){
        cout<<"������ϢΪ���й������֤����Ϊ��"<<endl;
        temp.setIdNumber("0");
    }else{
        int isIdNumberRight=1;
        cout<<"���������֤�ţ�";
        cin>>IDNumber;

        //�ж����֤�ų���
        if(IDNumber.length()!=18){
            cout<<"���֤�ų��ȴ����������������֤�ţ�"<<endl;
            isIdNumberRight=0;
        }

        //�ж���������
        if(isIdNumberRight==1){
            char adminDivisionBuf[100]="\0";
            int adminDivisionNum;
            while(!adminDivisionFile.eof()){
                adminDivisionFile.getline(adminDivisionBuf,100);
                adminDivisionNum=((adminDivisionBuf[0]-48)*100000+(adminDivisionBuf[1]-48)*10000+
                                  (adminDivisionBuf[2]-48)*1000
                                  +(adminDivisionBuf[1]-48)*100+(adminDivisionBuf[4]-48)*10+(adminDivisionBuf[5]-48));
                if(atoi(IDNumber.substr(0,6).c_str())==adminDivisionNum){
                    isIdNumberRight=1;
                    break;
                }else if(adminDivisionFile.eof()&&atoi(IDNumber.substr(0,6).c_str())!=adminDivisionNum){
                    cout<<"�������������������������֤�ţ�";
                    isIdNumberRight=0;
                    adminDivisionFile.clear();
                    adminDivisionFile.seekg(0,ios::beg);
                }
            }
        }

        //�жϳ�������
        if(isIdNumberRight==1){
            int IdbirthY=atoi(IDNumber.substr(6,10).c_str());//��ȡ���֤�������ڣ�������ת��Ϊint
            int IdbirthM=atoi(IDNumber.substr(10,12).c_str());
            int IdbirthD=atoi(IDNumber.substr(12,14).c_str());
            if(IdbirthY!=temp.getBirthday().getYear()||IdbirthM!=temp.getBirthday().getMonth()
               ||IdbirthD!=temp.getBirthday().getDay()){
                isIdNumberRight=0;
                cout<<"�������ڴ����������������֤�ţ�";
            }
        }

        //�ж�˳����
        if(isIdNumberRight==1){
            int sequenceNum=atoi(IDNumber.substr().c_str());
            if((sequenceNum%2)==0&&temp.getSex()==2){
                isIdNumberRight=1;
            }else if((sequenceNum%2)==temp.getSex()){
                isIdNumberRight=1;
            }else{
                isIdNumberRight=0;
                cout<<"�Ա�����������������֤�ţ�";
            }
        }

        //�ж�У��λ
        if(isIdNumberRight==1){
            char check[11]={'1','0','X','9','8','7','6','5','4','3','2'};
            int sumNum=(IDNumber[0]-48)*7+(IDNumber[1]-48)*9+(IDNumber[2]-48)*10+(IDNumber[3]-48)*5+
                       (IDNumber[4]-48)*8+(IDNumber[5]-48)*4+(IDNumber[6]-48)*2+(IDNumber[7]-48)*1+
                       (IDNumber[8]-48)*6+(IDNumber[9]-48)*3+(IDNumber[10]-48)*7+(IDNumber[11]-48)*9+
                       (IDNumber[12]-48)*10+(IDNumber[13]-48)*5+(IDNumber[14]-48)*8+(IDNumber[15]-48)*4+
                       (IDNumber[16]-48)*2;
            char checkNum=check[sumNum%11];
            if(checkNum!=IDNumber[17]){
                isIdNumberRight=0;
                cout<<"����λ�����������������֤�ţ�";
            }
        }

        //TODO �ж��Ƿ��ظ����֤��
    }
    cout<<"���֤��¼��ɹ���"<<endl<<endl<<endl;


    //����ѧ�����
    cout<<"����ѧ����𣬿�ѡ��������£�"<<endl;
    char typeBuf[100]="\0";
    item=0;
    string typeChoice;
    while(!typeFile.eof()){
        typeFile.getline(typeBuf,100);
        cout<<left<<setw(15)<<typeBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"��ѡ��ѧ�����";
    cin.get();
    typeChoice=cin.get();
    if(typeChoice=="\n"){
        temp.setType(1);
        cout<<"����Ч���룬�ѽ�ѧ�������ΪĬ��ֵ����"<<endl;
    }else{
        typeFile.clear();
        typeFile.seekg(0,ios::beg);
        int typeNum;
        while(!typeFile.eof()){
            typeFile.getline(typeBuf,100);
            typeNum=(typeBuf[0]-48);
            if(atoi(typeChoice.c_str())==typeNum){
                cout<<"��ѡ��"<<typeBuf<<endl;
                break;
            }else if(typeFile.eof()&&atoi(typeChoice.c_str())!=typeNum){
                cout<<"�������������ѡ��";
                cin>>typeChoice;
                typeFile.clear();
                typeFile.seekg(0,ios::beg);
            }
        }
        temp.setType(atoi(typeChoice.c_str()));
    }
    cout<<"ѧ�����¼��ɹ���"<<endl<<endl<<endl;

    //������ѧ����
    cout<<"��������ѧ���ڣ�"<<endl;
    cin>>enrollmentDate;
    int enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());//�������ڷָ������ת��Ϊint
    int enrollM=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
    int enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.length()).c_str());
    while(!(judge(enrollY,enrollM,enrollD)&&enrollM>=8&&enrollM<=10)){
        cout<<"��ѧ��������������������룺";
        cin>>enrollmentDate;
        enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());
        enrollM=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
        enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.length()).c_str());
    }
    temp.getEnrollmentDate().setDate(enrollY,enrollM,enrollD);
    cout<<"��ѧ����¼��ɹ���"<<endl<<endl<<endl;

    //������ѧ��ʽ
    cout<<"������ѧ��ʽ����ѡ��ʽ���£�"<<endl;
    char entranceWayBuf[100]="\0";
    item=0;
    string entranceWayChoice;
    while(!entranceWayFile.eof()){
        entranceWayFile.getline(entranceWayBuf,100);
        cout<<left<<setw(15)<<entranceWayBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"��ѡ����ѧ��ʽ��";
    cin.get();
    entranceWayChoice=cin.get();
    if(entranceWayChoice=="\n"){
        temp.setEntranceWay(1);
        cout<<"����Ч���룬�ѽ���ѧ��ʽ��ΪĬ��ֵ����ͨ��ѧ"<<endl;
    }else{
        entranceWayFile.clear();
        entranceWayFile.seekg(0,ios::beg);
        int entranceWayNum;
        while(!entranceWayFile.eof()){
            entranceWayFile.getline(entranceWayBuf,100);
            entranceWayNum=(entranceWayBuf[0]-48);
            if(atoi(entranceWayChoice.c_str())==entranceWayNum){
                cout<<"��ѡ��"<<entranceWayBuf<<endl;
                break;
            }else if(entranceWayFile.eof()&&atoi(entranceWayChoice.c_str())!=entranceWayNum){
                cout<<"�������������ѡ��";
                cin>>entranceWayChoice;
                entranceWayFile.clear();
                entranceWayFile.seekg(0,ios::beg);
            }
        }
        temp.setEntranceWay(atoi(entranceWayChoice.c_str()));
    }
    cout<<"��ѧ��ʽ¼��ɹ���"<<endl<<endl<<endl;


    //����ѧԺ��רҵ����


    //�����꼶
    cout<<"�����꼶�������������꼶";
    cin>>grade;
    if(grade!=2000+atoi(number.substr(2,4).c_str())){
        int tempChoice;
        cout<<"�����꼶��ѧ�����꼶��ͬ���Ƿ�ȷ��¼�룺1.��      2.��"<<endl;
        cin>>tempChoice;
        if(tempChoice==1){
            temp.setGrade(grade);
        }else{
            temp.setGrade(2000+atoi(number.substr(2,4).c_str()));
        }
    }else{
        temp.setGrade(2000+atoi(number.substr(2,4).c_str()));
    }
    cout<<"�꼶¼��ɹ���"<<endl<<endl<<endl;

    //����ѧ��

    //�����������

    //���ð༶��

    //���ø���Ա







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
            cout<<"ллʹ�á�"<<endl;
            goto end;
    }
    end:
    return 0;
}