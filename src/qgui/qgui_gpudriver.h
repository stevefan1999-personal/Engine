//========= Quiver - Ms ============//
#ifndef QGUI_GPUDRIVER_H
#define QGUI_GPUDRIVER_H

#ifdef _WIN32
#pragma once
#endif

#include "Ultralight/platform/GPUDriver.h"

using namespace ultralight;

class QGuiGPUDriver : public GPUDriver
{
	virtual void BeginSynchronize();
	virtual void EndSynchronize();
	virtual uint32_t NextTextureId();
	virtual void CreateTexture( uint32_t texture_id,
		Ref<Bitmap> bitmap );
	virtual void UpdateTexture( uint32_t texture_id,
		Ref<Bitmap> bitmap );
	virtual void BindTexture( uint8_t texture_unit,
		uint32_t texture_id );
	virtual void DestroyTexture( uint32_t texture_id );
	virtual uint32_t NextRenderBufferId();
	virtual void CreateRenderBuffer( uint32_t render_buffer_id,
		const RenderBuffer& buffer );
	virtual void BindRenderBuffer( uint32_t render_buffer_id );
	virtual void ClearRenderBuffer( uint32_t render_buffer_id );
	virtual void DestroyRenderBuffer( uint32_t render_buffer_id );
	virtual uint32_t NextGeometryId();
	virtual void CreateGeometry( uint32_t geometry_id,
		const VertexBuffer& vertices,
		const IndexBuffer& indices );
	virtual void UpdateGeometry( uint32_t geometry_id,
		const VertexBuffer& vertices,
		const IndexBuffer& indices );
	virtual void DrawGeometry( uint32_t geometry_id,
		uint32_t indices_count,
		uint32_t indices_offset,
		const GPUState& state );
	virtual void DestroyGeometry( uint32_t geometry_id );
	virtual void UpdateCommandList( const CommandList& list );
	virtual bool HasCommandsPending();
	virtual void DrawCommandList();
};

extern QGuiGPUDriver gQGuiGPUDriver;
#endif // QGUI_GPUDRIVER_H