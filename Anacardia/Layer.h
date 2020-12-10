#pragma once

namespace Anacardia
{
	class Layer
	{
	public:
		Layer(std::string name);
		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate() = 0;
	protected:
		// TODO: Remove, only for debug
		std::string m_Name;
	};
}
