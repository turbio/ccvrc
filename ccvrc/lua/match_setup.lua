--addSprite(index, x, y, "src", width, height);
--addStringSprite(index, x, y, size, "string", color);
--addPolySprite(index, color, x1, y1, x2, y2, x2, y2);
--linearInterpolate(index, destinationX, destinationY, speed);
--getProp

right_pane_start = 799;
left_pane_start = 1;
right_pane_destination = 450;
left_pane_destination = 350;
y_offset = 50;

addSprite("bg", 0, 0, "main_menu_bg.png", 0, 0);
addSprite("left_pane", 1, 50, "match_setup_panel.png", -400, 0);
addSprite("right_pane", 799, 50, "match_setup_panel.png",  0, 0);

--right panel
--addPolySprite("centa_bg", 455, 140, 0x14b4ff, 0, 0, 345, 0, 345, 10, 0, 10);
addSprite("centa_icon", right_pane_start + 30, 150, "centa_icon.png",  96, 96);
addStringSprite("centa_icon_text", right_pane_start + 136, 150, 30, "Centa Chicken", 0x000000);
addStringSprite("centa_icon_desc", right_pane_start + 136, 185, 20, "Centa chicken is the best\nchicken, in ever.", 0x000000);

addSprite("russ_icon", right_pane_start + 30, 271, "russ_icon.png",  96, 96);
addStringSprite("russ_icon_text", right_pane_start + 136, 271, 30, "Russian Chicken", 0x000000);
addStringSprite("russ_icon_desc", right_pane_start + 136, 306, 20, "russian chicken, not so\ngood.", 0x000000);

addPolySprite("ready_bg", right_pane_start + 5, 540, 0x14b4ff, 0, 0, 345, 0, 345, 60, 0, 60);
addSprite("ready_btn", right_pane_start + 30, 555, "btn_select_inact.png",  0, 0);
addStringSprite("ready_btn_text", right_pane_start + 77, 555, 25, "Ready", 0x000000);


--lables
addStringSprite("right_pane_title", right_pane_start + 275, y_offset, 45, "You", 0xdddddd);
addStringSprite("left_pane_title", left_pane_start - 345, 50, 45, "Enemy", 0xdddddd);

function init()
	stage = 0;
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
	
end

function error(type)

end