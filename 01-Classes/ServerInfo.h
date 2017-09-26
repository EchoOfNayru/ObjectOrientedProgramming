#pragma once
#include <string>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct ServerInfo 
{
	std::string serverName;
	std::string region;
	int currentPlayers;
	int maxPlayers;
	int ping;
};

class ServerBrowserService 
{
private:
	
	const static int SERVERINFO_CAPACITY = 20;

	ServerInfo servers[SERVERINFO_CAPACITY];

	int serverCount;
public:

	ServerBrowserService();

	bool registerServer(ServerInfo newServer);

	int getServers(ServerInfo * dstArray, size_t dstSize) const;
};