local mod = require("libLuaGraphicsFramework")

image = {}
image.__index = image

local index = -1

function image.load(x, y, w, h, path)
  local self = setmetatable({}, image)
  index = index + 1

  self.x = x
  self.y = y
  self.w = w
  self.h = h
  self.index = index

  mod.loadImage(path)
  return self
end

function image:draw()
  mod.drawImage(self.x, self.y, self.w, self.h, self.index)
end