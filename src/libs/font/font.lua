require("src.libs.font.fontLoader")

font = {}
font.__index = font

local index = -1

function font.create()
    local self = setmetatable({}, font)
    index = index + 1
    self.index = index

    return self
end

function font:loadFont(fontPath, size)
    loadFont(fontPath, size)
end