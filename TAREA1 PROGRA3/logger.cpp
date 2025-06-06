#include<fstream>
#include <string>

using namespace std;


namespace file::operations{
 
class logger{
private:
    ofstream file;
public:
    logger(string name){
        file.open(name, ios::app);
    }
    ~logger(){
        if(file.is_open()){
            file.close();}
    }
    void write(string m){
        if(file.is_open()){
            file << m << endl;}
    }
    
    template<typename T>
    logger& operator<<(const T& mensaje){
        if(file.is_open()){
            file << mensaje << endl;}
        return *this;
    }

};
}

