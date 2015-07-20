#ifndef MESSAGEPROVIDERIMPL_H
#define MESSAGEPROVIDERIMPL_H

#include <org.ssdut.plugin.helloworld.feature.messageprovider.h>

using namespace org::ssdut::plugin::helloworld::feature;

class MessageProviderImpl: public MessageProviderInterface
{
public:
  MessageProviderImpl();
  ~MessageProviderImpl();
public:
  QString getMessage() const;

private:
  QString _message;
};

#endif
