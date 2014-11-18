#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent ),
    m_maxSize( m_game.snakeMaxSize() )
{
    this->setFocusPolicy( Qt::StrongFocus );

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotUpdate() ) );
}

void Scene::slotUpdate()
{
    Snake::Status status = m_game.status();

    switch( status ) {
        case Snake::LIVE:
            break;
        case Snake::INCREASED:
            sendStatus();
            break;
        case Snake::DEAD:
            m_game.newGame();
            sendStatus();
            break;
        case Snake::WIN:
            m_timer.stop();
            sendStatus();
            return;
    }

    m_game.tick();
    updateGL();
}

void Scene::initializeGL()
{
    // Показать каркас
    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    // Цвет для очистки буфера изображения - будет просто фон окна
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

    // Устанавливает режим проверки глубины пикселей
    glEnable( GL_DEPTH_TEST );

    // Отключает режим сглаживания цветов
    glShadeModel( GL_FLAT );

    // Устанавливаем режим, когда строятся только внешние поверхности
    glEnable( GL_CULL_FACE );

    // Активизация массива вершин
    glEnableClientState( GL_VERTEX_ARRAY );

    // Активизация массива цветов вершин
    glEnableClientState( GL_COLOR_ARRAY );
}

void Scene::paintGL()
{
    // Окно виджета очищается текущим цветом очистки
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    if ( m_timer.isActive() ) {
        m_game.draw( p );
    }
}

void Scene::resizeGL( int w, int h )
{
    // Prevent a divide by zero
    if( h == 0 ) {
        h = 1;
    }

    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    glOrtho( 0, 200, 200, 0, 1.0, -1.0);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch ( event->key() ) {
        case Qt::Key_Left:
            m_game.keyEvent( Snake::LEFT );
            break;
        case Qt::Key_Up:
            m_game.keyEvent( Snake::UP );
            break;
        case Qt::Key_Right:
            m_game.keyEvent( Snake::RIGHT );
            break;
        case Qt::Key_Down:
            m_game.keyEvent( Snake::DOWN );
            break;
        case Qt::Key_Space:
            m_game.newGame();
            sendStatus();
            m_timer.start( 100 );
            break;
    }
}

void Scene::sendStatus()
{
    size_t points = m_game.snakeSize();
    emit signalShowStatus( QString( "%1/%2" ).arg( points ).arg( m_maxSize ) );
}
