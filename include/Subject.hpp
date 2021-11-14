#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <list>

#include "ISubject.hpp"

class Subject: public ISubject {
public:

    virtual ~Subject(){};

    void Attach(IObserver *observer) override {
        std::cout << "Attaching Observer" << std::endl;
        list_observer.push_back(observer);
    }

    void Detach(IObserver *observer) override {
        std::cout << "Detaching Observer" << std::endl;
        list_observer.remove(observer);
    }

    void Notify() override {
        std::list<IObserver *>::iterator iterator = list_observer.begin();
        while (iterator != list_observer.end()) {
            (*iterator)->Update();
            ++iterator;
        }
    }

private:
    std::list<IObserver *> list_observer;
};

#endif //SUBJECT_HPP
