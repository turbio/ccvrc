#include "GuiObject.h"

//Constructor :#
GuiObject::GuiObject(char n[]){
	name = n;	//set the name of this object
}

GuiObject::~GuiObject(void){

}

//return if clicked or mouse over
sf::Event GuiObject::pollEvent(sf::Event event){
	if(mouseOver()){
		if(event.MouseButtonPressed){
			setTexture(mouseDownTexture);
		}else{
			setTexture(mouseOverTexture);
		}
	}else{
		setTexture(defaultTexture);
	}

	return event;
}

//returns if mouse over this object
bool GuiObject::mouseOver(void){
	return false;	//not done yet
}