#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "IObserver.hpp"
#include "ISubject.hpp"

static unsigned int obs_num = 0;

class Observer: public IObserver {
public:

    Observer(ISubject &subj) : subject(subj) {
        this->subject.Attach(this);
        attached = true;
        this->number = obs_num++;
    }

    virtual ~Observer() {
        DetachFromSubject();
    }

    void Update() override {
        std::cout << "Received update from Subject" << std::endl;
    }

    void DetachFromSubject() {
        if (attached)
        {
            subject.Detach(this);
            attached = false;
        }
    }

    void reAttach() {
        if (!attached)
        {
            subject.Attach(this);
            attached = true;
        }
    }

    void attachToSubject(ISubject &subj, bool override_attach){
        if (!attached)
        {
            subject = subj;
            subject.Attach(this);
            attached = true;
        }
        else if (attached && override_attach)
        {
            std::cout << "Observer already attached! Overriding Subject!" << std::endl;
            DetachFromSubject();
            subject = subj;
            subject.Attach(this);
            attached = true;
        }
        else
        {
            std::cout << "Observer already attached! Can't attach to new Subject!" << std::endl;
        }
    }

private:

    bool attached = false;

    ISubject &subject;

    int number;
};

#endif //OBSERVER_HPP
