#include "pch.h"
#include "Config.h"

std::string Config::gameDirectory;

bool Config::readPlayerBetaCookieJar;

bool Config::initialized;

void Config::init()
{
	gameDirectory.resize(MAX_PATH);
	GetModuleFileName(nullptr, &gameDirectory[0], MAX_PATH);
	gameDirectory.resize(gameDirectory.rfind('\\'));

	// for now
	readPlayerBetaCookieJar = true;

	initialized = true;
}
