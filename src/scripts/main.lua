require("src.scripts.lgf")

LGF.Window.create("Lua Graphics Framework", 1280, 720)
LGF.Window:sync(60)

LGF.Renderer.new()

local testImg = LGF.Image.load(10, 10, 50, 50, "res/gfx/ball.png")

while LGF.Window:active() do
  LGF.Renderer:changeColorRGB(0, 0, 0)
  LGF.Renderer:clearScreen()

  testImg:draw()

  LGF.Renderer:render()

  LGF.Window:update()
end

LGF.Window:close()
