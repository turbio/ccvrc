enemy_health = 100;

addSprite("bg", 0, 0, "main_menu_bg.png", 0, 0);

--bottom bar
addSprite("bottom_bar_bg", 0, 440, "bottom_bar_bg.png", 0, 0);

--top bar
addSprite("top_bar_bg", 0, -20, "top_bar_bg.png", 0, 0);
addStringSprite("enemy_bar_text", 10, -3, 32, "Enemy: ", 0x000000);

addSprite("enemy_health_bar_bg", 110, 7, "bar_bg.png", 675, 25);
addSprite("enemy_health_bar", 110, 7, "health_bar.png", 675, 25);

function init()
	stage = 0;	--the current step that the ui is index

	--elements interpolate in at start
end

function event(target, type)
	
end

function error(type)

end