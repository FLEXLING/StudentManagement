#include<iostream>
#include<vector>
#include<conio.h>

using namespace std;

bool includeChinese(string);
/*ѧ�š��������Ա𡢹��𡢳������ڡ����塢����״����������ò�����֤�š�
  ѧ�������ѧ���¡���ѧ��ʽ��ѧԺ��רҵ��ѧ�ơ�������Ρ��꼶���༶�š�����Ա��*/
//TODO ����date��

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
    int numberRight=1;
    do{
        if(number.length()!=9){
            numberRight=0;
        }
        //TODO �����ж��߼�
        cout<<"����������������룺";
        cin>>number;
    }while(numberRight==0);
    temp.setCollege(number.substr(0,2));
    temp.getEnrollmentDate()//TODO ������ѧ����

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
    cout<<"��ѡ�������"<<endl;
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