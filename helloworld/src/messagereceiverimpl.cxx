#include <qtextstream.h>
#include <messagereceiverimpl.h>
MessageReceiverImpl::MessageReceiverImpl(){
}
MessageReceiverImpl:: ~MessageReceiverImpl(){
}
void MessageReceiverImpl::showMessage(const QString& message) const{
QTextStream out(stdout);
out<<"here!!!!!!!!!!"<<endl;
}
