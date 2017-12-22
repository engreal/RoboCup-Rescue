#include "Widget.h"
#include "PrevQueue.h"
#include <QDebug>
#include <math.h>
#include <Qmap>
#include <map>

struct AreaInfo
{
    int row;
    int col;
    int f_value;
    int g_value;
    int h_value;

    AreaInfo(int r, int c, int g = 1e8, int h = 1e8)
    {
        row = r;
        col = c;
        g_value = g;
        h_value = h;
        f_value = g_value + h_value;
    }
};

struct AreaInfoCompare
{
    bool operator ()(const AreaInfo &a, const AreaInfo &b)
    {
        return a.f_value > b.f_value;
    }
};

struct AreaPos
{
    int row;
    int col;
    AreaPos(int r = -1, int c = -1)
    {
        row = r;
        col = c;
    }
    AreaPos(const AreaPos & a)
    {
        row = a.row;
        col = a.col;
    }

    bool operator != (const AreaPos &a)
    {
        if (a.row != row)
            return true;
        else
            return a.col != col;
    }

    friend bool operator < (const AreaPos &a, const AreaPos &b)
    {
        QString str1 = QString::number(a.row) + QString::number(a.col);
        QString str2 = QString::number(b.row) + QString::number(b.col);
        return str1 < str2;
    }
};

int Widget::hfunc(int r, int c)
{
    int dr = abs(pEnd.row - r);
    int dc = abs(pEnd.col - c);

    //return 0;

    //return dr + dc;

    double d = sqrt(dr*dr + dc*dc);
    //return static_cast<int>(d);

    return (dr + dc) + d;
}

void Widget::aStarPathPlan()
{
    PrevQueue<AreaInfo, std::vector<AreaInfo>, AreaInfoCompare> q;
    QMap<AreaPos, AreaPos>path;
    AreaPos beginPos(pBegin.row, pBegin.col);
    AreaPos endPos(pEnd.row, pEnd.col);
    //四个方向
    int directs[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    //起点入队
    q.push(AreaInfo(pBegin.row, pBegin.col, 0, 0));
    for (bool finish = false; !finish && !q.empty();)
    {
        AreaInfo a = q.top();   //取出最小点
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int row = a.row + directs[k][0];
            int col = a.col + directs[k][1];
            MapType type = map[row][col];
            if (type == EXIT)
            {
                path.insert(endPos, AreaPos(a.row, a.col));
                finish = true;
                break;
            }
            if (type != ROAD)
            {
                continue;
            }
            int g = a.g_value + 1;
            int h = hfunc(row, col);
            PrevQueue<AreaInfo>::iterator it = std::find_if(q.begin(), q.end(),
                      [&row, &col](AreaInfo &a)->bool{
                        return a.row == row && a.col == col;
            });
            AreaInfo tmp(row, col, g, h);
            if (it == q.end())
            {
                path.insert(AreaPos(row, col), AreaPos(a.row, a.col));
                q.push(tmp);
                map[row][col] = SEEN;
            }
            else if (tmp.f_value < it->f_value)
            {
                it->f_value = tmp.f_value;
                path.insert(AreaPos(row, col), AreaPos(a.row, a.col));
            }

        }
    }

    for (AreaPos p = path.value(endPos, beginPos);
         p != beginPos;
         p = path.value(p, beginPos))
    {
        map[p.row][p.col] = PASS;
    }
}
