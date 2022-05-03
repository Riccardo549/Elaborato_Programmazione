//
// Created by Riccardo on 25/03/22.
//

#include <gtest/gtest.h>
#include "Message.h"
#include "User.h"


TEST(Message, Message_GetterSetter_Test) {
    auto f = std::make_shared<User>(User("Francesco"));
    auto a = std::make_shared<User>(User("Annalisa"));
    auto b = std::make_shared<User>(User("Benedetta"));
    auto m = std::make_shared<Message>(Message(f->getName(),a->getName(),"Ciao"));
    m->setSender(b->getName());
    ASSERT_EQ(m->getSender(),"Benedetta");
    m->setRead(true);
    m->setReceiver(f->getName());
    ASSERT_EQ(m->getReceiver(),"Francesco");
    m->setText("Buongiorno!");
    ASSERT_EQ(m->getText(), "Buongiorno!");
}