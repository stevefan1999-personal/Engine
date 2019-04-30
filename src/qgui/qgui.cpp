//========= Quiver - Ms ============//
#include "qgui/iqgui.h"
#include "tier2/tier2.h"
#include "Ultralight/Ultralight.h"
#include "qgui_filesystem.h"
#include "qgui_gpudriver.h"

class QGui : public CBaseAppSystem<IQGui>
{
public:
	virtual bool Connect( CreateInterfaceFn factory );
	virtual InitReturnVal_t Init();
	virtual void UpdateAndRender();
};

EXPOSE_SINGLE_INTERFACE( QGui, IQGui, QGUI_INTERFACE_VERSION );

using namespace ultralight;

RefPtr<Renderer> gRenderer = nullptr;

bool QGui::Connect( CreateInterfaceFn factory )
{
	ConnectTier2Libraries( &factory, 1 );
	if( g_pFullFileSystem == nullptr )
		return false;

	return true;
}

InitReturnVal_t QGui::Init()
{
	Platform::instance().set_file_system( &gQGuiFileSystem );
	Platform::instance().set_gpu_driver( &gQGuiGPUDriver );
	gRenderer = Renderer::Create();
	Ref<View> view = gRenderer->CreateView(800, 600, true);
	view->LoadURL( "file:///resource/index.html" );
	return INIT_OK;
}

void QGui::UpdateAndRender()
{
	// Update internal logic (timers, event callbacks, etc.)
	gRenderer->Update();

	// Render all active views to command lists and dispatch calls to GPUDriver
	gRenderer->Render();
}
