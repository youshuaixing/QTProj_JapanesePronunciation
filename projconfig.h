#ifndef PROJCONFIG_H
#define PROJCONFIG_H

#include "const.h"
#include <QSettings>

class ProjConfig
{
public:
    static ProjConfig* instance();
    ProjConfig();
    ~ProjConfig();

    void setIsFirstPopup(bool);
    bool getIsFirstPopup();

private:
    QSettings *mSetting;
};

#endif // PROJCONFIG_H
