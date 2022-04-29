//
// Created by Riccardo on 15/03/22.
//

#ifndef LABORATORYEXERCISE_MESSAGENOTIFIER_H
#define LABORATORYEXERCISE_MESSAGENOTIFIER_H


#include "Observer.h"
#include "Chat.h"
#include "Message.h"
#include <memory>

class MessageNotifier : public Observer {
public:
    MessageNotifier(bool a, std::shared_ptr<Chat> sub);
    virtual ~MessageNotifier();

    void attach() override;

    void detach() override;

    void update() override;

    void draw(std::string x, std::string y);

    bool isActive() const;

    void setActive(bool active);

private:
    bool active;
    std::shared_ptr<Chat> subject;
};


#endif //LABORATORYEXERCISE_MESSAGENOTIFIER_H
