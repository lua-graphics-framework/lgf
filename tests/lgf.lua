require("src.scripts.lgf")

local width = 1280
local height = 720
local window = LGF.Window.create("Pong", width, height)
window:sync(60)

local renderer = LGF.Renderer.create()
renderer:changeColorRGB(0, 0, 0)

local font = LGF.Font.create()
font:loadFont("tests/res/gfx/font.ttf", 20)

local text = LGF.Text.create("What is this?", 255, 255, 255, 10, 10)
font:loadText(text)

while window:active() do
  renderer:clearScreen()

  text:draw()

  renderer:render()
  window:update()
end

window:close()
