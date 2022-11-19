require("src.libs.image.imageLoader")

image = {}
image.__index = image

local index = -1

function image.load(x, y, w, h, path)
    local self = setmetatable({}, self)
    index = index + 1

    self.x = x
    self.y = y
    self.w = w
    self.h = h
    self.index = index

    loadImage(path)
    return self
end