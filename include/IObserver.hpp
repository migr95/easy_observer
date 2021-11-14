#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <string>

class IObserver {
public:

    virtual ~IObserver(){};

    virtual void Update() = 0;
};

#endif //IOBSERVER_HPP
