#include <QtTest/QtTest>
#include <fish_tst.h>

int main()
{
    FishTest ft;
    QTest::qExec(&ft);
}
