# include <Siv3D.hpp> // OpenSiv3D v0.6.11

//円ボタン
class CircleButton
{
public:
	Circle circle;
	double thickness;
	Font font;
	String text;
	Color color_in;
	Color color_text;

public:
	CircleButton()
		: circle(0,0,1),
		thickness(1),
		color_in(Palette::Black),
		color_text(Palette::Black)
	{}

	CircleButton(Circle circle, double thickness, Color color_in = Palette::Black)
		: circle(circle),
		thickness(thickness),
		color_in(color_in),
		color_text(Palette::White)
	{}

	CircleButton(Circle circle, double thickness, Font font, String text, Color color_text = Palette::White, Color color_in = Palette::Black)
		: circle(circle),
		thickness(thickness),
		font(font),
		text(text),
		color_text(color_text),
		color_in(color_in)
	{}

public:
	//更新
	bool updateButton()
	{
		return circle.leftClicked();
	}

	//描画
	void drawButton() const
	{
		circle.draw(color_in);

		if (font)
			font(text).drawAt(circle.center, color_text);
	}

	//更新・描画
	bool update()
	{
		const bool result = updateButton();
		drawButton();
		return result;
	}
};

void Main()
{
	CircleButton button(Circle(Scene::CenterF(), 50), 10, Font(20), U"ボタン");

	while (System::Update())
	{
		//ボタンを押したら
		if (button.update())
		{
		}
	}
}
