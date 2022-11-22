mouse = {}
mouse.__index = mouse

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
