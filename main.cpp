#include<iostream>
#include<vector>
#include<conio.h>
#include<string>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<fstream>

using namespace std;

//全局文件指针变量
ifstream collegeFile("college.txt");
ifstream countryFile("country.txt");
ifstream nationFile("nation.txt");
ifstream politicsStatusFile("politicsStatus.txt");
ifstream adminDivisionFile("administrativeDivision.txt");
ifstream typeFile("type.txt");
ifstream entranceWayFile("entranceWay.txt");
ifstream majorFile("major.txt");
ifstream counsellorFile("counsellor.txt");

//获取系统时间
SYSTEMTIME sysTime={0};

bool includeChinese(string);
void splitString(string,vector<string> &,string);

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
    if(judge(year,month,day)==1){
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
//Date类结束

//Student类开始
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

    void setBirthday(const Date birthday){
        Student::birthday=birthday;
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
//Student类结束

//Date类关联函数
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
    cout<<"请选择：";
}

void setNumber(Student &temp){
    //设置学号
    string number;
    cout<<"请输入学号(必须为9位)：";
    cin>>number;
    int numberRight=1;
    do{
        numberRight=1;
        if(number.length()!=9){//判断学号长度
            numberRight=0;
        }else{
            string tempCollege=number.substr(0,2);//判断学院是否正确
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
    temp.getEnrollmentDate().setYear(sysTime.wYear);
    temp.setNumber(number);
    cout<<"学号录入成功！"<<endl<<endl<<endl;
}

void setName(Student &temp){
    //设置姓名
    string name;
    cout<<"请输入姓名(2-20个汉字或40个以内字母)：";
    cin>>name;
    bool nameRight=1;
    while(1){
        if(includeChinese(name)){
            for(int i=0;i<name.length();i++){
                if(isalpha(name[i])||ispunct(name[i])||isdigit(name[i])){
                    cout<<"姓名中不能同时含有中文和其他字符！"<<endl;
                    nameRight=false;
                    break;
                }
            }
            if(name.length()<4||name.length()>40){
                nameRight=false;
                cout<<"姓名长度错误！"<<endl;
            }
        }else{
            for(int i=0;i<name.length();i++){
                if(!isalpha(name[i])){
                    nameRight=false;
                    cout<<"姓名中不能含有除中文和字母的其他字符！"<<endl;
                    break;
                }
            }
            if(name.length()<=0||name.length()>40){
                nameRight=false;
                cout<<"姓名长度错误！"<<endl;
            }
        }
        if(nameRight==false){
            cout<<"请重新输入：";
            cin>>name;
            nameRight=true;
        }else{
            temp.setName(name);
            break;
        }
    }
    cout<<"姓名录入成功！"<<endl<<endl<<endl;
}

void setSex(Student &temp){
    //设置性别
    int sex;
    cout<<"请选择性别(男/女)："<<endl<<"1.男   2.女"<<endl;
    cin>>sex;
    while(sex<1||sex>2){
        cout<<"输入错误，请重新输入：";
        cin>>sex;
    }
    if(sex==1){
        temp.setSex("男");
    }else if(sex==2){
        temp.setSex("女");
    }
    cout<<"性别录入成功！"<<endl<<endl<<endl;
}

void setCountry(Student &temp){
    //设置国别
    cout<<"国籍录入，可选择国籍如下："<<endl;
    string countryBuf;
    int item=0;
    string countryChoice;
    while(!countryFile.eof()){
        getline(countryFile,countryBuf);
        cout<<left<<setw(30)<<countryBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择国籍：";
    cin.clear();
    cin.sync();
    getline(cin,countryChoice);
    if(countryChoice.size()==0){
        temp.setCountry("中国");
        cout<<"无有效输入，已将国籍设为默认值：中国"<<endl;
    }else{
        countryFile.clear();
        countryFile.seekg(0,ios::beg);
        int countryNum;
        while(!countryFile.eof()){
            getline(countryFile,countryBuf);
            countryNum=atoi(countryBuf.substr(0,3).c_str());
            if(atoi(countryChoice.c_str())==countryNum){
                cout<<"已选择："<<countryBuf<<endl;
                temp.setCountry(countryBuf.substr(8,countryBuf.length()));
                break;
            }else if(countryFile.eof()&&atoi(countryChoice.c_str())!=countryNum){
                cout<<"输入错误，请重新选择：";
                cin>>countryChoice;
                countryFile.clear();
                countryFile.seekg(0,ios::beg);
            }
        }
    }
    cout<<"国籍录入成功！"<<endl<<endl<<endl;
}

void setBirthday(Student &temp){
    //设置出生日期
    string birthday;
    cout<<"请输入出生日期：";
    cin>>birthday;
    int birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());//出生日期分割，并将其转化为int
    int birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
    int birthD=atoi(birthday.substr(birthday.find_last_of('.')+1,birthday.length()).c_str());
    while(!(judge(birthY,birthM,birthD)&&(sysTime.wYear-birthY)>=10&&(sysTime.wYear-birthY)<=100)){
        cout<<"出生日期输入错误，请重新输入：";
        cin>>birthday;
        birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());
        birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
        birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    }
    temp.getBirthday().setDate(birthY,birthM,birthD);
    cout<<"出生日期录入成功！"<<endl<<endl<<endl;
}

void setNation(Student &temp){
    //设置民族
    int item;
    cout<<"民族录入，可选择民族如下："<<endl;
    string nationBuf;
    item=0;
    string nationChoice;
    while(!nationFile.eof()){
        getline(nationFile,nationBuf);
        cout<<left<<setw(30)<<nationBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择民族：";
    cin.clear();
    cin.sync();
    getline(cin,nationChoice);
    if(nationChoice.size()==0){
        temp.setNation("汉族");
        cout<<"无有效输入，已将民族设为默认值：汉族"<<endl;
    }else{
        nationFile.clear();
        nationFile.seekg(0,ios::beg);
        int nationNum;
        while(!nationFile.eof()){
            getline(nationFile,nationBuf);
            nationNum=atoi(nationBuf.substr(0,nationBuf.find_first_of('\t')).c_str());
            if(atoi(nationChoice.c_str())==nationNum){
                cout<<"已选择："<<nationBuf<<endl;
                temp.setNation(nationBuf.substr(nationBuf.find_last_of('\t'),nationBuf.length()));
                break;
            }else if(nationFile.eof()&&atoi(nationChoice.c_str())!=nationNum){
                cout<<"输入错误，请重新选择：";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
        }
    }
    cout<<"民族录入成功！"<<endl<<endl<<endl;
}

void setMarrige(Student &temp){
    string marrige;
    //设置婚姻状况
    cout<<"请选择婚姻状况："<<endl<<"1.未婚   2。已婚    3.丧偶    4.离婚    9.其他"<<endl;
    cin.clear();
    cin.sync();
    getline(cin,marrige);
    if(marrige.size()!=0){
        int int_marrige=atoi(marrige.c_str());
        while(int_marrige!=1&&int_marrige!=2&&int_marrige!=3&&int_marrige!=4&&int_marrige!=9){
            cout<<"输入错误，请重新输入：";
            cin>>marrige;
            int_marrige=atoi(marrige.c_str());
        }
        if(int_marrige==1){
            temp.setMarrige("未婚");
            cout<<"已选择：未婚"<<endl;
        }else if(int_marrige==2){
            temp.setMarrige("已婚");
            cout<<"已选择：已婚"<<endl;
        }else if(int_marrige==3){
            temp.setMarrige("丧偶");
            cout<<"已选择：丧偶"<<endl;
        }else if(int_marrige==4){
            temp.setMarrige("离婚");
            cout<<"已选择：离婚"<<endl;
        }else if(int_marrige==9){
            temp.setMarrige("其他");
            cout<<"已选择：其他"<<endl;
        }
    }else{
        temp.setMarrige("未婚");
        cout<<"无有效输入，已将婚姻状况设为默认值：未婚"<<endl;
    }
    cout<<"婚姻状况录入成功！"<<endl<<endl<<endl;
}

void setPoliticStatus(Student &temp){
    //设置政治面貌
    cout<<"政治面貌，可选择政治面貌如下："<<endl;
    string politicsStatusBuf;
    int item=0;
    string politicsStatusChoice;
    while(!politicsStatusFile.eof()){
        getline(politicsStatusFile,politicsStatusBuf);
        cout<<left<<setw(30)<<politicsStatusBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择政治面貌：";
    cin.clear();
    cin.sync();
    getline(cin,politicsStatusChoice);
    if(politicsStatusChoice.size()==0){
        temp.setPoliticsStatus("共青团员");
        cout<<"无有效输入，已将政治面貌设为默认值：共青团员"<<endl;
    }else{
        politicsStatusFile.clear();
        politicsStatusFile.seekg(0,ios::beg);
        int politicsStatusNum;
        while(!politicsStatusFile.eof()){
            getline(politicsStatusFile,politicsStatusBuf);
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
        temp.setPoliticsStatus(
                politicsStatusBuf.substr(politicsStatusBuf.find_last_of(' '),politicsStatusBuf.length()));
    }
    cout<<"政治面貌录入成功！"<<endl<<endl<<endl;
}

void setIDNumber(Student &temp){
    //设置身份证号
    string IDNumber;
    if(temp.getCountry()!="中国"){
        cout<<"国籍信息为非中国，身份证号设为空！"<<endl<<endl<<endl;
        temp.setIdNumber("0");
    }else{
        while(1){
            int isIdNumberRight=1;
            cout<<"请输入身份证号：";
            cin.clear();
            cin.sync();
            cin>>IDNumber;

            //判断身份证号长度
            if(IDNumber.length()!=18){
                cout<<"身份证号长度错误，";
                isIdNumberRight=0;
            }

            //判断行政区划
            if(isIdNumberRight==1){
                string adminDivisionBuf;
                int adminDivisionNum;
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
                        cout<<"行政区划错误，";
                        isIdNumberRight=0;
                        adminDivisionFile.clear();
                        adminDivisionFile.seekg(0,ios::beg);
                    }
                }
            }

            //判断出生日期
            if(isIdNumberRight==1){
                int IdbirthY=atoi(IDNumber.substr(6,4).c_str());//提取身份证出生日期，并将其转化为int
                int IdbirthM=atoi(IDNumber.substr(10,2).c_str());
                int IdbirthD=atoi(IDNumber.substr(12,2).c_str());
                if(IdbirthY!=temp.getBirthday().getYear()||IdbirthM!=temp.getBirthday().getMonth()
                   ||IdbirthD!=temp.getBirthday().getDay()){
                    isIdNumberRight=0;
                    cout<<"出生日期错误，";
                }
            }

            //判断顺序码
            int intSex;
            if(temp.getSex()=="男"){
                intSex=1;
            }else if(temp.getSex()=="女"){
                intSex=0;
            }
            if(isIdNumberRight==1){
                int sequenceNum=atoi(IDNumber.substr(14,3).c_str());
                if((sequenceNum%2)==intSex){
                    isIdNumberRight=1;
                }else{
                    isIdNumberRight=0;
                    cout<<"性别错误，";
                }
            }

            //判断校验位
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
                    cout<<"检验位错误，";
                }
            }
            if(isIdNumberRight==1){
                temp.setIdNumber(IDNumber);
                cout<<"身份证号录入成功！"<<endl<<endl<<endl;
                break;
            }
        }

        //TODO 判断是否重复身份证号
    }
}

void setType(Student &temp){
    //设置学生类别
    cout<<"设置学生类别，可选择类别如下："<<endl;
    string typeBuf;
    int item=0;
    string typeChoice;
    while(!typeFile.eof()){
        getline(typeFile,typeBuf);
        cout<<left<<setw(15)<<typeBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择学生类别：";
    cin.clear();
    cin.sync();
    getline(cin,typeChoice);
    if(typeChoice.size()==0){
        temp.setType("无");
        cout<<"无有效输入，已将学生类别设为默认值：无"<<endl;
    }else{
        typeFile.clear();
        typeFile.seekg(0,ios::beg);
        int typeNum;
        while(!typeFile.eof()){
            getline(typeFile,typeBuf);
            typeNum=(typeBuf[0]-48);
            if(atoi(typeChoice.c_str())==typeNum){
                cout<<"已选择："<<typeBuf<<endl;
                break;
            }else if(typeFile.eof()&&atoi(typeChoice.c_str())!=typeNum){
                cout<<"输入错误，请重新选择：";
                cin>>typeChoice;
                typeFile.clear();
                typeFile.seekg(0,ios::beg);
            }
        }
        temp.setType(typeBuf.substr(typeBuf.find_last_of(' '),typeBuf.length()));
    }
    cout<<"学生类别录入成功！"<<endl<<endl<<endl;
}

void setEnrollmentDate(Student &temp){
    //设置入学年月
    string enrollmentDate;
    cout<<"请输入入学日期：";
    cin>>enrollmentDate;
    int enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());//出生日期分割，并将其转化为int
    int enrollM=atoi(
            enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
    int enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.length()).c_str());
    while(!(judge(enrollY,enrollM,enrollD)&&enrollM>=8&&enrollM<=10)){
        cout<<"入学日期输入错误，请重新输入：";
        cin>>enrollmentDate;
        enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());
        enrollM=atoi(
                enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
        enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.length()).c_str());
    }
    temp.getEnrollmentDate().setDate(enrollY,enrollM,enrollD);
    cout<<"入学日期录入成功！"<<endl<<endl<<endl;
}

void setEntranceWay(Student &temp){
    //设置入学方式
    cout<<"设置入学方式，可选择方式如下："<<endl;
    string entranceWayBuf;
    int item=0;
    string entranceWayChoice;
    while(!entranceWayFile.eof()){
        getline(entranceWayFile,entranceWayBuf);
        cout<<left<<setw(15)<<entranceWayBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择入学方式：";
    cin.clear();
    cin.sync();
    getline(cin,entranceWayChoice);
    if(entranceWayChoice.size()==0){
        temp.setEntranceWay("普通入学");
        cout<<"无有效输入，已将入学方式设为默认值：普通入学"<<endl;
    }else{
        entranceWayFile.clear();
        entranceWayFile.seekg(0,ios::beg);
        int entranceWayNum;
        while(!entranceWayFile.eof()){
            getline(entranceWayFile,entranceWayBuf);
            entranceWayNum=(entranceWayBuf[0]-48);
            if(atoi(entranceWayChoice.c_str())==entranceWayNum){
                cout<<"已选择："<<entranceWayBuf<<endl;
                break;
            }else if(entranceWayFile.eof()&&atoi(entranceWayChoice.c_str())!=entranceWayNum){
                cout<<"输入错误，请重新选择：";
                cin>>entranceWayChoice;
                entranceWayFile.clear();
                entranceWayFile.seekg(0,ios::beg);
            }
        }
        temp.setEntranceWay(entranceWayBuf.substr(entranceWayBuf.find_last_of(' '),entranceWayBuf.length()));
    }
    cout<<"入学方式录入成功！"<<endl<<endl<<endl;
}

void setMajor(Student &temp){
    //设置专业名称
    cout<<"设置专业，你的学院为："<<temp.getCollege()<<endl;
    cout<<"可选择专业如下："<<endl;
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

    cout<<endl<<"请选择：";
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
            cout<<"已选择："<<majorNum<<endl;
            goto here;
        }else if(i==majors.size()-1&&majorChoice!=atoi(majorNum.substr(0,1).c_str())){
            cout<<"输入错误，请重新选择：";
            cin>>majorChoice;
            i=-1;
        }
        i++;
    }
    here:temp.setMajor(majorNum.substr(2,majorNum.length()));
    cout<<"专业录入成功！"<<endl<<endl<<endl;
}

void setGrade(Student &temp){
    //设置年级
    int grade;
    cout<<"设置年级，请输入所在年级：";
    cin>>grade;
    int numberYear=atoi(temp.getNumber().substr(2,2).c_str());
    if(grade!=2000+atoi(temp.getNumber().substr(2,2).c_str())){
        int tempChoice;
        cout<<"输入年级与学号中年级不同，是否确定录入：1.是      2.否"<<endl;
        cin>>tempChoice;
        if(tempChoice==1){
            temp.setGrade(grade);
        }else{
            temp.setGrade(2000+atoi(temp.getNumber().substr(2,2).c_str()));
            cout<<"已选择录入学号中年份!"<<endl;
        }
    }else{
        temp.setGrade(2000+atoi(temp.getNumber().substr(2,2).c_str()));
    }
    cout<<"年级录入成功！"<<endl<<endl<<endl;
}

void setSchoolLength(Student &temp){
    //设置学制
    if(atoi(temp.getNumber().substr(0,2).c_str())==15){
        temp.setSchoolLength(5);
    }else if(atoi(temp.getNumber().substr(0,2).c_str())==29){
        temp.setSchoolLength(3);
    }else{
        temp.setSchoolLength(4);
    }
}

void setTrainingLevel(Student &temp){
    //设置培养层次
    if(temp.getMajor()=="研究生专业"){
        temp.setTrainingLevel("研究生");
        cout<<endl<<"专业为研究生专业\n录入培养层次：研究生"<<endl<<endl<<endl;
    }else{
        temp.setTrainingLevel("本科生");
        cout<<endl<<"专业为本科专业\n录入培养层次：本科生"<<endl<<endl<<endl;
    }
}

void setClass(Student &temp){
    //设置班级号
    string classNum;
    cout<<"设置班级号，请输入所在班级：";
    cin>>classNum;
    int intClassNum=atoi(classNum.c_str());
    while(intClassNum<0||intClassNum>10){
        cout<<"班级号输入错误，请重新输入:";
        cin>>classNum;
        intClassNum=atoi(classNum.c_str());
    }
    temp.setClassNum(intClassNum);
    cout<<"班级为："<<intClassNum<<"班，班级录入成功！"<<endl<<endl<<endl;
}

void setCounsellor(Student &temp){
    //设置辅导员
    cout<<"录入辅导员："<<endl;
    string major=temp.getMajor();
    string counsellorBuf;
    string counsellor;
    int exist=0;
    while(!counsellorFile.eof()){
        getline(counsellorFile,counsellorBuf);
        if(counsellorBuf.substr(0,counsellorBuf.find_first_of(' '))==major){
            counsellor=counsellorBuf.substr(counsellorBuf.find_last_of(' '),counsellorBuf.length());
            temp.setCounsellor(counsellor);
            exist=1;
            cout<<"你的专业为："<<major<<endl<<"对应辅导员为："<<counsellor<<endl;
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
    cout<<"辅导员录入成功"<<endl<<endl<<endl;
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

void print(){

}

/*------------------Student成员函数结束----------------------*/

void splitString(string s,vector<string> &v,string c){
    int pos1,pos2;
    pos2=s.find(c);
    pos1=0;
    while(string::npos!=pos2){
        v.push_back(s.substr(pos1,pos2-pos1));
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
        if(temp&0x80||tempNext&0x80){//如果字符高位为1且下一字符高位也是1则有中文字符
            return true;
        }
    }
    return false;
}

int main(){
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
                ofstream studentFile("student.txt");
                studentFile<<temp.getNumber()<<' '<<temp.getName()<<' '<<temp.getSex()<<' '<<temp.getCountry()<<' '
                           <<temp.getBirthday().getYear()<<'.'<<temp.getBirthday().getMonth()<<'.'
                           <<temp.getBirthday().getDay()<<' '<<temp.getNation()<<' '<<temp.getMarrige()<<' '
                           <<temp.getPoliticsStatus()<<' '<<temp.getIdNumber()<<' '<<temp.getType()<<' '
                           <<temp.getEnrollmentDate().getYear()<<'.'<<temp.getEnrollmentDate().getMonth()
                           <<'.'<<temp.getEnrollmentDate().getDay()<<' '<<temp.getEntranceWay()<<' '
                           <<temp.getCollege()<<' '<<temp.getMajor()<<' '<<temp.getGrade()<<' '
                           <<temp.getSchoolLength()<<' '<<temp.getTrainingLevel()
                           <<' '<<temp.getClassNum()<<' '<<temp.getCounsellor()<<endl;
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
                cout<<"谢谢使用。"<<endl;
                goto end;
            default:
                cout<<"选择错误，请重新选择!"<<endl;
                break;
        }
    }
    end:exit(1);
}