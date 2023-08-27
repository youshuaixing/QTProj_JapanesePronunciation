#include "projconfig.h"
#include <QApplication>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDir>

ProjConfig* ProjConfig::instance()
{
    static ProjConfig* pProjConfig = nullptr;
    if (pProjConfig == NULL)
    {
        pProjConfig = new ProjConfig();
    }
    return pProjConfig;
}

ProjConfig::ProjConfig() :
    mSetting(new QSettings(QApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat))
{
    mSetting->setIniCodec("UTF-8");
}

ProjConfig::~ProjConfig()
{
    delete mSetting;
}

void ProjConfig::setIsFirstPopup(bool isFirst)
{
    mSetting->setValue(KEY_FIRST_POPUP, isFirst);
}

bool ProjConfig::getIsFirstPopup()
{
    if(mSetting->contains(KEY_FIRST_POPUP))
        return mSetting->value(KEY_FIRST_POPUP).toBool();
    else
        return true;
}
