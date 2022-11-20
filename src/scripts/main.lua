require("src.libs.window.window")

window.create("LGF Test", 1280, 720)
window:changeColor(0, 0, 0)
window:sync(60)

while window:active() do
  window:clear()
  window:render()
  window:update()
end

window:close()
