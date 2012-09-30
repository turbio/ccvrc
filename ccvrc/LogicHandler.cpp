#include "LogicHandler.h"

#define WIDTH 800	//window default width
#define HEIGHT 600	//window default height
#define TITLE "Centa Chicken Vs. Russian Chicken"

GuiObject *bottomBar, *topBar, *healthBar, *manaBar;

//CONSTRUCTOR
LogicHandler::LogicHandler(void){
	titleScreen = true;
	elapsedTime = 1;

	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);

	loadTextures("res/");

	titleScreenBg.setTexture(*textureList.at(0));
	titleScreenBg.setPosition(0, 0);

	setupSprites();

	window->setFramerateLimit(0);
}

void LogicHandler::setupSprites(void){
	//setup all sprites
	bottomBar = new GuiObject();
	bottomBar->setTexture(*textureList.at(1));
	bottomBar->setPosition(0, HEIGHT - bottomBar->getTexture()->getSize().y);
	guiList.push_back(bottomBar);

	topBar = new GuiObject();
	topBar->setTexture(*textureList.at(2));
	topBar->setPosition(0, 0);
	guiList.push_back(topBar);

	healthBar = new GuiObject();
	healthBar->setTexture(*textureList.at(3));
	healthBar->setPosition(79, 486);
	healthBar->setTextureRect(sf::IntRect(1, 0, 1, healthBar->getTexture()->getSize().y));
	healthBar->setScale(235, 1);
	guiList.push_back(healthBar);

	manaBar = new GuiObject();
	manaBar->setTexture(*textureList.at(3));
	manaBar->setPosition(79, 586);
	manaBar->setTextureRect(sf::IntRect(0, 0, 1, manaBar->getTexture()->getSize().y));
	manaBar->setScale(235, 1);
	guiList.push_back(healthBar);
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
			for(int i = 0; i < guiList.size(); i++){
				window->draw(*guiList.at(i));
			}
		}
		
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
