#pragma once

#ifdef TR_PLATFORM_WINDOWS
extern Turing::Application* Turing::CreateApplication();
int main(int argc, char** argv) {
	int a = 5;
	Turing::Log::Init();
	TR_CORE_WARN("Initialized Log | ��ʼ����־");
	TR_INFO("Hello Tring Engine | Var={0}", a);
	auto app = Turing::CreateApplication();
	app->Run();
	delete app;
}
#endif