require("src.scripts.lgf")

local wnd = LGF.Window.create("LGF", 1280, 720)
wnd:sync(60)

local renderer = LGF.Renderer.create()
renderer:changeColorRGB(180, 0, 0)

while wnd:active() do
  renderer:clearScreen()
  renderer:render()
  wnd:update()
end

wnd:close()
