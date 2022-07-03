//
// Created by shanshan on 2022/5/9.
//
#include <cstring>

class myString{
public:
    myString(const char *str= nullptr);
    myString(const myString &s);
    ~myString();
    myString& operator=(const myString& s);
    myString operator+(const myString& s);
    myString& operator+=(const myString& s);
    bool operator==(const myString& s);
    char& operator[](int index);
private:
    char *data;
};
myString::myString(const char *str){
    if(str){
        data=new char[strlen(str)+1];
        strcpy(data,str);
    }else{
        data=new char[1];
        *data='\0';
    }
}
myString::myString(const myString &s) {
    data=new char[strlen(s.data)+1];
    strcpy(data,s.data);
}
myString& myString::operator=(const myString &s) {
    data=new char[strlen(s.data)+1];
    strcpy(data,s.data);
    return *this;
}
myString myString::operator+(const myString &s) {
    myString ms;
    ms.data=new char[strlen(this->data)+strlen(s.data)+1];
    strcpy(ms.data,this->data);
    strcat(ms.data,s.data);
    return ms;
}
myString& myString::operator+=(const myString &s) {

}
myString::~myString() {
    delete[]data;
    data= nullptr;
}