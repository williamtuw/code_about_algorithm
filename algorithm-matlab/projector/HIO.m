function [points,N]=HIO(funcsm,funcss,funcsbar,ts,tm,tbar,p0,pend,maxsteps,beta,mulstep)
N=0;
flag=1;
p = p0;
points(1,:)=p;
nump=1;
steps = 0;

% dstq = sum((p-former_p).^2);
while  steps < maxsteps
    
    steps = steps +1 ;
    if mod(steps,mulstep)==0
        p = projector({@cline},ts,p);
    end
    
    pmp = projector(funcsm,tm,p);
    pspmp = projector(funcss,ts,pmp);
    
    p_betapmp = p - beta*pmp;
    psbarp_betapmp = projector(funcsbar,tbar,p_betapmp);
    
    p = pspmp + psbarp_betapmp;
    
   if isget2point(p,pend,1e-6)&&flag
        N = steps;
        flag = 0;
    end
    
    nump = nump+1;
    points(nump,:)=p;  
   
end
