//
// Created by Riccardo on 13/03/22.
//


#ifndef LABORATORYEXERCISE_MESSAGE_H
#define LABORATORYEXERCISE_MESSAGE_H

#include <iostream>
#include <memory>

class Message {
public:
    explicit Message(std::string se, std::string re, std::string te, bool r = false) : sender(se),
                                                                           receiver(re), text(te), read(r){
    }

    bool isRead() const {
        return read;
    }

    void setRead(bool read = true) {
        Message::read = read;
    }

    const std::string &getSender() const {
        return sender;
    }

    const std::string &getReceiver() const {
        return receiver;
    }

    const std::string &getText() const {
        return text;
    }

    void setText(const std::string &text) {
        Message::text = text;
    }

private:
    bool read;
    std::string sender;
    std::string receiver;
    std::string text;
};


#endif //LABORATORYEXERCISE_MESSAGE_H
