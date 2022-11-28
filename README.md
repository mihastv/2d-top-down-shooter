# 2d-top-down-shooter
- INFO:
			- game concept : shoot asteroids coming from above you, as the difficuly of the game increases
			- features (extra things added that were not mandatory) : health bars spawn periodically to help you survive, original soundtrack
		
		- CONTROLS AND DESIGN:
			- Use W,A,S,D to move your spaceship
			- Press LEFT CLICK to shoot your enemies
			- Press ESC to exit the game
			- Collision with an asteroid results in 1HP loss
			- Collision with a health bar results in 1HP gain
			- HP is reset to MAX HP every round (even if your current HP is larger than MAX HP - for fairplay)
			- Your ship cannot go out of bounds
			- Asteroids spawn from upper Y boundary on random coordinates pertaining to their spawn area and respawn on hitting minimum Y-axis boundary
			- Levelup occurs on hitting score milestones
			- Score is built up on hitting asteroids <=> simply avoiding them will not advance you
			- Shooting an asteroid is only possible if your oY position is lower than its oY position
