#include "Painter.h"
#include <GL/gl.h>

Painter::Painter()
{
    m_barVertices.resize( 6 * 3 );
    m_barIndices.resize( 6 );
    m_barColors.resize( 6 * 3 );

    m_circleVertices.resize( 6 * 3 );
    m_circleIndices.resize( 6 );
    m_circleColors.resize( 6 * 3 );
}

void Painter::bar( int x1, int y1, int x2, int y2 )
{
    setBarVertices( x1, y1, x2, y2 );
    setBarIndices();
    setBarColor( 0, 1, 0 );

    // Указываем, откуда нужно извлечь данные о массиве вершин
    glVertexPointer( 3, GL_INT, 0, m_barVertices.data() );

    // Указываем, откуда нужно извлечь данные о массиве цветов вершин
    glColorPointer( 3, GL_FLOAT, 0, m_barColors.data() );

    // Используя массивы вершин и индексов, строим поверхности
    glDrawElements( GL_TRIANGLES, m_barIndices.size(), GL_UNSIGNED_INT, m_barIndices.data() );

//    glBegin( GL_QUADS );
//    {
//        glVertex2f( x1, y1 );
//        glVertex2f( x2, y1 );
//        glVertex2f( x2, y2 );
//        glVertex2f( x1, y2 );
//    }
//    glEnd();
}

void Painter::circle( int x, int y, int radius )
{
    setCircleVertices( x, y, radius );
    setCircleIndices();
    setCircleColor( 1, 0, 0 );

    // Указываем, откуда нужно извлечь данные о массиве вершин
    glVertexPointer( 3, GL_INT, 0, m_circleVertices.data() );

    // Указываем, откуда нужно извлечь данные о массиве цветов вершин
    glColorPointer( 3, GL_FLOAT, 0, m_circleColors.data() );

    // Используя массивы вершин и индексов, строим поверхности
    glDrawElements( GL_TRIANGLES, m_circleIndices.size(), GL_UNSIGNED_INT, m_circleIndices.data() );

//    glColor3f( 1, 0, 0 );
//    glBegin( GL_POLYGON );
//    {
//        glVertex2f( x + radius, y );
//        glVertex2f( x, y + radius );
//        glVertex2f( x - radius, y );
//        glVertex2f( x, y - radius );
//    }
//    glEnd();
}

void Painter::setBarVertices( int x1, int y1, int x2, int y2 )
{
    // Первый треугольник
    // 0
    m_barVertices[0] = x1;
    m_barVertices[1] = y2;
    m_barVertices[2] = 0;

    // 1
    m_barVertices[3] = x2;
    m_barVertices[4] = y2;
    m_barVertices[5] = 0;

    // 2
    m_barVertices[6] = x1;
    m_barVertices[7] = y1;
    m_barVertices[8] = 0;

    // Второй треугольник
    // 3
    m_barVertices[9] = x1;
    m_barVertices[10] = y1;
    m_barVertices[11] = 0;

    // 4
    m_barVertices[12] = x2;
    m_barVertices[13] = y2;
    m_barVertices[14] = 0;

    // 5
    m_barVertices[15] = x2;
    m_barVertices[16] = y1;
    m_barVertices[17] = 0;
}

void Painter::setBarIndices()
{
    for ( unsigned int i = 0; i < 6; ++i ) {
        m_barIndices[i] = i;
    }
}

void Painter::setBarColor( float r, float g, float b )
{
    m_barColors[0] = r;
    m_barColors[1] = g;
    m_barColors[2] = b;

    m_barColors[3] = r;
    m_barColors[4] = g;
    m_barColors[5] = b;

    m_barColors[6] = r;
    m_barColors[7] = g;
    m_barColors[8] = b;

    m_barColors[9] = r;
    m_barColors[10] = g;
    m_barColors[11] = b;

    m_barColors[12] = r;
    m_barColors[13] = g;
    m_barColors[14] = b;

    m_barColors[15] = r;
    m_barColors[16] = g;
    m_barColors[17] = b;
}

void Painter::setCircleVertices( int x, int y, int radius )
{
    // 0
    m_circleVertices[0] = x + radius;
    m_circleVertices[1] = y;
    m_circleVertices[2] = 0;

    // 1
    m_circleVertices[3] = x - radius;
    m_circleVertices[4] = y;
    m_circleVertices[5] = 0;

    // 2
    m_circleVertices[6] = x;
    m_circleVertices[7] = y + radius;
    m_circleVertices[8] = 0;

    // 3
    m_circleVertices[9] = x + radius;
    m_circleVertices[10] = y;
    m_circleVertices[11] = 0;

    // 4
    m_circleVertices[12] = x;
    m_circleVertices[13] = y - radius;
    m_circleVertices[14] = 0;

    // 5
    m_circleVertices[15] = x - radius;
    m_circleVertices[16] = y;
    m_circleVertices[17] = 0;
}

void Painter::setCircleIndices()
{
    for ( unsigned int i = 0; i < m_circleIndices.size(); ++i ) {
        m_circleIndices[i] = i;
    }
}

void Painter::setCircleColor( float r, float g, float b )
{
    m_circleColors[0] = r;
    m_circleColors[1] = g;
    m_circleColors[2] = b;

    m_circleColors[3] = r;
    m_circleColors[4] = g;
    m_circleColors[5] = b;

    m_circleColors[6] = r;
    m_circleColors[7] = g;
    m_circleColors[8] = b;

    m_circleColors[9] = r;
    m_circleColors[10] = g;
    m_circleColors[11] = b;

    m_circleColors[12] = r;
    m_circleColors[13] = g;
    m_circleColors[14] = b;

    m_circleColors[15] = r;
    m_circleColors[16] = g;
    m_circleColors[17] = b;
}
