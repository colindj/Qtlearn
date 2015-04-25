/********************************************************************************
** Form generated from reading UI file 'logindig.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIG_H
#define UI_LOGINDIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Logindig
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *Logindig)
    {
        if (Logindig->objectName().isEmpty())
            Logindig->setObjectName(QStringLiteral("Logindig"));
        Logindig->resize(400, 300);
        pushButton = new QPushButton(Logindig);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 120, 80, 25));

        retranslateUi(Logindig);
        QObject::connect(pushButton, SIGNAL(clicked()), Logindig, SLOT(accept()));

        QMetaObject::connectSlotsByName(Logindig);
    } // setupUi

    void retranslateUi(QDialog *Logindig)
    {
        Logindig->setWindowTitle(QApplication::translate("Logindig", "Dialog", 0));
        pushButton->setText(QApplication::translate("Logindig", "\347\231\273\345\275\225\345\210\260\344\270\273\347\225\214\351\235\242", 0));
    } // retranslateUi

};

namespace Ui {
    class Logindig: public Ui_Logindig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIG_H
