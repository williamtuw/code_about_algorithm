% ����Ƶ�о���ѡȡ20֡
clc;clear;
v = VideoReader('E:\�ٶ�����\Appendix4.avi');
num = v.NumberOfFrames;
selected = 1:floor(num/20):num;
for i=1:length(selected)
    frame = v.read(selected(i));
    imwrite(frame,sprintf('imgs//img_%d.jpg',i));
end