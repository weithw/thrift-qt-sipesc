#ifndef REGISTDIALOG_H
#define REGISTDIALOG_H

#include <QDialog>

namespace Ui {
class RegistDialog;
}

class RegistDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RegistDialog(QWidget *parent = 0);
    ~RegistDialog();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::RegistDialog *ui;
};

#endif // REGISTDIALOG_H
