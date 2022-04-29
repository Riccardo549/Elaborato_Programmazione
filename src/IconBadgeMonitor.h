//
// Created by Riccardo on 15/03/22.
//

#ifndef LABORATORYEXERCISE_ICONBADGEMONITOR_H
#define LABORATORYEXERCISE_ICONBADGEMONITOR_H


#include "Observer.h"
#include "Chat.h"
#include <memory>

class IconBadgeMonitor : public Observer {
public:
    IconBadgeMonitor(std::shared_ptr<Chat> sub);
    virtual ~IconBadgeMonitor();

    void attach() override;

    void detach() override;

    void update() override;

    void draw(int um);


private:
    std::shared_ptr<Chat> subject;
};


#endif //LABORATORYEXERCISE_ICONBADGEMONITOR_H
