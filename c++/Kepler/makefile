LIBSGEN=-larmadillo -lm
LIBSOPENGL=-lGL -lGLU -lglut
FuentesGL=LOpenGL.h circuloopengl.hpp 

Kepler01.x: Kepler01.cpp Planeta01.hpp
	g++ $< $(LIBSGEN) -o $@

TresCuerposFlat01.x: TresCuerpos01.cpp Planeta01.hpp
	g++ $< $(LIBSGEN) -o $@

TresCuerpos3D01.x: TresCuerpos3D01.cpp Planeta3D01.hpp
	g++ $< $(LIBSGEN) -o $@


KeplerAnimado01.x: KeplerAnimado01.cpp Planeta01.hpp  FondosyFiguras01.hpp $(FuentesGL)
	g++ $< $(LIBSGEN) $(LIBSOPENGL) -o $@

KeplerAnimado02.x: KeplerAnimado02.cpp Planeta01.hpp FondosyFiguras02.hpp $(FuentesGL)
	g++ $< $(LIBSGEN) $(LIBSOPENGL) -o $@


TresCuerposAnimado01.x: TresCuerposAnimado01.cpp Planeta01.hpp FondosyFiguras03.hpp $(FuentesGL)
	g++ $< $(LIBSGEN) $(LIBSOPENGL) -o $@

