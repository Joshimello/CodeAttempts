#include <algorithm>
#include <string>

#include "Point.hpp"
#include "Slider.hpp"
#include "Collider.hpp"
#include "GameEngine.hpp"

Slider::Slider(float x, float y, float w, float h) :
	ImageButton("stage-select/slider.png", "stage-select/slider-blue.png", x - 100, y),
	Bar("stage-select/bar.png", x, y, w, h),
	End1("stage-select/end.png", x, y + h / 2, 0, 0, 0.5, 0.5),
	End2("stage-select/end.png", x + w, y + h / 2, 0, 0, 0.5, 0.5) {
	Position.x += w;
	Position.y += h / 2;
	Anchor = Engine::Point(0.5, 0.5);
}
void Slider::Draw() const {
    Bar.Draw();
    End1.Draw();
    End2.Draw();
    ImageButton::Draw();
}
void Slider::SetOnValueChangedCallback(std::function<void(float value)> onValueChangedCallback) {
    OnValueChangedCallback = onValueChangedCallback;
}
void Slider::SetValue(float v) {
	// TODO 1 (4/7): Call 'OnValueChangedCallback' when value changed. Can imitate ImageButton's 'OnClickCallback'.
	// Also, move the slider along the bar, to the corresponding position.
	value = v;
	Position.x = v * 190 + 743;
	//printf("%f\n", v);
	if (OnValueChangedCallback) {
		OnValueChangedCallback(value);
	}
}
void Slider::OnMouseDown(int button, int mx, int my) {
	// TODO 1 (5/7): Set 'Down' to true if mouse is in the slider.
	Engine::Point mouse = Engine::GameEngine::GetInstance().GetMousePosition();
	mouseIn = Engine::Collider::IsPointInBitmap(Engine::Point((mouse.x - Position.x) * GetBitmapWidth() / Size.x + Anchor.x * GetBitmapWidth(), (mouse.y - Position.y) * GetBitmapHeight() / Size.y + Anchor.y * GetBitmapHeight()), bmp);
	if (mouseIn) {
		Down = true;
	}
}
void Slider::OnMouseUp(int button, int mx, int my) {
	// TODO 1 (6/7): Set 'Down' to false.
	if (Down) {
		Down = false;
	}
}
void Slider::OnMouseMove(int mx, int my) {
	// TODO 1 (7/7): Clamp the coordinates and calculate the value. Call 'SetValue' when you're done.
	if (Down) {
		float rx = mx - 743;
		float val = rx / 190;
		if (val > 1) {
			val = 1.0;
		}
		if (val < 0) {
			val = 0.0;
		}
		Slider::SetValue(val);
	}
}