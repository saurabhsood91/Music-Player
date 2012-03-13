#ifndef HELPUI_H
#define HELPUI_H

#include<QDialog>
#include "ui_helpdialog.h"

class helpdialog: public QDialog, Ui::Dialog{
    Q_OBJECT
//     Invoke meta object compiler, Qt code is converted into C++
//     Looks for SIGNAL and SLOT keywords and work on them
   public: helpdialog(); // Constructor
};

#endif // HELPUI_H
