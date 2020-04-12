#pragma once
#include <SDL.h>
#include <string>

class window {
public:
	window(const std::string title, int height, int width);
	~window();
	inline bool is_closed() const { return _closed; };
	void pollEvents();
	void clear();
	void showHeightWidth() const;
	void moveRect(SDL_Rect &rect);
	void updateRectPos(const std::string direction, SDL_Rect &rect);
	void drawRect();
private:
	const std::string _window_title; 
	int	          _height;
	int		  _width;
	bool              _closed;
	SDL_Window        *_window = nullptr;
	SDL_Renderer      *_renderer = nullptr;
private:
	bool init();
};