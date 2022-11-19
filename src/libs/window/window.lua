window = {}
window.__index = window

function window.create(title, width, height)
  local self = setmetatable({}, window)

  self.title = title
  self.width = width
  self.height = height

  self:new()

  return self
end

function window:isCloseRequested()
  return isCloseRequested()
end

function window:setIcon(path)
  setIcon(path)
end

function window:new()
  create(self.title, self.width, self.height)
end

function window:vsyncOn()
  setVSync(1)
end

function window:vsyncOff()
  setVSync(0)
end

function window:changeColor(r, g, b)
  windowChangeColor(r, g, b)
end

function window:sync(fps)
  sync(fps)
end

function window:update()
  update()
end

function window:clear()
  clearScreen()
end

function window:render()
display()
end

function window:close()
close()
end