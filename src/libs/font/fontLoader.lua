require("src.libs.image.image")

fontLoader = {}
fontLoader.__index = fontLoader

function fontLoader.create()
    local self = setmetatable({}, fontLoader)
    return self
end

function fontLoader:loadText(font, text)
    loadText(font.index, text)
end

function fontLoader:renderText(x, y)
    renderText(font.index, x, y)
end