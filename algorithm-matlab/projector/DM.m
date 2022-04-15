function [points,N]=DM(funcsm,funcss,ts,tm,p0,pend,maxsteps,beta,mulstep)
N=0;
flag=1;
p = p0;
points(1,:)=p;
nump=1;
steps = 0;

gamas = - 1/beta;
gamam = 1/beta;
while  steps < maxsteps
    steps = steps +1 ;
    if mod(steps,mulstep)==0
        p = projector({@cline},ts,p);
    end
    
    psp = projector(funcss,ts,p);
    pmp = projector(funcsm,tm,p);
    
    oneagspmp_gsp = (1+gamas)*pmp - gamas*p;
    betaps1agspmp_gsp = beta * projector(funcss,ts,oneagspmp_gsp);
    
    oneagmpsp_gmp = (1+gamam)*psp - gamam*p;
    betapm1agmpsp_gmp = beta* projector(funcsm,tm,oneagmpsp_gmp);
    
    p =   p - betaps1agspmp_gsp + betapm1agmpsp_gmp;
    
   
     if isget2point(p,pend,1e-6)&&flag
        N = steps;
        flag = 0;
    end
    
    nump = nump+1;
    points(nump,:)=[p(1),-p(2)]; 
    
end

