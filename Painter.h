#ifndef PAINTER_H
#define PAINTER_H

#include <vector>

class Painter
{
public:
    Painter();
    void bar( int x1, int y1, int x2, int y2 );
    void circle( int x, int y, int radius );

private:
    void setBarVertices( int x1, int y1, int x2, int y2 );
    void setBarIndices();
    void setBarColor( float r, float g, float b );
    std::vector<int> m_barVertices;
    std::vector<unsigned int> m_barIndices;
    std::vector<float> m_barColors;

    void setCircleVertices( int x, int y, int radius );
    void setCircleIndices();
    void setCircleColor( float r, float g, float b );
    std::vector<int> m_circleVertices;
    std::vector<unsigned int> m_circleIndices;
    std::vector<float> m_circleColors;
};

#endif // PAINTER_H
