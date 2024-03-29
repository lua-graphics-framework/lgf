require("src.libs.window.window")
require("src.libs.renderer.renderer")
require("src.libs.rectangle.rectangle")
require("src.libs.mouse.mouse")
require("src.libs.keyboard.keyboard")
require("src.libs.image.image")
require("src.libs.font.font")
require("src.libs.utils.utils")

LGF = {}
LGF.__index = LGF

LGF.Window = window
LGF.Renderer = renderer
LGF.Rectangle = rectangle
LGF.Mouse = mouse
LGF.Keyboard = keyboard
LGF.Keyboard.Keycode = keycode
LGF.Image = image
LGF.Font = font
LGF.Text = text
LGF.Utils = utils

return LGF
