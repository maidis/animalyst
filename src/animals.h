#ifndef ANIMALS_H
#define ANIMALS_H

#include <Cutelyst/Application>

using namespace Cutelyst;

class Animals : public Application
{
    Q_OBJECT
    CUTELYST_APPLICATION(IID "Animals")
public:
    Q_INVOKABLE explicit Animals(QObject *parent = nullptr);
    ~Animals();

    bool init();

    virtual bool postFork() override;
};

#endif
