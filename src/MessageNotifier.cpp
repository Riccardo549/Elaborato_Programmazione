//
// Created by Riccardo on 15/03/22.
//

#include "MessageNotifier.h"

MessageNotifier::MessageNotifier(bool a, std::shared_ptr<Chat> sub) : active(a), subject(sub) {

}

MessageNotifier::~MessageNotifier() {

}

void MessageNotifier::attach() {
    subject->subscribe(std::make_shared<MessageNotifier>(*this));
}

void MessageNotifier::detach() {
    subject->unsubscribe(std::make_shared<MessageNotifier>(*this));
}

void MessageNotifier::update() {
    if(active)
        this->draw(subject->lastMessage()->getSender(), subject->lastMessage()->getText().substr(0,100));
}

void MessageNotifier::draw(std::string x, std::string y) {
    std::cout << "Ultimo messaggio da parte di " << x << ": " << y << "...\n" << std::endl;
}


void MessageNotifier::setActive(bool active) {
    MessageNotifier::active = active;
}
