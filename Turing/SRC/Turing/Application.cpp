#include "Application.h"

#include"Turing/Events/ApplicationEvent.h"
#include"Turing/Log.h"

Turing::Application::Application() {

}

Turing::Application::~Application() {

}

void Turing::Application::Run() {
	WindowResizeEvent e(1280, 720);
	if (e.IsInCategory(EventCategoryApplication))
	{
		TR_TRACE(e);
	}
	if (e.IsInCategory(EventCategoryInput))
	{
		TR_TRACE(e);
	}
	while (true);
}