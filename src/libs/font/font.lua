font = {}
font.__index = font

text = {}
text.__index = text

local index = -1
local textIndex = -1

function text.new(txt, r, g, b, x, y)
  local self = setmetatable({}, text)
  textIndex = textIndex + 1

  self.r = r
  self.g = g
  self.b = b
  self.x = x
  self.y = y

  self.idx = textIndex
  self.text = txt

  return self
end

function text:draw(x, y)
  renderText(self.idx, x, y)
end

function text:changeText(newText)
  changeFontText(self.idx, newText)
end

function text:updatePos()
  changeFontPosition(self.idx, self.x, self.y)
end

function font.create()
  local self = setmetatable({}, font)

  index = index + 1
  self.index = index
  self.text = {}

  return self
end

function font:loadFont(fontPath, size)
  loadFont(fontPath, size)
end

function font:loadText(text)
  loadText(text.idx, text.text, text.r, text.g, text.b, text.x, text.y)
end
