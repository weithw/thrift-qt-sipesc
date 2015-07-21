#include <org.ssdut.plugin.helloworld.h>
#include <messageproviderimpl.h>
#include <messagereceiverimpl.h>
#include <qtranslator.h>

OrgSsdutPluginHelloworldPlugin::OrgSsdutPluginHelloworldPlugin()
  {
  _running=false;
  }

OrgSsdutPluginHelloworldPlugin::~OrgSsdutPluginHelloworldPlugin()
  {
  }

bool OrgSsdutPluginHelloworldPlugin::initialize()
  {
  return true;
  }

bool OrgSsdutPluginHelloworldPlugin::cleanup()
  {
  return true;
  }

void OrgSsdutPluginHelloworldPlugin::start()
  {
  if(_running) return;
  _running=true;
  }

void OrgSsdutPluginHelloworldPlugin::stop()
  {
  if(!_running) return;
  _running=false;
  }

QStringList OrgSsdutPluginHelloworldPlugin::
getRequiredFeatures() const
  {
  return QStringList();
  }

MExtensionObject* OrgSsdutPluginHelloworldPlugin
::createOrgSsdutPluginHelloworldFeatureMessageProvider()
  {
  return new MessageProviderImpl;
  }
MExtensionObject* OrgSsdutPluginHelloworldPlugin
::createOrgSsdutPluginHelloworldFeatureMessageReceiver()
  {
  return new MessageReceiverImpl;
  }
