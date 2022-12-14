#ifndef ROOT_H
#define ROOT_H

#include <Cutelyst/Controller>

class Root : public Cutelyst::Controller
{
    Q_OBJECT
    C_NAMESPACE("")
public:
    explicit Root(QObject *parent = nullptr) : Cutelyst::Controller(parent) {}

    C_ATTR(index, :Path :AutoArgs)
    void index(Cutelyst::Context *c);

    C_ATTR(search, :Local :AutoArgs)
    void search(Cutelyst::Context *c);

    C_ATTR(about, :Local :AutoArgs)
    void about(Cutelyst::Context *c);

    C_ATTR(defaultPage, :Path)
    void defaultPage(Cutelyst::Context *c);

private:
    C_ATTR(End, :ActionClass("RenderView"))
    void End(Cutelyst::Context *c) { Q_UNUSED(c); }
};

#endif
