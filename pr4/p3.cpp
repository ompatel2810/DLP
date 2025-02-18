#include<iostream>
#include<fstream>
#include<string>  // Include this for string type (just in case it's needed explicitly)

using namespace std;

int main() {
    string srg;  
    ifstream filestream("p3.txt");
    if (filestream.is_open()) { 
        while (getline(filestream, srg)) {  
            
            // remove comment 
        int count=srg.find("//");
           if(count>0){
            count=0;
            srg.erase();
           }
            cout << srg << endl;  
        }
        filestream.close(); 
    } else {  
        cout << "File opening failed." << endl; 
    }  
    
    return 0;
}
