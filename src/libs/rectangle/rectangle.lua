local mod = require("libLuaGraphicsFramework")

rectangle = {}
rectangle.__index = rectangle

local idx = -1

function rectangle.create(x, y, w, h)
  local self = setmetatable({}, rectangle)
  idx = idx + 1

  self.x = x
  self.y = y
  self.w = w
  self.h = h
  self.idx = idx

  self:new()
  return self
end

function rectangle:new()
  mod.createRectangle(self.x, self.y, self.w, self.h)
end

function rectangle:changeColor(r, g, b)
  mod.changeRectangleColor(r, g, b);
end

function rectangle:draw()
  mod.drawRectangle(self.idx)
end