--addSprite(index, x, y, "src", width, height);
--addStringSprite(index, x, y, size, "string", color);
--addPolySprite(index, color, x1, y1, x2, y2, x2, y2);
--linearInterpolate(index, destinationX, destinationY, speed);
--setProp(target, type);

right_pane_start = 799;
left_pane_start = 1;
right_pane_destination = 450;
left_pane_destination = 350;
y_offset = 50;

this_plr = 0;
nme_plr = 0;
locked = false;

--background
addSprite("bg", 0, 0, "main_menu_bg.png", 0, 0);
addSprite("left_pane", 1, 50, "match_setup_panel.png", -400, 0);
addSprite("right_pane", 799, 50, "match_setup_panel.png",  0, 0);

--selector
addPolySprite("nme_selector_bg", left_pane_start + 5 - 6, 140 + 128, 0x14b4ff, 0, 0, 345, 0, 345, 96 + 20, 0, 96 + 20);
addPolySprite("selector_bg", right_pane_start + 5, 140, 0x14b4ff, 0, 0, 345, 0, 345, 96 + 20, 0, 96 + 20);
addPolySprite("nme_type_selector", left_pane_start - 342, 134 - 16, 0x14b4ff, 0, 0, 96, 0, 96, 96, 0, 96);

--right panel
addSprite("centa_icon", right_pane_start + 30, 150, "centa_icon.png", 96, 96);
addStringSprite("centa_icon_text", right_pane_start + 136, 150, 30, "Centa Chicken", 0x000000);
addStringSprite("centa_icon_desc", right_pane_start + 136, 185, 20, "Centa chicken is the best\nchicken, in ever.", 0x000000);

addSprite("russ_icon", right_pane_start + 30, 271, "russ_icon.png",  96, 96);
addStringSprite("russ_icon_text", right_pane_start + 136, 271, 30, "Russian Chicken", 0x000000);
addStringSprite("russ_icon_desc", right_pane_start + 136, 306, 20, "russian chicken, not so\ngood.", 0x000000);

addPolySprite("ready_bg", right_pane_start + 5, 540, 0x14b4ff, 0, 0, 345, 0, 345, 60, 0, 60);
addSprite("ready_btn", right_pane_start + 30, 555, "btn_select_inact.png",  32, 32);
addStringSprite("ready_btn_text", right_pane_start + 77, 555, 25, "Ready", 0x000000);

--left panel
addSprite("ai_icon", left_pane_start - 318, 134, "ai.png", 0, 0);
addSprite("net_icon", left_pane_start - 200, 134, "net.png", 0, 0);
addSprite("local_icon", left_pane_start - 85, 134, "local.png", 0, 0);

addStringSprite("ai_icon_text", left_pane_start - 305, 180, 22, "Ai", 0x000000);
addStringSprite("net_icon_text", left_pane_start - 213, 180, 22, "Network", 0x000000);
addStringSprite("local_icon_text", left_pane_start - 85, 180, 22, "Local", 0x000000);


addSprite("nme_centa_icon", left_pane_start - 10 + 30, 128+ 150, "centa_icon.png",  96, 96);
addStringSprite("nme_centa_icon_text", left_pane_start - 10 + 136,128 +  150, 30, "Centa Chicken", 0x000000);
addStringSprite("nme_centa_icon_desc", left_pane_start - 10 + 136,128 +  185, 20, "Centa chicken is the best\nchicken, in ever.", 0x000000);

addSprite("nme_russ_icon", left_pane_start - 10 + 30, 128+ 271, "russ_icon.png",  96, 96);
addStringSprite("nme_russ_icon_text", left_pane_start - 10 + 136,128 +  271, 30, "Russian Chicken", 0x000000);
addStringSprite("nme_russ_icon_desc", left_pane_start - 10 + 136,128 +  306, 20, "russian chicken, not so\ngood.", 0x000000);

--lables
addStringSprite("right_pane_title", right_pane_start + 275, y_offset, 45, "You", 0xdddddd);
addStringSprite("left_pane_title", left_pane_start - 345, 50, 45, "Enemy", 0xdddddd);

function init()
	linearInterpolate("ai_icon", left_pane_destination - 318, 134, 65.0);
	linearInterpolate("net_icon", left_pane_destination - 200, 134, 65.0);
	linearInterpolate("local_icon", left_pane_destination - 85, 134, 65.0);
	linearInterpolate("ai_icon_text", left_pane_destination - 305, 180, 65.0);
	linearInterpolate("net_icon_text", left_pane_destination - 213, 180, 65.0);
	linearInterpolate("local_icon_text", left_pane_destination - 85, 180, 65.0);

	linearInterpolate("selector_bg", right_pane_destination + 5, 140, 65.0);
	linearInterpolate("nme_type_selector", left_pane_destination - 342, 134 - 16, 65.0);

	linearInterpolate("centa_icon", right_pane_destination + 30, 150, 65.0);
	linearInterpolate("centa_icon_text", right_pane_destination + 136, 150, 65.0);
	linearInterpolate("centa_icon_desc", right_pane_destination + 136, 185, 65.0);

	linearInterpolate("russ_icon", right_pane_destination + 30, 271, 65.0);
	linearInterpolate("russ_icon_text", right_pane_destination + 136, 271, 65.0);
	linearInterpolate("russ_icon_desc", right_pane_destination + 136, 306, 65.0);

	linearInterpolate("ready_bg", right_pane_destination + 5, 540, 65.0);
	linearInterpolate("ready_btn", right_pane_destination + 30, 555, 65.0);
	linearInterpolate("ready_btn_text", right_pane_destination + 77, 555, 65.0);

	linearInterpolate("right_pane_title", right_pane_destination + 275, y_offset, 65.0);
	linearInterpolate("left_pane_title", left_pane_destination - 345, y_offset, 65.0);
	linearInterpolate("right_pane", right_pane_destination, y_offset, 65.0);
	linearInterpolate("left_pane", left_pane_destination, y_offset, 65.0);
end

function event(target, type)
	if target == "mousedown" then
		
	end

	if type == "clicked" and locked == false then
		print("clicked: "..target);

		if target == "centa_icon" then
			this_plr = 0;
			linearInterpolate("selector_bg", 455, 140, 100);
		end
		if target == "russ_icon" then
			this_plr = 1;
			linearInterpolate("selector_bg", 455, 260, 100);
		end
		if target == "nme_centa_icon" then
			nme_plr = 0;
			linearInterpolate("nme_selector_bg", left_pane_start + 5 - 6, 140 + 128, 100);
		end
		if target == "nme_russ_icon" then
			nme_plr = 1;
			linearInterpolate("nme_selector_bg", left_pane_start + 5 - 6, 140 + 128 + 121, 100);
		end

		if target == "ready_btn" then
			startBattle();
		end
	end

	if locked == true then --yeah i know
		if target == "vs" and type == "arrived" then
			print("calling state: battle with args: this play = "..this_plr..", enemy player = "..nme_plr);
			callState("battle", this_plr, nme_plr);
		end
	end
end

function startBattle()
	print("match setup, entering battle.");
	locked = true;

	addSprite("vs", 25, -230, "vs.png", 0, 0);
	linearInterpolate("vs", 25, 800, 100);
end

function error(type)

end