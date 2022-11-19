require("src.libs.window.window")

window.create("LGF Test", 1280, 720)
window:changeColor(0, 0, 0)
window:sync(60)

while not window:isCloseRequested() do
  window:clear()
  window:update()

  window:render()
end

window:close()

-- TODO: built in AABBs
-- TODO: fix code up
-- TODO: dynamic libraries
-- TODO: test, release