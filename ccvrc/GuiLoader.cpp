#include "GuiLoader.h"

GuiLoader::GuiLoader(void){

}

GuiLoader::~GuiLoader(void){

}

void GuiLoader::LoadFile(std::string path){
	std::string line = "";
	std::ifstream file(path);

	if(file.is_open()){
		while(file.good()){
			std::getline(file, line);


		}
	}else{
		std::cout << "unable to open file: \"" << path << "\"" << std::endl;
	}
}
