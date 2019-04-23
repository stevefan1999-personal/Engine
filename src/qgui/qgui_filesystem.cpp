//========= Quiver - Ms ============//
#include "qgui_filesystem.h"
#include "tier2/tier2.h"
#include "filesystem.h"
#include "utlbuffer.h"
#include <windows.h>

bool QGuiFilesystem::FileExists( const String16& path )
{
	char utf8[MAX_PATH];
	V_UnicodeToUTF8( path.data(), utf8, sizeof( utf8 ) );
	return g_pFullFileSystem->FileExists( utf8, "GAME" );
}

bool QGuiFilesystem::DeleteFile_( const String16& path )
{
	return false;
}

bool QGuiFilesystem::DeleteEmptyDirectory( const String16& path )
{
	return false;
}

bool QGuiFilesystem::MoveFile_( const String16& old_path, const String16& new_path )
{
	return false;
}

bool QGuiFilesystem::GetFileSize( const String16& path, int64_t& result )
{
	return false;
}

bool QGuiFilesystem::GetFileSize( FileHandle handle, int64_t& result )
{
	if ( result = g_pFullFileSystem->Size( FileHandle_t( handle ) ) )
		return true;
	return false;
}

bool QGuiFilesystem::GetFileMimeType( const String16& path, String16& result )
{
	char utf8[MAX_PATH];
	V_UnicodeToUTF8( path.data(), utf8, sizeof( utf8 ) );

	const char* extension;
	extension = utf8 + strlen( utf8 ) - 1;
	while ( extension != utf8 && *( extension - 1 ) != '.' )
		extension--;

	if ( extension == utf8 || *extension == '\\' || *extension == '/' )
		return false;  // no extension

	extension--; //include dot

	HKEY key = NULL;
	if ( ERROR_SUCCESS == VCRHook_RegOpenKeyEx( HKEY_CLASSES_ROOT, extension, 0, KEY_READ, &key ) )
	{
		char szBuffer[MAX_PATH];
		DWORD dwBuffSize = sizeof( szBuffer );

		if ( ERROR_SUCCESS == VCRHook_RegQueryValueEx( key, "Content Type", NULL, NULL,
			( LPBYTE )szBuffer, &dwBuffSize ) )
		{
			VCRHook_RegCloseKey( key );
			V_UTF8ToUnicode( szBuffer, result.data(), result.length() + 1 );
			return true;
		}
		VCRHook_RegCloseKey( key );
	}
	return false;
}

bool QGuiFilesystem::GetFileModificationTime( const String16& path, time_t& result )
{
	return false;
}

bool QGuiFilesystem::GetFileCreationTime( const String16& path, time_t& result )
{
	return false;
}

MetadataType QGuiFilesystem::GetMetadataType( const String16& path )
{
	return MetadataType();
}

String16 QGuiFilesystem::GetPathByAppendingComponent( const String16& path, const String16& component )
{
	return String16();
}

bool QGuiFilesystem::CreateDirectory_( const String16& path )
{
	return false;
}

String16 QGuiFilesystem::GetHomeDirectory()
{
	return String16();
}

String16 QGuiFilesystem::GetFilenameFromPath( const String16& path )
{
	return String16();
}

String16 QGuiFilesystem::GetDirectoryNameFromPath( const String16& path )
{
	return String16();
}

bool QGuiFilesystem::GetVolumeFreeSpace( const String16& path, uint64_t& result )
{
	return false;
}

int32_t QGuiFilesystem::GetVolumeId( const String16& path )
{
	return int32_t();
}

Ref<String16Vector> QGuiFilesystem::ListDirectory( const String16& path, const String16& filter )
{
	return String16Vector::Create();
}

String16 QGuiFilesystem::OpenTemporaryFile( const String16& prefix, FileHandle& handle )
{
	return String16();
}

FileHandle QGuiFilesystem::OpenFile( const String16& path, bool open_for_writing )
{
	char utf8[MAX_PATH];
	V_UnicodeToUTF8( path.data(), utf8, sizeof( utf8 ) );
	return (FileHandle)g_pFullFileSystem->Open( utf8, "r", "GAME" );
}

void QGuiFilesystem::CloseFile( FileHandle& handle )
{
	g_pFullFileSystem->Close( (FileHandle_t)handle );
}

int64_t QGuiFilesystem::SeekFile( FileHandle handle, int64_t offset, FileSeekOrigin origin )
{
	return int64_t();
}

bool QGuiFilesystem::TruncateFile( FileHandle handle, int64_t offset )
{
	return false;
}

int64_t QGuiFilesystem::WriteToFile( FileHandle handle, const char* data, int64_t length )
{
	return int64_t();
}

int64_t QGuiFilesystem::ReadFromFile( FileHandle handle, char* data, int64_t length )
{
	return g_pFullFileSystem->Read( data, length, ( FileHandle_t )handle );
}

bool QGuiFilesystem::CopyFile_( const String16& source_path, const String16& destination_path )
{
	return false;
}

QGuiFilesystem gQGuiFileSystem;