//========= Copyright © 1996-2008, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=====================================================================================//

#include "VOptions.h"
#include "VFooterPanel.h"
#include "VHybridButton.h"

#include "vgui_controls/Button.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

using namespace vgui;
using namespace BaseModUI;

//=============================================================================
Options::Options( Panel *parent, const char *panelName ):
BaseClass( parent, panelName )
{
	SetDeleteSelfOnClose(true);
	SetProportional( true );
	SetTitle( "#GameUI_Options", false );

	m_BtnGame = new BaseModHybridButton( this, "BtnGame", "#GameUI_Game", this, "Game" );
	m_BtnAudioVideo = new BaseModHybridButton( this, "BtnAudioVideo", "#GameUI_AudioVideo", this, "AudioVideo" );
	m_BtnController = new BaseModHybridButton( this, "BtnController", "#GameUI_Controller", this, "Controller" );
	m_BtnStorage = new BaseModHybridButton( this, "BtnStorage", "#GameUI_Storage", this, "Storage" );
	m_BtnCredits = new BaseModHybridButton( this, "BtnCredits", "#GameUI_Credits", this, "Credits" );

	SetUpperGarnishEnabled( true );
	SetLowerGarnishEnabled( true );

	CBaseModFooterPanel *footer = BaseModUI::CBaseModPanel::GetSingleton().GetFooterPanel();
	if ( footer )
	{
		footer->SetButtons( FB_ABUTTON | FB_BBUTTON, FF_AB_ONLY, false );
		footer->SetButtonText( FB_ABUTTON, "#GameUI_Select" );
		footer->SetButtonText( FB_BBUTTON, "#GameUI_Cancel" );
	}

	m_ActiveControl = m_BtnGame;
}

//=============================================================================
Options::~Options()
{
	delete m_BtnGame;
	delete m_BtnAudioVideo;
	delete m_BtnController;
	delete m_BtnStorage;
	delete m_BtnCredits;
}

//=============================================================================
void Options::OnCommand(const char *command)
{
	int iUserSlot = CBaseModPanel::GetSingleton().GetLastActiveUserId();
	int iController = XBX_GetUserId( iUserSlot );

	if ( UI_IsDebug() )
	{
		Msg("[GAMEUI] Handling options menu command %s from user%d ctrlr%d\n", command, iUserSlot, iController );
	}

	if(!Q_strcmp(command, "Game"))
	{
		CBaseModPanel::GetSingleton().OpenWindow(WT_GAMEOPTIONS, this);
	}
	else if(!Q_strcmp(command, "AudioVideo"))
	{
		CBaseModPanel::GetSingleton().OpenWindow(WT_AUDIOVIDEO, this);
	}
	else if(!Q_strcmp(command, "Controller"))
	{
		CBaseModPanel::GetSingleton().OpenWindow(WT_CONTROLLER, this);
	}
	else if(!Q_strcmp(command, "Storage"))
	{
		CUIGameData::Get()->SelectStorageDevice( new CChangeStorageDevice( iController ) );
	}
}