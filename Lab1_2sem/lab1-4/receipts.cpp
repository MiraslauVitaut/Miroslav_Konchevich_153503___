#include "receipts.h"

void Receipts::setType(const QString &newType)
{
    type = newType;
}

void Receipts::setBrand(const QString &newBrand)
{
    brand = newBrand;
}

void Receipts::setAcceptanceDate(const QDateTime &newAcceptanceDate)
{
    acceptanceDate = newAcceptanceDate;
}

void Receipts::setExecutionDate(const QDateTime &newExecutionDate)
{
    executionDate = newExecutionDate;
}

void Receipts::setReady_n_y(const QString &newReady_n_y)
{
    ready_n_y = newReady_n_y;
}

const QString &Receipts::getBrand() const
{
    return brand;
}

const QString &Receipts::getType() const
{
    return type;
}

const QString &Receipts::getReady_n_y() const
{
    return ready_n_y;
}

const QDateTime &Receipts::getAcceptanceDate() const
{
    return acceptanceDate;
}

const QDateTime &Receipts::getExecutionDate() const
{
    return executionDate;
}

Receipts::Receipts()
{

}

void Receipts::SetInfo(QString type, QString brand, QString acceptanceDate, QString executionDate, QString ready_n_y)
{
    this->type = type;
    this->brand = brand;
    this->acceptanceDate = QDateTime::fromString(acceptanceDate,"dd.MM.yyyy");
    this->executionDate = QDateTime::fromString(executionDate,"dd.MM.yyyy");
    this->ready_n_y = ready_n_y;
}

void Receipts::showInfo()
{
    qDebug()<<type<<brand<<acceptanceDate.toString("dd.MM.yyyy")<<executionDate.toString("dd.MM.yyyy")<<ready_n_y;
}

QString Receipts::showInfoDisplay()
{
    return type+" "+ brand + " " + acceptanceDate.toString("dd.MM.yyyy") + " " + executionDate.toString("dd.MM.yyyy") + " " + ready_n_y;
}

QString Receipts::saveInfo()
{
    return type+"\n"+ brand + "\n" + acceptanceDate.toString("dd.MM.yyyy") + "\n" + executionDate.toString("dd.MM.yyyy") + "\n" + ready_n_y+"\n";

}
