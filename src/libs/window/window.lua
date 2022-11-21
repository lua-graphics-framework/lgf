local mod = require("libLuaGraphicsFramework")

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
  return mod.active()
end

function window:setIcon(path)
  mod.setIcon(path)
end

function window:new()
  mod.windowCreate(self.width, self.height, self.title)
end

function window:sync(fps)
  mod.sync(fps)
end

function window:update()
  mod.update()
end

function window:close()
  mod.close()
end