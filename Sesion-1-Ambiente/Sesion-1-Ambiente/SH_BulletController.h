#pragma once

class SH_World;

class SH_BulletController
{
public:
	SH_BulletController();
	~SH_BulletController() {}

	void Initialize(SH_World*  world);
	void Update(float dt);
	void Draw(float dt);

private:
	SH_World* mWorld;
};

