#ifndef ORG_SSDUT_PLUGIN_HELLOWORLD_FEATURE_MESSAGERECEIVER_H
#define ORG_SSDUT_PLUGIN_HELLOWORLD_FEATURE_MESSAGERECEIVER_H

#include <mextension.h>

class QString;

namespace org {
namespace ssdut {
namespace plugin {
namespace helloworld {
namespace feature {

class MessageReceiverInterface;

// Wrapper Declaration
class MessageReceiver:
public MExtension
  {
  public:
    MessageReceiver();
    virtual ~MessageReceiver();
    MessageReceiver(MessageReceiverInterface* data);
    MessageReceiver(const MessageReceiver& obj);
    MessageReceiver(const MExtension& obj);
    MessageReceiver& operator=(const MessageReceiver& obj);
    MessageReceiver& operator=(const MExtension& obj);
  public:
    void showMessage(const QString& message) const;
  };

// Interface Declaration
class MessageReceiverInterface:
public MExtensionObject
  {
  public:
    virtual ~MessageReceiverInterface();
    QString getClassName() const;
    static QUuid getUuid();
    bool isInstanceOf(const QUuid& uuid) const;
    bool inherits(const QString& type) const;
  public:
    virtual void showMessage(const QString& message) const=0;
  private:
    static QString _getSelfClassName();
  };

// Interface Implementation
inline MessageReceiverInterface::~MessageReceiverInterface()
  {
  }

inline QString MessageReceiverInterface::getClassName() const
  {
  return _getSelfClassName();
  }

inline QUuid MessageReceiverInterface::getUuid()
  {
  QLatin1String uuid("{b3c8eee1-dd1d-422e-9b69-eb2896736ea6}");
  return QUuid(uuid);
  }

inline bool MessageReceiverInterface::isInstanceOf(const QUuid& uuid) const
  {
  return (uuid==getUuid());
  }

inline bool MessageReceiverInterface::inherits(const QString& type) const
  {
  if(type==_getSelfClassName()) return true;
  else return false;
  }

inline QString MessageReceiverInterface::_getSelfClassName()
  {
  return QLatin1String("org.ssdut.plugin.helloworld.feature.MessageReceiver");
  }

// Wrapper Implementation
inline MessageReceiver::MessageReceiver()
  {
  }

inline MessageReceiver::~MessageReceiver()
  {
  }

inline MessageReceiver::MessageReceiver(MessageReceiverInterface* data)
  :MExtension(data)
  {
  }

inline MessageReceiver::MessageReceiver(const MessageReceiver& obj)
  :MExtension(obj)
  {
  }

inline MessageReceiver::MessageReceiver(const MExtension& obj)
  {
  _data=_getptr<MessageReceiverInterface*>(&obj);
  _attach();
  }

inline MessageReceiver& MessageReceiver::operator=(const MessageReceiver& obj)
  {
  if(this!=&obj)
    {
    _detach();
    _data=obj._data;
    _attach();
    }
  return *this;
  }

inline MessageReceiver& MessageReceiver::operator=(const MExtension& obj)
  {
  if(this!=&obj)
    {
    _detach();
    _data=_getptr<MessageReceiverInterface*>(&obj);
    _attach();
    }
  return *this;
  }

inline void MessageReceiver::showMessage(const QString& message) const
  {
  MessageReceiverInterface* _ptr;
  _ptr=getPrivateData<MessageReceiverInterface*>();
  if(_ptr==0) return;
  _ptr->showMessage(message);
  }

}}}}}

Q_DECLARE_METATYPE(org::ssdut::plugin::helloworld::feature::MessageReceiver)
Q_DECLARE_METATYPE(org::ssdut::plugin::helloworld::feature::MessageReceiver*)
Q_DECLARE_METATYPE(org::ssdut::plugin::helloworld::feature::MessageReceiverInterface*)

#endif /* ORG_SSDUT_PLUGIN_HELLOWORLD_FEATURE_MESSAGERECEIVER_H */
