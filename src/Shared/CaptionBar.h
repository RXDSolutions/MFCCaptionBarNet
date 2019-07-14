#pragma once
#include "framework.h"

using namespace System;
using namespace System::Drawing;

delegate LRESULT GetMsgProcDelegate(int nCode, WPARAM wParam, LPARAM lParam);

namespace RxdSolutions
{
	namespace Windows
	{
		namespace MFC
		{
			public ref class CaptionBar
			{
			private:
				System::Boolean^ _isCreated;

				System::String^ _messageText;
				Bitmap^ _image;

				System::Boolean^ _displayButton;
				System::String^ _buttonText;
				System::String^ _buttonToolTip;

				HHOOK hook;
				LRESULT WINAPI GetMsgProc(int, WPARAM, LPARAM);
				GetMsgProcDelegate^ del;

				IntPtr _window;

				void Create();

			public:
				CaptionBar(IntPtr);

				event EventHandler^ OnButtonClicked;

				void Show();

				property Bitmap^ Image
				{
					Bitmap^ get();
					void set(Bitmap^ value);
				}

				property System::String^ Text
				{
					System::String^ get();
					void set(System::String^ value);
				}

				property System::String^ ButtonText
				{
					System::String^ get();
					void set(System::String^ value);
				}

				property System::String^ ButtonToolTip
				{
					System::String^ get();
					void set(System::String^ value);
				}

				property System::Boolean^ DisplayButton
				{
					System::Boolean^ get();
					void set(System::Boolean^ value);
				}

			protected:

			};
		}
	}
}
