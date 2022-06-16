function [L,C,R,err] = HPF(G,w,R0,first)

%This function does the high-pass filter transformation and calculates
%inductor and capacitor values

%The variable first is 0 for c-first LPF topology & 1 for l-first

L = zeros(length(G)-1,1);
C = zeros(length(G)-1,1);
err = '';
anstxt = "";

if(isempty(G)||isempty(w)||isempty(first)||isempty(R0))
   err = 'Not enough parameters entered';
   return
end

for ii=1:(length(G)-1)
    if(mod(ii,2)==first) %calculate capacitor value
        C(ii) = 1/(w*R0*G(ii));
        anstxt = anstxt + sprintf('C%d = %d F\n',ii,C(ii));
    else %calculate inductor value
        L(ii) = R0/(w*G(ii));
        anstxt = anstxt + sprintf('L%d = %d H\n',ii,L(ii));
    end
end

R = G(length(G))*R0;

anstxt = anstxt + sprintf('R = %d Ohm\n',R);

questdlg(sprintf('%s',anstxt),'HPF Result','OK','OK');