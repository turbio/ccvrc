#include "LogicHandler.h"

#define WIDTH 800	//window default width
#define HEIGHT 600	//window	default height
#define TITLE "Centa Chicken Vs. Russian Chicken"

//CONSTRUCTOR
LogicHandler::LogicHandler(void){
	titleScreen = true;
	elapsedTime = 1;

	width = WIDTH;
	height = HEIGHT;
	stateHandler = new StateHandler(&width, &height, this);

	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);

	stateHandler->loading(window);
	loadRes("res/");
	stateHandler->loaded();

	setupSprites();
}

void LogicHandler::setupSprites(void){
	stateHandler->setupGui();
}

//DESTRUCTOR
LogicHandler::~LogicHandler(void){

}

void LogicHandler::run(void){

	double deltaTime = 0;
	sf::Clock clock;

	double startTime, endTime;
	while (window->isOpen()){
		startTime = clock.getElapsedTime().asMicroseconds();

		sf::Event event;
		while (window->pollEvent(event)){
			handleEvent(event);
        }

		LogicHandler::update(deltaTime);
		LogicHandler::render();

		endTime = clock.getElapsedTime().asMicroseconds();

		deltaTime = endTime - startTime;
    }
}

void LogicHandler::render(void){
	window->clear(sf::Color(20, 180, 255));

	if(stateHandler->getCurrentState() != NULL){
		for(int list = 0; list < stateHandler->getCurrentState()->getSpriteList()->size(); list++){
			for(int sprite = 0; sprite < stateHandler->getCurrentState()->getSpriteList()->at(list).size(); sprite++){
				window->draw(*stateHandler->getCurrentState()->getSpriteList()->at(list).at(sprite));
			}
		}
	}

	window->display();
}

void LogicHandler::update(double delta){
	elapsedTime += (delta * 0.00001);

	if(stateHandler->getCurrentState() != NULL){
		stateHandler->getCurrentState()->update(delta);
	}
}

void LogicHandler::handleEvent(sf::Event evt){
	if (evt.type == sf::Event::Closed){
		window->close();
	}else if((evt.type == sf::Event::KeyPressed ||
		evt.type == sf::Event::MouseButtonPressed) && titleScreen){
			titleScreen = false;
	}
}

sf::Texture* LogicHandler::getTexture(std::string index){
	return textureList[index];
}

bool LogicHandler::loadRes(std::string dir){
	std::string line;

	std::ifstream file(dir + "res.txt");

	if(file.is_open()){
		std::cout <<  ":: line | index | loaded +/- ::::: loading from \"" << dir << "\" ::" << std::endl;

		for(int i = 0; i < 53 + dir.length(); i++){
			std::cout << ":";
		}
		std::cout << std::endl;
		
		while(file.good()){
			skip:
			std::getline(file, line);
			
			std::cout <<  ":: " << line;

			if(line.empty() || line.length() <= 3){
				std::cout << "\n"; 
				goto skip;
			}

			if(line.at(0) != '#' && line.length() > 3){
				if(line.substr(line.length() - 3, 3) == "png"){
					sf::Texture *tex;
					tex = new sf::Texture;

					if(!tex->loadFromFile(dir + line)){
						delete tex;
						std::cout << "-" << std::endl;
						goto skip;
					}

					textureList[line] = tex;
					std::cout << " | index:" << line << ": | ";
					std::cout << "+";
				}else if(line.substr(line.length() - 3, 3) == "ogg"){
					sf::SoundBuffer *buffer;
					buffer = new sf::SoundBuffer();

					if(!buffer->loadFromFile(dir + line)){
						delete buffer;
						std::cout << "-" << std::endl;
						goto skip;
					}

					sf::Sound *player = new sf::Sound();
					player->setBuffer(*buffer);
					//player->play();
					player->setLoop(true);

					std::cout << "+";
				}else if(line.substr(line.length() - 3, 3) == "wav"){

				}
			}

			std::cout << std::endl;
		}
		file.close();

		for(int i = 0; i < 53 + dir.length(); i++){
			std::cout << ":";
		}
		std::cout << "\n";
	}else{
		return false;
	}

	return true;
}
