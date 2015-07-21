#ifndef MESSAGERECEIVERIMPL_H
#define MESSAGERECEIVERIMPL_H
#include <org.ssdut.plugin.helloworld.feature.messagereceiver.h>
using namespace org::ssdut::plugin::helloworld::feature;
class MessageReceiverImpl: public MessageReceiverInterface
{
public:
MessageReceiverImpl();
~MessageReceiverImpl();
public:
void showMessage(const QString& message) const;
};
#endif
