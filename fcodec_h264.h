#ifndef FCODEC_H264_H
#define FCODEC_H264_H
#include <QDateTime>
#include <QByteArray>
#include "database.h"
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/avutil.h>
    #include <libswresample/swresample.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
}
class fcodec_h264
{
public:
    fcodec_h264();
    //编码参数初始化
    void codeInit();
    //编码
    void codecFrame(AVFrame *frame);//参数 一帧一帧的像素数据
    //写入结束帧：编码结束后调用
    void writeEndFrame();

    Cdatabase *mydb;
    static qint16 vdid;
private:
    AVCodecContext *codeContent;//定义存储编解码相关信息的对象
    AVPacket *pkt;
    AVFormatContext *forContext;
    int pkt_index;//帧的顺序
};

#endif // FCODEC_H264_H
