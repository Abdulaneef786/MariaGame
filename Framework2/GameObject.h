#pragma once 
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map> 

#include "Game.h" 
#include "Animation.h"
#include "Textures.h"
#include "Utils.h"
#include "Constant.h"
#include "Transform.h"

using namespace std; 

class GameObject :public Transform, protected MonoBehaviour {
protected: 
	int id; 
	DWORD dt; 

	string currentState, lastState; 

	unordered_map<string, LPANIMATION> animations;

public: 
	string tag; 

	GameObject(); 
	~GameObject(); 

	// Correct order of execution for the program
	// TODO: Add physics and collider box in the future 
	void Init(); 

	//virtual void Update(DWORD dt, Camera* cam);
	//virtual void Render(Camera* cam);
	//virtual void Update(DWORD dt);
	//virtual void Render();

	// Create a copy of animation and manage it with GameObject instead of pointer 
	// and with Singleton 
	// With this way, it is much easier 
	virtual void AddAnimation();
	virtual void LoadAnimation(); 
	
	//string GetState() { return state; }
	//void SetState(string newState){}
	bool CompareTag(GameObject& other); 

};
