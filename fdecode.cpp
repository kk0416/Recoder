#include "fdecode.h"
qint16 fdecode::ptidcount;
int fdecode::playflag=0;
int fdecode::posflag=0;
int fdecode::pixflag=0;
QString fdecode::picname=nullptr;

//fdecode *fdecode::pfdec=nullptr;

void fdecode::setCamera(const QString &value)
{
    camera = value;
}

fdecode::fdecode()
{
    /*
       （1）注册：av_register_all()
       （2）打开一个视频文件：：avformat_open_input()
       （3）获取视频文件相关信息：采用什么编码 用什么解码：
       （4）看有没有相关视频流信息：avformat_find_stream_info()
       （5）有：找对应的解码器：avcodec_find_decoder()
       （6）打开解码器：avcodec_open2()
       （7）获取一帧视频流(码流)信息：av_read_frame()
       （8）读取，解码：avcodec_decode_video2()
       （9）得到像素数据：yuv—>rgb
       循环重复789步骤
       （10）关闭解码器：avcodec_close()
       （11）关闭视频流文件: avformat_close_input()
       */

       //创建编码类对象
       fcodec=new fcodec_h264;


       mydb=Cdatabase::getSignal();



}
void fdecode::registerFFmpeg()
{
    av_register_all();
    avdevice_register_all();//注册设备
}

void fdecode::openViedoStream_jiema(QString filename)
{

    //视频路径url:固定的
    //char *path="video/Warcraft3_End.avi";
    //存放文件打开的信息：若打开失败null，以此判断
    AVFormatContext *forcontent;
    //分配空间
    forcontent=avformat_alloc_context();

    //打开设备 摄像头
    AVInputFormat *fmt=av_find_input_format("dshow");    
    QString b ="video="+camera;
    char*  ch;
    QByteArray ba = b.toLatin1();
    ch=ba.data();
    int res=avformat_open_input(&forcontent,ch,fmt,0);

    //判断是否打开
    if(res!=0)
    {
        qDebug()<<"打开视频失败"<<endl;
        return;
    }
    //4、查看是否有相关视频流信息（结构体，0）
    res=avformat_find_stream_info(forcontent,0);
    //判断
    //没有：提示
    if(res<0)
    {
        qDebug()<<"没有流媒体信息"<<endl;
        return;
    }
    //有·：
    int videoType=-1;
    //循环：一个视频有多股码流，存在数组中
    for(int i=0;i<forcontent->nb_streams;i++)
    {
        //找到视频流
        if(forcontent->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoType=i;//标识类型
            break;
        }
    }
    if(videoType==-1)
    {
        qDebug()<<"没有视频流相关信息"<<endl;
        return;
    }
    //定义编解码器：编解码器对应的上下文对象结构体：存放编解码信息以及图像的宽高以及像素信息
    AVCodecContext *codec=forcontent->streams[videoType]->codec;
    //5、找对应的解码器（编解码器id）定义指针接收
    AVCodec *decoder=avcodec_find_decoder(codec->codec_id);
    //判断
    //没有对应解码器：提示
    if(decoder==nullptr)
    {
        qDebug()<<"没有对应的解码器"<<endl;
        return;
    }
    //有：
    //6、打开解码器（上下文对象，AVcode，0）
    res=avcodec_open2(codec,decoder,0);
    if(res!=0)
    {
        qDebug()<<"解码器打开失败"<<endl;
        return;
    }
    qDebug()<<"解码器打开成功"<<endl;

    //定义包结构体指针：读出来的数据放进去
    AVPacket *pkt=nullptr;
    //malloc给包开空间（强转）
    pkt=(AVPacket *)malloc(sizeof(AVPacket));
    //计算一帧图片数据大小
    int size=codec->width*codec->height;
    //开包里空间
    av_new_packet(pkt,size);
    //定义指针变量：保存解码后的像素数据
    AVFrame *pictureYUV=nullptr,*picture=nullptr,*pictureRGB=nullptr;

    //指针变量开空间
    picture=av_frame_alloc();
    pictureYUV=av_frame_alloc();
    pictureRGB=av_frame_alloc();
    //一帧宽、高度、格式
    pictureYUV->width=codec->width;
    pictureYUV->height=codec->height;
    pictureYUV->format=codec->pix_fmt;
    //RGB一帧宽、高度、格式
    pictureRGB->width=codec->width;
    pictureRGB->height=codec->height;
    pictureRGB->format=codec->pix_fmt;

    //一帧码流数据解码后得到的像素数据有多大（编码上下文的宽度和高度）
    int numByte=avpicture_get_size(AV_PIX_FMT_YUV420P,codec->width,codec->height);
    int numByteRGB=avpicture_get_size(AV_PIX_FMT_RGB32,codec->width,codec->height);
    //结构体里的data开这么大的空间；开的空间用来保存像素数据
    uint8_t *buffer=(uint8_t*)av_malloc(numByte*sizeof(uint8_t));
    uint8_t *bufferRGB=(uint8_t*)av_malloc(numByteRGB*sizeof(uint8_t));
    //像素数据的填充（（AVPicture *）pictureYUV，buffer，YUV，宽、高度）
   avpicture_fill((AVPicture*)pictureYUV,buffer,AV_PIX_FMT_YUV420P,codec->width,codec->height);
   avpicture_fill((AVPicture*)pictureRGB,bufferRGB,AV_PIX_FMT_RGB32,codec->width,codec->height);
    //保存解码转换规则 定义指针变量
    SwsContext *sws_content=nullptr;
    sws_content=sws_getContext(codec->width,codec->height,codec->pix_fmt,
                               codec->width,codec->height,AV_PIX_FMT_YUV420P,
                               SWS_BICUBIC,nullptr,nullptr,nullptr);
    SwsContext *sws_contentRGB=nullptr;
    sws_contentRGB=sws_getContext(codec->width,codec->height,codec->pix_fmt,
                                  codec->width,codec->height,AV_PIX_FMT_RGB32,
                                  SWS_BICUBIC,nullptr,nullptr,nullptr);



    char path1[30]={0};
    char path2[30]={0};
    int count=0;
    int count1=0;
    int ptid;
//    QDateTime time = QDateTime::currentDateTime();
//    QString dateTime = time.toString("MM-dd-hh-MM");
    //7、循环while（读数据（保存结构体，包）==0）：=0:读到数据
    while(av_read_frame(forcontent,pkt)==0)
    {
        //判断一帧码流数据是不是我们要的视频流
         if(pkt->stream_index==videoType)
         {
             //是：写入fwrite
             qDebug()<<"解码"<<endl;
             //fwrite(pkt->data,pkt->size,1,fp);
             //定义有没有压缩的码流供解码(上下文压缩暗流，解码后的数据，有没有数据可解码，对谁解码)
             int got_picture_ptr=-1;
             //解码（编解码器上下文对象，指针变量保存读到的数据pictureYUV，有没有压缩的码流供解码，）
             avcodec_decode_video2(codec,picture,&got_picture_ptr,pkt);
             //判断
             //不等于0：做了解码的操作
             if(got_picture_ptr!=0)
             {
                 qDebug()<<count<<"-------------11---------------------------------1111111111111111111111111"<<endl;
                 count++;
                 qDebug()<<"把解码得到的坏数据剔除"<<endl;
                 //把解码得到的坏数据剔除 data是数组 [0]Y的数据 [1]U的数据 [2]V的数据
                 //剔除规则函数（剔除的规则，解码后得到的像素数据，一行多少个像素点（宽度），高度，目标处理完数据存到哪里，目标一行多少）
                 sws_scale(sws_content,picture->data,picture->linesize,0,picture->height,
                           pictureYUV->data,pictureYUV->linesize);
                 sws_scale(sws_contentRGB,picture->data,picture->linesize,0,picture->height,
                           pictureRGB->data,pictureRGB->linesize);

                 QImage img((uchar *)bufferRGB,codec->width,codec->height,QImage::Format_RGB32);

                 if(count==1)
                 {
                     QDateTime time1 = QDateTime::currentDateTime();
                     QString dateTime1 = time1.toString("MM-dd-hh-mm-ss");
                     QString str1= QString("picturpath/FM_Pic_%1.jpg").arg(dateTime1);
                     QByteArray ba1 = str1.toLatin1(); // must

                     sprintf(path1,ba1.data(),count);
                     img.save(path1);
//                     qDebug()<<"保存图片"<<count;
                     fcodec->codeInit();//编码初始化
                 }
            /* ------定时保存录制  失败 总是0kb
                 if(count%100==0)
                 {

                     qDebug()<<"11111111177777777777777777777777777777777777777777777777777777777777777"<<endl;

                     fcodec->codeInit();//编码初始化
//                     count=0;

                 }
*/
                 //现场拍照
                 if(pixflag==1)
                 {
                     //每解码一次 id+1

                     QDateTime time = QDateTime::currentDateTime();
                     QString dateTime = time.toString("MM-dd-hh-mm-ss");
                     QString str= QString("picturpath/Pic_%1.jpg").arg(dateTime);//图片名称
                     QByteArray ba = str.toLatin1(); // must

                     sprintf(path2,ba.data(),count);
                     img.save(path2);
                     QString ptTime=time.toString();//图片创建时间
                     QString ptName=QString("Pic_%1.jpg").arg(dateTime);
                     QString ptPath="./picturpath";


                     QString s=QString("insert into tbl_photo(ptName,ptTime,ptPath) values('%1','%2','%3');")
                             .arg(ptName).arg(ptTime).arg(ptPath);
                     qDebug()<<s;
                     mydb->Exec(const_cast<char *>(s.toStdString().c_str()));
                     qDebug()<<"保存图片信息到数据库----------------------------------------------"<<count;

//                     qDebug()<<"现场拍照"<<count;


                     pixflag=0;
                 }
                 emit sendImage(img);
                // msleep(30);
                 //发送yuv信号：解码得到数据才会触发信号实现边播放边编码
                 emit sendYUV(pictureYUV);
                 //=====调用编码类的函数：构造函数里创建类对象================
                  //fcodec->codecFrame(pictureYUV);
             }

         }
         //清空包里空间：
         av_packet_unref(pkt);
    }

    //提示保存码流数据成功
//    qDebug()<<"保存码流数据成功"<<endl;
    //发送一个信号 表示结束
    emit sendEndFlag(1);
    //=======写入尾巴帧==================
    //fcodec->writeEndFrame();
}



void fdecode::run()
{
    this->registerFFmpeg();
     QString filename="";
//    //实现边播放边编码
    this->openViedoStream_jiema(filename);//录像

}

void fdecode::setPicname(const QString &value)
{
    picname = value;
}

//fdecode *fdecode::getfdec()
//{
//    fdecode fd;
//    if(fd.pfdec==nullptr)
//    {
//        fd.pfdec=new fdecode();
//    }
//    return fd.pfdec;

//}


