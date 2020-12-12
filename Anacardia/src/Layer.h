#pragma once

namespace Anacardia
{
	class Layer
	{
	public:
		Layer(std::string name);
		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		/*
		* Shows the kind of windows to be rendered (using virtual ports)
		*/
		virtual void OnImGuiRender() = 0;
	protected:
		// TODO: Remove, only for debug
		std::string m_Name;
	};
}
