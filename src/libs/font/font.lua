local mod = require("libLuaGraphicsFramework")

font = {}
font.__index = font

text = {}
text.__index = text

local index = -1
local textIndex = -1

function text.new(txt, r, g, b)
  local self = setmetatable({}, text)
  textIndex = textIndex + 1

  self.r = r
  self.g = g
  self.b = b

  self.idx = textIndex
  self.text = txt

  return self
end

function text:draw(x, y)
  mod.renderText(self.idx, x, y)
end

function font.create()
  local self = setmetatable({}, font)

  index = index + 1
  self.index = index
  self.text = {}

  return self
end

function font:loadFont(fontPath, size)
  mod.loadFont(fontPath, size)
end

function font:loadText(text)
  mod.loadText(text.idx, text.text, text.r, text.g, text.b)
end
