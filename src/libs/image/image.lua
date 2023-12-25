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
  self._index = index

  self.srcX = 0
  self.srcY = 0
  self.srcWidth = w
  self.srcHeight = h

  loadImage(path)
  return self
end

function image:draw()
  drawImage(self.x, self.y, self.w, self.h, self.index)
end
