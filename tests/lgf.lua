require("src.scripts.lgf")

local width = 1280
local height = 720
local window = LGF.Window.create("Pong", width, height)
window:sync(60)

local renderer = LGF.Renderer.create()
renderer:changeColorRGB(0, 0, 0)

local paddle1 = LGF.Rectangle.create(20, height/2 - 75, 5, 150) -- alligned paddle correctly
local paddle2 = LGF.Rectangle.create(1260, height/2 - 75, 5, 150) -- alligned paddle correctly

while window:active() do
  renderer:clearScreen()

  keyboard:poll()
  if LGF.Keyboard:keydown(keycode.KEY_S) then
    paddle1.w = paddle1.w + 1
    paddle1:updateSize() -- update position
  end

  paddle1:changeColor(255, 255, 255)
  paddle1:draw()

  paddle2:changeColor(255, 255, 255)
  paddle2:draw()

  renderer:render()
  window:update()
end

window:close()
