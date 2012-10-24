#include "LogicHandler.h"

#define WIDTH 800	//window default width
#define HEIGHT 600	//window default height
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
	while (window->isOpen()){
		sf::Event event;
		while (window->pollEvent(event)){
			handleEvent(event);
        }
		
		clock.restart();
		LogicHandler::update(deltaTime);

		window->clear(sf::Color(20, 180, 255));

		for(int i = 0; i < guiList.size(); i++){
			window->draw(*guiList.at(i));
		}for(int i = 0; i < fgList.size(); i++){
			window->draw(*guiList.at(i));
		}for(int i = 0; i < mgList.size(); i++){
			window->draw(*guiList.at(i));
		}for(int i = 0; i < bgList.size(); i++){
			window->draw(*guiList.at(i));
		}
		
		deltaTime = (double)clock.getElapsedTime().asMicroseconds();

		window->display();
    }
}

void LogicHandler::update(double delta){
	elapsedTime += (delta * 0.00001);

	if(stateHandler->getCurrentState() == NULL){
		stateHandler->getCurrentState()->update(delta);
	}

	for(int i = 0; i < guiList.size(); i++){
		if(guiList.at(i) == NULL){
			guiList.erase(guiList.begin() + i - 1);
		}
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

void LogicHandler::addGuiObj(GuiObject *object){
	guiList.push_back(object);
}

sf::Texture* LogicHandler::getTexture(int index){
	return textureList.at(index);
}

bool LogicHandler::loadRes(std::string dir){
	std::string line;
	std::vector<sf::Texture*> textures;

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

					textures.push_back(tex);
					std::cout << " | " << textures.size() - 1 << " | ";
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
					player->play();
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
	}else{
		return false;
	}

	textureList = textures;
	return true;
}
