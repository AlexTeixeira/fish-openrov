#include "processing.h"

//Processing::Processing(QObject *parent) :
//    QObject(parent)
//{
//}

Processing::Processing(VideoCapture _cap) {
    this->cap = _cap;
}

void Processing::run()
{
    double count = this->cap.get(CV_CAP_PROP_FRAME_COUNT);
    this->frameList = new QList<Mat>;
    for(int i=0;i<(int)count;i+=10){
        Mat frame;
        this->cap.set(CV_CAP_PROP_POS_FRAMES, i);
        this->cap >> frame;
        this->frameList->push_back(frame);
    }
    qDebug() <<"Thread finish";
    //MatchingMethod(0,0,frame);
    for(int j=0;j<this->frameList->count();j++){
        qDebug() << j;
        MatchingMethod(0,0,this->frameList->at(j));
    }
}

int Processing::GetId() {
    return this->id;
}

Result* Processing::GetResult() {
    return this->result;
}

void Processing::SetId(int _id) {
    this->id = _id;
}

void Processing::SetResult(Result* _result) {
    this->result = _result;
}

void Processing::MatchingMethod(int, void*, Mat img)
{

    Mat templ; Mat result;
    const char* image_window = "Source Image";
    const char* result_window = "Result window";
    templ = imread( "C:/clownfish2.png", 1 );
    if (!templ.empty()) {
        //imshow("Sample",templ);
    }

    int match_method;
  /// Source image to display
  Mat img_display;
  img.copyTo(img_display);

  /// Create the result matrix
  int result_cols = img.cols - templ.cols + 1;
  int result_rows = img.rows - templ.rows + 1;

  result.create( result_cols, result_rows, CV_32FC1 );

  /// Do the Matching and Normalize
  matchTemplate( img, templ, result, CV_TM_CCORR );
  normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

  /// Localizing the best match with minMaxLoc
  double minVal; double maxVal; Point minLoc; Point maxLoc;
  Point matchLoc;

  minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );


  if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
    { matchLoc = minLoc; }
  else
    { matchLoc = maxLoc; }

  /// Show me what you got
  rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
  rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );

  imshow( image_window, img_display );
  //imshow( result_window, result );

    waitKey(0);
  //return;
}
