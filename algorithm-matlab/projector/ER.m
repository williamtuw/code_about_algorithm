function [points,N]=ER(funcsm,funcss,ts,tm,p0,pend,maxsteps,mulstep)
N=0;
flag=1;
p = p0;
points(1,:)=p;
nump=1;
steps = 0;
while  steps < maxsteps
    
    steps = steps +1 ;
    if mod(steps,mulstep)==0
        p = projector({@cline},ts,p);
    end
    
    
    
    pmp =projector(funcsm,tm,p);
%     nump = nump+1;
%     points(nump,:)=pmp;
    pspmp = projector(funcss,ts,pmp);
    p = pspmp;
    
    
    if isget2point(p,pend,1e-6)&&flag
        N = steps;
        flag = 0;
    end
    nump = nump+1;
    points(nump,:)=p;

end
