 
#include <messageproviderimpl.h>

MessageProviderImpl::MessageProviderImpl()
{

  _message = "Hello world Plugin from Xiaodong222333.";
  
}

MessageProviderImpl::~MessageProviderImpl(){
}

QString MessageProviderImpl::getMessage() const
{
  return _message;
  
}