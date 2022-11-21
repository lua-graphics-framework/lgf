local mod = require("libLuaGraphicsFramework")

renderer = {}
renderer.__index = renderer

function renderer.new()
  local self = setmetatable({}, renderer)
  mod.create()

  return self
end

function renderer:toggleVSync()
  mod.toggleVSync()
end

function renderer:clearScreen()
  mod.clearScreen()
end

function renderer:render()
  mod.render()
end

function renderer:changeColorRGB(r, g, b)
  mod.changeColorRGB(r, g, b)
end

return renderer
