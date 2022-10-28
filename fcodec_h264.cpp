#include "fcodec_h264.h"
#include <QDebug>
qint16 fcodec_h264::vdid=0;
fcodec_h264::fcodec_h264()
{
    //注册组件
    av_register_all();


//    mydb=Cdatabase::getSignal();
}
void fcodec_h264::codeInit()
{

    //（1）定义存储编解码相关信息的对象 开空间malloc
    //AVCodecContext *codeContent;
   // codeContent=av_malloc();
     //定义文件名—路径

    QDateTime time = QDateTime::currentDateTime();
    QString dateTime = time.toString("MM-dd-hh-mm-ss");
    QString str= QString("videopath/Data%1.h264").arg(dateTime);
    QByteArray ba = str.toLatin1();
    char * file_out=ba.data();
/*
//    vdid++;
    QString vdTime=time.toString();//图片创建时间
    QString vdName=QString("Data%1.h264").arg(dateTime);
    QString vdPath="./videopath";

    QString s=QString("insert into tbl_video(vdName,vdTime,vdPath) values('%1','%2','%3');")
            .arg(vdName).arg(vdTime).arg(vdPath);
    qDebug()<<s;
    mydb->Exec(const_cast<char *>(s.toStdString().c_str()));
    qDebug()<<"保存视频信息到数据库--------------------------------------------999999999999999999999999999999999999999999--";
*/


//    char *file_out="videopath/code_frame.h264";
    //（2）猜测函数（0，文件名，0）
    AVOutputFormat *avformat=av_guess_format(nullptr,file_out,nullptr);
    //（3）判断有没有匹配到格式
    if(avformat==nullptr)
    {
        qDebug()<<"没有匹配到格式！！！"<<endl;
        return;
    }
    qDebug()<<"匹配格式成功"<<endl;
    //（4）打开编码之前要做设置输出格式
    // ①AVFormatContext用来保存视频相关信息，有输入信息也有输出的相关信息
    //AVFormatContext *forContext;
    forContext=avformat_alloc_context();
    forContext->oformat=avformat;
    //②打开视频流（AVIOContent输入输出的上下文对象，文件流的路径url文件名，文件打开的方式 写入）
    int res=avio_open(&forContext->pb,file_out,AVIO_FLAG_WRITE);
    //判断是否打开成功
    //返回值小于0 失败 提示
    if(res<0)
    {
        qDebug()<<"打开视频流失败！！！"<<endl;
        return;
    }

    //③	成功 新建视频流（保存视频信息的结构体forcontent，0）
    qDebug()<<"打开视频流成功"<<endl;
    AVStream *newStream=avformat_new_stream(forContext,nullptr);
    //判断是否新建成功
    //失败-返回值等于null  AVStream
    if(newStream==nullptr)
    {
       qDebug()<<"新建视频流失败！！！" <<endl;
       return;
    }
    qDebug()<<"新建视频流成功" <<endl;

    // ④设置编码器相关参数
    // a)保存视频流对应的AVCodecContext
    codeContent=newStream->codec;
    // b)其他参数的设置
    // i.宽高度
    codeContent->width=800;
    codeContent->height=368;
    //ii.帧率 （一秒25张）
    codeContent->time_base={1,25};
    //iii.码率（ 一秒存多少比特 不要随便设置400000）
    codeContent->bit_rate=400000;
    //iv.设置显示的率
    codeContent->framerate={25,1};
    //v.每一组有几张图片：IBP帧
    codeContent->gop_size=10;
    //vi.量化参数（影响视频清晰度 越小越清晰）
    codeContent->qmax=51;
    codeContent->qmin=10;
    //vii.不想要B帧 =0
    codeContent->max_b_frames=0;
    //viii.编码格式
    codeContent->pix_fmt=AV_PIX_FMT_YUV420P;
    //ix.流的设置（每一帧是什么流：视频流）
    codeContent->codec_type=AVMEDIA_TYPE_VIDEO;
    //x.编码器的id的设置
    codeContent->codec_id=avformat->video_codec;
    //⑤	查找对应的编码器（编码器的id）
    AVCodec *codec=avcodec_find_encoder(codeContent->codec_id);
    //a)返回值判断是否查找到
    if(codec==nullptr)
    {
        qDebug()<<"没有找到编码器！！！"<<endl;
        return;
    }
      qDebug()<<"找到编码器成功"<<endl;
    //⑥	打开编码器（上下文对象结构体，编码器，目录0）
    res=avcodec_open2(codeContent,codec,nullptr);
    //a)	res返回值判断是否打开成功 res！=0 失败
    if(res!=0)
    {
        qDebug()<<"打开编码器失败！！！"<<endl;
        return;
    }
    qDebug()<<"编码器打开成功"<<endl;
    res=avformat_write_header(forContext,nullptr);
    if(res<0)
    {
        qDebug()<<"数据写入失败"<<endl;
        return;
    }

    pkt=av_packet_alloc(); //给保存码流数据的包分配内存空间
    pkt_index=0;
    qDebug()<<"----初始化完毕----"<<endl;
}
//编码：YUV的像素数据变为码流数据
void fcodec_h264::codecFrame(AVFrame *frame)
{
    qDebug()<<"开始编码"<<endl;
    //（1）发送一帧像素数据给 编码器上下文结构体：定义为类的私有成员 进行编码
    int res=avcodec_send_frame(codeContent,frame);
    //a)判断是否发送成功
    if(res<0)
    {
        qDebug()<<"发送数据失败！！！"<<endl;
        return;
    }
    qDebug()<<"发送数据成功 开始编码---"<<endl;
    //（2）while循环：一个pkt放不下 需要循环
    while(res>=0)
    {
        //显示时间基：保证视频播放顺序的准确性，可能一帧yuv要两个包存放 防止解码的时候出问题
        frame->pts=pkt_index;
        pkt_index++;
        //①	获取像素数据 压缩后的数据存到存放码流数据的包里 定义包指针变量为类的私有成员//函数1结尾初始化
        res=avcodec_receive_packet(codeContent,pkt);
        //②判断是否获取到
        if(res<0)//打包失败
        {
            qDebug()<<"packet打包失败！！！"<<endl;
            return;
        }
        qDebug()<<"packet打包成功"<<endl;
        qDebug()<<"码流数据写入文件---"<<endl;
        //判断是不是我们要的视频流 0表示视频流
        pkt->stream_index=0;
        //③	码流数据写入文件 视频信息结构体为类的私有成员
        av_interleaved_write_frame(forContext,pkt);
        //④	清空
        av_packet_unref(pkt);
    }

}
void fcodec_h264::writeEndFrame()
{
    av_write_trailer(forContext);
     qDebug()<<"写入尾巴帧成功"<<endl;
}

