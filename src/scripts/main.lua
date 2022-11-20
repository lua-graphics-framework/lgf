require("src.scripts.lgf")

LGF.Window.create("Lua Graphics Framework", 1280, 720)
LGF.Window:sync(60)

LGF.Renderer.new()

while LGF.Window:active() do
  LGF.Renderer:clearScreen()

  LGF.Mouse:poll()
  local pos = LGF.Mouse:getCursorPos()

  if pos[1] < 100 then
    print("Mouse position is less than 100.")
  end

  LGF.Renderer:changeColorRGB(0, 0, 0)
  LGF.Renderer:render()

  LGF.Window:update()
end

LGF.Window:close()
