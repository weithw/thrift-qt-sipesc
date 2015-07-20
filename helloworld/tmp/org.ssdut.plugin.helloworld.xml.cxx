#include <qvariant.h>
#include <qcoreapplication.h>
#include <mmiscutility.h>
#include <mdatatypemanager.h>
#include <org.ssdut.plugin.helloworld.h>
#include <org.ssdut.plugin.helloworld.feature.messagereceiver.h>
#include <qstring.h>
#include <org.ssdut.plugin.helloworld.feature.messageprovider.h>

Q_DECLARE_METATYPE(QString)
Q_DECLARE_METATYPE(QVariant::Type)

void OrgSsdutPluginHelloworldPlugin::setupMetaTypes()
  {
  MDataTypeManager manager=MDataTypeManager::getManager();
  manager.registerMetaType<org::ssdut::plugin::helloworld::feature::MessageReceiver>("org.ssdut.plugin.helloworld.feature.MessageReceiver");
  manager.registerMetaType<org::ssdut::plugin::helloworld::feature::MessageReceiver*>("org.ssdut.plugin.helloworld.feature.MessageReceiver*");
  manager.registerMetaType<org::ssdut::plugin::helloworld::feature::MessageReceiverInterface*>("org.ssdut.plugin.helloworld.feature.MessageReceiverInterface*");
  manager.registerMetaType<org::ssdut::plugin::helloworld::feature::MessageProvider>("org.ssdut.plugin.helloworld.feature.MessageProvider");
  manager.registerMetaType<org::ssdut::plugin::helloworld::feature::MessageProvider*>("org.ssdut.plugin.helloworld.feature.MessageProvider*");
  manager.registerMetaType<org::ssdut::plugin::helloworld::feature::MessageProviderInterface*>("org.ssdut.plugin.helloworld.feature.MessageProviderInterface*");
  manager.registerMetaType<QString>("QString");
  manager.registerMetaType<QVariant::Type>("QVariant::Type");
  }

int OrgSsdutPluginHelloworldPlugin::convertData(QVariant& data, const QString& type) const
  {
  uint hash=qHash(type);
  QString vtype=data.typeName();
  switch(hash)
    {
    case 111907047:
      if(type=="QString")
        {
        if(type==vtype) return 2;
        else if(data.canConvert<QString>())
          {
          data=QVariant::fromValue(data.value<QString>());
          return 1;
          }
        }
      break;
    }
  return 0;
  }

static struct
  {
  int type;
  const char* text;
  }
OrgSsdutPluginHelloworldPluginStringMapper[]=
  {
    { 0, "2.0" },
    { 0, "org.ssdut.plugin.helloworld" },
    { 0, "1.0.0" },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "Hello World") },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "xiaodong") },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "All rights reserved by Xiaodong") },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "This is example plugin developed by xiaodong.") },
    { 0, "org.ssdut.plugin.helloworld.feature" },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "Feature Example") },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "This is the namespace.") },
    { 0, "MessageReceiver" },
    { 0, "{c7ac15b5-31f7-40c1-b334-e60fc4657a5a}" },
    { 0, "true" },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "It is used to show messages.") },
    { 0, "org.ssdut.plugin.helloworld.feature.category" },
    { 0, "showMessage2" },
    { 0, "const" },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "show a messages.") },
    { 0, "message" },
    { 0, "QString" },
    { 0, "const reference" },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "The message to show") },
    { 0, "MessageProvider" },
    { 0, "{a54638cd-319a-40e0-91ac-fcb90fc21a37}" },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "MessageProvider is used to provide message.") },
    { 0, "QString()" },
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "=Helloworld message attribute\nThis attribute holds the message to provide.") }
  };
static const int OrgSsdutPluginHelloworldPluginStringMapperCount=27;

static const uchar OrgSsdutPluginHelloworldPluginPluginXmlData[]=
  {
  0X00,0X00,0X01,0Xb2,0X78,0Xda,0X75,0X8e,0Xc9,0X12,0X82,0X40,0X10,0X43,
  0X7b,0X00,0X67,0X03,0X17,0X10,0X14,0X71,0Xa1,0X3c,0Xf8,0Xff,0Xbf,0X68,
  0Xa7,0Xab,0X72,0X98,0X42,0X0f,0X49,0Xbd,0X43,0Xd2,0X1d,0X57,0X8b,0X48,
  0X17,0Xd4,0X9e,0X2a,0X01,0X2c,0X2a,0X07,0X78,0Xab,0X2a,0Xc0,0Xac,0Xaa,
  0X01,0X27,0X55,0X03,0X18,0X54,0X3b,0Xc0,0Xa4,0Xf2,0X11,0X47,0X02,0Xbb,
  0X61,0Xd3,0X8d,0X4c,0X26,0X4b,0X7a,0X26,0X33,0X60,0X55,0Xb5,0X80,0X33,
  0X97,0X3c,0X08,0Xa8,0Xec,0X01,0X1f,0Xd5,0Xc1,0Xba,0Xd9,0X3c,0Xf1,0Xc2,
  0X11,0Xd0,0X63,0Xd9,0Xa6,0Xd8,0X5b,0Xb2,0X65,0X72,0X00,0Xbc,0Xf0,0X86,
  0X95,0X91,0Xc9,0X29,0X36,0X48,0Xc2,0X12,0X2c,0Xc3,0X7c,0Xb1,0Xf4,0Xc2,
  0Xa5,0Xd7,0Xff,0X4b,0Xe7,0X72,0Xa9,0X33,0X97,0Xdf,0Xff,0X47,0Xd5,0X8d,
  0Xc5,0X05,0X70,0X2f,0X6e,0Xda,0X22,0X81,0X39,0X1b,0X03,0X0b,0Xb0,0Xae,
  0Xfa,0X02,0X44,0X8f,0X07,0X8b
  };
static const int OrgSsdutPluginHelloworldPluginPluginXmlDataSize=160;

static QVariant callOrgSsdutPluginHelloworldFeatureMessageReceiverMethod(MExtensionObject* extension, const QString& methodName, QList<void*>& params)
  {
  QVariant result;
  org::ssdut::plugin::helloworld::feature::MessageReceiverInterface* object;
  object=dynamic_cast<org::ssdut::plugin::helloworld::feature::MessageReceiverInterface*>(extension);
  uint hash=qHash(methodName);
  switch(hash)
    {
    case 197928068:
      if(methodName=="void showMessage2(const QString& message) const")
        {
        QString p1=*((QString*)(params.at(0)));
        object->showMessage2(p1);
        }
      break;
    default:
      break;
    }
  return result;
  }

static QVariant callOrgSsdutPluginHelloworldFeatureMessageProviderMethod(MExtensionObject* extension, const QString& methodName, QList<void*>& params)
  {
  QVariant result;
  org::ssdut::plugin::helloworld::feature::MessageProviderInterface* object;
  object=dynamic_cast<org::ssdut::plugin::helloworld::feature::MessageProviderInterface*>(extension);
  uint hash=qHash(methodName);
  switch(hash)
    {
    case 16775108:
      if(methodName=="QString getMessage() const")
        {
        QString resultValue=object->getMessage();
        result=QVariant::fromValue(resultValue);
        }
      break;
    default:
      break;
    }
  return result;
  }

QVariant OrgSsdutPluginHelloworldPlugin
::callMethod(MExtensionObject* extension, const QString& extensionName, const QString& methodName, QList<void*>& params)
  {
  bool isext;
  uint hash=qHash(extensionName);
  switch(hash)
    {
    case 168901090:
      isext=(extensionName=="org.ssdut.plugin.helloworld.feature.MessageReceiver");
      if(isext) return callOrgSsdutPluginHelloworldFeatureMessageReceiverMethod(extension, methodName, params);
      break;
    case 150588930:
      isext=(extensionName=="org.ssdut.plugin.helloworld.feature.MessageProvider");
      if(isext) return callOrgSsdutPluginHelloworldFeatureMessageProviderMethod(extension, methodName, params);
      break;
    default:
      break;
    }
  return 0;
  }

QByteArray OrgSsdutPluginHelloworldPlugin::getPluginXml() const
  {
  int nbytes=OrgSsdutPluginHelloworldPluginPluginXmlDataSize;
  return qUncompress(OrgSsdutPluginHelloworldPluginPluginXmlData, nbytes);
  }

MExtensionObject* OrgSsdutPluginHelloworldPlugin
::createObject(const QString& type)
  {
  bool isext;
  uint hash=qHash(type);
  switch(hash)
    {
    case 168901090:
      isext=(type=="org.ssdut.plugin.helloworld.feature.MessageReceiver");
      if(isext) return createOrgSsdutPluginHelloworldFeatureMessageReceiver();
      break;
    case 150588930:
      isext=(type=="org.ssdut.plugin.helloworld.feature.MessageProvider");
      if(isext) return createOrgSsdutPluginHelloworldFeatureMessageProvider();
      break;
    default:
      break;
    }
  return 0;
  }

QString OrgSsdutPluginHelloworldPlugin
::getTextStringForId(qint32 id) const
  {
  int index=id;
  QString result;
  if(index>=0&&index<OrgSsdutPluginHelloworldPluginStringMapperCount)
    {
    const char* txt;
    txt=OrgSsdutPluginHelloworldPluginStringMapper[index].text;
    if(OrgSsdutPluginHelloworldPluginStringMapper[index].type!=0)
      {
      QCoreApplication* app=QCoreApplication::instance();
      const char* context="OrgSsdutPluginHelloworldPlugin";
      result=app->translate(context, txt);
      }
    else result=QString::fromLatin1(txt);
    }
  return result;
  }

QVariant OrgSsdutPluginHelloworldPlugin
::getData(const QString& text) const
  {
  bool is=false;
  uint hash=qHash(text);
  switch(hash)
    {
    case 194045161:
      is=(text==QLatin1String("QString()"));
      if(is) return QVariant::fromValue(QString());
      break;
    default:
      break;
    }
  return QVariant();
  }

M_EXTMGR_PLUGIN_INSTANCE(OrgSsdutPluginHelloworldPlugin);
