#ifndef VIDEO_TST_H
#define VIDEO_TST_H

#include <QObject>

class video_tst : public QObject
{
    Q_OBJECT
public:
    explicit video_tst(QObject *parent = 0);
    ~video_tst();

signals:

public slots:
};

#endif // VIDEO_TST_H
