#pragma once

class SH_World;

class SH_EnemyController
{
public:
	SH_EnemyController();
	~SH_EnemyController() {}

	void Initialize(SH_World*  world);
	void Update(float dt);
	void Draw(float dt);

private:
	SH_World* mWorld;
};

