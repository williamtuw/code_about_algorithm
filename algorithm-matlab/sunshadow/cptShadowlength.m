function [ shadowlength ] = cptShadowlength( barheight,elevation  )
shadowlength = barheight ./ tan(elevation);
end

