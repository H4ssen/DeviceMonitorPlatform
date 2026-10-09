#pragma once
#include <vector>
#include <QPluginLoader>
#include <QString>
#include "transportFactory.h"
#include "ITransportPlugin.h"


class PluginManager {

    public:
        void loadPLugins(TransportFactory& factory, const QString& pluginDir) {
            QDir dir(pluginDir);
            for (const QString& fileName : dir.entryList(QDir::Files)) {
                auto loader = std::make_unique<QPluginLoader>(dir.absoluteFilePath(fileName));
                QObject* plugin = loader->instance();

                if (!plugin) {
                    //cout error
                }

                auto* transportPlugin =  qobject_cast<ITransportPlugin*>(plugin);

                if (!transportPlugin) {
                    //cout error
                }

                factory.registerType(transportPlugin->typeName(),[transportPlugin](const TransportConfig& config) {
                    return transportPlugin->create(config);
                });
            }
        }

    private:
        std::vector<QPluginLoader> loaders_;
};