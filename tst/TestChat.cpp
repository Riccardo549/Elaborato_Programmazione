//
// Created by Riccardo on 24/03/22.
//

#include "gtest/gtest.h"
#include "Chat.h"

class TestChat : public::testing::Test{
public:
    TestChat(){}
    virtual void SetUp()  {
        ch = std::make_shared<Chat>(Chat("Francesco","Annalisa"));
    }
    std::shared_ptr<Chat> ch;

};

TEST_F(TestChat, Chat_GetterSetter_Test) {
    ASSERT_EQ(ch->getMyName(), "Francesco");
    ASSERT_EQ(ch->getOtherName(), "Annalisa");
    ch->setMyName("Lorenzo");
    ch->setOtherName("Benedetta");
    ASSERT_EQ(ch->getMyName(), "Lorenzo");
    ASSERT_EQ(ch->getOtherName(), "Benedetta");
}

TEST_F(TestChat, Chat_Func_Test) {
    ASSERT_EQ(ch->getTextByPosition(0), "Ciao come va?");
    ASSERT_EQ(ch->getTextByPosition(1), "Tutto bene, te?");

    ASSERT_NO_THROW(ch->setReadByPosition(0));
    ASSERT_NO_THROW(ch->setTextByPosition(1, "Potrebbe andare meglio."));
    ASSERT_NE(ch->getTextByPosition(1), "Tutto bene, te?");
    ASSERT_EQ(ch->getTextByPosition(1), "Potrebbe andare meglio.");
}
//test posizione non presente
TEST_F(TestChat, Chat_Ecx_Test) {
    ASSERT_THROW(ch->addMessage(std::make_shared<Message>(Message("Benedetta", "Annalisa", "Come va?"))), std::runtime_error);
    ASSERT_THROW(ch->setReadByPosition(5), std::out_of_range);
    ASSERT_THROW(ch->setTextByPosition(5, "Chiudiamo la conversazione qui"), std::out_of_range);
}