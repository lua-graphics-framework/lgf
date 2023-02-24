mouse = {}
mouse.__index = mouse

local poll = false
local checked = false

function mouse:poll()
  mousePollEvents()
  poll = true
end

function mouse:mouseButtonDown(btn)
  if poll == false and checked == false then
    print("Warning: Poll your mouse events before checking!")
    checked = true
  end

  return mouseButtonDown(btn)
end

function mouse:mouseButtonUp(btn)
  if poll == false and checked == false then
    print("Warning: Poll your mouse events before checking!")
    checked = true
  end

  return mouseButtonUp(btn)
end

function mouse:getCursorPos()
  return { getMousePosX(), getMousePosY() }
end
