--addSprite(index, x, y, "src", width, height);
--addStringSprite(index, x, y, size, "string", color);
--addPolySprite(index, color, x1, y1, x2, y2, x2, y2);
--linearInterpolate(index, destinationX, destinationY, speed);
--callState(state);

addSprite("bg", 0, 0, "main_menu_bg.png", 0, 0);
addSprite("centa", 600, 400, "centa_full.png", 0, 0);
addSprite("russ", 200, 400, "russ_final.png", -674, 0);
addSprite("title", (800 / 2) - (684 / 2), 50, "logo.png", 0, 0);
addStringSprite("cts", 250, 450, 64, "Click to Start", 0xfeffff);



function init()
	stage = 0;	--the current step that the ui is in
end

function event(target, type)
	if target == "mousedown" or target == "keydown" or type == "arrived" then
		if stage == 0 then
			if target == "mousedown" or target == "keydown" then
				linearInterpolate("cts", getProp("cts", "x"), 600, 40.0);
				stage = stage + 1;
			end
		elseif stage == 1 then
			print("setting state: match_setup");
			callState("match_setup");
			stage = stage + 1;
		end
	end
end

function error(type)

end