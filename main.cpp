#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1360, 760), "Pong Game", sf::Style::Close);
    window.setFramerateLimit(60);

    sf::RectangleShape player1;
    sf::RectangleShape player2;

    sf::Text p1ScoreText;
    sf::Text p2ScoreText;
    sf::Font font;
    font.loadFromFile("../font/ARIAL.TTF");
    p1ScoreText.setFont(font);
    p2ScoreText.setFont(font);
    p1ScoreText.setString("0");
    p2ScoreText.setString("0");
    p1ScoreText.setCharacterSize(48);
    p2ScoreText.setCharacterSize(48);

    p1ScoreText.setPosition(580, 100);
    p2ScoreText.setPosition(780, 100);

    player1.setFillColor(sf::Color::White);
    player2.setFillColor(sf::Color::White);
    player1.setSize(sf::Vector2f(15, 100));
    player2.setSize(sf::Vector2f(15, 100));
    player1.setPosition(30,330);
    player2.setPosition(1325,330);

    float y1 = player1.getPosition().y;
    float y2 = player2.getPosition().y;
    float vy1 = 0.0f;
    float vy2 = 0.0f;
    float speed = 350.0f;
    bool p1move,p2move;
    p1move = false;
    p2move = false;
    sf::Clock clock;
    int p1Score = 0;
    int p2Score = 0;

    sf::CircleShape ball;
    ball.setFillColor(sf::Color::White);
    ball.setRadius(7);
    ball.setPosition(1360/2, 760/2);
    float bvx = 0.0f;
    float bvy = 0.0f;
    float bx = ball.getPosition().x;
    float by = ball.getPosition().y;
    float ballSpeed = 500.0f;
    bvx = ballSpeed * 0.707f;
    bvy = ballSpeed * 0.707f;

    const int TOP_Y = 0;
    const int BOTTOM_Y = 760-ball.getRadius();
    const int LEFT_X = 0;
    const int RIGHT_X = 1360-ball.getRadius();

    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            vy1 = speed;
            p1move = true;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            p1move = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            vy1 = -speed;
            p1move = true;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            p1move = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            vy2 = -speed;
            p2move = true;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            p2move = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            vy2 = speed;
            p2move = true;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            p2move = false;
        }

        if (!p1move)
        {
            vy1 = 0.0f;
        }
        if (!p2move)
        {
            vy2 = 0.0f;
        }

        float dt = clock.restart().asSeconds();
        y1 += vy1 * dt;
        y2 += vy2 * dt;

        if (y1 > 660)
        {
            y1 = 660;
        }
        if (y2 > 660)
        {
            y2 = 660;
        }
        if (y1 < 0)
        {
            y1 = 0;
        }
        if (y2 < 0)
        {
            y2 = 0;
        }

        if (by<TOP_Y || by>BOTTOM_Y)
        {
            bvy = -bvy;
        }

        if (bx > RIGHT_X)
        {
            // Player1 scores
            p1Score++;
        }
        if (bx < LEFT_X)
        {
            // Player2 scores
            p2Score++;
        }

        if (bx > RIGHT_X || bx < LEFT_X)
        {
            bx = 1360/2;
            by = 760/2;
            bvx = -bvx;
            bvy = -bvy;
        }


        if (ball.getGlobalBounds().intersects(player1.getGlobalBounds()) || ball.getGlobalBounds().intersects(player2.getGlobalBounds()))
        {
            bvx = -bvx;
        }

        p1ScoreText.setString(std::to_string(p1Score));
        p2ScoreText.setString(std::to_string(p2Score));

        bx += bvx * dt;
        by += bvy * dt;
        player1.setPosition(player1.getPosition().x, y1);
        player2.setPosition(player2.getPosition().x,y2);
        ball.setPosition(bx,by);
        // Rendering
        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.draw(p1ScoreText);
        window.draw(p2ScoreText);
        window.display();
    }

    return 0;
}