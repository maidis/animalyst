#ifndef ROOT_H
#define ROOT_H

#include <Cutelyst/Controller>

using namespace Cutelyst;

class Root : public Cutelyst::Controller
{
    Q_OBJECT
    C_NAMESPACE("")
public:
    explicit Root(QObject *parent = nullptr) : Cutelyst::Controller(parent) {}

    C_ATTR(index, :Path :AutoArgs)
    void index(Context *c);

    C_ATTR(search, :Local :AutoArgs)
    void search(Context *c);

    C_ATTR(about, :Local :AutoArgs)
    void about(Context *c);

    C_ATTR(defaultPage, :Path)
    void defaultPage(Context *c);

private:
    C_ATTR(End, :ActionClass("RenderView"))
    void End(Context *c) { Q_UNUSED(c); }
};

#endif
