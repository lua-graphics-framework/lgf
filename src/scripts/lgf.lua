require("src.libs.window.window")
require("src.libs.renderer.renderer")
require("src.libs.rectangle.rectangle")

LGF = {}
LGF.__index = LGF

LGF.Window = window
LGF.Renderer = renderer
LGF.Rectangle = rectangle

return LGF
