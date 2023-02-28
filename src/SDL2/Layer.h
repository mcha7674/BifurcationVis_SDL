#pragma once
#include <iostream>
#include "EventListener.h"

class Layer
{
public:
	Layer(const std::string& name = "Layer");
	virtual ~Layer() = default;

	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual void OnUpdate(EventListener& eventListener) {}

	inline const std::string& GetName() const { return m_DebugName; }
protected:
	std::string m_DebugName;
};

