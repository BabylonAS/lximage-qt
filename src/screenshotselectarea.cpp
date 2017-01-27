/*
    <one line to give the library's name and an idea of what it does.>
    Copyright (C) 2013  <copyright holder> <email>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include "screenshotselectarea.h"
#include <QMouseEvent>

using namespace LxImage;

ScreenshotSelectArea::ScreenshotSelectArea(QImage image, QWidget* parent) : QDialog(parent)
{
  scene = new QGraphicsScene(this);
  scene->addPixmap(QPixmap::fromImage(image));
  
  view = new ScreenshotSelectAreaGraphicsView(scene, this);
  view->setRenderHints( QPainter::Antialiasing );
  view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
  view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
  view->show();
  view->move(0,0);
  view->resize(image.width(), image.height());
  setWindowState(windowState() | Qt::WindowFullScreen);
  connect(view, SIGNAL(selectedArea(QRect)), this, SLOT(areaSelected(QRect)));
}

QRect ScreenshotSelectArea::selectedArea()
{
  return selectedRect;
}

void ScreenshotSelectArea::areaSelected(QRect rect)
{
  this->selectedRect = rect;
  accept();
}