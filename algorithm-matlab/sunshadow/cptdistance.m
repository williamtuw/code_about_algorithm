function [ distance ] = cptdistance( n,la,t1,t2,L1,L2 )
% ����Ԥ�ⳤ�ȱ���ʵ�ʳ��ȱȵ�ƫ��
sh1 = cptElevation(decangle(n),la,t1);
sh2 = cptElevation(decangle(n),la,t2);
if sh1==-1 ||sh2==-1
    distance = -1;
else
    distance = abs(tan(sh1)/tan(sh2)-L2/L1);
end
end
