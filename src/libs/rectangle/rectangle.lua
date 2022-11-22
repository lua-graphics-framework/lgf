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

  createRectangle(self.x, self.y, self.w, self.h)
  return self
end

function rectangle:updatePos()
  changeRectanglePos(self.idx, self.x, self.y)
end

function rectangle:updateSize()
  changeRectangleSize(self.idx, self.w, self.h)
end

function rectangle:changeColor(r, g, b)
  changeRectangleColor(r, g, b);
end

function rectangle:draw()
  drawRectangle(self.idx)
end