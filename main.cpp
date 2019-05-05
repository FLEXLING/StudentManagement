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

//全局文件指针变量
ifstream collegeFile("221801201_凌铧钦_college.txt");
ifstream countryFile("221801201_凌铧钦_country.txt");
ifstream nationFile("221801201_凌铧钦_nation.txt");
ifstream politicsStatusFile("221801201_凌铧钦_politicsStatus.txt");
ifstream adminDivisionFile("221801201_凌铧钦_administrativeDivision.txt");
ifstream typeFile("221801201_凌铧钦_type.txt");
ifstream entranceWayFile("221801201_凌铧钦_entranceWay.txt");
ifstream majorFile("221801201_凌铧钦_major.txt");
ifstream counsellorFile("221801201_凌铧钦_counsellor.txt");
fstream studentFile("221801201_凌铧钦_student.txt");
ifstream fileReadIn("221801201_凌铧钦_fileReadIn.txt");

//获取系统时间
SYSTEMTIME sysTime={0};

//CMD颜色控制
HANDLE hOut;

//其余函数声明
bool includeChinese(string);
void splitString(string,vector<string> &,string);
bool isChoice(string);
int judge(int,int,int);

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
    string number;//学号
    string name;//姓名
    string sex;//性别
    string country;//国家
    Date birthday;//生日
    string nation;//民族
    string marrige;//婚姻状况
    string politicsStatus;//政治面貌
    string IDNumber;//身份证号
    string type;//学生类型
    Date enrollmentDate;//入学日期
    string entranceWay;//入学方式
    string college;//学院
    string major;//专业
    int schoolLength;//学制
    string trainingLevel;//培养层次
    int grade;//年级
    int classNum;//班级
    string counsellor;//辅导员
};
//Student类结束

//Date类关联函数
int judge(int y,int m,int d){//判断日期是否合法
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


//主菜单显示
void menu(){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);//设置CMD蓝色（下同）
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
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);//设置CMD白色（下同）
}


//设置学号
void setNumber(Student &temp){
    string number;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入学号(必须为9位)：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
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
            collegeFile.seekg(0,ios::beg);//使学号文件指针指向开头（下同）
            while(!collegeFile.eof()){//遍历文件查找学院
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
    temp.getEnrollmentDate().setYear(sysTime.wYear);//设置入学年份
    temp.setNumber(number);//设置学号
    cout<<"学号录入成功！"<<endl<<endl<<endl;
}

//设置姓名
void setName(Student &temp){
    string name;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入姓名(2-20个汉字或40个以内字母)：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>name;
    bool nameRight=1;
    while(1){
        if(includeChinese(name)){
            //中文情况
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
            //英文情况
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

//设置性别
void setSex(Student &temp){
    int sex;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请选择性别(男/女)："<<endl<<"1.男   2.女"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
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

//设置国籍
void setCountry(Student &temp){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"国籍录入，可选择国籍如下："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string countryBuf;
    int item=0;
    string countryChoice;
    countryFile.clear();
    countryFile.seekg(0,ios::beg);
    //输出文件中国家
    while(!countryFile.eof()){
        getline(countryFile,countryBuf);
        cout<<left<<setw(30)<<countryBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    //读入并设置
    cout<<endl<<"请选择国籍：";
    cin.clear();
    cin.sync();
    getline(cin,countryChoice);
    if(countryChoice.size()==0){//设为默认值
        temp.setCountry("中国");
        cout<<"无有效输入，已将国籍设为默认值：中国"<<endl;
    }else{
        countryFile.clear();
        countryFile.seekg(0,ios::beg);
        int countryNum;
        while(!countryFile.eof()){//遍历文件对应输入序号
            while(!isChoice(countryChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>countryChoice;
                countryFile.clear();
                countryFile.seekg(0,ios::beg);
            }
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

//设置出生日期
void setBirthday(Student &temp){
    string birthday;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入出生日期：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>birthday;
    int birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());//出生日期分割，并将其转化为int
    int birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
    int birthD=atoi(birthday.substr(birthday.find_last_of('.')+1,birthday.length()).c_str());
    while(!(judge(birthY,birthM,birthD)&&(sysTime.wYear-birthY)>=10&&(sysTime.wYear-birthY)<=100)){//判断错误输入
        cout<<"出生日期输入错误，请重新输入：";
        cin>>birthday;
        birthY=atoi(birthday.substr(0,birthday.find_first_of('.')).c_str());
        birthM=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.find_last_of('.')).c_str());
        birthD=atoi(birthday.substr(birthday.find_first_of('.')+1,birthday.length()).c_str());
    }
    temp.getBirthday().setDate(birthY,birthM,birthD);
    cout<<"出生日期录入成功！"<<endl<<endl<<endl;
}

//设置民族
void setNation(Student &temp){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"民族录入，可选择民族如下："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string nationBuf;
    int item=0;
    string nationChoice;
    nationFile.clear();
    nationFile.seekg(0,ios::beg);
    while(!nationFile.eof()){//按照一行四个进行输出
        getline(nationFile,nationBuf);
        cout<<left<<setw(30)<<nationBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    cout<<endl<<"请选择民族：";
    cin.clear();
    cin.sync();//清空cin缓冲区
    getline(cin,nationChoice);//读入选择
    if(nationChoice.size()==0){//设为默认值
        temp.setNation("汉族");
        cout<<"无有效输入，已将民族设为默认值：汉族"<<endl;
    }else{
        nationFile.clear();
        nationFile.seekg(0,ios::beg);
        int nationNum;
        while(!nationFile.eof()){//遍历文件查找对应序号
            while(!isChoice(nationChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>nationChoice;
                nationFile.clear();
                nationFile.seekg(0,ios::beg);
            }
            getline(nationFile,nationBuf);
            nationNum=atoi(nationBuf.substr(0,nationBuf.find_first_of('\t')).c_str());
            if(atoi(nationChoice.c_str())==nationNum){
                cout<<"已选择："<<nationBuf<<endl;
                temp.setNation(nationBuf.substr(nationBuf.find_last_of('\t')+1,nationBuf.length()));
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

//设置婚姻状况
void setMarrige(Student &temp){
    string marrige;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请选择婚姻状况："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"1.未婚   2.已婚    3.丧偶    4.离婚    9.其他"<<endl;
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
        temp.setMarrige("未婚");//设为默认值
        cout<<"无有效输入，已将婚姻状况设为默认值：未婚"<<endl;
    }
    cout<<"婚姻状况录入成功！"<<endl<<endl<<endl;
}

//设置政治面貌
void setPoliticStatus(Student &temp){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"政治面貌，可选择政治面貌如下："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string politicsStatusBuf;
    int item=0;
    string politicsStatusChoice;
    politicsStatusFile.clear();
    politicsStatusFile.seekg(0,ios::beg);
    while(!politicsStatusFile.eof()){//输出文件选项
        getline(politicsStatusFile,politicsStatusBuf);
        cout<<left<<setw(30)<<politicsStatusBuf;
        item++;
        if(item%4==0&&item!=0){
            cout<<endl;
        }
    }
    //读入并设置
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
        while(!politicsStatusFile.eof()){//遍历文件查找对应序号
            while(!isChoice(politicsStatusChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>politicsStatusChoice;
            }
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
                politicsStatusBuf.substr(politicsStatusBuf.find_last_of(' ')+1,politicsStatusBuf.length()));
    }
    cout<<"政治面貌录入成功！"<<endl<<endl<<endl;
}

//设置身份证号
void setIDNumber(Student &temp){
    string IDNumber;
    if(temp.getCountry()!="中国"){//判断是否为外国人
        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
        cout<<"国籍信息为非中国，身份证号设为空！"<<endl<<endl<<endl;
        temp.setIdNumber("0");
    }else{
        while(1){
            int isIdNumberRight=1;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cout<<"请输入身份证号：";
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cin.clear();
            cin.sync();
            cin>>IDNumber;

            //判断身份证号字符
            if(includeChinese(IDNumber)){
                cout<<"身份证号中不能含有汉字！"<<endl;
                isIdNumberRight=0;
            }
            for(int i=0;i<IDNumber.length();i++){
                if(ispunct(IDNumber[i])||isalpha(IDNumber[i])){
                    cout<<"身份证号中不能含有字符或数字";
                    isIdNumberRight=0;
                    break;
                }
            }

            //判断身份证号长度
            if(IDNumber.length()!=18){
                cout<<"身份证号长度错误，";
                isIdNumberRight=0;
            }

            //判断行政区划
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
                        cout<<"行政区划错误，";
                        break;
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
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            if(isIdNumberRight==1){
                temp.setIdNumber(IDNumber);
                cout<<"身份证号录入成功！"<<endl<<endl<<endl;
                break;
            }
        }
    }
}

//设置学生类别
void setType(Student &temp){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"设置学生类别，可选择类别如下："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string typeBuf;
    int item=0;
    string typeChoice;
    typeFile.clear();
    typeFile.seekg(0,ios::beg);
    while(!typeFile.eof()){//输出文件内容
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
    if(typeChoice.size()==0){//设为默认值
        temp.setType("无");
        cout<<"无有效输入，已将学生类别设为默认值：无"<<endl;
    }else{
        typeFile.clear();
        typeFile.seekg(0,ios::beg);
        int typeNum;
        while(!typeFile.eof()){//遍历文件查找对应序号
            while(!isChoice(typeChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>typeChoice;
            }
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

//设置入学年月
void setEnrollmentDate(Student &temp){
    string enrollmentDate;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入入学日期：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>enrollmentDate;
    int enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());//入学日期分割，并将其转化为int
    int enrollM=atoi(
            enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
    int enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.length()).c_str());
    while(!(judge(enrollY,enrollM,enrollD)&&enrollM>=8&&enrollM<=10)){//判错逻辑
        cout<<"入学日期输入错误，请重新输入：";
        cin>>enrollmentDate;
        enrollY=atoi(enrollmentDate.substr(0,enrollmentDate.find_first_of('.')).c_str());
        enrollM=atoi(
                enrollmentDate.substr(enrollmentDate.find_first_of('.')+1,enrollmentDate.find_last_of('.')).c_str());
        enrollD=atoi(enrollmentDate.substr(enrollmentDate.find_last_of('.')+1,enrollmentDate.length()).c_str());
    }
    temp.getEnrollmentDate().setDate(enrollY,enrollM,enrollD);
    cout<<"入学日期录入成功！"<<endl<<endl<<endl;
}

//设置入学方式
void setEntranceWay(Student &temp){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"设置入学方式，可选择方式如下："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string entranceWayBuf;
    int item=0;
    string entranceWayChoice;
    entranceWayFile.clear();
    entranceWayFile.seekg(0,ios::beg);
    while(!entranceWayFile.eof()){//遍历文件输出
        getline(entranceWayFile,entranceWayBuf);
        cout<<left<<setw(15)<<entranceWayBuf;
    }
    cout<<endl<<"请选择入学方式：";
    cin.clear();
    cin.sync();
    getline(cin,entranceWayChoice);
    if(entranceWayChoice.size()==0){//设为默认值
        temp.setEntranceWay("普通入学");
        cout<<"无有效输入，已将入学方式设为默认值：普通入学"<<endl;
    }else{
        entranceWayFile.clear();
        entranceWayFile.seekg(0,ios::beg);
        int entranceWayNum;
        while(!entranceWayFile.eof()){//遍历文件查找对应序号
            while(!isChoice(entranceWayChoice)){
                cout<<"输入错误，请重新选择：";
                cin>>entranceWayChoice;
            }
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

//设置年级
void setGrade(Student &temp){
    int grade;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"设置年级，请输入所在年级：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
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

//设置专业名称
void setMajor(Student &temp){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"设置专业，你的学院为："<<temp.getCollege()<<endl;
    cout<<"可选择专业如下："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string majorBuf;
    string majorCollege;
    int majorChoice;
    majorFile.clear();
    majorFile.seekg(0,ios::beg);
    while(!majorFile.eof()){//遍历文件输出对应学院专业
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
    while(!majorFile.eof()){//遍历文件将对应专业分割存入vector对象以供选择匹配
        getline(majorFile,majorBuf);
        if(majorBuf.substr(2,majorBuf.find_first_of(' ')-2)==temp.getCollege()){
            majorBuf=majorBuf.substr(majorBuf.find_first_of(' ')+1,majorBuf.length());
            splitString(majorBuf,majors," ");
        }
    }
    int i=0;
    while(1){
        majorNum=majors[i];//遍历vector查找对应序号
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

//设置学制
void setSchoolLength(Student &temp){
    if(atoi(temp.getNumber().substr(0,2).c_str())==15){//按照专业设置学制
        temp.setSchoolLength(5);
    }else if(atoi(temp.getNumber().substr(0,2).c_str())==29){
        temp.setSchoolLength(3);
    }else{
        temp.setSchoolLength(4);
    }
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"根据专业，学制已设置为："<<temp.getSchoolLength()<<endl<<endl<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
}

//设置培养层次
void setTrainingLevel(Student &temp){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    if(temp.getMajor()=="研究生专业"){
        temp.setTrainingLevel("研究生");
        cout<<endl<<"专业为研究生专业\n录入培养层次：研究生"<<endl<<endl<<endl;
    }else{//非研究生专业设置为本科生
        temp.setTrainingLevel("本科生");
        cout<<endl<<"专业为本科专业\n录入培养层次：本科生"<<endl<<endl<<endl;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    }
}

//设置班级号
void setClass(Student &temp){
    string classNum;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"设置班级号，请输入所在班级：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>classNum;
    int intClassNum=atoi(classNum.c_str());
    while(intClassNum<0||intClassNum>10){//判错逻辑
        cout<<"班级号输入错误，请重新输入:";
        cin>>classNum;
        intClassNum=atoi(classNum.c_str());
    }
    temp.setClassNum(intClassNum);
    cout<<"班级为："<<intClassNum<<"班，班级录入成功！"<<endl<<endl<<endl;
}

//设置辅导员
void setCounsellor(Student &temp){
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"录入辅导员："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    string major=temp.getMajor();
    string counsellorBuf;
    string counsellor;
    int exist=0;
    counsellorFile.clear();
    counsellorFile.seekg(0,ios::beg);
    while(!counsellorFile.eof()){//查找当前专业有没有辅导员信息
        getline(counsellorFile,counsellorBuf);
        if(counsellorBuf.substr(0,counsellorBuf.find_first_of(' '))==major){
            counsellor=counsellorBuf.substr(counsellorBuf.find_last_of(' ')+1,counsellorBuf.length());
            temp.setCounsellor(counsellor);
            exist=1;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cout<<"你的专业为："<<major<<endl<<"对应辅导员为："<<counsellor<<endl;
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            break;
        }
    }
    if(exist==0){//没有信息则输入
        cin>>counsellor;
        ofstream inCounsellorFile("221801201_凌铧钦_counsellor.txt");
        inCounsellorFile<<major<<' '<<counsellor<<endl;
        temp.setCounsellor(counsellor);
        inCounsellorFile.close();
    }
    cout<<"辅导员录入成功！"<<endl<<endl<<endl;
}

//查找信息函数
void search(){
    string key;
    string studentBuf;
    vector<string> splits;
    int find=0;
    int searchChoice;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"可查找的学生信息：1.学号    2.姓名    3.民族    4.身份证号\n"
          "                  5.学院    6.专业"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入选择：";//选择要查询的学生信息
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
    cout<<"请输入查找字段：";//查找的字段
    cin>>key;
    cout<<endl<<endl<<"查找结果如下："<<endl;
    studentFile.clear();
    studentFile.seekg(ios::beg);
    while(!studentFile.eof()){//遍历文件查找对应字段
        getline(studentFile,studentBuf);
        splitString(studentBuf,splits," ");//分割学生信息
        if(key==splits[searchChoice]){
            find=1;
            cout<<studentBuf<<endl;
        }
        if(studentFile.eof()&&find==0){
            cout<<"无对应学生信息！"<<endl;
        }
        splits.clear();
    }
}

//修改学生信息
void change(){
    fstream changeFile("221801201_凌铧钦_changeTemp.txt",ios::out|ios::in);//修改的临时存储文件指针
    changeFile.clear();
    changeFile.seekg(0,ios::beg);
    int changeChoice;
    string changeNum;
    string studentBuf;
    vector<string> splits;
    int find=0;
    int findStu=0;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入您要修改的学生学号：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>changeNum;
    studentFile.clear();
    studentFile.seekg(ios::beg);
    while(!studentFile.eof()){//输入并查找对应学号信息
        getline(studentFile,studentBuf);
        if(studentBuf.substr(0,9)==changeNum){
            find=1;
            findStu=1;
            cout<<"查找到信息如下："<<endl;
            cout<<studentBuf<<endl;
            break;
        }
        else{
            changeFile<<studentBuf<<endl;//如果不是则拷贝到临时文件
            //TODO debug是否有空行
        }
        if(studentFile.eof()&&find==0){
            cout<<"无对应学生信息！"<<endl;
            findStu=0;
        }
    }
    if(findStu){
        splitString(studentBuf,splits," ");//分割查找到的字符串并且存入临时Student对象里
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
        cout<<"可选修改项：1.姓名      2.民族      3.婚姻状况      4.政治面貌\n"
              "            5.学生类型  6.入学方式  7.年级          8.班级\n"
              "请输入选择：";
        cin>>changeChoice;
        while(changeChoice<1||changeChoice>8){
            cout<<"选择错误，请重新输入：";
            cin>>changeChoice;
        }
        string changeItem;
        switch(changeChoice){//根据选择项进入对应设置函数
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
        changeFile<<temp.getNumber()<<' '<<temp.getName()<<' '<<temp.getSex()<<' '<<temp.getCountry()<<' '//将临时student输出到文件里
                  <<temp.getBirthday().getYear()<<'.'<<temp.getBirthday().getMonth()<<'.'
                  <<temp.getBirthday().getDay()<<' '<<temp.getNation()<<' '<<temp.getMarrige()<<' '
                  <<temp.getPoliticsStatus()<<' '<<temp.getIdNumber()<<' '<<temp.getType()<<' '
                  <<temp.getEnrollmentDate().getYear()<<'.'<<temp.getEnrollmentDate().getMonth()
                  <<'.'<<temp.getEnrollmentDate().getDay()<<' '<<temp.getEntranceWay()<<' '
                  <<temp.getCollege()<<' '<<temp.getMajor()<<' '<<temp.getGrade()<<' '
                  <<temp.getSchoolLength()<<' '<<temp.getTrainingLevel()
                  <<' '<<temp.getClassNum()<<' '<<temp.getCounsellor()<<endl;
        ofstream studentFile("221801201_凌铧钦_student.txt",ios::trunc);//打开并清空学生信息文件
        string tempBuf;
        changeFile.clear();
        changeFile.seekg(0,ios::beg);
        while(!changeFile.eof()){//将临时信息文件拷贝到学生信息文件中
            getline(changeFile,tempBuf);
            studentFile<<tempBuf<<endl;
        }
        cout<<"修改学生信息并保存成功！"<<endl<<endl;
    }
}

//删除学生信息
void deleteInfo(){
    fstream deleteFile("221801201_凌铧钦_deleteTemp.txt",ios::in|ios::out);
    string deleteNum;
    string studentBuf;
    int find=0;
    int findStu=0;SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入您要的学生学号：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>deleteNum;
    studentFile.clear();
    studentFile.seekg(ios::beg);
    while(!studentFile.eof()){
        getline(studentFile,studentBuf);
        if(studentBuf.substr(0,9)==deleteNum){
            find=1;
            findStu=1;
            cout<<"查找到信息如下："<<endl;
            cout<<studentBuf<<endl;
            break;
        }
        else{
            deleteFile<<studentBuf<<endl;
            //TODO debug是否有空行
        }
        if(studentFile.eof()&&find==0){
            cout<<"无对应学生信息！"<<endl;
            findStu=0;
        }
    }
    if(findStu){
        char deleteChoice;
        cout<<"是否要删除学生信息(y确认，其他键取消)：";
        cin>>deleteChoice;
        if(isupper(deleteChoice)){
            tolower(deleteChoice);
        }
        if(deleteChoice=='y'){
            ofstream studentFile("221801201_凌铧钦_student.txt",ios::trunc);//打开并清空学生文件
            string tempBuf;
            deleteFile.clear();
            deleteFile.seekg(0,ios::beg);
            while(!deleteFile.eof()){
                getline(deleteFile,tempBuf);
                studentFile<<tempBuf<<endl;
            }
            cout<<"删除学生信息并保存成功！"<<endl<<endl;
        }else{
            cout<<"已取消，返回主菜单！"<<endl<<endl;
        }
    }else{
        cout<<"未找到，返回主菜单！"<<endl<<endl;
    }
}

//统计分析函数
void analyze(){
    string studentBuf;
    string analyzeKey;
    vector<string> splits;
    int find=0;
    int itemNum=0;
    int analyzeChoice;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入您要统计的信息：1.性别    2.政治面貌    3.国籍    4.民族    5.学院    6.专业"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"请输入选择：";
    cin>>analyzeChoice;
    if(analyzeChoice==1){//根据输入设置统计项
        analyzeChoice=2;
    }else if(analyzeChoice==2){
        analyzeChoice=7;
    }else if(analyzeChoice==3){
        analyzeChoice=3;
    }else if(analyzeChoice==4){
        analyzeChoice=5;
    }else if(analyzeChoice==5){
        analyzeChoice=12;
    }else if(analyzeChoice==6){
        analyzeChoice=13;
    }
    cout<<"请输入要查询字段：";
    cin>>analyzeKey;
    cout<<endl<<endl<<"统计结果如下："<<endl;
    studentFile.clear();
    studentFile.seekg(ios::beg);
    while(!studentFile.eof()){//输出统计结果
        getline(studentFile,studentBuf);
        splitString(studentBuf,splits," ");
        if(analyzeKey==splits[analyzeChoice]){
            find=1;
            itemNum++;
        }
        if(studentFile.eof()&&find==0){
            cout<<"无对应信息！"<<endl;
        }
    }
    cout<<analyzeKey<<"："<<itemNum<<endl;
}

//学号排序器
bool comp1(Student &a,Student &b){
    return a.getNumber()<b.getNumber();
}

//年级排序器
bool comp2(Student &a,Student &b){
    return a.getGrade()<b.getGrade();
}

//排序函数
void sort(){
    string sortBuf;
    Student temp;
    int sortChoice;
    vector<Student> students;
    vector<string> splits;
    studentFile.clear();
    studentFile.seekg(0,ios::beg);
    while(!studentFile.eof()){//读取学生信息分割储存到vector<student>里
        getline(studentFile,sortBuf);
        if(sortBuf.size()!=0){
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
            splits.clear();
        }
    }
    ofstream studentFile("221801201_凌铧钦_student.txt",ios::trunc);//打开并清空学生文件
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"排序方式：  1.学号    2.年级\n"
          "请选择：";
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cin>>sortChoice;
    while(sortChoice<1||sortChoice>2){
        cout<<"选择错误，请重新选择：";
        cin>>sortChoice;
    }
    if(sortChoice==1){//按照不同方式排序
        sort(students.begin(),students.end(),comp1);
    }else if(sortChoice==2){
        sort(students.begin(),students.end(),comp2);
    }

    for(int i=0;i<students.size();i++){//储存到学生文件中
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

    cout<<"排序成功！"<<endl<<endl<<endl;
}

//输出学生信息函数
void print(){
    string printBuf;
    vector<string> splits;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"学生信息如下："<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    studentFile.clear();
    studentFile.seekg(0,ios::beg);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"   学号     姓名      性别   国籍        出生日期    民族     婚姻状况  政治面貌         身份证号          类别    入学日期    入学方式      学院                  专业     年级  学制  层次  班级  辅导员\n";
    while(!studentFile.eof()){
        getline(studentFile,printBuf);
        splits.clear();
        splitString(printBuf,splits," ");
        for(int i=0;i<splits.size();i++){
            if(i==7||i==1||i==3||i==5||i==4||i==10){
                cout<<left<<setw(10)<<splits[i]<<"  ";
            }else if(i==12){
                cout<<left<<setw(20)<<splits[i]<<"  ";
            }else{
                cout<<splits[i]<<"   ";
            }
        }
        cout<<endl;
    }
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------=\n";
    cout<<"输出成功！"<<endl<<endl<<endl;
}

/*------------------Student成员函数结束----------------------*/

//分割字符串函数
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

//判断是否含有中文函数
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

//判断是否为正确选择
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
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);//CMD变色管理器
    GetLocalTime(&sysTime);//获取当前时间
    vector<Student> all;
    int choice;
    while(1){
        menu();
        choice=getch();
        choice-=48;
        cout<<choice<<endl;
        switch(choice){
            case 1:{//读入信息
                int readChoice;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                cout<<"输入方式：  1.键盘输入    2.文件输入\n"
                      "请选择：";
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                cin>>readChoice;
                while(readChoice<1||readChoice>2){
                    cout<<"选择错误，请重新选择：";
                    cin>>readChoice;
                }
                if(readChoice==1){//键盘录入
                    studentFile.clear();
                    studentFile.seekp(0,ios::end);
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
                    //输出到文件
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
                    //文件录入
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"文件读入信息需放入fileReadIn.txt中，按读取顺序放入，空格隔开每个字段,请保持数据正确性！"<<endl;//提示信息
                    SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                    system("pause");
                    string fileReadBuf;
                    fileReadIn.clear();
                    fileReadIn.seekg(0,ios::beg);
                    studentFile.clear();
                    studentFile.seekp(0,ios::end);
                    while(!fileReadIn.eof()){//拷贝文件
                        getline(fileReadIn,fileReadBuf);
                        studentFile<<fileReadBuf<<endl;
                    }
                    cout<<"录入成功！"<<endl;
                }
                break;
            }
            case 2://查找功能
                search();
                break;
            case 3://修改功能
                change();
                break;
            case 4://删除功能
                deleteInfo();
                break;
            case 5://分析统计功能
                analyze();
                break;
            case 6://排序功能
                sort();
                break;
            case 7://输出功能
                print();
                break;
            case 8://退出程序
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                cout<<"谢谢使用。"<<endl;
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                goto end;
            default://选择错误情况
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                cout<<"选择错误，请重新选择!"<<endl;
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                break;
        }
    }
    end:exit(1);
}