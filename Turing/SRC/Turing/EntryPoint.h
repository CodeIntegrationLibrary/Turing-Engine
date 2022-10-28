#pragma once

#ifdef TR_PLATFORM_WINDOWS
extern Turing::Application* Turing::CreateApplication();
int main(int argc, char** argv) {
	Turing::Log::Init();
	TR_CORE_WARN("Initialized Log  | 初始化日志 ！");
	int a = 5;
	TR_INFO("Hello Turing Engine | Var{0}", a);

	auto app = Turing::CreateApplication();
	app->Run();
	delete app;
}
#endif