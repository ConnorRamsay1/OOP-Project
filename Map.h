#ifndef MAP_H
#define MAP_H

class Map{
    private:
    const int screenWidth;
    const int screenHeight;
    public:
    Map(const int screenWidth, const int screenHeight);
    void Draw();
};

#endif