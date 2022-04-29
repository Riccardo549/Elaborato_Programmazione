//
// Created by Riccardo on 13/03/22.
//
#include <iostream>
#include <vector>
#include <list>

#ifndef LABORATORYEXERCISE_OBSERVER_H
#define LABORATORYEXERCISE_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {}
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;

};


#endif //LABORATORYEXERCISE_OBSERVER_H
