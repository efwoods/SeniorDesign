%Housekeeping
close all;
clear;
clc;

% build and start the motor control 
rtwbuild('Psim')
tg=xpc;
load(tg,'Psim')
tg.start
tg.status
stateW=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
stateAng1=[-42,-54,-66,-78,-90,-102,-114,-126,-138,138,126,144,102,78,66,54,42];
state =[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
Stock =[-42,-54,-66,-78,-90,-102,-114,-126,-138];
Refill =[-258,-246,-234,-222];
Delivery=[-318,-306,-294,-282];

Di=1; % Current delivery location
Ri=1; % Current refill LOcation

% take Pictur of QR code generate R(1),G(2),Y(4)
[order,message]=qrfunc();
R=order(1);
G=order(2);
Y=order(3);
%get current frameCurrentFrame=captureVideoFrame(1,30);
% image pross
wellcolor=imqpros();

% location vectors
Rloc=zeros(1,9);
Gloc=zeros(1,9);
Yloc=zeros(1,9);
RLB=0;
GLB=0;
YLB=0;

%indexes locations of each color and counts the number of each color
for i=1:9
    state(i)=wellcolor(i);
    if wellcolor(i)==1 %red
        RLB=RLB+1;
        Rloc(RLB)=Stock(i);
    end
    if wellcolor(i)==2 %green
        GLB=GLB+1;
        Gloc(GLB)=Stock(i);
    end
    if wellcolor(i)==3 %yellow
        YLB=YLB+1;
        Yloc(YLB)=Stock(i);
    end
end

pause(1);
state1=state;
[ER,Ri,Di,state,stateW] = movebottels(tg,RLB,Rloc,Ri,Di,R,state,stateW);
[EG,Ri,Di,state,stateW] = movebottels(tg,GLB,Gloc,Ri,Di,G,state,stateW);
[EY,Ri,Di,state,stateW] = movebottels(tg,YLB,Yloc,Ri,Di,Y,state,stateW);






% report why R stoped
if ER==0
    fprintf('All Ketchup Delivered\n');
elseif ER>0
    fprint('%f orders of ketchup were not delivered',R);
elseif ER==-1
    fprintf('No Space in delivery or refill');
end

if EG==0
    fprintf('All Relish Delivered \n');
elseif EG>0
    fprint('%f orders of Relish were not delivered \n',G);
elseif EG==-1
    fprintf('No Space in delivery \n');
end
if EY==0
    fprintf('All musterd Delivered\n');
elseif EY>0
    fprintf('%f orders of Musterd were not delivered',Y);
elseif EY==-1
    fprintf('No Space in delivery');
end
tg.setparam('A/Value',0);
w_enc(tg);
tg.stop;
