//
// Created by Riccardo on 15/03/22.
//

#include "IconBadgeMonitor.h"

IconBadgeMonitor::IconBadgeMonitor(std::shared_ptr<Chat> sub) : subject(sub) {

}

IconBadgeMonitor::~IconBadgeMonitor() {

}

void IconBadgeMonitor::attach() {
    std::shared_ptr<IconBadgeMonitor> ptr = std::make_shared<IconBadgeMonitor>(*this);
    subject->subscribe(ptr);
}

void IconBadgeMonitor::detach() {
    std::shared_ptr<IconBadgeMonitor> ptr = std::make_shared<IconBadgeMonitor>(*this);
    subject->unsubscribe(ptr);
}

void IconBadgeMonitor::update() {
    this->draw(subject->getUnreadMessages());
}

void IconBadgeMonitor::draw(int num) {
    std::cout <<"Per " << subject->getMyName() << ": Hai " << num << " messaggi non letti" << std::endl;
}
