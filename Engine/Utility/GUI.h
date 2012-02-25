#ifndef EG_GUI_GUI_H
#define EG_GUI_GUI_H

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

//#include <Awesomium/WebCore.h>
#include <Awesomium/awesomium_capi.h>
#include "../Math/Math.h"
#include "../Utility/StringDictionary.h"
#include "../Graphics/OffscreenBuffer.h"
#include "../Graphics/Texture.h"

#define gui EG::GUI::GUI::Instance()

namespace EG{
	namespace GUI{
		class WebResourceResponse{
			public:
				WebResourceResponse(void){}
				~WebResourceResponse(void){}
				virtual std::string Call(std::map<std::string, std::string> args);
		};

		awe_resource_response *resource_interceptor(awe_webview *caller, awe_resource_request *request);
		void js_console_callback(awe_webview *caller, const awe_string *message, int line_number, const awe_string *source);

		class GUI{
			public:
				GUI(void);
				~GUI(void);

				void Initialize(std::string base_directory, std::string url);
				void Update(void);
				void Render(void);
				bool GetInitialized(void);

				unsigned int GetTextureId(void);
				void ExecuteScript(std::string script);
				void InjectMouseMove(unsigned int x, unsigned int y);
				void InjectMouseDown(awe_mousebutton button);
				void InjectMouseUp(awe_mousebutton button);
				void InjectKeyPress(awe_webkeyboardevent keyboard_event);
				void InjectKeyPress(int key_code);
				void AddResponseHandler(std::string url, WebResourceResponse *handler);
				awe_resource_response *ResourceInterceptor(awe_webview *caller, awe_resource_request *request);

				// Singleton Stuffs
				static GUI *Instance(void);
			private:
				static GUI* instance;

				bool initialized;
				EG::Graphics::Texture *texture;
				unsigned char *buffer;
				int bpp, rowspan, width, height;
				awe_webview *web_view;
				awe_string *mime_type;
				EG::Utility::StringDictionary<WebResourceResponse *> resources;
		};
	}
}

#endif
