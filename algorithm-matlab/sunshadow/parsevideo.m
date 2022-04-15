% 从视频中均匀选取20帧
clc;clear;
v = VideoReader('E:\百度网盘\Appendix4.avi');
num = v.NumberOfFrames;
selected = 1:floor(num/20):num;
for i=1:length(selected)
    frame = v.read(selected(i));
    imwrite(frame,sprintf('imgs//img_%d.jpg',i));
end