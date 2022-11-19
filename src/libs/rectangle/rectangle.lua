rectangle = {}
rectangle.__index = rectangle

function rectangle.create(x, y, w, h)
  local self = setmetatable({}, rectangle)

  self.x = x
  self.y = y
  self.w = w
  self.h = h
  
  self:new()

  return rectangle
end

function rectangle:new()
  createRectangle(self.x, self.y, self.w, self.h)
end

function rectangle:changeColor(r, g, b)
  changeRectangleColor(r, g, b);
end

function rectangle:draw()
  drawRectangle();
end