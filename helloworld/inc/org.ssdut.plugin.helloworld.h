#ifndef ORG_SSDUT_PLUGIN_HELLOWORLD_H
#define ORG_SSDUT_PLUGIN_HELLOWORLD_H

#include <mplugin.h>

class OrgSsdutPluginHelloworldPlugin:public MPluginObject
  {
  public:
    OrgSsdutPluginHelloworldPlugin();
    virtual ~OrgSsdutPluginHelloworldPlugin();
  public:
    bool initialize();
    bool cleanup();
    void start();
    void stop();
    void setupMetaTypes();
  public:
    QByteArray getPluginXml() const;
    QStringList getRequiredFeatures() const;
    QString getTextStringForId(qint32) const;
    QVariant getData(const QString& text) const;
    int convertData(QVariant&, const QString& type) const;
  protected:
    QVariant callMethod(MExtensionObject*, const QString&, const QString&, QList<void*>&);
    MExtensionObject* createObject(const QString&);
    MExtensionObject* createOrgSsdutPluginHelloworldFeatureMessageProvider();
    MExtensionObject* createOrgSsdutPluginHelloworldFeatureMessageReceiver();
  private:
    bool _running;
  };

#endif /* ORG_SSDUT_PLUGIN_HELLOWORLD_H */
