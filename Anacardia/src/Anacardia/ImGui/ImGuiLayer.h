#pragma once
#include "pch.h"
#include "Layer.h"

namespace Anacardia
{
	class ANACARDIA_API ImGuiLayer : public Layer
	{
	public:
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		static void Begin();
		static void End();
	private:
		float m_Time = 0.0f;
		bool m_ShowDemoWindow = true;
	};
}