#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace sf;
using namespace std;
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
class Textbox {
public:
	Textbox(int size, Color color, bool sel) {
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		isSelected = sel;
		if (sel) {
			textbox.setString("|");

		}
		else {
			textbox.setString("");
		}
	}


	void setFont(Font& font) {
		textbox.setFont(font);
	}
	void setPosition(Vector2f pos) {
		textbox.setPosition(pos);

	}
	void SetString(string a) {
		textbox.setString(a);
	}
	void setLimit(bool ToF) {
		hasLimit = ToF;
	}
	void setLimit(bool ToF, int lim) {
		hasLimit = ToF;
		limit = lim - 1;

	}
	void setSelected(bool sel) {
		isSelected = sel;
		if (!sel) {
			string t = text.str();
			string newT = "";
			for (int i = 0; i < t.length(); i++) {
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}
	string getText() {
		return text.str();
	}
	void drawTO(RenderWindow& window) {
		window.draw(textbox);

	}
	void typedOn(Event input) {
		if (isSelected) {
			int charTyped = input.text.unicode;

			if ((charTyped >= 48 && charTyped <= 57 && charTyped != Mouse::Left) || charTyped == 8 || charTyped == 45) {
				if (hasLimit) {
					if (text.str().length() <= limit) {
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY) {
						deleteLastChar();
					}

				}
				else {
					inputLogic(charTyped);
				}
			}
		}
	}

private:
	Text textbox;
	ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped) {
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
			text << static_cast<char>(charTyped);

		}
		else if (charTyped == DELETE_KEY) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
		}
		textbox.setString(text.str() + "|");
	}

	void deleteLastChar() {
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		text.str("");
		text << newT;

		textbox.setString(text.str());
	}
};



