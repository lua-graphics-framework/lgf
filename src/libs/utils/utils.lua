utils = {}
utils.__index = utils

function utils:mouseInRect(mousex, mousey, x, y, w, h)
  if mousex < x then
    return false
  end

  if mousey < y then
    return false
  end

  if mousex > x + w then
    return false
  end

  if mousey > y + h then
    return false
  end

  return true
end

function utils:aabb(x1, y1, x2, y2, w1, h1, w2, h2)
  local leftA = x1
  local rightA = x1 + w1
  local topA = y1
  local bottomA = y1 + h1

  local leftB = x2
  local rightB = x2 + w2
  local topB = x2
  local bottomB = y2 + h2

  if bottomA <= topB then
    return false
  end

  if topA >= bottomB then
    return false
  end

  if rightA <= leftB then
    return false
  end

  if leftA >= rightB then
    return false
  end

  return true
end

return utils
