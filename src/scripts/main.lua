require("src.scripts.lgf")

LGF.Window.create("Lua Graphics Framework", 1280, 720)
LGF.Window:sync(60)

LGF.Renderer.new()

local r = LGF.Rectangle.create(10, 10, 50, 50)
local r2 = LGF.Rectangle.create(10, 70, 50, 50)
local r3 = LGF.Rectangle.create(10, 130, 50, 50)

while LGF.Window:active() do
  LGF.Renderer:clearScreen()

  r:changeColor(255, 255, 255)
  r:draw()

  r2:changeColor(255, 255, 255)
  r2:draw()

  r3:changeColor(255, 255, 2555)
  r3:draw()

  LGF.Renderer:changeColorRGB(0, 0, 0)
  LGF.Renderer:render()

  LGF.Window:update()
end

LGF.Window:close()
