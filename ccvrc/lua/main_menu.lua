--require "state";

--addSprite(index, x, y, "src", width, height);
--addStringSprite(index, x, y, size, "string", color);
--addPolySprite(index, color, x1, y1, x2, y2, x2, y2);


addSprite("bg", 0, 0, "main_menu_bg.png", 0, 0);
addSprite("centa", 600, 400, "centa_full.png", 0, 0);
addSprite("title", (800 / 2) - (684 / 2), 10, "logo.png", 0, 0);
addStringSprite("cts", 250, 350, 64, "Click to start", 0xfeffff);

function init()

end

function event(target, type)

end

function error(type)

end