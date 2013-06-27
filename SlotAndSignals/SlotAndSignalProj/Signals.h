#ifndef SIGNALS_H
#define SIGNALS_H

#include <QObject>

class Signals : public QObject
{
    Q_OBJECT
public:
    explicit Signals(QObject *parent = 0);

    void doSomeWork();
    
signals:
    void sendASignal();
    
public slots:
    
};

#endif // SIGNALS_H
