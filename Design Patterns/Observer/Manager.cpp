#include "Publisher.h"
#include "Subscriber.h"

int main () {
    std::unique_ptr<Subscriber> Dennis = std::make_unique<Subscriber>("Dennis");
    std::unique_ptr<Subscriber> Charles = std::make_unique<Subscriber>("Charles");
    std::unique_ptr<Subscriber> Parkinson = std::make_unique<Subscriber>("Parkinson");
    std::unique_ptr<Subscriber> Walsh = std::make_unique<Subscriber>("Walsh");
    std::unique_ptr<Subscriber> Markus = std::make_unique<Subscriber>("Markus");
    std::unique_ptr<Subscriber> Jeenie = std::make_unique<Subscriber>("Jeenie");

    Publisher* textPublisher = new Publisher(std::move(Dennis));

    textPublisher->add_subscriber(std::move(Charles));
    textPublisher->send_udpate("Texting");

    textPublisher->add_subscriber(std::move(Parkinson));
    textPublisher->add_subscriber(std::move(Walsh));

    textPublisher->remove_subscriber("Dennis");
    textPublisher->add_subscriber(std::move(Markus));
    textPublisher->add_subscriber(std::move(Jeenie));

    textPublisher->send_udpate("Texting");

    delete textPublisher;

}