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
    { 1, QT_TRANSLATE_NOOP("OrgSsdutPluginHelloworldPlugin", "ghw") },
    { 0, "org.ssdut.plugin.helloworld.feature" },
    { 0, "MessageReceiver" },
    { 0, "{b3c8eee1-dd1d-422e-9b69-eb2896736ea6}" },
    { 0, "true" },
    { 0, "org.ssdut.plugin.helloworld.feature.category" },
    { 0, "showMessage" },
    { 0, "const" },
    { 0, "message" },
    { 0, "QString" },
    { 0, "const reference" },
    { 0, "MessageProvider" },
    { 0, "{fc1ffa20-bb92-4a9b-9c4b-85671179b33e}" },
    { 0, "QString()" }
  };
static const int OrgSsdutPluginHelloworldPluginStringMapperCount=17;

static const uchar OrgSsdutPluginHelloworldPluginPluginXmlData[]=
  {
  0X00,0X00,0X01,0X58,0X78,0Xda,0X85,0X90,0Xcd,0X0a,0X83,0X40,0X10,0X83,
  0X67,0Xd5,0Xba,0Xab,0Xf5,0Xaf,0Xe8,0X49,0Xdb,0X8a,0X87,0Xbe,0Xff,0X2b,
  0X3a,0X09,0X44,0X58,0X10,0X7a,0Xc8,0X47,0X08,0X99,0X9d,0X61,0X43,0X69,
  0X66,0X5d,0X74,0X7c,0X5c,0X06,0Xb3,0Xba,0X02,0Xcc,0Xe1,0X2a,0X60,0X26,
  0X57,0X99,0Xd0,0X8c,0X2a,0X54,0X57,0X81,0X79,0Xad,0Xfc,0X01,0Xb3,0X2b,
  0X99,0X35,0Xf2,0X96,0Xf9,0Xb9,0X12,0X47,0X5a,0Xb2,0Xd1,0X20,0Xcd,0X0b,
  0Xf9,0Xd5,0X67,0Xe1,0Xa9,0X02,0Xcd,0X57,0Xd7,0Xa2,0Xd9,0Xa7,0X0a,0X39,
  0Xd0,0X00,0X2d,0X50,0X67,0Xe7,0X0c,0X3a,0X67,0Xfc,0X77,0X4e,0X20,0Xed,
  0X7e,0Xdb,0X82,0X4f,0X80,0Xd9,0Xb2,0X17,0Xb8,0Xdf,0X80,0Xc0,0Xd5,0X40,
  0X04,0Xba,0Xe2,0X04,0Xb0,0X4e,0X05,0X67
  };
static const int OrgSsdutPluginHelloworldPluginPluginXmlDataSize=134;

static QVariant callOrgSsdutPluginHelloworldFeatureMessageReceiverMethod(MExtensionObject* extension, const QString& methodName, QList<void*>& params)
  {
  QVariant result;
  org::ssdut::plugin::helloworld::feature::MessageReceiverInterface* object;
  object=dynamic_cast<org::ssdut::plugin::helloworld::feature::MessageReceiverInterface*>(extension);
  uint hash=qHash(methodName);
  switch(hash)
    {
    case 197928068:
      if(methodName=="void showMessage(const QString& message) const")
        {
        QString p1=*((QString*)(params.at(0)));
        object->showMessage(p1);
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
