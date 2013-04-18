
addSprite("bg", 0, 0, "main_menu_bg.png", 0, 0);

--bottom bar
addSprite("bottom_bar_bg", 0, 440, "bottom_bar_bg.png", 0, 0);

addStringSprite("health_txt", 10, 450, 24, "Health:", 0);
addSprite("health_bg", 85, 455, "bar_bg.png", 240, 20);
addSprite("health", 85, 455, "health_bar.png", 240, 20);

addStringSprite("mana_txt", 21, 485, 24, "Mana:", 0);
addSprite("mana_bg", 85, 490, "bar_bg.png", 240, 20);
addSprite("mana", 85, 490, "mana_bar.png", 240, 20);

--top bar
addSprite("enemy_health_bar_bg", 110, 7, "bar_bg.png", 675, 25);
addSprite("enemy_health_bar", 110, 7, "health_bar.png", 675, 25);

addSprite("top_bar_bg", 0, -20, "top_bar_bg.png", 0, 0);
addStringSprite("enemy_bar_text", 10, -3, 32, "Enemy: ", 0x000000);

addStringSprite("health_count", 400, 10, 16, "null/null", 0xffffff);

--actions
addPolySprite("basic_action_bg", 345, 450, 0x14b4ff, 0, 0, 64 + 10, 0, 64 + 10, 64 + 10, 0, 64 + 10);
addSprite("basic_action", 350, 455, "basic_attack.png", 64, 64);

addPolySprite("basic_action2_bg", 345, 450 + 78, 0x14b4ff, 0, 0, 64 + 10, 0, 64 + 10, 64 + 10, 0, 64 + 10);
addSprite("basic_action2", 350, 455 + 78, "basic_attack.png", 64, 64);