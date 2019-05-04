#include<iostream>
#include<vector>
#include<conio.h>
#include<string>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

//ȫ���ļ�ָ�����
ifstream collegeFile("college.txt");
ifstream countryFile("country.txt");
ifstream nationFile("nation.txt");
ifstream politicsStatusFile("politicsStatus.txt");
ifstream adminDivisionFile("administrativeDivision.txt");
ifstream typeFile("type.txt");
ifstream entranceWayFile("entranceWay.txt");
ifstream majorFile("major.txt");
ifstream counsellorFile("counsellor.txt");
fstream studentFile("student.txt");

//��ȡϵͳʱ��
SYSTEMTIME sysTime={0};

//CMD��ɫ����
HANDLE hOut;

bool includeChinese(string);
void splitString(string,vector<string> &,string);
bool isChoice(string);

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
    if(judge(year,month,day)){
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
    if(judge(y,m,d)==1){
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
    string getNumber(){
        return number;
    }

    void setNumber(const string number){
        Student::number=number;
    }

    string getName(){
        return name;
    }

    void setName(const string name){
        Student::name=name;
    }

    string getSex(){
        return sex;
    }

    void setSex(const string sex){
        Student::sex=sex;
    }

    string getCountry(){
        return country;
    }

    void setCountry(const string country){
        Student::country=country;
    }

    Date &getBirthday(){
        return birthday;
    }

    string getNation(){
        return nation;
    }

    void setNation(const string nation){
        Student::nation=nation;
    }

    string getMarrige(){
        return marrige;
    }

    void setMarrige(const string marrige){
        Student::marrige=marrige;
    }

    string getPoliticsStatus(){
        return politicsStatus;
    }

    void setPoliticsStatus(const string politicsStatus){
        Student::politicsStatus=politicsStatus;
    }

    string getIdNumber(){
        return IDNumber;
    }

    void setIdNumber(const string idNumber){
        IDNumber=idNumber;
    }

    string getType(){
        return type;
    }

    void setType(const string type){
        Student::type=type;
    }

    Date &getEnrollmentDate(){
        return enrollmentDate;
    }

    void setEnrollmentDate(const Date enrollmentDate){
        Student::enrollmentDate=enrollmentDate;
    }

    string getEntranceWay(){
        return entranceWay;
    }

    void setEntranceWay(const string entranceWay){
        Student::entranceWay=entranceWay;
    }

    string getCollege(){
        return college;
    }

    void setCollege(const string college){
        Student::college=college;
    }

    string getMajor(){
        return major;
    }

    void setMajor(const string major){
        Student::major=major;
    }

    int getSchoolLength(){
        return schoolLength;
    }

    void setSchoolLength(int schoolLength){
        Student::schoolLength=schoolLength;
    }

    string getTrainingLevel(){
        return trainingLevel;
    }

    void setTrainingLevel(const string trainingLevel){
        Student::trainingLevel=trainingLevel;
    }

    int getGrade(){
        return grade;
    }

    void setGrade(int grade){
        Student::grade=grade;
    }

    int getClassNum(){
        return classNum;
    }

    void setClassNum(int classNum){
        Student::classNum=classNum;
    }

    string getCounsellor(){
        return counsellor;
    }

    void setCounsellor(const string counsellor){
        Student::counsellor=counsellor;
    }

private:
    string number;
    string name;
    string sex;
    string country;
    Date birthday;
    string nation;
    string marrige;
    string politicsStatus;
    string IDNumber;
    string type;
    Date enrollmentDate;
    string entranceWay;
    string college;
    string major;
    int schoolLength;
    string trainingLevel;
    int grade;
    int classNum;
    string counsellor;
};
//Student�����

//Date���������
int judge(int y,int m,int d){
    int isRight=1;
    if(y>0&&m>0&&m<13&&d>0&&d<32){
        if(m==2){
            if(!(y%4==0&&y%100!=0||y%400==0)&&d>28){
                isRight=0;
            }else if((y%4==0&&y%100!=0||y%400==0)&&d>29){
                isRight=0;
            }
        }else if((m==4||m==6||m==9||m==11)&&d==31){
            isRight=0;
        }
    }else{
        isRight=0;
    }
    return isRight;
}

int isRun(int year){
    if(year%400==0||(year%4==0&&year%100!=0)){
        return 1;
    }else{
        return 0;
    }
}


void menu(){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
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
    cout<<"��ѡ��";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
}

void setNumber(Student &temp){
    //����ѧ��
    string number;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"������ѧ��(����Ϊ9λ)��";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>number;
    int numberRight=1;
    do{
        numberRight=1;
        if(number.length()!=9){//�ж�ѧ�ų���
            numberRight=0;
        }else{
            string tempCollege=number.substr(0,2);//�ж�ѧԺ�Ƿ���ȷ
            string buf;
            int is=0;
            collegeFile.clear();
            collegeFile.seekg(0,ios::beg);
            while(!collegeFile.eof()){
                getline(collegeFile,buf);
                if(tempCollege==buf.substr(0,2)){
                    is=1;
                    temp.setCollege(buf.substr(3,buf.length()));
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
    temp.getEnrollmentDate().setYear(sysTime.wYear);
    temp.setNumber(number);
    cout<<"ѧ��¼��ɹ���"<<endl<<endl<<endl;
}

void setName(Student &temp){
    //��������
    string name;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"����������(2-20�����ֻ�40��������ĸ)��";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>name;
    bool nameRight=1;
    while(1){
        if(includeChinese(name)){
            for(int i=0;i<name.length();i++){
                if(isalpha(name[i])||ispunct(name[i])||isdigit(name[i])){
                    cout<<"�����в���ͬʱ�������ĺ������ַ���"<<endl;
                    nameRight=false;
                    break;
                }
            }
            if(name.length()<4||name.length()>40){
                nameRight=false;
                cout<<"�������ȴ���"<<endl;
            }
        }else{
            for(int i=0;i<name.length();i++){
                if(!isalpha(name[i])){
                    nameRight=false;
                    cout<<"�����в��ܺ��г����ĺ���ĸ�������ַ���"<<endl;
                    break;
                }
            }
            if(name.length()<=0||name.length()>40){
                nameRight=false;
                cout<<"�������ȴ���"<<endl;
            }
        }
        if(nameRight==false){
            cout<<"���������룺";
            cin>>name;
            nameRight=true;
        }else{
            temp.setName(name);
            break;
        }
    }
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;
}

void setSex(Student &temp){
    //�����Ա�
    int sex;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"��ѡ���Ա�(��/Ů)��"<<endl<<"1.��   2.Ů"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>sex;
    while(sex<1||sex>2){
        cout<<"����������������룺";
        cin>>sex;
    }
    if(sex==1){
        temp.setSex("��");
    }else if(sex==2){
        temp.setSex("Ů");
    }
    cout<<"�Ա�¼��ɹ���"<<endl<<endl<<endl;
}

void setCountry(Student &temp){
    //���ù���
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"����¼�룬��ѡ��������£�"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string countryBuf;
    int item=0;
    string countryChoice;
    countryFile.clear();
    countryFile.seekg(0,ios::beg);
    while(!countryFile.eof()){
        getline(countryFile,countryBuf);
        cout<<left<<setw(30)<<countryBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"��ѡ�������";
    cin.clear();
    cin.sync();
    getline(cin,countryChoice);
    if(countryChoice.size()==0){
        temp.setCountry("�й�");
        cout<<"����Ч���룬�ѽ�������ΪĬ��ֵ���й�"<<endl;
    }else{
        countryFile.clear();
        countryFile.seekg(0,ios::beg);
        int countryNum;
        while(!countryFile.eof()){
            while(!isChoice(countryChoice)){
                cout<<"�������������ѡ��";
                cin>>countryChoice;
                countryFile.clear();
                countryFile.seekg(0,ios::beg);
            }
            getline(countryFile,countryBuf);
            countryNum=atoi(countryBuf.substr(0,3).c_str());
            if(atoi(countryChoice.c_str())==countryNum){
                cout<<"��ѡ��"<<countryBuf<<endl;
                temp.setCountry(countryBuf.substr(8,countryBuf.length()));
                break;
            }else if(countryFile.eof()&&atoi(countryChoice.c_str())!=countryNum){
                cout<<"�������������ѡ��";
                cin>>countryChoice;
                countryFile.clear();
                countryFile.seekg(0,ios::beg);
            }
        }
    }
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;
}

void setBirthday(Student &temp){
    //���ó�������
    string birthday;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"������������ڣ�";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>birthday;
    int birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());//�������ڷָ������ת��Ϊint
    int birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
    int birthD=atoi(birthday.substr(birthday.find_last_of('.')+1,birthday.length()).c_str());
    while(!(judge(birthY,birthM,birthD)&&(sysTime.wYear-birthY)>=10&&(sysTime.wYear-birthY)<=100)){
        cout<<"������������������������룺";
        cin>>birthday;
        birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());
        birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
        birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    }
    temp.getBirthday().setDate(birthY,birthM,birthD);
    cout<<"��������¼��ɹ���"<<endl<<endl<<endl;
}

void setNation(Student &temp){
    //��������
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"����¼�룬��ѡ���������£�"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string nationBuf;
    int item=0;
    string nationChoice;
    nationFile.clear();
    nationFile.seekg(0,ios::beg);
    while(!nationFile.eof()){//����һ���ĸ��������
        getline(nationFile,nationBuf);
        cout<<left<<setw(30)<<nationBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"��ѡ�����壺";
    cin.clear();
    cin.sync();//���cin������
    getline(cin,nationChoice);//����ѡ��
    if(nationChoice.size()==0){//����Ч�������
        temp.setNation("����");
        cout<<"����Ч���룬�ѽ�������ΪĬ��ֵ������"<<endl;
    }else{
        nationFile.clear();
        nationFile.seekg(0,ios::beg);
        int nationNum;
        while(!nationFile.eof()){
            while(!isChoice(nationChoice)){
                cout<<"�������������ѡ��";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
            getline(nationFile,nationBuf);
            nationNum=atoi(nationBuf.substr(0,nationBuf.find_first_of('\t')).c_str());
            if(atoi(nationChoice.c_str())==nationNum){
                cout<<"��ѡ��"<<nationBuf<<endl;
                temp.setNation(nationBuf.substr(nationBuf.find_last_of('\t')+1,nationBuf.length()));
                break;
            }else if(nationFile.eof()&&atoi(nationChoice.c_str())!=nationNum){
                cout<<"�������������ѡ��";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
        }
    }
    cout<<"����¼��ɹ���"<<endl<<endl<<endl;
}

void setMarrige(Student &temp){
    string marrige;
    //���û���״��
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"��ѡ�����״����"<<endl<<"1.δ��   2.�ѻ�    3.ɥż    4.���    9.����"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin.clear();
    cin.sync();
    getline(cin,marrige);
    if(marrige.size()!=0){
        int int_marrige=atoi(marrige.c_str());
        while(int_marrige!=1&&int_marrige!=2&&int_marrige!=3&&int_marrige!=4&&int_marrige!=9){
            cout<<"����������������룺";
            cin>>marrige;
            int_marrige=atoi(marrige.c_str());
        }
        if(int_marrige==1){
            temp.setMarrige("δ��");
            cout<<"��ѡ��δ��"<<endl;
        }else if(int_marrige==2){
            temp.setMarrige("�ѻ�");
            cout<<"��ѡ���ѻ�"<<endl;
        }else if(int_marrige==3){
            temp.setMarrige("ɥż");
            cout<<"��ѡ��ɥż"<<endl;
        }else if(int_marrige==4){
            temp.setMarrige("���");
            cout<<"��ѡ�����"<<endl;
        }else if(int_marrige==9){
            temp.setMarrige("����");
            cout<<"��ѡ������"<<endl;
        }
    }else{
        temp.setMarrige("δ��");
        cout<<"����Ч���룬�ѽ�����״����ΪĬ��ֵ��δ��"<<endl;
    }
    cout<<"����״��¼��ɹ���"<<endl<<endl<<endl;
}

void setPoliticStatus(Student &temp){
    //����������ò
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"������ò����ѡ��������ò���£�"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string politicsStatusBuf;
    int item=0;
    string politicsStatusChoice;
    politicsStatusFile.clear();
    politicsStatusFile.seekg(0,ios::beg);
    while(!politicsStatusFile.eof()){
        getline(politicsStatusFile,politicsStatusBuf);
        cout<<left<<setw(30)<<politicsStatusBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"��ѡ��������ò��";
    cin.clear();
    cin.sync();
    getline(cin,politicsStatusChoice);
    if(politicsStatusChoice.size()==0){
        temp.setPoliticsStatus("������Ա");
        cout<<"����Ч���룬�ѽ�������ò��ΪĬ��ֵ��������Ա"<<endl;
    }else{
        politicsStatusFile.clear();
        politicsStatusFile.seekg(0,ios::beg);
        int politicsStatusNum;
        while(!politicsStatusFile.eof()){
            while(!isChoice(politicsStatusChoice)){
                cout<<"�������������ѡ��";
                cin>>politicsStatusChoice;
            }
            getline(politicsStatusFile,politicsStatusBuf);
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
        temp.setPoliticsStatus(
                politicsStatusBuf.substr(politicsStatusBuf.find_last_of(' '),politicsStatusBuf.length()));
    }
    cout<<"������ò¼��ɹ���"<<endl<<endl<<endl;
}

void setIDNumber(Student &temp){
    //�������֤��
    string IDNumber;
    if(temp.getCountry()!="�й�"){
        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
        cout<<"������ϢΪ���й������֤����Ϊ�գ�"<<endl<<endl<<endl;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
        temp.setIdNumber("0");
    }else{
        while(1){
            int isIdNumberRight=1;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cout<<"���������֤�ţ�";
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cin.clear();
            cin.sync();
            cin>>IDNumber;

            //�ж����֤���ַ�
            if(includeChinese(IDNumber)){
                cout<<"���֤���в��ܺ��к��֣�"<<endl;
                isIdNumberRight=0;
            }
            for(int i=0;i<IDNumber.length();i++){
                if(ispunct(IDNumber[i])||isalpha(IDNumber[i])){
                    cout<<"���֤���в��ܺ����ַ�������";
                    isIdNumberRight=0;
                    break;
                }
            }

            //�ж����֤�ų���
            if(IDNumber.length()!=18){
                cout<<"���֤�ų��ȴ���";
                isIdNumberRight=0;
            }

            //�ж���������
            if(isIdNumberRight==1){
                string adminDivisionBuf;
                int adminDivisionNum;
                adminDivisionFile.clear();
                adminDivisionFile.seekg(0,ios::beg);
                while(!adminDivisionFile.eof()){
                    getline(adminDivisionFile,adminDivisionBuf);
                    adminDivisionNum=atoi(adminDivisionBuf.substr(0,6).c_str());
                    int debug=atoi(IDNumber.substr(0,6).c_str());
                    if(atoi(IDNumber.substr(0,6).c_str())==adminDivisionNum){
                        isIdNumberRight=1;
                        adminDivisionFile.clear();
                        adminDivisionFile.seekg(0,ios::beg);
                        break;
                    }else if(adminDivisionFile.eof()&&atoi(IDNumber.substr(0,6).c_str())!=adminDivisionNum){
                        cout<<"������������";
                        isIdNumberRight=0;
                        adminDivisionFile.clear();
                        adminDivisionFile.seekg(0,ios::beg);
                    }
                }
            }

            //�жϳ�������
            if(isIdNumberRight==1){
                int IdbirthY=atoi(IDNumber.substr(6,4).c_str());//��ȡ���֤�������ڣ�������ת��Ϊint
                int IdbirthM=atoi(IDNumber.substr(10,2).c_str());
                int IdbirthD=atoi(IDNumber.substr(12,2).c_str());
                if(IdbirthY!=temp.getBirthday().getYear()||IdbirthM!=temp.getBirthday().getMonth()
                   ||IdbirthD!=temp.getBirthday().getDay()){
                    isIdNumberRight=0;
                    cout<<"�������ڴ���";
                }
            }

            //�ж�˳����
            int intSex;
            if(temp.getSex()=="��"){
                intSex=1;
            }else if(temp.getSex()=="Ů"){
                intSex=0;
            }
            if(isIdNumberRight==1){
                int sequenceNum=atoi(IDNumber.substr(14,3).c_str());
                if((sequenceNum%2)==intSex){
                    isIdNumberRight=1;
                }else{
                    isIdNumberRight=0;
                    cout<<"�Ա����";
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
                    cout<<"����λ����";
                }
            }
            if(isIdNumberRight==1){
                temp.setIdNumber(IDNumber);
                cout<<"���֤��¼��ɹ���"<<endl<<endl<<endl;
                break;
            }
        }

        //TODO �ж��Ƿ��ظ����֤��
    }
}

void setType(Student &temp){
    //����ѧ�����
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"����ѧ����𣬿�ѡ��������£�"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string typeBuf;
    int item=0;
    string typeChoice;
    typeFile.clear();
    typeFile.seekg(0,ios::beg);
    while(!typeFile.eof()){
        getline(typeFile,typeBuf);
        cout<<left<<setw(15)<<typeBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"��ѡ��ѧ�����";
    cin.clear();
    cin.sync();
    getline(cin,typeChoice);
    if(typeChoice.size()==0){
        temp.setType("��");
        cout<<"����Ч���룬�ѽ�ѧ�������ΪĬ��ֵ����"<<endl;
    }else{
        typeFile.clear();
        typeFile.seekg(0,ios::beg);
        int typeNum;
        while(!typeFile.eof()){
            while(!isChoice(typeChoice)){
                cout<<"�������������ѡ��";
                cin>>typeChoice;
            }
            getline(typeFile,typeBuf);
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
        temp.setType(typeBuf.substr(typeBuf.find_last_of(' '),typeBuf.length()));
    }
    cout<<"ѧ�����¼��ɹ���"<<endl<<endl<<endl;
}

void setEnrollmentDate(Student &temp){
    //������ѧ����
    string enrollmentDate;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"��������ѧ���ڣ�";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>enrollmentDate;
    int enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());//�������ڷָ������ת��Ϊint
    int enrollM=atoi(
            enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
    int enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.length()).c_str());
    while(!(judge(enrollY,enrollM,enrollD)&&enrollM>=8&&enrollM<=10)){
        cout<<"��ѧ��������������������룺";
        cin>>enrollmentDate;
        enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());
        enrollM=atoi(
                enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
        enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_last_of('.')+1,enrollmentDate.length()).c_str());
    }
    temp.getEnrollmentDate().setDate(enrollY,enrollM,enrollD);
    cout<<"��ѧ����¼��ɹ���"<<endl<<endl<<endl;
}

void setEntranceWay(Student &temp){
    //������ѧ��ʽ
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"������ѧ��ʽ����ѡ��ʽ���£�"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string entranceWayBuf;
    int item=0;
    string entranceWayChoice;
    entranceWayFile.clear();
    entranceWayFile.seekg(0,ios::beg);
    while(!entranceWayFile.eof()){
        getline(entranceWayFile,entranceWayBuf);
        cout<<entranceWayBuf;
    }
    cout<<endl<<"��ѡ����ѧ��ʽ��";
    cin.clear();
    cin.sync();
    getline(cin,entranceWayChoice);
    if(entranceWayChoice.size()==0){
        temp.setEntranceWay("��ͨ��ѧ");
        cout<<"����Ч���룬�ѽ���ѧ��ʽ��ΪĬ��ֵ����ͨ��ѧ"<<endl;
    }else{
        entranceWayFile.clear();
        entranceWayFile.seekg(0,ios::beg);
        int entranceWayNum;
        while(!entranceWayFile.eof()){
            while(!isChoice(entranceWayChoice)){
                cout<<"�������������ѡ��";
                cin>>entranceWayChoice;
            }
            getline(entranceWayFile,entranceWayBuf);
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
        temp.setEntranceWay(entranceWayBuf.substr(entranceWayBuf.find_last_of(' '),entranceWayBuf.length()));
    }
    cout<<"��ѧ��ʽ¼��ɹ���"<<endl<<endl<<endl;
}

void setMajor(Student &temp){
    //����רҵ����
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"����רҵ�����ѧԺΪ��"<<temp.getCollege()<<endl;
    cout<<"��ѡ��רҵ���£�"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string majorBuf;
    string majorCollege;
    int majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    while(!majorFile.eof()){
        getline(majorFile,majorCollege);
        if(majorCollege.substr(2,majorCollege.find_first_of(' ')-2)==temp.getCollege()){
            cout<<majorCollege.substr(majorCollege.find_first_of(' ')+1,majorCollege.length());
        }
    }

    cout<<endl<<"��ѡ��";
    cin>>majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    string majorNum;
    vector<string> majors;
    while(!majorFile.eof()){
        getline(majorFile,majorBuf);
        if(majorBuf.substr(2,majorBuf.find_first_of(' ')-2)==temp.getCollege()){
            majorBuf=majorBuf.substr(majorBuf.find_first_of(' ')+1,majorBuf.length());
            splitString(majorBuf,majors," ");
        }
    }
    int i=0;
    while(1){
        majorNum=majors[i];
        if(majorChoice==atoi(majorNum.substr(0,2).c_str())){
            cout<<"��ѡ��"<<majorNum<<endl;
            goto here;
        }else if(i==majors.size()-1&&majorChoice!=atoi(majorNum.substr(0,1).c_str())){
            cout<<"�������������ѡ��";
            cin>>majorChoice;
            i=-1;
        }
        i++;
    }
    here:temp.setMajor(majorNum.substr(2,majorNum.length()));
    cout<<"רҵ¼��ɹ���"<<endl<<endl<<endl;
}

void setGrade(Student &temp){
    //�����꼶
    int grade;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"�����꼶�������������꼶��";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>grade;
    int numberYear=atoi(temp.getNumber().substr(2,2).c_str());
    if(grade!=2000+atoi(temp.getNumber().substr(2,2).c_str())){
        int tempChoice;
        cout<<"�����꼶��ѧ�����꼶��ͬ���Ƿ�ȷ��¼�룺1.��      2.��"<<endl;
        cin>>tempChoice;
        if(tempChoice==1){
            temp.setGrade(grade);
        }else{
            temp.setGrade(2000+atoi(temp.getNumber().substr(2,2).c_str()));
            cout<<"��ѡ��¼��ѧ�������!"<<endl;
        }
    }else{
        temp.setGrade(2000+atoi(temp.getNumber().substr(2,2).c_str()));
    }
    cout<<"�꼶¼��ɹ���"<<endl<<endl<<endl;
}

void setSchoolLength(Student &temp){
    //����ѧ��
    if(atoi(temp.getNumber().substr(0,2).c_str())==15){
        temp.setSchoolLength(5);
    }else if(atoi(temp.getNumber().substr(0,2).c_str())==29){
        temp.setSchoolLength(3);
    }else{
        temp.setSchoolLength(4);
    }
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"����רҵ��ѧ��������Ϊ��"<<temp.getSchoolLength()<<endl<<endl<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
}

void setTrainingLevel(Student &temp){
    //�����������
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    if(temp.getMajor()=="�о���רҵ"){
        temp.setTrainingLevel("�о���");
        cout<<endl<<"רҵΪ�о���רҵ\n¼��������Σ��о���"<<endl<<endl<<endl;
    }else{
        temp.setTrainingLevel("������");
        cout<<endl<<"רҵΪ����רҵ\n¼��������Σ�������"<<endl<<endl<<endl;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    }
}

void setClass(Student &temp){
    //���ð༶��
    string classNum;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"���ð༶�ţ����������ڰ༶��";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>classNum;
    int intClassNum=atoi(classNum.c_str());
    while(intClassNum<0||intClassNum>10){
        cout<<"�༶�������������������:";
        cin>>classNum;
        intClassNum=atoi(classNum.c_str());
    }
    temp.setClassNum(intClassNum);
    cout<<"�༶Ϊ��"<<intClassNum<<"�࣬�༶¼��ɹ���"<<endl<<endl<<endl;
}

void setCounsellor(Student &temp){
    //���ø���Ա
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"¼�븨��Ա��"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string major=temp.getMajor();
    string counsellorBuf;
    string counsellor;
    int exist=0;
    counsellorFile.clear();
    counsellorFile.seekg(0,ios::beg);
    while(!counsellorFile.eof()){
        getline(counsellorFile,counsellorBuf);
        if(counsellorBuf.substr(0,counsellorBuf.find_first_of(' '))==major){
            counsellor=counsellorBuf.substr(counsellorBuf.find_last_of(' ')+1,counsellorBuf.length());
            temp.setCounsellor(counsellor);
            exist=1;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cout<<"���רҵΪ��"<<major<<endl<<"��Ӧ����ԱΪ��"<<counsellor<<endl;
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            break;
        }
    }
    if(exist==0){
        cin>>counsellor;
        ofstream inCounsellorFile("counsellor.txt");
        inCounsellorFile<<major<<' '<<counsellor<<endl;
        temp.setCounsellor(counsellor);
        inCounsellorFile.close();
    }
    cout<<"����Ա¼��ɹ���"<<endl<<endl<<endl;
}

void search(){
    string key;
    string studentBuf;
    vector<string> splits;
    int find=0;
    int searchChoice;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"�ɲ��ҵ�ѧ����Ϣ��1.ѧ��    2.����    3.����    4.���֤��\n"
          "                  5.ѧԺ    6.רҵ"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"������ѡ��";
    cin>>searchChoice;
    if(searchChoice==1){
        searchChoice=0;
    }else if(searchChoice==2){
        searchChoice=1;
    }else if(searchChoice==3){
        searchChoice=5;
    }else if(searchChoice==4){
        searchChoice=8;
    }else if(searchChoice==5){
        searchChoice=12;
    }else if(searchChoice==6){
        searchChoice=13;
    }
    cout<<"����������ֶΣ�";
    cin>>key;
    cout<<endl<<endl<<"���ҽ�����£�"<<endl;
    studentFile.clear();
    studentFile.seekg(ios::beg);
    while(!studentFile.eof()){
        getline(studentFile,studentBuf);
        splitString(studentBuf,splits," ");
        if(key==splits[searchChoice]){
            find=1;
            cout<<studentBuf<<endl;
            break;
        }
        if(studentFile.eof()&&find==0){
            cout<<"�޶�Ӧѧ����Ϣ��"<<endl;
        }
    }
}

void change(){
    fstream changeFile("changeTemp.txt",ios::out|ios::in);
    changeFile.clear();
    changeFile.seekg(0,ios::beg);
    int changeChoice;
    string changeNum;
    string studentBuf;
    vector<string> splits;
    int find=0;
    int findStu=0;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"��������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>changeNum;
    studentFile.clear();
    studentFile.seekg(ios::beg);

    while(!studentFile.eof()){
        getline(studentFile,studentBuf);
        if(studentBuf.substr(0,9)==changeNum){
            find=1;
            findStu=1;
            cout<<"���ҵ���Ϣ���£�"<<endl;
            cout<<studentBuf<<endl;
            break;
        }
        else{
            changeFile<<studentBuf;
            //TODO debug�Ƿ��п���
        }
        if(studentFile.eof()&&find==0){
            cout<<"�޶�Ӧѧ����Ϣ��"<<endl;
            findStu=0;
        }
    }
    if(findStu){
        splitString(studentBuf,splits," ");
        Student temp;
        temp.setNumber(splits[0]);
        temp.setName(splits[1]);
        temp.setSex(splits[2]);
        temp.setCountry(splits[3]);
        temp.getBirthday().setDate(atoi(splits[4].substr(0,4).c_str()),atoi(splits[4].substr(5,2).c_str()),
                                   atoi(splits[4].substr(splits[4].find_last_of('.')+1,2).c_str()));
        temp.setNation(splits[5]);
        temp.setMarrige(splits[6]);
        temp.setPoliticsStatus(splits[7]);
        temp.setIdNumber(splits[8]);
        temp.setType(splits[9]);
        temp.getEnrollmentDate().setDate(atoi(splits[10].substr(0,4).c_str()),atoi(splits[10].substr(5,2).c_str()),
                                         atoi(splits[10].substr(splits[10].find_last_of('.')+1).c_str()));
        temp.setEntranceWay(splits[11]);
        temp.setCollege(splits[12]);
        temp.setMajor(splits[13]);
        temp.setGrade(atoi(splits[14].c_str()));
        temp.setSchoolLength(atoi(splits[15].c_str()));
        temp.setTrainingLevel(splits[16]);
        temp.setClassNum(atoi(splits[17].c_str()));
        temp.setCounsellor(splits[18]);
        cout<<"��ѡ�޸��1.����      2.����      3.����״��      4.������ò\n"
              "            5.ѧ������  6.��ѧ��ʽ  7.�꼶          8.�༶\n"
              "������ѡ��";
        cin>>changeChoice;
        while(changeChoice<1||changeChoice>8){
            cout<<"ѡ��������������룺";
            cin>>changeChoice;
        }
        string changeItem;
        switch(changeChoice){
            case 1:
                setName(temp);
                break;
            case 2:
                setNation(temp);
                break;
            case 3:
                setMarrige(temp);
                break;
            case 4:
                setPoliticStatus(temp);
                break;
            case 5:
                setType(temp);
                break;
            case 6:
                setEntranceWay(temp);
                break;
            case 7:
                setGrade(temp);
                break;
            case 8:
                setClass(temp);
                break;
        }
        changeFile<<temp.getNumber()<<' '<<temp.getName()<<' '<<temp.getSex()<<' '<<temp.getCountry()<<' '
                  <<temp.getBirthday().getYear()<<'.'<<temp.getBirthday().getMonth()<<'.'
                  <<temp.getBirthday().getDay()<<' '<<temp.getNation()<<' '<<temp.getMarrige()<<' '
                  <<temp.getPoliticsStatus()<<' '<<temp.getIdNumber()<<' '<<temp.getType()<<' '
                  <<temp.getEnrollmentDate().getYear()<<'.'<<temp.getEnrollmentDate().getMonth()
                  <<'.'<<temp.getEnrollmentDate().getDay()<<' '<<temp.getEntranceWay()<<' '
                  <<temp.getCollege()<<' '<<temp.getMajor()<<' '<<temp.getGrade()<<' '
                  <<temp.getSchoolLength()<<' '<<temp.getTrainingLevel()
                  <<' '<<temp.getClassNum()<<' '<<temp.getCounsellor()<<endl;
        ofstream studentFile("student.txt",ios::trunc);
        string tempBuf;
        changeFile.clear();
        changeFile.seekg(0,ios::beg);
        while(!changeFile.eof()){
            getline(changeFile,tempBuf);
            studentFile<<tempBuf;
        }
        cout<<"�޸�ѧ����Ϣ������ɹ���"<<endl<<endl;
    }
}

void deleteInfo(){
    fstream deleteFile("deleteTemp.txt",ios::in|ios::out);
    string deleteNum;
    string studentBuf;
    int find=0;
    int findStu=0;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"��������Ҫ��ѧ��ѧ�ţ�";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>deleteNum;
    studentFile.clear();
    studentFile.seekg(ios::beg);
    while(!studentFile.eof()){
        getline(studentFile,studentBuf);
        if(studentBuf.substr(0,9)==deleteNum){
            find=1;
            findStu=1;
            cout<<"���ҵ���Ϣ���£�"<<endl;
            cout<<studentBuf<<endl;
            break;
        }
        else{
            deleteFile<<studentBuf;
            //TODO debug�Ƿ��п���
        }
        if(studentFile.eof()&&find==0){
            cout<<"�޶�Ӧѧ����Ϣ��"<<endl;
            findStu=0;
        }
    }
    if(findStu){
        char deleteChoice;
        cout<<"�Ƿ�Ҫɾ��ѧ����Ϣ(yȷ�ϣ�������ȡ��)��";
        cin>>deleteChoice;
        if(isupper(deleteChoice)){
            tolower(deleteChoice);
        }
        if(deleteChoice=='y'){
            ofstream studentFile("student.txt",ios::trunc);
            string tempBuf;
            deleteFile.clear();
            deleteFile.seekg(0,ios::beg);
            while(!deleteFile.eof()){
                getline(deleteFile,tempBuf);
                studentFile<<tempBuf;
            }
            cout<<"ɾ��ѧ����Ϣ������ɹ���"<<endl<<endl;
        }else{
            cout<<"��ȡ�����������˵���"<<endl<<endl;
        }
    }else{
        cout<<"δ�ҵ����������˵���"<<endl<<endl;
    }
}

void analyze(){
    string key;
    string studentBuf;
    vector<string> splits;
    int find=0;
    int itemNum=0;
    int searchChoice;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"��������Ҫ���ҵ�ѧ����Ϣ��1.ѧ��    2.����    3.����    4.���֤��\n"
          "                          5.ѧԺ    6.רҵ"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"������ѡ��";
    cin>>searchChoice;
    if(searchChoice==1){
        searchChoice=0;
    }else if(searchChoice==2){
        searchChoice=1;
    }else if(searchChoice==3){
        searchChoice=5;
    }else if(searchChoice==4){
        searchChoice=8;
    }else if(searchChoice==5){
        searchChoice=12;
    }else if(searchChoice==6){
        searchChoice=13;
    }
    cout<<"����������ֶΣ�";
    cin>>key;
    cout<<endl<<endl<<"���ҽ�����£�"<<endl;
    studentFile.clear();
    studentFile.seekg(ios::beg);
    while(!studentFile.eof()){
        getline(studentFile,studentBuf);
        splitString(studentBuf,splits," ");
        if(key==splits[searchChoice]){
            find=1;
            itemNum++;
            cout<<studentBuf<<endl;
            break;
        }
        if(studentFile.eof()&&find==0){
            cout<<"�޶�Ӧѧ����Ϣ��"<<endl;
        }
    }

}

bool comp1(Student &a,Student &b){
    return a.getNumber()<b.getNumber();
}

bool comp2(Student &a,Student &b){
    return a.getGrade()<b.getGrade();
}

void sort(){
    string sortBuf;
    Student temp;
    int sortChoice;
    vector<Student> students;
    vector<string> splits;
    studentFile.clear();
    studentFile.seekg(0,ios::beg);
    while(!studentFile.eof()){
        getline(studentFile,sortBuf);
        splitString(sortBuf,splits," ");
        temp.setNumber(splits[0]);
        temp.setName(splits[1]);
        temp.setSex(splits[2]);
        temp.setCountry(splits[3]);
        temp.getBirthday().setDate(atoi(splits[4].substr(0,4).c_str()),atoi(splits[4].substr(5,2).c_str()),
                                   atoi(splits[4].substr(splits[4].find_last_of('.')+1,2).c_str()));
        temp.setNation(splits[5]);
        temp.setMarrige(splits[6]);
        temp.setPoliticsStatus(splits[7]);
        temp.setIdNumber(splits[8]);
        temp.setType(splits[9]);
        temp.getEnrollmentDate().setDate(atoi(splits[10].substr(0,4).c_str()),atoi(splits[10].substr(5,2).c_str()),
                                         atoi(splits[10].substr(splits[10].find_last_of('.')+1).c_str()));
        temp.setEntranceWay(splits[11]);
        temp.setCollege(splits[12]);
        temp.setMajor(splits[13]);
        temp.setGrade(atoi(splits[14].c_str()));
        temp.setSchoolLength(atoi(splits[15].c_str()));
        temp.setTrainingLevel(splits[16]);
        temp.setClassNum(atoi(splits[17].c_str()));
        temp.setCounsellor(splits[18]);
        students.push_back(temp);
    }
    ofstream studentFile("student.txt",ios::trunc);
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"����ʽ��  1.ѧ��    2.�꼶\n"
          "��ѡ��";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>sortChoice;
    while(sortChoice<1||sortChoice>2){
        cout<<"ѡ�����������ѡ��";
        cin>>sortChoice;
    }
    if(sortChoice==1){
        sort(students.begin(),students.end(),comp1);
    }else if(sortChoice==2){
        sort(students.begin(),students.end(),comp2);
    }

    for(int i=0;i<students.size();i++){
        studentFile<<students[i].getNumber()<<' '<<students[i].getName()<<' '<<students[i].getSex()<<' '<<students[i].getCountry()<<' '
                  <<students[i].getBirthday().getYear()<<'.'<<students[i].getBirthday().getMonth()<<'.'
                  <<students[i].getBirthday().getDay()<<' '<<students[i].getNation()<<' '<<students[i].getMarrige()<<' '
                  <<students[i].getPoliticsStatus()<<' '<<students[i].getIdNumber()<<' '<<students[i].getType()<<' '
                  <<students[i].getEnrollmentDate().getYear()<<'.'<<students[i].getEnrollmentDate().getMonth()
                  <<'.'<<students[i].getEnrollmentDate().getDay()<<' '<<students[i].getEntranceWay()<<' '
                  <<students[i].getCollege()<<' '<<students[i].getMajor()<<' '<<students[i].getGrade()<<' '
                  <<students[i].getSchoolLength()<<' '<<students[i].getTrainingLevel()
                  <<' '<<students[i].getClassNum()<<' '<<students[i].getCounsellor()<<endl;
    }

    cout<<"����ɹ���"<<endl<<endl<<endl;
}

void print(){
    string printBuf;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"ѧ����Ϣ���£�"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    studentFile.clear();
    studentFile.seekg(0,ios::beg);
    while(studentFile.eof()){
        getline(studentFile,printBuf);
        cout<<printBuf<<endl;
    }
    cout<<"����ɹ���"<<endl<<endl<<endl;
}

/*------------------Student��Ա��������----------------------*/

void splitString(string s,vector<string> &v,string c){
    int pos1,pos2;
    pos2=s.find(c);
    pos1=0;
    while(string::npos!=pos2){
        if(pos1!=pos2){
            v.push_back(s.substr(pos1,pos2-pos1));
        }
        pos1=pos2+c.size();
        pos2=s.find(c,pos1);
    }
    if(pos1!=s.length())
        v.push_back(s.substr(pos1));
}

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

bool isChoice(string choice){
    if(includeChinese(choice)){
        return false;
    }
    for(int i=0;i<choice.length();i++){
        if(ispunct(choice[i])||isalpha(choice[i])){
            return false;
        }
    }
    if(atoi(choice.c_str())<=0){
        return false;
    }else{
        return true;
    }
}

int main(){
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    GetLocalTime(&sysTime);

    vector<Student> all;
    int choice;
    while(1){
        menu();
        choice=getch();
        choice-=48;
        cout<<choice<<endl;
        switch(choice){
            case 1:{
                int readChoice;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                cout<<"���뷽ʽ��  1.��������    2.�ļ�����\n"
                      "��ѡ��";
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                cin>>readChoice;
                while(readChoice<1||readChoice>2){
                    cout<<"ѡ�����������ѡ��";
                    cin>>readChoice;
                }
                if(readChoice==1){
                    Student temp;
                    setNumber(temp);
                    setName(temp);
                    setSex(temp);
                    setCountry(temp);
                    setBirthday(temp);
                    setNation(temp);
                    setMarrige(temp);
                    setPoliticStatus(temp);
                    setIDNumber(temp);
                    setType(temp);
                    setEnrollmentDate(temp);
                    setEntranceWay(temp);
                    setMajor(temp);
                    setGrade(temp);
                    setSchoolLength(temp);
                    setTrainingLevel(temp);
                    setClass(temp);
                    setCounsellor(temp);
                    studentFile<<temp.getNumber()<<' '<<temp.getName()<<' '<<temp.getSex()<<' '<<temp.getCountry()<<' '
                               <<temp.getBirthday().getYear()<<'.'<<temp.getBirthday().getMonth()<<'.'
                               <<temp.getBirthday().getDay()<<' '<<temp.getNation()<<' '<<temp.getMarrige()<<' '
                               <<temp.getPoliticsStatus()<<' '<<temp.getIdNumber()<<' '<<temp.getType()<<' '
                               <<temp.getEnrollmentDate().getYear()<<'.'<<temp.getEnrollmentDate().getMonth()
                               <<'.'<<temp.getEnrollmentDate().getDay()<<' '<<temp.getEntranceWay()<<' '
                               <<temp.getCollege()<<' '<<temp.getMajor()<<' '<<temp.getGrade()<<' '
                               <<temp.getSchoolLength()<<' '<<temp.getTrainingLevel()
                               <<' '<<temp.getClassNum()<<' '<<temp.getCounsellor()<<endl;
                }else if(readChoice==2){
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                    cout<<"�ļ�������Ϣ�����fileReadIn.txt�У�����ȡ˳����룬�ո����ÿ���ֶ�"<<endl;
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);

                }
                break;
            }
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
                print();
                break;
            case 8:
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                cout<<"ллʹ�á�"<<endl;
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                goto end;
            default:
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                cout<<"ѡ�����������ѡ��!"<<endl;
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                break;
        }
    }
    end:exit(1);
}