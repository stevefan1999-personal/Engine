//========= Quiver - Ms ============//
#include "qgui_gpudriver.h"
#include "tier2/tier2.h"
#include "materialsystem/texturemanager.h"

void QGuiGPUDriver::BeginSynchronize()
{
}

void QGuiGPUDriver::EndSynchronize()
{
}

uint32_t QGuiGPUDriver::NextTextureId()
{
	texturemanag
}

void QGuiGPUDriver::CreateTexture( uint32_t texture_id, Ref<Bitmap> bitmap )
{
	
}

void QGuiGPUDriver::UpdateTexture( uint32_t texture_id, Ref<Bitmap> bitmap )
{
}

void QGuiGPUDriver::BindTexture( uint8_t texture_unit, uint32_t texture_id )
{
}

void QGuiGPUDriver::DestroyTexture( uint32_t texture_id )
{
}

uint32_t QGuiGPUDriver::NextRenderBufferId()
{
	return uint32_t();
}

void QGuiGPUDriver::CreateRenderBuffer( uint32_t render_buffer_id, const RenderBuffer& buffer )
{
}

void QGuiGPUDriver::BindRenderBuffer( uint32_t render_buffer_id )
{
}

void QGuiGPUDriver::ClearRenderBuffer( uint32_t render_buffer_id )
{
}

void QGuiGPUDriver::DestroyRenderBuffer( uint32_t render_buffer_id )
{
}

uint32_t QGuiGPUDriver::NextGeometryId()
{
	return uint32_t();
}

void QGuiGPUDriver::CreateGeometry( uint32_t geometry_id, const VertexBuffer& vertices, const IndexBuffer& indices )
{
}

void QGuiGPUDriver::UpdateGeometry( uint32_t geometry_id, const VertexBuffer& vertices, const IndexBuffer& indices )
{
}

void QGuiGPUDriver::DrawGeometry( uint32_t geometry_id, uint32_t indices_count, uint32_t indices_offset, const GPUState& state )
{
}

void QGuiGPUDriver::DestroyGeometry( uint32_t geometry_id )
{
}

void QGuiGPUDriver::UpdateCommandList( const CommandList& list )
{
}

bool QGuiGPUDriver::HasCommandsPending()
{
	return false;
}

void QGuiGPUDriver::DrawCommandList()
{
}

QGuiGPUDriver gQGuiGPUDriver;