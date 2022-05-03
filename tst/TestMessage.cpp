//
// Created by Riccardo on 25/03/22.
//

#include <gtest/gtest.h>
#include "Message.h"
#include "User.h"

class TestMessage: public::testing::Test{
public:
    virtual void SetUp(){
        f = std::make_shared<User>(User("Francesco"));
        a = std::make_shared<User>(User("Annalisa"));
        b = std::make_shared<User>(User("Benedetta"));
        m = std::make_shared<Message>(Message(f->getName(),a->getName(),"Ciao"));
    }

    std::shared_ptr<User> f;
    std::shared_ptr<User> a;
    std::shared_ptr<User> b;
    std::shared_ptr<Message> m;


};


TEST_F(TestMessage, Message_GetterSetter_Test) {
    m->setSender(b->getName());
    ASSERT_EQ(m->getSender(),"Benedetta");
    m->setRead(true);
    m->setReceiver(f->getName());
    ASSERT_EQ(m->getReceiver(),"Francesco");
    m->setText("Buongiorno!");
    ASSERT_EQ(m->getText(), "Buongiorno!");
}