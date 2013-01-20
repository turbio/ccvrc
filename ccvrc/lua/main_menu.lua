--require "state";

--addSprite(index, x, y, "src", width, height);
--addStringSprite(index, x, y, size, "string", color);
--addPolySprite(index, color, x1, y1, x2, y2, x2, y2);

addSprite("bg", 0, 0, "main_menu_bg.png", 0, 0);
addSprite("title", 123, 123, "logo.png", 0, 0);
--addStringSprite(0, 123, 123, 64, getProp(-1, "width"), 0xfeffff);

function init()

end

function event(target, type)

end

function error(type)

end