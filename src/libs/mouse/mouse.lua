mouse = {}
mouse.__index = mouse

function mouse.create()
  local self = setmetatable({}, mouse)

  self.button1Up = false
  self.button1Down = false
  self.button2Up = false
  self.button2Down = false
  self.button3Up = false
  self.button3Down = false

  return self
end

function mouse:clearEvents()
  self.button1Up = false
  self.button1Down = false
  self.button2Up = false
  self.button2Down = false
  self.button3Up = false
  self.button3Down = false
end

function mouse:poll()
  if mouseButtonUp(1) == true then
    self:clearEvents()
    self.button1Up = true
  elseif mouseButtonDown(1) == true then
    self:clearEvents()
    self.button1Down = true
  elseif mouseButtonUp(2) == true then
    self:clearEvents()
    self.button2Up = true
  elseif mouseButtonDown(2) == true then
    self:clearEvents()
    self.button2Down = true
  elseif mouseButtonUp(3) == true then
    self:clearEvents()
    self.button3Up = true
  elseif mouseButtonDown(3) == true then
    self:clearEvents()
    self.button3Down = true
  else
    self:clearEvents()
  end
end