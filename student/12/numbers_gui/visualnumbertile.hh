#ifndef VISUALNUMBERTILE_HH
#define VISUALNUMBERTILE_HH

#include <QGraphicsSimpleTextItem>
#include <QPainter>

class VisualNumberTile : public QGraphicsSimpleTextItem
{
public:
    VisualNumberTile(int number, int sideLenght, int posX, int posY);
    // makes boundaries for the objcet
    QRectF boundingRect() const;
    // used for drawing rectangle around the number
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int sideLenght;
    int posX;
    int posY;
    QBrush color;
};

#endif // VISUALNUMBERTILE_HH
