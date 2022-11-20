renderer = {}
renderer.__index = renderer

function renderer.new()
  local self = setmetatable({}, renderer)
  create()

  return self
end

function renderer:toggleVSync()
  toggleVSync()
end

function renderer:clearScreen()
  clearScreen()
end

function renderer:render()
  render()
end

function renderer:changeColorRGB(r, g, b)
  changeColorRGB(r, g, b)
end

return renderer
