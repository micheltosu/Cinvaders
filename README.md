Programmet behöver ha mappen Resources i samma mapp som programmet körs från.

Spelet spelas med tangenterna WASD samt mellanslag. I menyn innan spelet startas kan man ange sitt spelarnamn. Tryck sedan på knappen start för att börja spela. 


Vid kompilering måste följande mappar inkluderas:
Include/ToMingine/Headers



Dessutom måste SDL2, SDL2_image och SDL2_ttf kunna hittas av Kompilator och Länkare.




kommando för att kompilera med GCC. Stående i mappen Cinvaders.

g++ -o Cinvaders.ex -L "SD2 path" -L "SDL2_Image path" -L "SDL2_TTF path"  e -I "Include/ToMingine/Headers" *.cpp

g++ -o Cinvaders.exe -m32 -std=c++11 -w -Wl,-subsystem,windows -I"C:\Program Files (x86)\DevLibs\SDL2\include\SDL2" -I"C:\Program Files (x86)\DevLibs\SDL2_image\include\SDL2" -I"C:\Program Files (x86)\DevLibs\SDL2_ttf\include\SDL2" -I"Cinvaders/Include/ToMingine/Headers" -I"Cinvaders/Include/ToMingine" -L"C:\Program Files (x86)\DevLibs\SDL2\lib" -L"C:\Program Files (x86)\DevLibs\SDL2_image\lib" -L"C:\Program Files (x86)\DevLibs\SDL2_ttf\lib" -lSDL2_ttf -lSDL2_image -lmingw32 -lSDL2main -lSDL2  Cinvaders/Include/ToMingine/*.cpp Cinvaders/*.cpp


