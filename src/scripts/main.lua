require("src.scripts.lgf")

LGF.Window.create("Lua Graphics Framework", 1280, 720)
LGF.Window:sync(60)

LGF.Renderer.new()

while LGF.Window:active() do
  LGF.Renderer:clearScreen()

  if LGF.Mouse:mouseButtonUp(1) == true then
    print("Left mouse button pressed.")
  end

  if LGF.Mouse:mouseButtonUp(2) == true then
    print("Middle mouse button pressed.")
  end

  if LGF.Mouse:mouseButtonUp(3) == true then
    print("Right mouse button pressed.")
  end

  LGF.Renderer:changeColorRGB(0, 0, 0)
  LGF.Renderer:render()

  LGF.Window:update()
end

LGF.Window:close()
