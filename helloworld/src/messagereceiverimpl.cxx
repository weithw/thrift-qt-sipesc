#include <QStringList>
#include <qtextstream.h>
#include <fstream>
#include <iostream>
#include <messagereceiverimpl.h>
#include <string>
MessageReceiverImpl::MessageReceiverImpl(){
}

MessageReceiverImpl:: ~MessageReceiverImpl(){
}

void MessageReceiverImpl::showMessage(const QString& message) const{
    QTextStream out(stdout);
    message.trimmed();
    std::string totcommand;
    totcommand=message.toStdString();

    QStringList strlist = message.trimmed().split(" ");
    QString command = strlist.at(0).toLocal8Bit().data();
    char filelocal [totcommand.length()-1];
    char * ch = "hello world";
    // out<<command<<endl;

	if(command== QString("-v"))
	{
		out<<"Version: 1.0.0 Date:20150719"<<endl; 
	} 
	else if (command == QString("-f"))
	{
        int spacenum=0;
        for(int i=0 ;i<(totcommand.length()-2);i++)
        {
            if(totcommand[i+2]==' ')
            {
                spacenum++;
            }
            else
            {
                filelocal[i-spacenum]=totcommand[i+2];
                filelocal[i+1-spacenum]='\0';
            }
        }
        out<<filelocal<<endl;
        std::fstream in(filelocal);
		// std::fstream in("/home/lyh/test");
		if(!in)
		{
			out<<"cannot open file"<<endl; 
			return ;
		}
	 	else
		{ 
			out<<"write ok "<<endl;
			in.write(ch,strlen(ch));
			in.close();
			return;
		}
	} else {
        out<<"wrong command"<<endl;
    }
	  
  //std::fstream in("/home/lyh/test");
 // if(!in)
 // 	{
 // 		out<<"cannot open file"<<endl; 
 // 		return ;
 // 	}
 // else
  //	{ 
 // 		out<<"write ok "<<endl;
 // 		in.write(ch,strlen(ch));
 // 		in.close();
 // 		return;
  //	}
} 
