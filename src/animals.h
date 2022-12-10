#ifndef ANIMALS_H
#define ANIMALS_H

#include <Cutelyst/Application>

class Animals : public Cutelyst::Application
{
    Q_OBJECT
    CUTELYST_APPLICATION(IID "Animals")
    public:
    Q_INVOKABLE explicit Animals(QObject *parent = nullptr) : Cutelyst::Application(parent) {}

    bool init() override;

    virtual bool postFork() override;
};

#endif
