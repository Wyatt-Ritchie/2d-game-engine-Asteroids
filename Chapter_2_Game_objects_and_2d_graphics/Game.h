#pragma once
#include <SDL.h>
#include <vector>
#include <unordered_map>
#include <string>

class Game
{
public:
	// constructor
	Game();

	// initialize
	bool Initialize();

	// Run Loop
	void RunLoop();

	// add/remove actor functions
	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
	void AddAsteroid(class Asteroid* ast);
	void RemoveAsteroid(class Asteroid* ast);
	void ResetShip();
	void SetShipDead() { mShipDead = true; }
	std::vector<class Asteroid*> GetAsteroids() const { return mAsteroids; }

	SDL_Texture* GetTexture(const std::string& fileName);

	//shutdown game loop
	void ShutDown();
private:

	// helper functions for the game loop
	void ProcessInput();

	void UpdateGame();

	void GenerateOutput();

	void LoadData();

	void UnloadData();

	// Window created by SDL
	SDL_Window* mWindow;

	// game running bool
	bool mIsRunning;

	// SDL renderer
	SDL_Renderer* mRenderer;

	// vectors containing active actors and pending actors
	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	std::vector<class SpriteComponent*> mSprites;
	std::vector<class Asteroid*> mAsteroids;
	float mRespawnTimer;
	bool mShipDead;

	int mTicksCount;
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	// functiong for getting textures
	
	// declare a load data function. This function will be 
	// hardcoded to load the exact actors and textures for
	// any particular game.
	

	bool mUpdatingActors;

	class Ship* mShip;
};

