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
  windowCreate(self.width, self.height, self.title)
end

function window:sync(fps)
  sync(fps)
end

function window:update()
  update()
end

function window:close()
  close()
end