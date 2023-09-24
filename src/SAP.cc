
#include "../include/SAP.hh"
#include "SFML/Audio/Sound.hpp"
#include <stdio.h>

int main() {
    // Inisialisasi SFML
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Audio");
    sf::Music music;
    sf::Sound sound;

    // Load music
    if (!music.openFromFile("../sample.ogg")) {
        printf("Failed to load audio file");
        return 1;
    }

    // Putar audio
    music.setVolume(10.0f);
    music.play();

    // Loop utama
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Tambahan: Hentikan audio jika tombol Escape ditekan
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            music.stop();
        }

        window.clear();
        window.display();
    }

    return 0;
}
