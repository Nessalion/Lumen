#include "TextBox.h"
#include "Button.h"

void chtenie(const char* filename) {
	ifstream is{ "shifr.txt" };

	string b;
	//ЗАПИСЬ В СТРОКУ
	getline(is, b);
	cout << b;

	is.close();

}
void zapis(const char* filename) {

	ofstream os{ "shifr.txt" };

	//из стринг в инт atoi();

	/*из инт в стринг
	int a = 10;
	char* intStr = itoa(a);
	string str = string(intStr);*/

	//ТИПО КРИПТОКЛЮЧ
	string  a;
	os << a;
	os.close();

}
int main()
{
	RenderWindow window(VideoMode(900, 900), "DevHack");
	setlocale(LC_ALL, "Rus");
	//font
	Font font;
	font.loadFromFile("Textbox.ttf");

	//menu
	Texture textureMenu;
	textureMenu.loadFromFile("background.jpg");
	Sprite menu(textureMenu);

	//sprites


	/// <summary>
	/// ////////
	/// </summary>
	/// <returns></returns>
	/// 
	Text C(L" НАПИШИТЕ СЮДА СВОЙ КРИПТО КЛЮЧ ", font, 20);
	C.setFillColor(Color::White);
	//X,Y
	C.setPosition(520, 330);
	Texture textureTextboxCrypted;
	textureTextboxCrypted.loadFromFile("textbox.png");
	Sprite TextBoxCrypted(textureTextboxCrypted);
	TextBoxCrypted.setPosition(500, 357);
	/// <summary>
	/// ///////////////////////
	/// </summary>
	/// <returns></returns>

	Texture textureTextboxDeCrypted;
	textureTextboxDeCrypted.loadFromFile("textbox.png");
	Sprite TextBoxDeCrypted(textureTextboxDeCrypted);
	TextBoxDeCrypted.setPosition(515, 643);
	//buttons
	Button crypted("crypted.png", "cryptedSet.png");
	crypted.setPosition({ 530,130 });

	Button decrypted("decrypted.png", "decryptedSet.png");
	decrypted.setPosition({ 530,750 });


	Text A(L"Криптоключ для дешифровки: ", font, 20);
	A.setFillColor(Color::White);
	A.setPosition(520, 330);

	Text B(L"Введите ключ для дешифровки: ", font, 20);
	B.setFillColor(Color::White);
	B.setPosition(520, 615);

	//textboxs


	Textbox TextboxDeCrypted(20, Color::Red, false);
	TextboxDeCrypted.setFont(font);
	TextboxDeCrypted.setPosition({ 533, 660 });

	//пример работы
	ofstream os{ "shifr.txt" };
	string  a = "1";
	string c;
	os << a;
	os.close();

	ifstream is("shifr.txt");
	getline(is, c);

	Text B1(c, font, 50);
	B1.setFillColor(Color::Red);
	///
	B1.setPosition(100, 100);
	is.close();
	/////////
	while (window.isOpen())
	{
		Event event;
		Vector2i mousePoz = Mouse::getPosition(window);
		while (window.pollEvent(event))
		{

			if (crypted.isHover(window)) {
				crypted.Box.setTexture(crypted.Hover);
			}
			else {
				crypted.Box.setTexture(crypted.Main);
			}

			if (decrypted.isHover(window)) {
				decrypted.Box.setTexture(decrypted.Hover);
			}
			else {
				decrypted.Box.setTexture(decrypted.Main);
			}

			switch (event.type) {
			case Event::Closed:
				window.close();

			case Event::MouseButtonPressed:
				if (TextBoxDeCrypted.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
					TextboxDeCrypted.setSelected(true);
				}
			case Event::TextEntered:

				TextboxDeCrypted.typedOn(event);

			}


		}
		//ТУТ ВЫВОД
		window.clear();

		window.draw(menu);
		window.draw(decrypted.Box);
		window.draw(crypted.Box);
		window.draw(A);
		window.draw(B);
		window.draw(B1);
		//window.draw(C);
		window.draw(TextBoxCrypted);
		///ТУТ ТЕКСТБОКСЫ
		window.draw(TextBoxDeCrypted);
		TextboxDeCrypted.drawTO(window);

		window.display();
	}


}