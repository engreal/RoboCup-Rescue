#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

class Widget : public QWidget
{
    Q_OBJECT
public:
    enum MapType
    {
        ROAD,   //道路
        WALL,   //障碍
        ENTRANCE, //入口
        EXIT, //出口
        SEEN,
        PASS,
    };

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initMap();
    void drawMap(QPainter *p);
    void drawArea(QPainter *p, const QRectF &areaRect, const QBrush &brush);

    void aStarPathPlan();
    int hfunc(int r, int c);
    void paintEvent(QPaintEvent *);

public:
    QVector<QVector<MapType> > map;
    int mapRows;
    int mapCols;
    double areaWidth;
    double areaHeight;

    struct {
        int row;
        int col;
    }pBegin, pEnd;
};

#endif // WIDGET_H
