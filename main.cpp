#include<iostream>
#include"SFML/Graphics.hpp"
using namespace std;
using namespace sf;


int main() {

    //game set up (you'll need these two lines in every game)
    RenderWindow renderWindow(VideoMode(500, 500), "Pong Paddle"); //set up screen
    Event event; //set up event queue

    //paddle1 set up
    RectangleShape paddle1(Vector2f(25.0f, 100.0f));
    paddle1.setFillColor(Color::Blue); //other colors: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php
    paddle1.setPosition(450.0f, 250.0f); //set position: this is where the top left corner will be

    RectangleShape paddle2(Vector2f(25.0f, 100.0f));
    paddle2.setFillColor(Color::Blue); //other colors: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php
    paddle2.setPosition(50.0f, 250.0f); //set position: this is where the top left corner will be

    //ball set up
    CircleShape ball(100);
    ball.setFillColor(Color(200, 50, 50));
    ball.setPosition(0, 0);

    float bx = 250;
    float by = 250;
    float xv = .01;
    float yv = .01;

    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (renderWindow.isOpen()) {//keep window open until user shuts it down
        while (renderWindow.pollEvent(event)) { //look for events

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == Event::EventType::Closed)
                renderWindow.close();

            //KEYBOARD INPUT (just one key to start
            if (Keyboard::isKeyPressed(Keyboard::W)) { //checks if "W" is pressed
                paddle2.move(0, -5); //move the rectangle 5 pixels UP on the y axis
                cout << "rectangle moving up" << endl; //for Mo's testing, you can take this out
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) { //checks if "W" is pressed
                paddle2.move(0, 5); //move the rectangle 5 pixels UP on the y axis
                cout << "rectangle moving down" << endl; //for Mo's testing, you can take this out
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) { //checks if "W" is pressed
                paddle1.move(0, -5); //move the rectangle 5 pixels UP on the y axis
                cout << "rectangle moving up" << endl; //for Mo's testing, you can take this out
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) { //checks if "W" is pressed
                paddle1.move(0, 5); //move the rectangle 5 pixels UP on the y axis
                cout << "rectangle moving down" << endl; //for Mo's testing, you can take this out
            }
        }
        if (bx < 0 || bx > 500)
        bx += xv;
        by += yv;
        ball.setPosition(bx, by);
        //render section-----------------------------------------
        renderWindow.clear(); //wipes screen, without this things smear
        renderWindow.draw(ball);
        renderWindow.draw(paddle1); //you gotta drew each object
        renderWindow.draw(paddle2); //you gotta drew each object
        renderWindow.display(); //flips memory drawings onto screen

    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
} //end game
