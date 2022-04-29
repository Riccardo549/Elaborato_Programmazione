//
// Created by Riccardo on 13/03/22.
//

#ifndef LABORATORYEXERCISE_CHAT_H
#define LABORATORYEXERCISE_CHAT_H

#include "Subject.h"
#include "Observer.h"
#include "Message.h"
#include <list>
#include <vector>
#include <memory>

class Chat : public Subject {
public:

    Chat(std::string se, std::string re);

    virtual ~Chat();

    void addMessage(std::shared_ptr<Message> newMsg);

    const std::shared_ptr<Message> &lastMessage() const;

    void setReadByPosition(int i);

    int getUnreadMessages() const;

    void subscribe(std::shared_ptr<Observer> obj) override;

    void unsubscribe(std::shared_ptr<Observer> obj) override;

    void notify() override;

    const std::string &getMyName() const;

    void setMyName(const std::string &myName);

    const std::string &getOtherName() const;

    void setOtherName(const std::string &otherName);

    void setTextByPosition (int pos, std::string text);

    const std::string &getTextByPosition(int pos);

private:
    std::list<std::shared_ptr<Observer>> observers;
    std::vector<std::shared_ptr<Message>> messages;
    std::string myName;
    std::string otherName;
};


#endif //LABORATORYEXERCISE_CHAT_H
