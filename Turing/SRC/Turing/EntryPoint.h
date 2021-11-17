#pragma once

#ifdef TR_PLATFORM_WINDOWS
extern Turing::Application* Turing::CreateApplication();
int main(int argc, char** argv) {
	printf("Turing Engine");
	auto app = Turing::CreateApplication();
	app->Run();
	delete app;
}
#endif