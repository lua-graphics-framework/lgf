font = {}
font.__index = font

text = {}
text.__index = text

local index = -1
local textIndex = -1

function text.create(txt, r, g, b, x, y)
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

function text:draw()
  renderText(self.idx, self.x, self.y)
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
  if text.x and text.y and text.text and text.r and text.g and text.b and text.idx then
    loadText(text.idx, text.text, text.r, text.g, text.b, text.x, text.y)
  else
    print("Error: Attempted to load invalid text.")
    print("\tPlease make sure you are passing a `LGF.Text` object rather than a string.")
    print("\tAlso, be sure that each member variable of the text object is valid.")
    os.exit(1, true)
  end
end
