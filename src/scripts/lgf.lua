require("src.libs.window.window")
require("src.libs.renderer.renderer")
require("src.libs.rectangle.rectangle")
require("src.libs.mouse.mouse")
require("src.libs.keyboard.keyboard")

LGF = {}
LGF.__index = LGF

LGF.Window = window
LGF.Renderer = renderer
LGF.Rectangle = rectangle
LGF.Mouse = mouse
LGF.Keyboard = keyboard
LGF.Keyboard.Keycode = keycode

return LGF
