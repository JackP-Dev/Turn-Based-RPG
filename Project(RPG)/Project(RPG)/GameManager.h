#pragma once
#include <SDL.h>
#include "SceneManager.h"
#include "AudioManager.h"
#include "ImportManager.h"
#include "Database.h"
#include "InputManager.h"
#include "Globals.h"
#include "Actions.h"
#include "MainMenuClass.h"
#include "ObjectManager.h"

struct Managers
{
	GameManager* mGameMgr;
	ObjectManager* mObjectMgr;
	AudioManager* mAudioMgr;
	SceneManager* mSceneMgr;
	InputManager* mInputMgr;
	ImportManager* mImportMgr;

};


class GameManager
{
private:
	bool bRunning;
	SDL_Window* mWnd;
	SDL_Renderer* mRnd;
	//SceneManager* mScManager;
	SDL_Surface* mSurface;
	//AudioManager* mAudioMgr;
	//ImportManager* mImportMgr;
	//InputManager* mInputMgr;
	//ObjectManager* mObjMgr;
	Database* mDb;
	//GameManager* sInstance;

	Managers* mMgrs;

public:
	bool Init();
	bool Running();
	void Run();
	Act Poll(SDL_Keycode kCode);
	void Quit();
	InputManager* GetInputMgr();
private:
	bool CreateWindow();
	void SetupManagers();
	void InitManagers();

};


