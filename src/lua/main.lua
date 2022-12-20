local window = require("window")

local win = window.new(1280, 720, "LGF Test")
win.sync(60)

while win.active() do
  win.clear()
  win.display()
  win.update()
end

win.close()
