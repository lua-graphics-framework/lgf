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
  mousePollEvents()
end

function mouse:mouseButtonDown(btn)
  return mouseButtonDown(btn)
end

function mouse:mouseButtonUp(btn)
  return mouseButtonUp(btn)
end

function mouse:getCursorPos()
  return { getMousePosX(), getMousePosY() }
end
