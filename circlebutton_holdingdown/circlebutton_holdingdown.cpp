# include <Siv3D.hpp> // OpenSiv3D v0.6.11

//長押し円ボタン
class CircleButton_HoldingDown
{
public:
	Circle circle;
	double thickness;
	Duration time;
	Font font;
	String text;
	Color color_in;
	Color color_out;
	Color color_arc;
	Color color_text;
private:
	double time_pressed;

public:
	CircleButton_HoldingDown()
		: circle(0,0,1),
		thickness(1),
		time(1s),
		color_in(Palette::Black),
		color_out(Palette::Black),
		color_arc(Palette::Black),
		color_text(Palette::Black),
		time_pressed(0)
	{}

	CircleButton_HoldingDown(Circle circle, double thickness, Duration time, Color color_in = Palette::Black, Color color_out = Palette::White, Color color_holding = Palette::Gray)
		: circle(circle),
		thickness(thickness),
		time(time),
		color_in(color_in),
		color_out(color_out),
		color_arc(color_holding),
		color_text(Palette::White),
		time_pressed(0)
	{}

	CircleButton_HoldingDown(Circle circle, double thickness, Duration time, Font font, String text, Color color_text = Palette::White, Color color_in = Palette::Black, Color color_out = Palette::White, Color color_holding = Palette::Gray)
		: circle(circle),
		thickness(thickness),
		time(time),
		font(font),
		text(text),
		color_text(color_text),
		color_in(color_in),
		color_out(color_out),
		color_arc(color_holding),
		time_pressed(0)
	{}

public:
	//更新
	bool updateButton()
	{
		if (circle.leftPressed())
			time_pressed += Scene::DeltaTime();
		else
			time_pressed = 0;

		return time_pressed >= time.count();
	}

	//描画
	void drawButton() const
	{
		circle.draw(color_in)
			.drawFrame(0, thickness, color_out);

		if(circle.leftPressed())
			circle.drawArc(0, Math::Tau * (time_pressed / time.count()), 0, thickness, color_arc);

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
	CircleButton_HoldingDown button(Circle(Scene::CenterF(), 50), 10, 1s, Font(20), U"ボタン");

	while (System::Update())
	{
		//ボタンを長押ししたら
		if (button.update())
		{
		}
	}
}
