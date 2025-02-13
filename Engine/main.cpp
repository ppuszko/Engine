#include <iostream>
#include <raylib.h>

#include "GameObject.hpp"
#include "BoxCollider.hpp"
#include "RigidBody.hpp"

int main()
{
	
	InitWindow(800, 600, "window");

	//Texture2D texture = LoadTexture("Assets/bipedal.png");
	//std::cout << texture.width << std::endl;
	//int w = texture.width, h = texture.height;
	//Rectangle source = { 0, 0, w, h };
	//Rectangle dest = { 0, 200, w, h };

	if (true)
	{
		std::shared_ptr<GameObject> gm = std::make_shared<GameObject>("Player");
	
		Sprite s("Assets/bipedal.png");
		s.ClipSpriteSheet(7, 1);
		gm->AddComponent<SpriteRenderer>(&s);
		gm->AddComponent<BoxCollider>();
		gm->AddComponent<RigidBody>(5);
		
		SetTargetFPS(60);

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(WHITE);
			gm->Update();
			
			/*DrawTexturePro(texture, source, dest, {w / 2.f, h / 2.f}, 0, WHITE); */

			EndDrawing();
		}
		CloseWindow();

	}
	

	/*UnloadTexture(texture);*/
	


	return 0;

}