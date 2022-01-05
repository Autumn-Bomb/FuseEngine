#pragma once
#include "../../../Framework/Panels/BasePanel/Panel.h"

#include <string>

namespace Fuse
{
	enum class MessageType { MESSAGE, WARNING, ERROR, ACTION };

	class Console : public Fuse::Panel
	{
		public:
			Console();
			~Console();

		public:
			void OnImGuiRender() override;
			void ClearConsole();

		public:
			static void PrintToConsole(MessageType messageType, const char* message, ...);

		private:
			MessageType m_MessageType;
			ImGuiTextFilter m_Filter;

		private:
			inline static ImGuiTextBuffer m_Buffer;
			inline static ImVector<int> m_LineOffsets;

			inline static ImVec4 m_TextColour;

		private:
			bool m_AutoScroll;

			bool m_ShowActions;
			bool m_ShowWarnings;
			bool m_ShowErrors;
			bool m_ShowMessages;
	};
}