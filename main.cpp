#include<iostream>
#include<vector>
#include<conio.h>

using namespace std;

bool includeChinese(string);
/*学号、姓名、性别、国别、出生日期、民族、婚姻状况、政治面貌、身份证号、
  学生类别、入学年月、入学方式、学院、专业、学制、培养层次、年级、班级号、辅导员等*/
//TODO 导入date类

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

    const Date getBirthday(){
        return birthday;
    }

    void setBirthday(const Date birthday){
        Student::birthday=birthday;
    }

    const Date getEnrollmentDate(){
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

    //设置学号
    cout<<"请输入学号："<<endl;
    int numberRight=1;
    do{
        if(number.length()!=9){
            numberRight=0;
        }
        //TODO 其余判断逻辑
        cout<<"输入错误，请重新输入：";
        cin>>number;
    }while(numberRight==0);
    temp.setCollege(number.substr(0,2));
    temp.getEnrollmentDate()//TODO 设置入学日期

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
    cout<<"请选择国籍："<<endl;
    temp.setCountry(country);
    cout<<""<<endl;
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
            cout<<"谢谢使用。"<<endl;
            goto end;
    }
    end:return 0;
}