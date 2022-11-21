local mod = require("libLuaGraphicsFramework")

mouse = {}
mouse.__index = mouse

mouse.button1Up = false
mouse.button1Down = false
mouse.button2Up = false
mouse.button2Down = false
mouse.button3Up = false
mouse.button3Down = false

function clearEvents()
  mouse.button1Up = false
  mouse.button1Down = false
  mouse.button2Up = false
  mouse.button2Down = false
  mouse.button3Up = false
  mouse.button3Down = false
end

function mouse:poll()
  mod.mousePollEvents()
end

function mouse:mouseButtonDown(btn)
  return mod.mouseButtonDown(btn)
end

function mouse:mouseButtonUp(btn)
  return mod.mouseButtonUp(btn)
end

function mouse:getCursorPos()
  return { mod.getMousePosX(), mod.getMousePosY() }
end
