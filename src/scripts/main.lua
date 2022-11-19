require("src.libs.window.window")

window.create("yeehaw", 800, 600)
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