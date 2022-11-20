require("src.scripts.lgf")

LGF.Window.create("Lua Graphics Framework", 1280, 720)
LGF.Window:sync(60)

LGF.Renderer.new()

local font = LGF.Font.create()
font:loadFont("res/gfx/font.ttf", 30)

local text = LGF.Text.new("Hello LGF!", 255, 255, 255)
font:loadText(text)

while LGF.Window:active() do
  LGF.Renderer:changeColorRGB(0, 0, 0)
  LGF.Renderer:clearScreen()

  text:draw(30, 30)
  LGF.Renderer:render()

  LGF.Window:update()
end

LGF.Window:close()
