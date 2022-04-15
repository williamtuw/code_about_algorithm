clc
clear
p0 = [2,0];
pend=[-0.13397459621556135323627682924706,0];
ts = [-50,50];
tm = [0,2*pi-2e-10;0,2*pi-2e-10];
tbar = [-50,50];
maxsteps = 40;
points = zeros(maxsteps+1,2,8);
mulstep = 20;
beta = 0.75;
[points(:,:,1),N(1)] = ER({@mline2,@mline},{@sline},ts,tm,p0,pend,maxsteps,mulstep);
[points(:,:,2),N(2)] = SF({@mline2,@mline},{@sline},ts,tm,p0,pend,maxsteps,mulstep);
[points(:,:,3),N(3)] = HIO({@mline2,@mline},{@sline},{@sbarline},ts,tm,tbar,p0,pend,maxsteps,beta,mulstep);
[points(:,:,4),N(4)] = DM({@mline2,@mline},{@sline},ts,tm,p0,pend,maxsteps,beta,mulstep);
[points(:,:,5),N(5)] = ASR({@mline2,@mline},{@sline},ts,tm,p0,pend,maxsteps,mulstep);
[points(:,:,6),N(6)] = HPR({@mline2,@mline},{@sline},ts,tm,p0,pend,maxsteps,beta,mulstep);
[points(:,:,7),N(7)]= RAAR({@mline2,@mline},{@sline},ts,tm,p0,pend,maxsteps,beta,mulstep);
[points(:,:,8),N(8)] = HIO_ER({@mline2,@mline},{@sline},{@sbarline},ts,tm,tbar,p0,pend,maxsteps,beta,mulstep);

t1 = -2:0.01:2;
t2 = 0:0.01:2*pi-1e-8;
p1 = sline(t1);
p3 = mline(t2);
p2 = mline2(t2);
psbar = sbarline(t1);
p4=cline(t1);

% »æÍ¼

plotfig_amiation(points,{p1,psbar,p4,p2,p3},{'b','--k','','k','k',},{'Support','C_S_u_p_p_o_r_t','Con','Modulus'},p0,N,beta,maxsteps);

















