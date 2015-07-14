#ifndef ORG_SSDUT_PLUGIN_HELLOWORLD_FEATURE_MESSAGEPROVIDER_H
#define ORG_SSDUT_PLUGIN_HELLOWORLD_FEATURE_MESSAGEPROVIDER_H

#include <mextension.h>
#include <qstring.h>

namespace org {
namespace ssdut {
namespace plugin {
namespace helloworld {
namespace feature {

class MessageProviderInterface;

// Wrapper Declaration
class MessageProvider:
public MExtension
  {
  public:
    MessageProvider();
    virtual ~MessageProvider();
    MessageProvider(MessageProviderInterface* data);
    MessageProvider(const MessageProvider& obj);
    MessageProvider(const MExtension& obj);
    MessageProvider& operator=(const MessageProvider& obj);
    MessageProvider& operator=(const MExtension& obj);
  public:
    QString getMessage() const;
  };

// Interface Declaration
class MessageProviderInterface:
public MExtensionObject
  {
  public:
    virtual ~MessageProviderInterface();
    QString getClassName() const;
    static QUuid getUuid();
    bool isInstanceOf(const QUuid& uuid) const;
    bool inherits(const QString& type) const;
  public:
    virtual QString getMessage() const=0;
  private:
    static QString _getSelfClassName();
  };

// Interface Implementation
inline MessageProviderInterface::~MessageProviderInterface()
  {
  }

inline QString MessageProviderInterface::getClassName() const
  {
  return _getSelfClassName();
  }

inline QUuid MessageProviderInterface::getUuid()
  {
  QLatin1String uuid("{a54638cd-319a-40e0-91ac-fcb90fc21a37}");
  return QUuid(uuid);
  }

inline bool MessageProviderInterface::isInstanceOf(const QUuid& uuid) const
  {
  return (uuid==getUuid());
  }

inline bool MessageProviderInterface::inherits(const QString& type) const
  {
  if(type==_getSelfClassName()) return true;
  else return false;
  }

inline QString MessageProviderInterface::_getSelfClassName()
  {
  return QLatin1String("org.ssdut.plugin.helloworld.feature.MessageProvider");
  }

// Wrapper Implementation
inline MessageProvider::MessageProvider()
  {
  }

inline MessageProvider::~MessageProvider()
  {
  }

inline MessageProvider::MessageProvider(MessageProviderInterface* data)
  :MExtension(data)
  {
  }

inline MessageProvider::MessageProvider(const MessageProvider& obj)
  :MExtension(obj)
  {
  }

inline MessageProvider::MessageProvider(const MExtension& obj)
  {
  _data=_getptr<MessageProviderInterface*>(&obj);
  _attach();
  }

inline MessageProvider& MessageProvider::operator=(const MessageProvider& obj)
  {
  if(this!=&obj)
    {
    _detach();
    _data=obj._data;
    _attach();
    }
  return *this;
  }

inline MessageProvider& MessageProvider::operator=(const MExtension& obj)
  {
  if(this!=&obj)
    {
    _detach();
    _data=_getptr<MessageProviderInterface*>(&obj);
    _attach();
    }
  return *this;
  }

inline QString MessageProvider::getMessage() const
  {
  MessageProviderInterface* _ptr;
  _ptr=getPrivateData<MessageProviderInterface*>();
  if(_ptr==0) return QString();
  return _ptr->getMessage();
  }

}}}}}

Q_DECLARE_METATYPE(org::ssdut::plugin::helloworld::feature::MessageProvider)
Q_DECLARE_METATYPE(org::ssdut::plugin::helloworld::feature::MessageProvider*)
Q_DECLARE_METATYPE(org::ssdut::plugin::helloworld::feature::MessageProviderInterface*)

#endif /* ORG_SSDUT_PLUGIN_HELLOWORLD_FEATURE_MESSAGEPROVIDER_H */
