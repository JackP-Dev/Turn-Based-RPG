#pragma once
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <istream>
#include <thread>
#include <mutex>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include "Globals.h"
#include "Scene.h"
#include "MainMenuScene.h"
#include "NoughtsAndCrossesScene.h"
#include "Interface.h"
#include "Player.h"
#include "json.hpp"


#pragma comment (lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

class GameManager
{

private:

	MainMenuScene* mMainMenuSceneInstance;
	NoughtsAndCrossesScene* mNoughtsAndCrossesSceneInstance;

	bool bRunning = true;
	std::mutex mut;
	Scenes mCScene = Scenes::MainMenu;
	SDL_Window* mWnd;
	SDL_Renderer* mRnd;
	SDL_Surface* mSurface;

	Player mPlayer;
	std::map<std::string, RenderObject*> objects; // This is where the RenderObject types are stored 
	std::map<std::string, SpriteSheet*> sheets; // This is where the spritesheets are stored

	std::vector<Scene*> scenes;
	Scene* currentScene;

	Interface mInterface{&bRunning, &objects, &mCScene, &mPlayer};

	SDL_Texture* LoadTexture(std::string path); //Moved it here for now
	void LoadScene();
	bool SetUp();
	bool Create_Window();
	void SendData(int* x, int *y, Act *act, bool *isSender, SOCKET* usedSocket, std::mutex* mut);
	void SendOrReceiveData(int* x, int* y, Act* act, bool* isSender, SOCKET* usedSocket, std::mutex* mut, SDL_Event* ev);
	void ReceiveData(int *x, int *y, Act *act, bool *isSender, SOCKET* usedSocket, std::mutex* mut);

	
public:

	GameManager() {}
	~GameManager();
	
	bool Init(bool isSender);
	void Run(bool isHost, SOCKET usedSocket); // if true, the user is a host
	void Quit();	

};


