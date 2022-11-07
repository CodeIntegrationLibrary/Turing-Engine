#include<Turing.h>

class ExampleLayer :public Turing::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}

	void OnUpdate() override {
		TR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Turing::Event& event) override {
		TR_TRACE("{0}",event);
	}
};

class Sandbox : public Turing::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}

};

Turing::Application* Turing::CreateApplication() {
	return new Sandbox();
}