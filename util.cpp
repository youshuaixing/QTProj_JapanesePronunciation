#include "util.h"

void ShowMessageBox(QString message, bool onceFirst)
{
    if(onceFirst)
    {
        if(!ProjConfig::instance()->getIsFirstPopup())
            return;
        else
            ProjConfig::instance()->setIsFirstPopup(false);
    }

    QMessageBox* msgBox = new QMessageBox(QMessageBox::Information, QString("Tips"), message, QMessageBox::Ok);
    msgBox->setModal(false); // 设置为非阻塞式
    msgBox->setAttribute(Qt::WA_DeleteOnClose); //关掉消息框后删除指针
    msgBox->show();
}
