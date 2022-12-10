#include "animals.h"

#include "root.h"

#include <Cutelyst/Plugins/View/Cutelee/cuteleeview.h>

#include <QtSql>
#include <Cutelyst/Plugins/Utils/Sql>

using namespace Cutelyst;

bool Animals::init()
{
    new Root(this);

    auto view = new CuteleeView(this);
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
