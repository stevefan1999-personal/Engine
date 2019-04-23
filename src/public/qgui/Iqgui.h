//========= Quiver - Ms ============//
#ifndef IQGUI_H
#define IQGUI_H

#ifdef _WIN32
#pragma once
#endif

#include "appframework/IAppSystem.h"

abstract_class IQGui : public IAppSystem
{
public:
	virtual void UpdateAndRender() = 0;
};

#define QGUI_INTERFACE_VERSION	"QGui001"

#endif // IQGUI_H