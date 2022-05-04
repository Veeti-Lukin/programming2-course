#include "visualnumbertile.hh"
#include <QGraphicsItem>

VisualNumberTile::VisualNumberTile(int number, int sideLenght, int posX, int posY) :
    QGraphicsSimpleTextItem(const QString &text, QGraphicsItem *parent = nullptr),
    sideLenght(sideLenght),
    posX(posX),
    posY(posY)
{
    color = Qt::red;
}

QRectF VisualNumberTile::boundingRect() const
{
    return QRectF(posX, posY, sideLenght, sideLenght);
}

void VisualNumberTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    painter->fillRect(rec, color);
    painter->drawRect(rec);
}


