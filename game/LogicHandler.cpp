#include "LogicHandler.h"

#define WIDTH 640	//window default width
#define HEIGHT 480	//window default height
#define TITLE "game title"

sf::RectangleShape shape;

//CONSTRUCTOR
LogicHandler::LogicHandler(void){
	titleScreen = true;
	elapsedTime = 1;

	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);

	shape.setSize(sf::Vector2f(10.0f, 10.0f));
	if(!LogicHandler::loadTextures("res/")){
		shape.setFillColor(sf::Color::Red);
	}else{
		shape.setFillColor(sf::Color::Green);
	}

	titleScreenBg.setTexture(*textureList.at(0));
	titleScreenBg.setPosition(0, 0);

	setupSprites();

	window->setFramerateLimit(0);
}

void LogicHandler::setupSprites(void){
	//setup all sprites
}

//DESTRUCTOR
LogicHandler::~LogicHandler(void){

}

void LogicHandler::run(void){

	double deltaTime = 0;
	sf::Clock clock;
	while (window->isOpen()){
		sf::Event event;
		while (window->pollEvent(event)){
			handleEvent(event);
        }
		
		clock.restart();
		LogicHandler::update(deltaTime);

		window->clear(sf::Color(20, 180, 255));

		//render
		if(titleScreen){
			window->draw(titleScreenBg);
		}else{
			for(int i = 0; i < spriteList.size(); i++){
				window->draw(*spriteList.at(i));
			}
		}

		window->draw(shape);
		
		deltaTime = (double)clock.getElapsedTime().asMicroseconds();

		window->display();
    }
}

void LogicHandler::update(double delta){
	elapsedTime += (delta * 0.00001);

	//update game objects
}

void LogicHandler::handleEvent(sf::Event evt){
	if (evt.type == sf::Event::Closed){
		window->close();
	}else if((evt.type == sf::Event::KeyPressed ||
		evt.type == sf::Event::MouseButtonPressed) && titleScreen){
			titleScreen = false;
	}
}

bool LogicHandler::loadTextures(std::string dir){
	std::string line;
	std::vector<sf::Texture*> textures;

	std::ifstream file(dir + "res.txt");

	if(file.is_open()){
		while(file.good()){
			std::getline(file, line);
			
			std::cout << "res: " << line;

			sf::Texture *tex;
			tex = new sf::Texture;
			if(!tex->loadFromFile( dir + line)){
				return false;
			}
			textures.push_back(tex);
			
			std::cout << " loaded" << std::endl;
		}
		file.close();
	}else{
		return false;
	}

	textureList = textures;
	return true;
}
