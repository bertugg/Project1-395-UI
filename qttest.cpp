#include "qttest.h"
#include "ui_qttest.h"
#include "Graph.h"
#include <QGraphicsItemGroup>

#define MAPPATH "C:/Users/test/Documents/GitHub/Project1-395-UI/KatPlaniPP.jpg"
#define DMWIDTH 35 // Destination Marker Width
#define NLWIDTH 15 // Node Location Marker Width
#define DEVELOPERMODE true

QTTest::QTTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTTest)
{
    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);

    vector<Vertex> vertexList;
    g.addVertex(Coor(150,165)); // Z06 Kapi
    g.addVertex(Coor(180,164));
    g.addVertex(Coor(179,133));
    g.addVertex(Coor(226,165));
    g.addVertex(Coor(198,201)); // Z11 Kapi
    g.addVertex(Coor(223,203)); // Z11 Onu
    g.addVertex(Coor(220,360)); // Sol Cikis
    g.addVertex(Coor(227,377));
    g.addVertex(Coor(196,386)); // Bilgisayar Lab
    g.addVertex(Coor(195,555)); // Kantin Kapi
    g.addVertex(Coor(225,555)); // Kantin Onu
    g.addVertex(Coor(229,611)); // Giris Sol Kose
    g.addVertex(Coor(351,615)); // Giris Ic
    g.addVertex(Coor(349,678)); // Giris Dis
    g.addVertex(Coor(479,620)); // Giris Sag Kose
    g.addVertex(Coor(514,537)); // Z23 Kapi
    g.addVertex(Coor(489,540)); // Z23 Onu
    g.addVertex(Coor(516,388)); // Devre Lab
    g.addVertex(Coor(481,370)); // Sag Cikis Onu
    g.addVertex(Coor(515,360)); // Sag Cikis
    g.addVertex(Coor(515,202)); // Lojik Lab
    g.addVertex(Coor(487,202)); // Lojik Lab Onu
    g.addVertex(Coor(492,125));
    g.addVertex(Coor(561,163)); // Z10 Kapi
    g.addVertex(Coor(530,99)); // Z05 Kapi
    g.addVertex(Coor(526,130));
    g.addVertex(Coor(481,126));
    g.addVertex(Coor(399,97)); // Z04 Kapi
    g.addVertex(Coor(399,118)); // Z04 Onu
    g.addVertex(Coor(372,98)); // Arka Cikis İci
    g.addVertex(Coor(356,117)); // Arka Cikis Onu
    g.addVertex(Coor(310,98)); // Z02 Kapi
    vertexList = g.getVertexList(); // Refers all vertexes


    g.setEdge(vertexList[0],vertexList[1]);
    g.setEdge(vertexList[1],vertexList[2]);
    g.setEdge(vertexList[1],vertexList[3]);
    /*
    g.add(Coor(150,165),Coor(180,164));
    g.add(Coor(180,164),Coor(179,133));
    g.add(Coor(179,133),Coor(226,165));
    g.add(Coor(226,165),Coor(223,203));
    g.add(Coor(198,201),Coor(223,203));
    g.add(Coor(220,360),Coor(223,203));

    // Get Edge List Must Be Implemented
    // Shortest Path Must Return Edge List
    */

    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    blackPen.setWidth(6);

    // Add Map First
    planPixmap = scene -> addPixmap(QPixmap(MAPPATH));



    // Create Destination Marker on map
    destinationMarker = scene -> addEllipse(0,0,DMWIDTH,DMWIDTH,blackPen,redBrush);
    destinationMarker->setFlag(QGraphicsItem::ItemIsMovable);
    destinationVertex = g.addVertex(Coor(destinationMarker->pos().x() + DMWIDTH/2, destinationMarker->pos().y() + DMWIDTH/2));

    // Create User Location Marker
    locationMarker = scene -> addPolygon(QPolygonF( QVector<QPointF>() << QPointF( 20, -20 ) << QPointF( 0, -20) << QPointF( 10, 20)),blackPen,blueBrush);
    locationMarker->setFlag(QGraphicsItem::ItemIsMovable);
    locationVertex = g.addVertex(Coor(locationMarker->pos().x(), locationMarker->pos().y()));

    // Create Node Locations Marker
    if(DEVELOPERMODE)
    {
        // Draw lines between all vertexes
        vector<Edge> edgeList = g.getAllEdge();
        for(uint i = 0; i < edgeList.size()-1; ++i)
        {
            // Add Line for Edges
            drawLine(edgeList[i].getSourceVertex(), edgeList[i].getDestVertex(), blackPen);
        }

        for(uint i = 0; i < vertexList.size(); ++i)
        {
            nodeLocationsMarker = scene -> addEllipse(vertexList[i].getX()-NLWIDTH/2,
                                                      vertexList[i].getY()-NLWIDTH/2,
                                                      NLWIDTH,
                                                      NLWIDTH,
                                                      blackPen,
                                                      greenBrush);
        }
    }
    /*
    // Draw lines between all vertexes
    for(uint i = 0; i < vertexList.size()-1; ++i)
    {
        // Add Line for Edges
        drawLine(vertexList[i],vertexList[i+1] );

    }
    */
    //seekLocation();


    QPixmap pix(1000,1000);
    pix.fill(Qt::transparent);

    QPainter painter(&pix);

    painter.setBrush(QColor(0, 255, 0, 127));
    //painter.drawRect(20, 12, 215, 178); //1. bolge
    //painter.drawRect(20, 184, 240, 185); //2. bolge
    //painter.drawRect(32, 375, 230, 137); //3. bolge
    //painter.drawRect(20, 510, 250, 180); //4. bolge
    //painter.drawRect(260, 510, 200, 145); //5. bolge
    //painter.drawRect(460, 510, 240, 180); //6. bolge
    //painter.drawRect(420, 380, 280, 140); //7. bolge
    //painter.drawRect(456, 189, 260, 190); //8. bolge
    //painter.drawRect(518, 12, 180, 190); //9. bolge
    //painter.drawRect(392, 16, 125, 180); //10. bolge
    //painter.drawRect(215, 16, 185, 180); //11. bolge
    //painter.drawRect(0, 0, width()/2, height());


    vector<Area> colorAreaPoint;

    Area point1 (20, 12, 215, 178);
    colorAreaPoint.push_back(point1);
    Area point2(20, 184, 240, 185);
    colorAreaPoint.push_back(point2);
    Area point3 (32, 375, 230, 137);
    colorAreaPoint.push_back(point3);
    Area point4 (20, 510, 250, 180);
    colorAreaPoint.push_back(point4);
    Area point5 (260, 510, 200, 145);
    colorAreaPoint.push_back(point5);
    Area point6 (460, 510, 240, 180);
    colorAreaPoint.push_back(point6);
    Area point7 (420, 380, 280, 140);
    colorAreaPoint.push_back(point7);
    Area point8 (456, 189, 260, 190);
    colorAreaPoint.push_back(point8);
    Area point9 (518, 12, 180, 190);
    colorAreaPoint.push_back(point9);
    Area point10 (392, 16, 125, 180);
    colorAreaPoint.push_back(point10);
    Area point11 (215, 16, 185, 180);
    colorAreaPoint.push_back(point11);


    int veri=3;
    //Bölge id si denemesi icin veri degiskeni kullanilmistir

   //Hangi bolge gelirse veri olarak onu boyar
    painter.drawRect(colorAreaPoint.at(veri-1).x, colorAreaPoint.at(veri-1).y, colorAreaPoint.at(veri-1).width, colorAreaPoint.at(veri-1).height);

    scene -> addPixmap(pix);



}

QTTest::~QTTest()
{
    delete ui;
}

void QTTest::on_pushButton_clicked()
{
    // Print destination location
    //ui->label->setText(QString::number(destinationMarker->pos().x()+ DMWIDTH/2) + ", " + QString::number(destinationMarker->pos().y()+ DMWIDTH/2));

    QPen redPen(Qt::red);
    redPen.setWidth(5);

    destinationVertex->setVertex(destinationMarker->pos().x() + DMWIDTH/2, destinationMarker->pos().y() + DMWIDTH/2);
    locationVertex->setVertex(locationMarker->pos().x() + 10, locationMarker->pos().y());

    ui->label->setText("destination vertex = " + QString::number(destinationVertex->getX()) + ", " + QString::number(destinationVertex->getY()));

    clearLines();

    QGraphicsLineItem *line;
    line = drawLine(*locationVertex, g.getVertexList()[0], redPen);
    drawedLines.push_front(line);
    for(uint i = 0; i < g.getVertexList().size()-3; ++i)
    {
        // Add Line for Edges
        line = drawLine(g.getVertexList()[i], g.getVertexList()[i+1], redPen);
        drawedLines.push_front(line);
    }
    line = drawLine(*destinationVertex, g.getVertexList()[g.getVertexList().size()-3], redPen);
    drawedLines.push_front(line);

}

void QTTest::seekLocation()
{
    ui->label->setText("Seeking User Location...");
    // Get location from hardware
}

QGraphicsLineItem* QTTest::drawLine(Vertex &c1, Vertex &c2, QPen pen)
{
    return scene -> addLine(c1.getX(),c1.getY(),c2.getX(),c2.getY(),pen);
}

void QTTest::clearLines()
{
    for(int i = 0; i < drawedLines.size(); ++i)
    {
        scene->removeItem(drawedLines[i]);
        scene->update();
    }
}

