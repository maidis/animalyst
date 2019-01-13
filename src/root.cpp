#include "root.h"

#include <QtSql>
#include <Cutelyst/Plugins/Utils/Sql>

using namespace Cutelyst;

Root::Root(QObject *parent) : Controller(parent)
{
}

Root::~Root()
{
}

void Root::defaultPage(Context *c)
{
    c->response()->body() = "Page not found!";
    c->response()->setStatus(404);
}

void Root::about(Context *c)
{
    c->setStash("template", "about.html");
}

void Root::index(Context *c)
{
     QSqlQuery query = CPreparedSqlQueryThreadForDB("SELECT name,image FROM animals", "Animals");
     if (query.exec()) {
         c->setStash("animals", Sql::queryToHashList(query));
     }

    c->setStash("template", "list.html");
}


void Root::search(Context *c)
{
    QSqlQuery query;

    QString searchText = c->req()->queryParam(QStringLiteral("q"));

    query = CPreparedSqlQueryThreadForDB(
                QStringLiteral("SELECT name,image FROM animals "
                               "WHERE name LIKE '%'||:search||'%'"),
                QStringLiteral("Animals"));
    // https://forum.qt.io/topic/78303/why-doesn-t-bind-work-with-this-query/8
    query.bindValue(QStringLiteral(":search"), searchText);
     if (query.exec()) {
         c->setStash("animals", Sql::queryToHashList(query));
     }
     c->setStash("template", "list.html");
}
