function [sys,x0,str,ts] = sfun_int(t,x,u,flag,initial_state)

switch flag,
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes(initial_state);
  case 1,
    sys=mdlDerivatives(t,x,u);
  case 2,
    sys=mdlUpdate(t,x,u);
  case 3,
    sys=mdlOutputs(t,x,u);
  case 4,
    sys=mdlGetTimeOfNextVarHit(t,x,u);
  case 9,
    sys=mdlTerminate(t,x,u);
  otherwise
    DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));
end

function [sys,x0,str,ts]=mdlInitializeSizes(initial_state)
sizes = simsizes;

sizes.NumContStates  = 1;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 1;%一个输出，输出积分结果
sizes.NumInputs      = 1;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;

sys = simsizes(sizes);
x0  = initial_state;
str = [];
ts  = [0 0];

function sys=mdlDerivatives(t,x,u)
sys = u;

function sys=mdlUpdate(t,x,u)
sys = [];

function sys=mdlOutputs(t,x,u)
sys = x;

function sys=mdlGetTimeOfNextVarHit(t,x,u)
sampleTime = 1;   
sys = t + sampleTime;

function sys=mdlTerminate(t,x,u)
sys = [];