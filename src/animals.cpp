#include "animals.h"

#include "root.h"

#include <Cutelyst/Plugins/View/Grantlee/grantleeview.h>

#include <QtSql>
#include <Cutelyst/Plugins/Utils/Sql>

using namespace Cutelyst;

Animals::Animals(QObject *parent) : Application(parent)
{
}

Animals::~Animals()
{
}

bool Animals::init()
{
    new Root(this);

    auto view = new GrantleeView(this);
    view->setIncludePaths({ pathTo("root/src") });
    view->setWrapper("wrapper.html");

    return true;
}

bool Animals::postFork()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", Sql::databaseNameThread("Animals"));
    db.setDatabaseName("animals.db");
    db.setConnectOptions("foreign_keys = ON");
    if (!db.open()) {
        qCritical() << "Failed to open database:" << db.lastError().text();
        return false;
    }
    return true;
}
