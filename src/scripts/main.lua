require("src.scripts.lgf")

LGF.Window.create("Lua Graphics Framework", 1280, 720)
LGF.Window:sync(60)

LGF.Renderer.new()

while LGF.Window:active() do
  LGF.Renderer:clearScreen()
  LGF.Renderer:render()

  LGF.Window:update()
end

LGF.Window:close()
