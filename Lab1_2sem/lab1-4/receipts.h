#ifndef RECEIPTS_H
#define RECEIPTS_H

#include <QString>
#include <QDateTime>
#include <QDebug>

class Receipts
{
private:
    QString type="_";
    QString brand="_";
    QDateTime acceptanceDate = QDateTime::fromString("01.01.2000","dd.MM.yyyy");;
    QDateTime executionDate = QDateTime::fromString("01.01.2000","dd.MM.yyyy");;
    QString ready_n_y="_";
public:
    Receipts();
    void SetInfo(QString type, QString brand, QString acceptanceDate, QString executionDate, QString ready_n_y);
    void showInfo();
    QString showInfoDisplay();
    QString saveInfo();
    void setType(const QString &newType);
    void setBrand(const QString &newBrand);
    void setAcceptanceDate(const QDateTime &newAcceptanceDate);
    void setExecutionDate(const QDateTime &newExecutionDate);
    void setReady_n_y(const QString &newReady_n_y);
    const QString &getBrand() const;
    const QString &getType() const;
    const QString &getReady_n_y() const;
    const QDateTime &getAcceptanceDate() const;
    const QDateTime &getExecutionDate() const;
};

#endif // RECEIPTS_H
