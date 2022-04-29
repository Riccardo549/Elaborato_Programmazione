#include <iostream>
#include "Chat.h"
#include "User.h"
#include "Message.h"
#include "MessageNotifier.h"
#include "IconBadgeMonitor.h"

int main() {
    auto a = std::make_shared<User>(User("Riccardo"));
    auto b = std::make_shared<User>(User("Eleonora"));
    auto c = std::make_shared<User>(User("Jacopo"));

    auto ch = std::make_shared<Chat>(Chat(a->getName(), c->getName()));

    try {
        a->addChat(std::make_shared<Chat>(Chat(a->getName(), b->getName())));
        //b->addChat(a->findChat(c)); //a non ha una chat con c
        //b->addChat(ch);  //ch non è una chat con b
        b->addChat(a->findChat(b));

        MessageNotifier messageNotifier = MessageNotifier(true, a->findChat(b));
        IconBadgeMonitor iconBadgeMonitor = IconBadgeMonitor(a->findChat(b));

        iconBadgeMonitor.attach();
        messageNotifier.attach();

        a->sendMessage(b, std::make_shared<Message>(Message(a->getName(), b->getName(), "E' uscito al cinema il nuovo film di Spider-Man!")));
        a->sendMessage(b, std::make_shared<Message>(Message(a->getName(), b->getName(), "Lo andiamo a vedere insieme?")));
        b->sendMessage(a, std::make_shared<Message>(Message(b->getName(), a->getName(), "Vengo molto volentieri!")));
        a->sendMessage(b, std::make_shared<Message>(Message(a->getName(), b->getName(), "Allora a stasera!")));
        b->sendMessage(a, std::make_shared<Message>(Message(b->getName(), a->getName(), "A dopoo!")));
        //a->sendMessage(c,std::make_shared<Message>(Message(b->getName(), a->getName(), "A dopoo!")));  //chat con c non esiste
        //a->sendMessage(b,std::make_shared<Message>(Message(c->getName(), a->getName(), "A dopoo!")));  //sender messaggio sbagliatio
        b->setReadByPosition(a, 0);
        //b->setReadByPosition(a,-1);  //posizione negativa
        b->setReadByPosition(a, 1);
        a->setReadByPosition(b, 2);
        b->setReadByPosition(a, 3);
        //a->setReadByPosition(b,5);  //posizione troppo alta
        a->setReadByPosition(b,4);
    } catch (std::runtime_error &e) {
        std::cerr << "Messaggio di errore: runtime_error: " << e.what() << std::endl;
    }
    catch (std::out_of_range &e) {
        std::cerr << "Messaggio di errore: out of range: " << e.what() << std::endl;
    }
}
