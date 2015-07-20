#include <qapplication.h>
#include <mpluginmanager.h>
#include <mextensionmanager.h>
#include <org.ssdut.plugin.helloworld.feature.messageprovider.h>
#include <org.ssdut.plugin.helloworld.feature.messagereceiver.h>
using namespace org::ssdut::plugin::helloworld::feature;
int main(int argc, char *argv[]){
QApplication app(argc, argv);
MPluginManager::initialize(false);
//获得插件管理器
MPluginManager pmanager = MPluginManager::getManager();
Q_ASSERT(!pmanager.isNull());
bool ok = pmanager.loadAllPlugins();
Q_ASSERT(ok);
//获得全局扩展管理器
MExtensionManager extManager = MExtensionManager::getManager();
Q_ASSERT(!extManager.isNull());
QString name = "org.ssdut.plugin.helloworld.feature.MessageProvider";
//获得 provider 扩展
MessageProvider provider = extManager.createExtension(name);
//获得 receiver 扩展
name = "org.ssdut.plugin.helloworld.feature.MessageReceiver";
MessageReceiver receiver = extManager.createExtension(name);
if(provider.isNull() || receiver.isNull()){
return 0;
}
//从 provider 获得信息,并使用 receiver 显示。
receiver.showMessage("/home/ghw/Desktop/log.txt");
return 0;
}
 
