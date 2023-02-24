require("src.scripts.lgf")

local width = 1280
local height = 720
local window = LGF.Window.create("Pong", width, height)
window:sync(60)

local renderer = LGF.Renderer.create()
renderer:changeColorRGB(0, 0, 0)

local paddle1 = LGF.Rectangle.create(20, height/2 - 150, 5, 150)
local paddle2 = LGF.Rectangle.create(1260, height/2 - 150, 5, 150)

local function draw()
  paddle1:changeColor(255, 255, 255)
  paddle1:draw()

  paddle2:changeColor(255, 255, 255)
  paddle2:draw()
end

local function keys()
  keyboard:poll()

  if keyboard:keydown(LGF.Keyboard.Keycode.KEY_S) then
    paddle1.y = paddle1.y + 5
    paddle1:updatePos()
  end
end

while window:active() do
  renderer:clearScreen()

  keys()
  draw()

  renderer:render()
  window:update()
end

window:close()
