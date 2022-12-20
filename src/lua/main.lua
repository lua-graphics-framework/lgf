local window = require("src.lua.window")

local win = window.create(1280, 720, "LGF Test")
win:sync(60)
win:changeColor(0, 0, 255)

while win:active() do
  win:clear()
  win:display()
  win:update()
end

win:close()
