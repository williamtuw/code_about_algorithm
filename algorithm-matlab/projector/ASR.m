function [points,N]=ASR(funcsm,funcss,ts,tm,p0,pend,maxsteps,mulstep)
N=0;
flag = 1;
p = p0;
points(1,:)=p;
nump=1;
steps = 0;

while  steps < maxsteps
    steps = steps +1 ;
    if mod(steps,mulstep)==0
        p = projector({@cline},ts,p);
    end

    rmp=refector(funcsm,tm,p);
    rsmp=refector(funcss,ts,rmp);
    p = 1/2 * (rsmp + p);
    
    nump = nump+1;
    points(nump,:)=p;
    
    if isget2point(p,pend,1e-6)&&flag
        N = steps;
        flag = 0;
    end
end

