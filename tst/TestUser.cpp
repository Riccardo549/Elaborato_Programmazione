//
// Created by Riccardo on 25/03/22.
//

#include "gtest/gtest.h"
#include "User.h"

class TestUser : public :: testing::Test{
public:
    TestUser(){}

    std::shared_ptr<User> a;
    std::shared_ptr<User> b;
    std::shared_ptr<User> c;
};


TEST_F(TestUser, User_GetterSetter_Test) {
    ASSERT_EQ(a->getName(), "Francesco");
    ASSERT_EQ(b->getName(), "Benedetta");
    ASSERT_EQ(c->getName(), "Lorenzo");
}

TEST_F(TestUser, User_Func_Test) {
    ASSERT_NO_THROW(b->addChat(std::make_shared<Chat>(Chat(b->getName(), a->getName()))));
    ASSERT_NO_THROW(a->addChat(b->findChat(a)));
    ASSERT_NO_THROW(b->sendMessage(a, std::make_shared<Message>(Message(b->getName(), a->getName(), "Ciao come va?"))));
    ASSERT_NO_THROW(a->sendMessage(b, std::make_shared<Message>(Message(b->getName(), a->getName(), "Tutto bene, tu?"))));
    ASSERT_NO_THROW(b->sendMessage(a, std::make_shared<Message>(Message(b->getName(), a->getName(), "Bene grazie, volevo invitarti al mio diciottesimo"))));
    ASSERT_NO_THROW(a->sendMessage(b, std::make_shared<Message>(Message(b->getName(), a->getName(), "Sarò presente!"))));
}

TEST_F(TestUser, User_ReadText_Test) {
    ASSERT_NO_THROW(a->setReadByPosition(b, 0));
    ASSERT_NO_THROW(b->setReadByPosition(a, 1));
    ASSERT_NO_THROW(a->setTextByPosition(b, 3, "Ti faccio sapere al più presto"));
    ASSERT_EQ(b->getTextByPosition(b, 3), "Ti faccio sapere al più presto");
}
//test chat non presente
TEST_F(TestUser, User_Exc_Test) {
    ASSERT_THROW(a->setTextByPosition(b, 7, "Ciao"), std::runtime_error);
    ASSERT_THROW(a->sendMessage(c, std::make_shared<Message>(Message(b->getName(), a->getName(), "Ciao come va?"))), std::runtime_error);

}