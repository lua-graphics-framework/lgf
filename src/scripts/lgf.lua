require("src.libs.window.window")
require("src.libs.renderer.renderer")
require("src.libs.rectangle.rectangle")
require("src.libs.mouse.mouse")

LGF = {}
LGF.__index = LGF

LGF.Window = window
LGF.Renderer = renderer
LGF.Rectangle = rectangle
LGF.Mouse = mouse

return LGF
