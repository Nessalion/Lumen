#pragma once
#include "TextBox.h"
Mouse c;
class Button {
public:
	Sprite Box;
	Mouse& mouse = c;
	Texture Main;
	Texture Hover;

	Button(string main, string hover = "None") {

		Main.loadFromFile(main);
		Box.setTexture(Main);
		if (hover != "None") Hover.loadFromFile(hover);
	}


	Button() {};

	~Button() {};
	void setPosition(Vector2f position) {
		Box.setPosition(position);

	}

	bool isHover(RenderWindow& Current) {
		if (mouse.getPosition(Current).x >= Box.getPosition().x && mouse.getPosition(Current).x < Main.getSize().x + Box.getPosition().x && mouse.getPosition(Current).y >= Box.getPosition().y && mouse.getPosition(Current).y < Main.getSize().y + Box.getPosition().y) return true;
		else return false;
	}

	bool isClicked(RenderWindow& current) {
		if (mouse.isButtonPressed(Mouse::Left) && isHover(current)) return true;
		else return false;
	}
};