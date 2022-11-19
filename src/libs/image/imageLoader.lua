imageLoader = {}
imageLoader.__index = imageLoader

function imageLoader.create()
    local self = setmetatable({}, imageLoader)
    return self
end

function imageLoader:draw(image)
    drawImage(image.x, image.y, image.w, image.h, image.index)
end