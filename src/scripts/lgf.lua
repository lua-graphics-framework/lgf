require("src.libs.window.window")
require("src.libs.renderer.renderer")

LGF = {}
LGF.__index = LGF

LGF.Window = window
LGF.Renderer = renderer

return LGF
