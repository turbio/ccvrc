ui = require 'battle_ui';

current_turn = false;
enemy_health = 1000;
self_health = 1000;
normal_health = 1000;
max_health = 1500;
enemy_alive = true;
self_alive = true;

local hero;

function init(chosenHero)
	chosenHero = 0;

	if chosenHero == 0 then
		hero = require 'battle_centa';
		addSprite("centa_full_battle", 100, 100, "centa_full.png", 0, 0);
	end

	stage = 0;	--the current step that the ui is index
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

	setProp("health_count", "string", enemy_health.."/"..normal_health);
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