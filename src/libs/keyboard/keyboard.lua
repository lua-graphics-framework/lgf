require("src.libs.keyboard.keycode")

keyboard = {}
keyboard.__index = keyboard

function keyboard:keyup(keycode)
  if keycode then
    if keyup() == keycode then
      return true
    end
  end

  return false
end

function keyboard:keydown(keycode)
  if keycode then
    if keydown() == keycode then
      return true
    end
  end

  return false
end

function keyboard:poll()
  pollKeyboard()
end
