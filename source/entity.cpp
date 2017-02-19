#include "entity.h"

Entity::Entity(st_spritesheet *spritesheet, std::vector<unsigned char> frames)
{
	this.position = {0, 0};
	this.id = ++this.last_used_id;
	this.frames = frames;
	this.spritesheet = spritesheet;
	this.current_frame = 0;
}

Entity::render_next_frame(int framecount)
{
	this.current_frame = framecount % frames_len;
	ST_RenderSpritePosition(this.spritesheet, (int)(frames[current_frame] % 8) * 16, (int)(frames[current_frame] / 8) * 16, 16, 16, this.position.x * 16, this.position.y * 16);
}