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

function window:active()
  return active()
end

function window:setIcon(path)
  setIcon(path)
end

function window:new()
  create(self.width, self.height, self.title)
end

function window:vsyncOn()
  setVSync(1)
end

function window:vsyncOff()
  setVSync(0)
end

function window:changeColor(r, g, b)
  changeColorRGB(r, g, b)
end

function window:sync(fps)
  sync(fps)
end

function window:update()
  update()
end

function window:clear()
  clear()
end

function window:render()
  render()
end

function window:close()
  close()
end