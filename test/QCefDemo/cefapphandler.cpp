#include "cefapphandler.h"
#include "localschemehandlerfactory.h"

void CefAppHandler::onCefInitialized() {
	//BinaryResourceProvider
  //CefRegisterSchemeHandlerFactory("https", "test", new LocalSchemeHandlerFactory());
}