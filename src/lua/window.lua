window = {}
window.__index = window

function window.create(title, width, height)
  local self = setmetatable({}, window)

  self.title = title
  self.width = width
  self.height = height

  lgf_window_create(self.width, self.height, self.title)

  return self
end

function window:clear()
  lgf_window_clear()
end

function window:display()
  lgf_window_display()
end

function window:active()
  return lgf_window_active()
end

function window:sync(fps)
  lgf_window_sync(fps)
end

function window:update()
  lgf_window_update()
end

function window:close()
  lgf_window_close()
end
