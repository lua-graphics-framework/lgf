imageLoader = {}
imageLoader.__index = imageLoader

function imageLoader:draw(image)
  drawImage(image.x, image.y, image.w, image.h, image.index)
end