#include <messageproviderimpl.h>
MessageProviderImpl::MessageProviderImpl()
{
_message = "Hello world Plugin from Xiaodong.";
}
MessageProviderImpl::~MessageProviderImpl(){
}
QString MessageProviderImpl:: getMessage() const
{
return _message;
}
