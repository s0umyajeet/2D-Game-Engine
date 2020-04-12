#include "window.h"
#include <iostream>

window::window(const std::string title, int height, int width)
	:_window_title(title), _height(height), _width(width)
{
	_closed = !init(); 
}

window::~window() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL\n";
		return 0;
	}
	_window = SDL_CreateWindow(
		_window_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_height,
		_width,
		SDL_WINDOW_RESIZABLE
	);

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_window == nullptr) {
		std::cerr << "Failed to create window\n";
		return 0;
	}

	if (_renderer == nullptr) {
		std::cerr << "Failed to create rendere\n";
	}

	return true;
}

void window::pollEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			std::cout << "Closing window\n";
			_closed = true;
			break;
		}
	}
}

void window::moveRect(SDL_Rect &rect) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_a:
				updateRectPos("left", rect);
				break;
			case SDLK_d:
				updateRectPos("right", rect);
				break;
			case SDLK_w:
				updateRectPos("up", rect);
				break;
			case SDLK_s:
				updateRectPos("down", rect);
				break;
			default:
				break;
			}
		default: break;
		}

	}
}


void window::clear() {
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void window::drawRect() {
	SDL_Rect rect;
	rect.w = 120;
	rect.h = 120;
	rect.x = _width / 2; // - (rect.w / 2);
	rect.y = _height / 2; // -(rect.h / 2);

	SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
	SDL_RenderClear(_renderer);
	SDL_RenderFillRect(_renderer, &rect);
	SDL_RenderPresent(_renderer);
}

void window::showHeightWidth() const {
	std::cout << "Width of the window is: " << _width << std::endl;
	std::cout << "Height of the window is: " << _height << std::endl;
}


void window::updateRectPos(const std::string direction, SDL_Rect& rect) {
	if (direction == "left") {
		rect.x -= 2;
	}
	if (direction == "right") {
		rect.x += 2;
	}
	if (direction == "up") {
		rect.y += 2;
	}
	if (direction == "down") {
		rect.y -= 2;
	}
}







