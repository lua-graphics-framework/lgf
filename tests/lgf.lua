require("src.scripts.lgf")

local width = 1280
local height = 720
local window = LGF.Window.create("Pong", width, height)
window:sync(60)

local renderer = LGF.Renderer.create()
renderer:changeColorRGB(0, 0, 0)

while window:active() do
  renderer:clearScreen()
  renderer:render()

  -- mouse:poll()

  if mouse:mouseButtonUp(1) == true then
    print("??")
  end

  window:update()
end

window:close()
