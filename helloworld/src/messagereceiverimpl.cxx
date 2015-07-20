#include <qtextstream.h>
#include <fstream> 
#include <iostream>
#include <messagereceiverimpl.h>
#include <string>
using namespace std;
MessageReceiverImpl::MessageReceiverImpl(){
}

MessageReceiverImpl:: ~MessageReceiverImpl(){
}

void MessageReceiverImpl::showMessage2(const QString& message) const{
	char*  filePath;
	QByteArray ba = message.toLatin1();    
	filePath=ba.data();
	
    ifstream myfile (filePath); 
    if(!myfile){  
    cout << "Unable to open file:" << filePath;  
        exit(1); // terminate with error  
  
	} 	
	char buffer[256];  
	myfile.getline (buffer,10);  

	cout << buffer << endl;
}