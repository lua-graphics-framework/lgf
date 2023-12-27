require("src.scripts.lgf")

local width = 1280
local height = 720
local window = LGF.Window.create("Pong", width, height)
window:sync(60)

local renderer = LGF.Renderer.create()
renderer:changeColorRGB(0, 0, 0)

local cookies_clicked = 0;

local font = LGF.Font.create()
font:loadFont("tests/cookie_clicker/res/gfx/font.ttf", 40)

local text = LGF.Text.create("Cookies: 0", 255, 255, 255, 10, 10)
font:loadText(text)

local cookie = LGF.Rectangle.create(590, 310, 100, 100)

while window:active() do
  renderer:changeColorRGB(0, 0, 0)
  renderer:clearScreen()

  text:draw()
  cookie:changeColor(255, 255, 255)
  cookie:draw()

  LGF.Mouse:poll()

  renderer:render()
  window:update()
end

window:close()
