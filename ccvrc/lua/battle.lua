current_turn = 0;
enemy_health = 1000;
self_health = 1000;
enemy_alive = true;
self_alive = true;

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

addStringSprite("health_count", 400, 10, 16, enemy_health.."/1000", 0xffffff);

--actions
addPolySprite("basic_action_bg", 345, 450, 0x14b4ff, 0, 0, 64 + 10, 0, 64 + 10, 64 + 10, 0, 64 + 10);
addSprite("basic_action", 350, 455, "basic_attack.png", 64, 64);

addPolySprite("basic_action2_bg", 345, 450 + 78, 0x14b4ff, 0, 0, 64 + 10, 0, 64 + 10, 64 + 10, 0, 64 + 10);
addSprite("basic_action2", 350, 455 + 78, "basic_attack.png", 64, 64);

function init()
	stage = 0;	--the current step that the ui is index

	--elements interpolate in at start
end

function event(target, type)
	if type == "clicked" then
		if target == "basic_action" then
			enemyHealth(math.random(1, 300));
		end
		if target == "basic_action2" then
			enemyHealth(-math.random(1, 300));
		end
	end
end

function error(type)

end

enemy_hit_num = 0;
function enemyHealth(amount)
	if enemy_alive == false or self_alive == false then
		return;
	end

	print("health: 1000/"..enemy_health.."/"..map(enemy_health, 0, 1000, 110, 110 - 675));
	if amount > 0 and (enemy_health + amount) > 1000 then
		amount = 1000 - enemy_health;
	end
	if amount < 0 and (enemy_health + amount) < 0 then
		addStringSprite("enemy_dmg_"..enemy_hit_num, 200, 200, 16, amount, 0xff0000);
		linearInterpolate("enemy_dmg_"..enemy_hit_num, 200, -100, 10.0);
		enemy_hit_num = enemy_hit_num + 1;
		amount = -enemy_health
		enemy_health = enemy_health + amount;
		enemyDie();
		return;
	end

	enemy_health = enemy_health + amount;

	if amount < 0 then
		addStringSprite("enemy_dmg_"..enemy_hit_num, 200, 200, 16, amount, 0xff0000);
		linearInterpolate("enemy_dmg_"..enemy_hit_num, 200, -100, 10.0);
		enemy_hit_num = enemy_hit_num + 1;
	end

	if amount > 0 then
		addStringSprite("enemy_dmg_"..enemy_hit_num, 200, 200, 16, "+"..amount, 0x00ff00);
		linearInterpolate("enemy_dmg_"..enemy_hit_num, 200, -100, 10.0);
		enemy_hit_num = enemy_hit_num + 1;
	end

	linearInterpolate("enemy_health_bar", map(enemy_health, 0, 1000, 110 - 675, 110), 7, 20);
end

function selfHealth(amount)

end

function enemyDie()
	linearInterpolate("enemy_health_bar", 110 - 675, 7, 35);
	addSprite("you_win_splash", (800 / 2) - ((151 * 3.5) / 2) + 35, 0, "winner.png", 151 * 3.5, 184 * 3.5);
	enemy_alive = false;
end

function selfDie()
	addSprite("you_lose_splash", (800 / 2) - ((151 * 3.5) / 2) + 35, 0, "looser.png", 151 * 3.5, 184 * 3.5);
	self_alive = false;
end

function map(val, imin, imax, omin, omax)
	return omin + (omax - omin) * ((val - imin) / (imax - imin));
end