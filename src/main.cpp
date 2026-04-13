#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../include/LinkedList.h"
#include "../include/Stack.h"
#include "../include/Queue.h"
#include "../include/BST.h"
#include "../include/AVL.h"

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(900, 600), "Code Visualizer UI");

    // Data structures
    LinkedList ll;
    StackDS st;
    QueueDS q;
    BST bst;
    AVL avl;

    int selectedDS = 0;

    // Buttons
    sf::RectangleShape btnLL(sf::Vector2f(150, 50));
    btnLL.setPosition(50, 100);
    btnLL.setFillColor(sf::Color::Blue);

    sf::RectangleShape btnStack(sf::Vector2f(150, 50));
    btnStack.setPosition(50, 170);
    btnStack.setFillColor(sf::Color::Blue);

    sf::RectangleShape btnQueue(sf::Vector2f(150, 50));
    btnQueue.setPosition(50, 240);
    btnQueue.setFillColor(sf::Color::Blue);

    sf::RectangleShape btnBST(sf::Vector2f(150, 50));
    btnBST.setPosition(50, 310);
    btnBST.setFillColor(sf::Color::Blue);

    sf::RectangleShape btnAVL(sf::Vector2f(150, 50));
    btnAVL.setPosition(50, 380);
    btnAVL.setFillColor(sf::Color::Blue);

    // Load Font
    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf")) {
        cout << "Error loading font\n";
    }

    // Title
    sf::Text title("Select Data Structure", font, 24);
    title.setPosition(50, 30);
    title.setFillColor(sf::Color::White);

    // Button Texts
    sf::Text textLL("Linked List", font, 16);
    textLL.setPosition(60, 110);

    sf::Text textStack("Stack", font, 16);
    textStack.setPosition(60, 180);

    sf::Text textQueue("Queue", font, 16);
    textQueue.setPosition(60, 250);

    sf::Text textBST("BST", font, 16);
    textBST.setPosition(60, 320);

    sf::Text textAVL("AVL", font, 16);
    textAVL.setPosition(60, 390);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                if (btnLL.getGlobalBounds().contains(x, y)) {
                    selectedDS = 1;
                    cout << "Linked List selected\n";
                }
                if (btnStack.getGlobalBounds().contains(x, y)) {
                    selectedDS = 2;
                    cout << "Stack selected\n";
                }
                if (btnQueue.getGlobalBounds().contains(x, y)) {
                    selectedDS = 3;
                    cout << "Queue selected\n";
                }
                if (btnBST.getGlobalBounds().contains(x, y)) {
                    selectedDS = 4;
                    cout << "BST selected\n";
                }
                if (btnAVL.getGlobalBounds().contains(x, y)) {
                    selectedDS = 5;
                    cout << "AVL selected\n";
                }
            }
        }

        window.clear(sf::Color::Black);

        window.draw(title);

        window.draw(btnLL);
        window.draw(btnStack);
        window.draw(btnQueue);
        window.draw(btnBST);
        window.draw(btnAVL);

        window.draw(textLL);
        window.draw(textStack);
        window.draw(textQueue);
        window.draw(textBST);
        window.draw(textAVL);

        window.display();
    }

    return 0;
}