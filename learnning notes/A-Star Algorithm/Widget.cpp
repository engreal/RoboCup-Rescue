#include "Widget.h"
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    initMap();
}

Widget::~Widget()
{

}

void Widget::initMap()
{
    QFile mapFile(":/world.map");
    if (! mapFile.open(QIODevice::ReadOnly))
        exit(0);
    QTextStream fin(&mapFile);
    QVector<MapType> line;
    map.append(line);
    mapRows = 1;
    while (! fin.atEnd())
    {
        QByteArray buf = fin.readLine().toLatin1();
        line.clear();
        line.append(MapType::WALL);
        mapCols = 1;
        for (int i = 0; i < buf.size(); i++)
        {
            switch(buf[i])
            {
            case ' ':
            case 'O':
                line.append(MapType::ROAD);
                break;
            case '#':
                line.append(MapType::WALL);
                break;
            case 'X':
                pBegin.row = mapRows;
                pBegin.col = mapCols;
                line.append(MapType::ENTRANCE);
                break;
            case 'E':
                pEnd.row = mapRows;
                pEnd.col = mapCols;
                line.append(MapType::EXIT);
                break;
            default:
                line.append(MapType::ROAD);
            }
            ++mapCols;
        }
        line.append(MapType::WALL);
        ++mapCols;
        map.append(line);
        ++mapRows;
    }
    line.clear();
    for (int i = 0; i < mapCols; i++)
    {
        line.append(MapType::WALL);
        map.first().append(MapType::WALL);
    }
    map.append(line);
    ++mapRows;
}

void Widget::drawMap(QPainter *p)
{
    MapType type;
    QBrush brush(Qt::white);
    areaWidth = static_cast<double>(width()) / static_cast<double>(mapCols);
    areaHeight = static_cast<double>(height()) / static_cast<double>(mapRows);
    for(int i = 0; i < mapRows; i++)
    {
        for (int j = 0; j < mapCols; j++)
        {
            type = map[i][j];
            switch (type)
            {
            case MapType::WALL:
                brush.setColor(Qt::black);
                break;
            case MapType::ROAD:
                brush.setColor(Qt::white);
                break;
            case MapType::SEEN:
                brush.setColor(Qt::yellow);
                break;
            case MapType::PASS:
                brush.setColor(Qt::darkYellow);
                break;
            case MapType::ENTRANCE:
                brush.setColor(Qt::blue);
                break;
            case MapType::EXIT:
                brush.setColor(Qt::green);
                break;
            default:
                break;
            }
            drawArea(p,
                     QRectF(j*areaWidth, i*areaHeight, areaWidth, areaHeight),
                     brush);
        }
    }

}

void Widget::drawArea(QPainter *p, const QRectF &areaRect, const QBrush &brush)
{
    p->setBrush(brush);
    p->drawRect(areaRect);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::lightGray);
    drawMap(&p);
    p.setPen(Qt::black);
    p.drawText(QRectF(pBegin.col*areaWidth,
                      pBegin.row*areaHeight,
                      areaWidth,
                      areaHeight),
               "起");
    p.drawText(QRectF(pEnd.col*areaWidth,
                      pEnd.row*areaHeight,
                      areaWidth,
                      areaHeight),
               "终");
}
