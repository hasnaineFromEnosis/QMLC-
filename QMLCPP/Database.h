
#ifndef DATABASE_H
#define DATABASE_H

#include <QHash>
#include <QObject>
#include "person.h"

class Database : public QObject
{
    Q_OBJECT

public:
    explicit Database(QObject* parent = nullptr);
    Q_INVOKABLE Person lookup(const QString& name) const;
    Q_INVOKABLE Person makePerson(const QString& name, int age);
    Q_INVOKABLE void addPerson(const Person& person);

private:
    QHash<QString, Person> m_persons;
};

#endif // DATABASE_H
